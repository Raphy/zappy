print("initializing package {0} ...".format(__name__))

from enum import Enum, unique

from . import pilot
from . import drone
from . import drone_id
from . import inventory
from . import message
from . import messenger
from . import msg_time
from . import orientation
from . import team
from . import cmd_tracer
from . import command


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

    def __prolog_generator(self):
        cmd = command.TeamName(self.core.team_name)
        key = self.core.cmd_tracer.push(cmd, force=True)
        cmd = self.core.cmd_tracer.pull(key)
        while cmd is None:
            yield
            cmd = self.core.cmd_tracer.pull(key)
        print("slot_number:", cmd.slot_number, "dimenension:", cmd.dimension)
        self.state = State.think

    def __think_generator(self):
        while True:
            yield

    GENERATORS = {
        State.initial: __initial_generator,
        State.prolog: __prolog_generator,
        State.think: __think_generator,
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
        self.cmd_tracer = cmd_tracer.CmdTracer(network, verbose)
        self.messenger = messenger.Messenger(self.network,
            self.cmd_tracer, team_name)
        self.state_machine = StateMachine(self)
        self.context = Context()

        self.__setup_handlers()


        """temporary"""

    def __setup_handlers(self):
        self.network.hook_cmd_welcome(self.__handler_welcome, self)
        self.network.hook_timeout(self.__handler_timeout, self)
        self.network.set_timeout(1, 0)


    @staticmethod
    def __handler_welcome(core):
        if core.verbose:
            core.context.set_consumable_tag(Tag.welcomed, None)
            print ("welcomed")

    @staticmethod
    def __handler_timeout(core):
        if core.verbose:
            print("handler timeout")
        core.state_machine.tick()