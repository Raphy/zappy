import sys

from enum import Enum, unique
from random import randint
from datetime import datetime

from .. import fork

from . import drone
from . import vision
from . import messenger
from . import cmd_tracer
from . import command
from . import knowledge
from . import team
from . import pilot

from . import drone_id
from . import inventory
from . import message
from . import msg_time
from . import orientation

@unique
class State(Enum):
    initial = 1
    """ send team_name and receive
    slot_number and map dimension """
    prolog = 2
    think = 3
    explore = 4
    loot = 5
    search = 6

class StateMachine:

    def __initial_generator(self):
        while True:
            if self.core.context.consume_with_tag(Tag.welcomed):
                self.state = State.prolog
            yield
        raise StopIteration

    def __prolog_generator(self):
        cmd = command.TeamName(self.core.team_name)
        key = self.core.cmd_tracer.push(cmd, force=True)
        cmd = self.core.cmd_tracer.pull(key)
        while cmd is None:
            yield
            cmd = self.core.cmd_tracer.pull(key)
        print("slot_number:", cmd.slot_number, "dimenension:", cmd.dimension)
        self.core.knowledge.slot_number = cmd.slot_number
        self.core.knowledge.map_dimension = cmd.dimension
        self.state = State.think
        yield
        raise StopIteration

    @staticmethod
    def __is_there_takeable(objects):
        return len([obj for obj in objects if obj.is_player() == False ]) > 0

    @staticmethod
    def __is_there_stone(objects):
        return len([obj for obj in objects if obj.is_stone() ]) > 0


    def __search_generator(self):

        for cmd in self.core.pilot.look_up():
            yield

        food = self.core.drone.inventory.food_pocket.remaining
        front_objects = self.core.knowledge.get_front_objects()
        if  (food < 42 and self.__is_there_takeable(front_objects)) or \
            (food >= 42 and self.__is_there_stone(front_objects)):
            for cmd in self.core.pilot.move_forward():
                yield
        else:
            if self.__is_there_takeable(self.core.knowledge.get_left_objects()):
                for cmd in self.core.pilot.turn_left():
                    yield
            elif self.__is_there_takeable(self.core.knowledge.get_right_objects()): 
                for cmd in self.core.pilot.turn_right():
                    yield
            else:
                self.state = State.explore
                yield
                raise StopIteration
            for cmd in self.core.pilot.move_forward():
                yield
        self.state = State.loot
        yield
        raise StopIteration

    def __loot_generator(self):

        for obj in self.core.vision.get(0,0):

            if obj.is_food():
                if self.core.drone.inventory.food_pocket.remaining < 100:
                    for cmd in self.core.pilot.take_food():
                        yield
            elif obj.is_stone():
                print("loot stone:", obj.get_stone())
                for cmd in self.core.pilot.take_stone(obj.get_stone()):
                    yield

        self.state = State.think
        yield
        raise StopIteration


    def __explore_generator(self):
        for i in range(int(self.core.drone.level / 2) + 1):
            r = randint(1,4)
            gen = None
            if r < 3:
                gen = self.core.pilot.move_forward() 
            elif r == 3:
                gen = self.core.pilot.turn_left()
            elif r == 4:
                gen = self.core.pilot.turn_right()
            for cmd in gen:
                yield

        self.state = State.search
        yield
        raise StopIteration

    def __think_generator(self):
        while True:

            # send identity
            if self.core.context.consume_with_tag(Tag.send_identity):
                for cmd in self.core.pilot.broadcast_identity():
                    yield

            # look inventory
            if self.core.context.consume_with_tag(Tag.inventory_request):
                for cmd in self.core.pilot.get_inventory():
                    yield

            # commande fork
            if self.core.context.consume_with_tag(Tag.fork):
                if self.core.team_sync.get_team_size() < 8:
                    for cmd in self.core.pilot.fork():
                        yield

            # slot request
            if self.core.context.consume_with_tag(Tag.slot_request):
                for cmd in self.core.pilot.get_slot_number():
                    yield

            # execve
            if self.core.knowledge.slot_number > 0:
                self.core.fork()
                yield

            # explore
            self.state = State.explore
            yield
        raise StopIteration

    GENERATORS = {
        State.initial: __initial_generator,
        State.prolog: __prolog_generator,
        State.think: __think_generator,
        State.explore: __explore_generator,
        State.loot: __loot_generator,
        State.search: __search_generator,
    }

    FIRST_STATE = State.initial
    DEFAULT_STATE = State.think

    def __init__(self, core):
        self.core = core
        self.state = self.FIRST_STATE
        self.counter = 0

    def timer(self):
        self.counter = (self.counter + 1) & 0x0fffffff

        if self.counter % 1000 == 0:
            self.core.context.set_consumable_tag(Tag.send_identity, None)

        if self.counter % 1000 == 200:
            self.core.context.set_consumable_tag(Tag.slot_request, None)

        if self.counter % 1000 == 0:
            self.core.context.set_consumable_tag(Tag.inventory_request, None)

        if self.counter % 5000 == 0:
            if self.core.team_sync.get_team_size() < 8:
                self.core.context.set_consumable_tag(Tag.fork, None)

    def tick(self):
        self.timer()

        if self.state is None:
            self.state = self.DEFAULT_STATE

        if self.core.verbose:
            print("counter:", self.counter,
                "| state:", self.state.name,
                "| food:", self.core.drone.inventory.food_pocket.remaining,  
                "| team:", self.core.team_sync.get_team_size())

        try:
            next(self.generator)
        except StopIteration:
            self.state = None

    @property
    def state(self):
        return self._state

    @state.setter
    def state(self, value):
        if value is None:
            self._state = None
            self.generator = None
        else:
            assert type(value) == State
            try:
                self.generator = self.GENERATORS[value](self)
                self._state = value
            except KeyError:
                raise RuntimeError("no generator found for " + value.name)

@unique
class Tag(Enum):
    welcomed = 1
    fork = 2
    slot_request = 3
    send_identity = 4
    inventory_request = 5

class Context:

    def __init__(self):
        self.consumable_tags = []
        self.current_tags = []

    def set_current_tag(self, tag, data):
        assert type(tag) == Tag
        self.current_tags.append((tag, data))

    def set_consumable_tag(self, tag, data):
        assert type(tag) == Tag
        self.consumable_tags.append((tag, data))

    def get_currents_with_tag(self, tag):
        return (i_data for i_tag, i_data in self.current_tags if i_tag == tag)

    def get_consumable_with_tag(self, tag):
        new_consumable_tags = []
        for i_tag, i_data in self.consumable_tags:
            if i_tag != tag:
                new_consumable_tags.append((i_tag, i_data))
            else:
                yield i_data
        self.consumable_tags = new_consumable_tags

    def consume_with_tag(self, tag):
        return len([i for i in self.get_consumable_with_tag(tag)]) > 0

    
class Core:

    def __init__(self, client, network, team_name, verbose=False):
        self.verbose = verbose

        self.client = client
        self.forker = fork.Fork(sys.argv[0])
        self.fork_counter = 0

        self.network = network

        self.team_name = team_name
        self.drone = drone.Drone(network, team_name)
        self.vision = vision.Vision(8)
        self.knowledge = knowledge.Knowledge(self.drone, self.vision, None)

        self.cmd_tracer = cmd_tracer.CmdTracer(self, verbose)
        self.messenger = messenger.Messenger(
            self.network, self.cmd_tracer,
            team_name, self.drone.id)

        self.team_sync = team.TeamSync(self)

        self.state_machine = StateMachine(self)
        self.context = Context()
        self.pilot = pilot.Pilot(self)

        self.__setup_handlers()

    def __setup_handlers(self):
        self.network.hook_cmd_welcome(self.__handler_welcome, self)
        self.network.hook_return(self.__handler_return, self)
        self.network.hook_timeout(self.__handler_timeout, self)
        self.network.set_timeout(0, 10000)

    @staticmethod
    def __handler_welcome(core):
        if core.verbose:
            print ("welcomed")
        core.context.set_consumable_tag(Tag.welcomed, None)

    @staticmethod
    def __handler_return(typ, core):
        core.state_machine.tick()

    @staticmethod
    def __handler_timeout(core):
        core.state_machine.tick()

    def receive_message(self, s):
        print("receive msg:", s)
        tab = s.strip().split(',')
        if len(tab) != 2:
            return False
        msg_str = tab[1]

        tab = tab[0].split()
        if len(tab) != 2:
            return False
        direction = None
        try:
            direction = orientation.Orientation8.from_k(int(tab[1]))
        except:
            return False
        self.messenger.receive(msg_str, direction)
        return True

    def receive_kick(self, s):
        print("receive kick:", s)

    def die(self):
        cmd = self.cmd_tracer.waiting_queue[0][1]
        print(int(datetime.now().timestamp()), self.drone.id, 'Died:',
            type(cmd), cmd.create_time, "=>", cmd.send_time,
            "food:", self.drone.inventory.food_pocket.remaining, self.drone.inventory.food_pocket.update_time) 

    def fork(self):
        self.forker.new_process('-n', self.client.team_name,
                                '-h', self.client.hostname,
                                '-p', str(self.client.port),
                                '-v')
        self.fork_counter += 1