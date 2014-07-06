print("initializing module {0} ...".format(__name__))

from ..network import Network
from .drone import Drone

class Pilot:
    def __init__(self, network, drone):
        self.network = network
        self.drone = drone
        #self.team = None

    """ action commands """
    def move_forward(self):
        pass
    def turn_left(self):
        pass
    def turn_right(self):
        pass
    def look_up(self):
        pass
    def get_inventory(self):
        pass
    def take_food(self):
        pass
    def take_stone(self, stone):
        pass
    def put_food(self):
        pass
    def put_stone(self, stone):
        pass
    def kick(self):
        pass
    def start_incantation(self):
        pass
    def fork(self):
        pass
    def get_slots_number(self):
        pass

    """ action message broadcast """
    def broadcast_str(self, s):
        pass
    def broadcast_identity(self):
        pass
    def broadcast_inventory(self):
        pass

    """ getters """
    @property
    def drone(self):
        return self._drone

    @property
    def team(self):
        return self._team

    @property
    def network(self):
        return self._network

    """ setters """
    @drone.setter
    def drone(self, value):
        assert type(value) == Drone
        self._drone = value

    @team.setter
    def team(self, value):
        assert type(value) == Team
        self._team = value

    @network.setter
    def network(self, value):
        assert type(value) == Network 
        self._network = value


""" test """
network = Network()
p = Pilot(network, Drone(network, "toto"))
