
from ..network import Network

from .orientation import *
from .drone_id import DroneId
from .inventory import Inventory

class BaseDrone:
    START_LEVEL = 1
    END_LEVEL = 8

    def __init__(self, team_name, drone_id=None, level=None, orientation=None):
        self.team_name = team_name
        self.id = DroneId.from_machine() if drone_id is None else drone_id 
        self.level = BaseDrone.START_LEVEL if level is None else level
        self.orientation = Orientation4(North) if orientation is None else orientation
        self.inventory = Inventory()

    def __str__(self):
        return ("Drone({0}):\n" + \
                "\tteam_name: {1}\n" +\
                "\tdrone_id: {2}\n" +\
                "\tlevel: {3}\n" +\
                "\torientation: {4}\n" +\
                "\tinventory: {5}")\
                .format(hex(id(self)), self.team_name, self.id,
                    self.level, self.orientation, self.inventory)

    """ getters """
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

    @property
    def inventory(self):
        return self._inventory

    """ setters """
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
        assert isinstance(value, Orientation4) 
        self._orientation = value

    @inventory.setter
    def inventory(self, value):
        assert type(value) == Inventory 
        self._inventory = value

class Drone(BaseDrone):

    def __init__(self, network, team_name, level=None):
        super().__init__(team_name, level=level)  
        self.network = network
        self.inventory.food_pocket.start_supplying()

    """ getters """
    @property
    def network(self):
        return self._network

    """ setters """
    @network.setter
    def network(self, value):
        assert type(value) == Network
        self._network = value


""" test """
"""
nw = Network()

drone = Drone(nw, "toto")

print(drone)
"""