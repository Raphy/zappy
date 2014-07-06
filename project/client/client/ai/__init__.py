print("initializing package {0} ...".format(__name__))

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

class Core:

    def __init__(self, network, team_name):
        self.network = network
        self.team_name = team_name
        self.drone = drone.Drone(network, team_name)
        self.cmd_tracer = cmd_tracer.CmdTracer(network)
        self.messenger = messenger.Messenger(self.network,
            self.cmd_tracer, team_name)

        self.__setup_handlers()

    def __setup_handlers(self):
        self.network.hook_cmd_welcome(self.__handler_welcome, self)

    @staticmethod
    def __handler_welcome(core):
        print ("welcomed")