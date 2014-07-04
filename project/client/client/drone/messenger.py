print("initializing module {0} ...".format(__name__))

from . import message
from .msg_time import MsgTime

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
        _make_type_id('exte'): message.Extended,
    }

    _msg_types_items_view = _msg_types.items()

    def __init__(self, network, team_name):
        self._network = network
        self._counter = 0
        self._callbacks = {}
        self._default = None
        self._team_name = team_name

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
        self._network.broadcast(msg_str)


    def receive(self, msg_str, direction):
        self.__receive(msg_str, direction, None)

    def __msg_setup(self, message):
        message.counter = self._counter
        self._counter += 1
        message.time = MsgTime.now()
        message.team_name = self._team_name
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
            self.__unreconized_msg(msg, direction)
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

nw = network.Network()
msgr = Messenger(nw, "toto team")
d = drone_id.DroneId.from_machine()
msg = message.Extended.from_scratch(emitter_id=d, added='42')
msgr.send(msg)

def callback(message, direction, data):
    print(message, direction, data)

msgr.register(message.Extended, callback, "extended data")
msgr.register(None, callback, "default data")

msgr.receive('exte' + str(msg), "dir")
msgr.receive('qsdf64fq6df56qsd4f:65qs4f:56d4f65qsd4f65sd4qf', 'dir')

msg.team_name ="titi"
msgr.receive('exte' + str(msg), "dir")
"""