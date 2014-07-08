print("initializing package {0} ...".format(__name__))

from enum import Enum, unique
from random import randint

from . import drone
from . import vision
from . import messenger
from . import cmd_tracer
from . import command
from . import knowledge

from . import pilot
from . import drone_id
from . import inventory
from . import message
from . import msg_time
from . import orientation
#from . import team

@unique
class State(Enum):
    initial = 1
    """ send team_name and receive
    slot_number and map dimension """
    prolog = 2
    think = 3
    explore = 4

class StateMachine:

    def __initial_generator(self):
        while True:
            if len([i for i in self.core.context.get_consumable_with_tag(Tag.welcomed)]) > 0:
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
        return StopIteration


    def __explore_generator(self):
        while True:

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
            for cmd in self.core.pilot.look_up():
                yield

            print(self.core.vision)
        raise StopIteration

    def __think_generator(self):
        while True:
            self.state = State.explore
            yield
        raise StopIteration

    GENERATORS = {
        State.initial: __initial_generator,
        State.prolog: __prolog_generator,
        State.think: __think_generator,
        State.explore: __explore_generator
    }

    FIRST_STATE = State.initial
    DEFAULT_STATE = State.think

    def __init__(self, core):
        self.core = core
        self.state = self.FIRST_STATE

    def tick(self):
        if self.state is None:
            self.state = self.DEFAULT_STATE
        try:
            if self.core.verbose:
                print("transistion({0},?)".format(self.state.name))
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
                new_consumable_tags.append(i_tag, i_data)
            else:
                yield i_data
        self.consumable_tags = new_consumable_tags
    
class Core:

    def __init__(self, network, team_name, verbose=False):
        self.verbose = verbose

        self.network = network

        self.team_name = team_name
        self.drone = drone.Drone(network, team_name)
        self.vision = vision.Vision(8)
        self.knowledge = knowledge.Knowledge(self.drone, self.vision, None)

        self.cmd_tracer = cmd_tracer.CmdTracer(network, verbose)
        self.messenger = messenger.Messenger(
            self.network, self.cmd_tracer,
            team_name, self.drone.id)

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
        if core.verbose:
            print("handler return")
        core.state_machine.tick()        

    @staticmethod
    def __handler_timeout(core):
        if core.verbose:
            print("handler timeout")
        core.state_machine.tick()