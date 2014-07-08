print("initializing module {0} ...".format(__name__))

from . import message
from .msg_time import MsgTime
from . import command

""""""
_type_id_len = 4

def _make_type_id(s):
    return s.zfill(_type_id_len)[:_type_id_len]

def _extract_type_id(msg_str):
    return (msg_str[:_type_id_len], msg_str[_type_id_len:])
""""""

class Messenger:

    _msg_types = {
        _make_type_id('base'): message.Base,
        _make_type_id('inve'): message.InventoryMsg,
        _make_type_id('exte'): message.Extended,
    }

    _msg_types_items_view = _msg_types.items()

    def __init__(self, network, cmd_tracer, team_name, emitter_id):
        self._cmd_tracer = cmd_tracer
        self._counter = 0
        self._callbacks = {}
        self._default = None
        self._team_name = team_name
        self._emitter_id = emitter_id

        """ hook broadcast with an instance of __receive method
        that contains directly the 'self' instance """
        network.hook_broadcast(self.__receive, None)

    def register(self, msg_type, callback, data):
        if msg_type == None or msg_type == type(None):
            self._default = (callback, data)
        else:
            assert type(msg_type) == type
            assert issubclass(msg_type, message.Base)
            self._callbacks[msg_type] = (callback, data)

    def send(self, message):
        message = self.__msg_setup(message)
        type_id = self.__type_id_of(message)
        msg_str = str(message)
        if type_id is None or msg_str is None:
            return False
        else:
            self.send_str(type_id + msg_str)
            return True

    def send_str(self, msg_str):
        cmd = command.Broadcast(msg_str)
        key = self._cmd_tracer.push(cmd, force=True)
        return key

    def receive(self, msg_str, direction):
        self.__receive(msg_str, direction, None)

    def __msg_setup(self, message):
        message.counter = self._counter
        self._counter += 1
        message.time = MsgTime.now()
        message.team_name = self._team_name
        message.emitter_id = self.emitter_id
        return message

    def __unreconized_msg(self, msg_str, direction):
        if self._default is not None:
            callback, data = self._default
            callback(msg_str, direction, data)

    def __fraud_attempt(self, message, direction):
        pass

    def __receive(self, msg_str, direction, unused_data):
        type_id, content = _extract_type_id(msg_str)

        if type_id not in self._msg_types:
            self.__unreconized_msg(msg_str, direction)
            return

        msg_type = self._msg_types[type_id]

        if msg_type not in self._callbacks:
            self.__unreconized_msg(msg_str, direction)
            return

        callback, data = self._callbacks[msg_type]
        message = msg_type.from_str(content)

        if message is None:
            self.__unreconized_msg(msg_str, direction)
        elif message.team_name != self._team_name:
            self.__unreconized_msg(msg_str, direction)
        elif message.time.is_expired():
            self.__fraud_attempt(msg_str, direction)
        else:
            callback(message, direction, data)

    @staticmethod
    def __type_id_of(msg_type):
        for type_id, cur_msg_type in Messenger._msg_types_items_view:
            if cur_msg_type == msg_type:
                return type_id
        return None

""" test, to be removed """
"""
from .. import network
from . import drone_id
from .inventory import Inventory
from .cmd_tracer import CmdTracer

nw = network.Network()
cmd_tracer = CmdTracer(network)
msgr = Messenger(nw, "toto team")
d = drone_id.DroneId.from_machine()
i=Inventory()
i.food_pocket.update(42)
msg = message.InventoryMsg.from_scratch(emitter_id=d, inventory=i.to_sendable_str())
key = msgr.send(msg)

def inv_callback(message, direction, data):
    inv = Inventory()
    inv.update_from_str(message.inventory)
    print (inv)


def callback(message, direction, data):
    print(message, direction, data)

msgr.register(message.InventoryMsg, inv_callback, "inventory data")
msgr.register(None, callback, "default data")

msgr.receive('inve' + str(msg), "dir")
msgr.receive('qsdf64fq6df56qsd4f:65qs4f:56d4f65qsd4f65sd4qf', 'dir')

msg.team_name ="titi"
msgr.receive('inve' + str(msg), "dir")
"""