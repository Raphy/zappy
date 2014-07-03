print("initializing module {0} ...".format(__name__))

from . import message

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

    def __init__(self, network):
        self._network = network
        self._counter = 0
        self._callbacks = {}
        self._default = None

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
        message.counter = self._counter
        self._counter += 1
        type_id = self.__type_id_of(message)
        msg_str = str(message)
        if type_id is None or msg_str is None:
            return False
        else:
            self._network.broadcast(type_id + msg_str)
            return True

    def receive(self, msg_str, direction, unused_data):
        self.__receive(msg_str, direction, unused_data)

    def __receive(self, msg_str, direction, unused_data):
        type_id, content = _extract_type_id(msg_str)
        try:
            msg_type = self._msg_types[type_id]
            callback, data = self._callbacks[msg_type]
            message = msg_type.from_str(content)
            if message is not None:
                callback(message, direction, data)
            else:
                raise KeyError
        except KeyError:
            if self._default is not None:
                callback, data = self._default
                callback(msg_str, direction, data)

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
msgr = Messenger(nw)
d = drone_id.DroneId.from_machine()
msg = message.Extended.from_scratch(emitter_id=d, added='42')
msgr.send(msg)

def callback(message, direction, data):
    print(message, direction, data)

msgr.register(message.Extended, callback, "extended data")
msgr.register(None, callback, "default data")

msgr.receive('exte' + str(msg), "dir", None)
msgr.receive('qsdf64fq6df56qsd4f65qs4f56d4f65qsd4f65sd4qf', 'dir', None)
"""