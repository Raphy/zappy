print("initializing module {0} ...".format(__name__))

from . import command
#from .team import Team

class Pilot:
    def __init__(self, core):
        self.core = core
        self.knowledge = core.knowledge
        self.cmd_tracer = core.cmd_tracer

    """ action commands """

    def __wait_return(self, key):
        while True:
            cmd = self.cmd_tracer.pull(key)
            yield cmd
            if cmd is not None:
                raise StopIteration

    def move_forward(self):
        cmd = command.MoveForward(self.knowledge)
        key = self.cmd_tracer.push(cmd, force=True)
        return self.__wait_return(key)

    def turn_left(self):
        cmd = command.TurnLeft(self.knowledge)
        key = self.cmd_tracer.push(cmd, force=True)
        return self.__wait_return(key)

    def turn_right(self):
        cmd = command.TurnRight(self.knowledge)
        key = self.cmd_tracer.push(cmd, force=True)
        return self.__wait_return(key)

    def look_up(self):
        cmd = command.LookUp(self.knowledge)
        key = self.cmd_tracer.push(cmd, force=True)
        return self.__wait_return(key)

    def get_inventory(self):
        cmd = command.LookInventory(self.knowledge)
        key = self.cmd_tracer.push(cmd, force=True)
        return self.__wait_return(key)

    def take_food(self):
        cmd = command.TakeFood(self.knowledge)
        key = self.cmd_tracer.push(cmd, force=True)
        return self.__wait_return(key)

    def take_stone(self, stone):
        cmd = command.TakeStone(stone, self.knowledge)
        key = self.cmd_tracer.push(cmd, force=True)
        return self.__wait_return(key)

    def put_food(self):
        cmd = command.PutFood(self.knowledge)
        key = self.cmd_tracer.push(cmd, force=True)
        return self.__wait_return(key)

    def put_stone(self, stone):
        cmd = command.PutStone(stone, self.knowledge)
        key = self.cmd_tracer.push(cmd, force=True)
        return self.__wait_return(key)

    def kick(self):
        cmd = command.Kick()
        key = self.cmd_tracer.push(cmd, force=True)
        return self.__wait_return(key)

    def start_incantation(self):
        cmd = command.StartIncantation(self.knowledge)
        key = self.cmd_tracer.push(cmd, force=True)
        return self.__wait_return(key)

    def fork(self):
        cmd = command.Fork()
        key = self.cmd_tracer.push(cmd, force=True)
        return self.__wait_return(key)

    def get_slot_number(self):
        cmd = command.SlotNumber(self.knowledge)
        key = self.cmd_tracer.push(cmd, force=True)
        return self.__wait_return(key)

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
"""
network = Network()
p = Pilot(network, Drone(network, "toto"))
"""