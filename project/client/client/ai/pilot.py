
from . import command
from . import message
#from . import drone
#from .team import Team

class Pilot:
    def __init__(self, core):
        self.core = core
        self.knowledge = core.knowledge
        self.cmd_tracer = core.cmd_tracer

    """ action commands """

    def __wait_return(self, key, timeout=500):
        if key is None:
            raise StopIteration
        i = 0
        while True:
            if i > timeout:
                print(self.core.drone.id, "PROBLEM:", i, len(self.cmd_tracer.over_queue))
                self.cmd_tracer.cancel(key)
                raise StopIteration

            cmd = self.cmd_tracer.pull(key)
            yield cmd
            if cmd is not None:
                raise StopIteration
            i += 1

    def move_forward(self):
        cmd = command.MoveForward(self.knowledge)
        key = self.cmd_tracer.push(cmd, force=False)
        return self.__wait_return(key)

    def turn_left(self):
        cmd = command.TurnLeft(self.knowledge)
        key = self.cmd_tracer.push(cmd, force=False)
        return self.__wait_return(key)

    def turn_right(self):
        cmd = command.TurnRight(self.knowledge)
        key = self.cmd_tracer.push(cmd, force=False)
        return self.__wait_return(key)

    def look_up(self):
        cmd = command.LookUp(self.knowledge)
        key = self.cmd_tracer.push(cmd, force=False)
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
        return self.__wait_return(key, timeout=10000)

    def fork(self):
        cmd = command.Fork()
        key = self.cmd_tracer.push(cmd, force=True)
        return self.__wait_return(key, timeout=2000)

    def get_slot_number(self):
        cmd = command.SlotNumber(self.knowledge)
        key = self.cmd_tracer.push(cmd, force=True)
        return self.__wait_return(key)

    """ action message broadcast """
    def broadcast_identity(self):
        msg = message.Identity.from_scratch(level=self.knowledge.drone.level)
        return self.broadcast_message(msg)

    def broadcast_message(self, msg):
        key = self.core.messenger.send(msg)
        return self.__wait_return(key)

    def broadcast_str(self, s):
        key = self.core.messager.send_str(s)
        return self.__wait_return(key)


""" test """
"""
network = Network()
p = Pilot(network, Drone(network, "toto"))
"""