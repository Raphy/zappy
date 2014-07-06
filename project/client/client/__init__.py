print("initializing package {0} ...".format(__name__))

from . import ai
from . import network 

class Client:
    
    def __init__(self, team_name, hostname, port):

        self.hostname = hostname
        self.port = port
        self.team_name = team_name

        self.network = network.Network()
        self.connected = False
        self.error = None
        self.__setup_handlers()

        self.core = ai.Core(self.network, team_name)

    def __setup_handlers(self):
        self.network.hook_connected(self.__handler_connected, self)
        self.network.hook_disconnected(self.__handler_disconnected, self)
        self.network.hook_error(self.__handler_error, self)

    @staticmethod
    def __handler_connected(client):
        print("client connected")
        client.connected = True

    @staticmethod
    def __handler_disconnected(client):
        print ("client disconnected")
        client.connected = False

    @staticmethod
    def __handler_error(errno, msg, client):
        print("error:{0}: {1}".format(errno, msg))
        client.error = (errno, msg)

    def connect(self):
        res = self.network.connect(self.hostname, self.port)
        return res == 0

    def run(self):
        self.network.run()
