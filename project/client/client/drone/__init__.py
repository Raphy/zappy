print("initializing package {0} ...".format(__name__))

from .messenger import Messenger
from .orientation import *
from .drone_id import DroneId
from ..network import Network
from . import message
from . import inventory

class Drone:
    
    START_LEVEL = 1
    END_LEVEL = 8

    def __init__(self, network, team_name):
        self.network = network
        self.id = DroneId.from_machine()
        self.team_name = team_name
        self.level = self.START_LEVEL
        self.orientation = Orientation4(North)

    """ getters """
    @property
    def network(self):
        return self._network

    @property
    def id(self):
        return self._id

    @property
    def team_name(self):
        return self._team_name

    @property
    def level(self):
        return self._level

    @property
    def orientation(self):
        return self._orientation

    """ setters """
    @network.setter
    def network(self, value):
        assert type(value) == Network
        self._network = value

    @id.setter
    def id(self, value):
        assert type(value) == DroneId
        self._id = value

    @team_name.setter
    def team_name(self, value):
        assert type(value) == str
        self._team_name = value

    @level.setter
    def level(self, value):
        assert type(value) == int
        assert value >= self.START_LEVEL and value <= self.END_LEVEL
        self._level = value

    @orientation.setter
    def orientation(self, value):
        assert type(value) == Orientation4 
        self._orientation = value


""" test """
"""
nw = Network()

drone = Drone(nw, "toto")

print(drone, drone.network, drone.id, drone.team_name, drone.level, drone.orientation)
"""