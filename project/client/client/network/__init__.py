print("initializing package {0} ...".format(__name__))
from ctypes import *
from enum import Enum, unique

from .lib_bind import LibBind
from . import callback_datas as cbdatas

@unique
class HookType(Enum):
    UNKNOWN = 0
    ERRNO = 1
    CALLBACK = 2
    CLIENT_CONNECTED = 3
    CLIENT_DISCONNECTED = 4
    TIMEOUT = 5
    STDIN = 6
    CMD_UNKNOWN = 7
    CMD_WELCOME = 8
    CMD_TEAM_NAME = 9
    CMD_GRAPHIC = 10
    CMD_RMT = 11
    RMT_PUBKEY = 12
    MAX = 13

class Network:
    """A bind to the client side of the zappy C library"""
    
    _ErrorCallbackType = CFUNCTYPE(None, c_void_p, c_int, c_char_p, c_void_p)
    _ReturnCallbackType = CFUNCTYPE(None, c_void_p, c_uint, c_void_p)
    _BasicCallbackType = CFUNCTYPE(None, c_void_p, c_void_p)

    _callbacks = {}

    def __init__(self):
        self.__bind_setup()
        self._cstruct = self._clib.zc_new()
        if self._cstruct is None:
            raise RuntimeError

    def __del__(self):
        if hasattr(self, '_clib'):
            if hasattr(self, '_cstruct'):
                if self._cstruct is not None:
                    self._clib.zc_delete(self._cstruct)

    def __bind_setup(self):
        self._clib = LibBind('../libraries/libzappy.so')
        self._clib.bind_funct('zc_new', [], c_void_p)
        self._clib.bind_funct('zc_delete', [c_void_p])
        self._clib.bind_funct('zc_main', [c_void_p])
        self._clib.bind_funct('zc_connect',  [c_void_p, c_char_p, c_int], c_int)
        self._clib.bind_funct('zc_disconnect', [c_void_p])
        self._clib.bind_funct('zc_disable_timeout', [c_void_p])
        self._clib.bind_funct('zc_set_timeout', [c_void_p, c_long, c_long])

        self._clib.bind_funct('zc_send_team_name', [c_void_p, c_char_p])
        self._clib.bind_funct('zc_send_cmd_forward', [c_void_p])
        self._clib.bind_funct('zc_send_cmd_left', [c_void_p])
        self._clib.bind_funct('zc_send_cmd_right', [c_void_p])


        self._clib.bind_funct('zc_hook_errno', [c_void_p, Network._ErrorCallbackType, c_void_p])
        self._clib.bind_funct('zc_hook_callback', [c_void_p, Network._ReturnCallbackType, c_void_p])
        self._clib.bind_funct('zc_hook_timeout', [c_void_p, Network._BasicCallbackType, c_void_p])
        self._clib.bind_funct('zc_hook_connected', [c_void_p, Network._BasicCallbackType, c_void_p])
        self._clib.bind_funct('zc_hook_disconnected', [c_void_p, Network._BasicCallbackType, c_void_p])
        self._clib.bind_funct('zc_hook_stdin', [c_void_p, Network._BasicCallbackType, c_void_p])
        self._clib.bind_funct('zc_hook_cmd_unknown', [c_void_p, Network._BasicCallbackType, c_void_p])
        self._clib.bind_funct('zc_hook_cmd_welcome', [c_void_p, Network._BasicCallbackType, c_void_p])

    """ interface """

    def connect(self, host, port):
        res = self._clib.zc_connect(\
            self._cstruct, c_char_p(host.encode('utf-8')), c_int(port))
        return res

    def disconnect(self):
        self._clib.zc_disconnect(self._cstruct)

    def run(self):
        self._clib.zc_main(self._cstruct)

    def set_timeout(self, sec, usec):
        self._clib.zc_set_timeout(self._cstruct, sec, usec)

    def disable_timeout(self):
        self._clib.zc_disable_timeout(self._cstruct)


    """ commands """

    def send_team_name(self, team_name):
        self._clib.zc_send_team_name(self._cstruct, team_name.encode('utf-8'))

    def broadcast(self, msg_str):
        pass

    def send_cmd_forward(self):
        self._clib.zc_send_cmd_forward(self._cstruct)

    def send_cmd_left(self):
        self._clib.zc_send_cmd_left(self._cstruct)

    def send_cmd_right(self):
        self._clib.zc_send_cmd_right(self._cstruct)
        
    """ handlers and tools """

    @staticmethod
    def __get_real_data(received_data):
        key = 0 if received_data is None else received_data
        try:
            return cbdatas.get(key)
        except KeyError:
            return None

    @staticmethod
    def __error_handler(cstruct, errno, msg, d):
        data = Network.__get_real_data(d)
        msg = None
        try:
            msg = msg.decode('utf-8')
        except:
            pass
        Network._callbacks['error'](errno, msg, data)

    @staticmethod
    def __return_handler(cstruct, typ, d):
        data = Network.__get_real_data(d)
        try:
            hook_type = HookType(typ)
        except ValueError:
            hook_type = None
        finally:
            Network._callbacks['return'](hook_type, data)


    """ hooker """

    def hook_error(self, callback, data):
        key = cbdatas.add(data)
        self._error_handler = Network._ErrorCallbackType(Network.__error_handler)
        Network._callbacks['error'] = callback
        self._clib.zc_hook_errno(self._cstruct, self._error_handler, key)

    def hook_return(self, callback, data):
        key = cbdatas.add(data)
        self._return_handler = Network._ReturnCallbackType(Network.__return_handler)
        Network._callbacks['return'] = callback
        self._clib.zc_hook_callback(self._cstruct, self._return_handler, key)

    def __hook_basic(self, name, callback, data):
        key = cbdatas.add(data)
        def basic_handler(cstruct, d):
            callback(Network.__get_real_data(d))
        handler = Network._BasicCallbackType(basic_handler)
        setattr(self, '_' + name + "_handler", handler)
        Network._callbacks[name] = basic_handler
        getattr(self._clib, 'zc_hook_' + name)(self._cstruct, handler, key)

    def hook_timeout(self, callback, data):
        self.__hook_basic('timeout', callback, data)

    def hook_connected(self, callback, data):
        self.__hook_basic('connected', callback, data)

    def hook_disconnected(self, callback, data):
        self.__hook_basic('disconnected', callback, data)

    def hook_stdin(self, callback, data):
        self.__hook_basic('stdin', callback, data)

    def hook_cmd_unknown(self, callback, data):
        self.__hook_basic('cmd_unknown', callback, data)

    def hook_cmd_welcome(self, callback, data):
        self.__hook_basic('cmd_welcome', callback, data)

    def hook_broadcast(self, callback, data):
        pass

""" test, to be removed """

nw = Network()
r_data ="r data"
e_data = 'e data'
t_data = 't data'

def return_callback(typ, data):
    print("return callback: type={0}, data={1}".format(None if typ is None else typ.name, data))

def error_callback(errno, msg, data):
    print("error callback: errno={0}, msg={1}, data={2}".format(errno, msg, data))

def timeout_callback(nw):
    print("timeout callback")

def stdin_callback(nw):
    print("stdin callback")

def disconnected_callback(nw):
    print("disconnected callback")

"""
nw.hook_timeout(timeout_callback, nw)
nw.hook_return(return_callback, r_data)
nw.hook_error(error_callback, e_data)
nw.hook_stdin(stdin_callback, nw)
nw.hook_disconnected(disconnected_callback, nw)
nw.set_timeout(2,1)
nw.disable_timeout()
nw.set_timeout(2,1)

nw.connect('localhost', 4242)
nw.send_team_name('toto')
nw.send_cmd_forward()
nw.send_cmd_left()
nw.send_cmd_right()

nw.run()
"""