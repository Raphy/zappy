print("initializing module {0} ...".format(__name__))

from collections import deque
from . import command

class CmdTracer:

    MAX_CMD_NUMBER = 10

    def __init__(self, network):
        self.network = network
        self.waiting_queue = deque()
        self.out_queue = {}
        self.over_queue = deque()
        self.free_keys = []
        self.next_new_key = 0

    def __str__(self):
        return "waiting: {0}\nout: {1}\nover: {2}"\
            .format(self.waiting_queue, self.out_queue, self.over_queue)

    def receive(self, response):
        if len(self.waiting_queue) > 0:
            key, cmd = self.waiting_queue[0]
            if cmd.accept(response):
                if cmd.answered:
                    self.out_queue[key] = cmd
                    self.waiting_queue.popleft()
                    if len(self.over_queue) > 0:
                        self.__unload_over_queue()
                return True
        return False

    def __reserve_key(self):
        key = None
        if len(self.free_keys) > 0:
            key = self.free_keys.pop()
        else:
            key = self.next_new_key
            self.next_new_key += 1
        return key

    def __free_key(self, key):
        self.free_keys.append(key)

    def __push_in_over_queue(self, cmd):
        key = self.__reserve_key()
        self.over_queue.append((key, cmd))
        return key

    def __push_in_waiting_queue(self, cmd):
        key = self.__reserve_key()
        self.waiting_queue.append((key, cmd))
        cmd.send(self.network)
        return key

    def __unload_over_queue(self):
        assert len(self.over_queue) > 0
        assert len(self.waiting_queue) < self.MAX_CMD_NUMBER
        key, cmd = self.over_queue.popleft()
        self.waiting_queue.append((key, cmd))
        cmd.send(self.network)

    def push(self, cmd, force=False):
        assert isinstance(cmd, command.Base)
        if len(self.waiting_queue) >= self.MAX_CMD_NUMBER:
            if force == False:
                return None
            return self.__push_in_over_queue(cmd)
        return self.__push_in_waiting_queue(cmd)

    def pull(self, key):
        if key not in self.out_queue:
            return None
        cmd = self.out_queue[key]
        del self.out_queue[key]
        self.__free_key(key)
        return cmd

    def __getitem__(self, key, no_except=False):
        if key in self.out_queue:
            return self.out_queue[key]
        def get_from_queue(queue):
            for cur_key, cur_cmd in queue:
                if cur_key == key:
                    return cur_cmd
            return None
        cmd = get_from_queue(self.waiting_queue)
        if cmd is None: cmd = get_from_queue(self.over_queue)
        if cmd is not None:
            return cmd
        if no_except:
            return None
        raise KeyError

""" tests """
"""
from ..network import Network
network = Network()
tracer = CmdTracer(network)

keys = [tracer.push(command.TurnLeft(), force=True) for i in range(15)]
print (tracer)

for key in keys:
    tracer.receive("toto")

for key in keys:
    print ("received:", key, tracer.pull(key))

print(tracer)
"""