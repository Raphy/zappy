print("initializing package {0} ...".format(__name__))

from .lib_bind import LibBind
from . import callback_datas as cbdatas

from ctypes import *

class Network:
    """A bind to the client side of the zappy C library"""

    _ErrorCallbackType = CFUNCTYPE(None, c_void_p, c_int, c_char_p, c_void_p)
    _ReturnCallbackType = CFUNCTYPE(None, c_void_p, c_uint, c_void_p)
    _TimeoutCallbackType = CFUNCTYPE(None, c_void_p, c_void_p)

    _callbacks = {}

    def __init__(self):
        self._clib = LibBind('../libraries/libzappy.so')
        self._clib.bind_funct('zc_new', [], c_void_p)
        self._clib.bind_funct('zc_delete', [c_void_p])
        self._clib.bind_funct('zc_main', [c_void_p])
        self._clib.bind_funct('zc_connect',\
            [c_void_p, c_char_p, c_int], c_int)
        self._clib.bind_funct('zc_disable_timeout', [c_void_p])
        self._clib.bind_funct('zc_set_timeout', [c_void_p, c_long, c_long])
        self._clib.bind_funct('zc_hook_errno',\
            [c_void_p, Network._ErrorCallbackType, c_void_p])
        self._clib.bind_funct('zc_hook_callback',\
            [c_void_p, Network._ReturnCallbackType, c_void_p])
        self._clib.bind_funct('zc_hook_timeout',\
            [c_void_p, Network._TimeoutCallbackType, c_void_p])

        self._cstruct = self._clib.zc_new()
        if self._cstruct is None:
            raise RuntimeError

    def __del__(self):
        if hasattr(self, '_clib')\
        and hasattr(self, '_cstruct')\
        and self._cstruct is not None:
            self._clib.zc_delete(self._cstruct)

    def connect(self, host, port):
        res = self._clib.zc_connect(\
            self._cstruct, c_char_p(host.encode('utf-8')), c_int(port))
        return res

    def run(self):
        self._clib.zc_main(self._cstruct)

    def set_timeout(self, sec, usec):
        self._clib.zc_set_timeout(self._cstruct, sec, usec)

    def disable_timeout(self):
        self._clib.zc_disable_timeout(self._cstruct)

    def __error_handler(cstruct, errno, msg, d):
        key = 0 if d is None else d
        data = None
        try: data = cbdatas.get(key)
        except KeyError: pass
        msg = None
        try: msg = msg.decode('utf-8')
        except: pass
        Network._callbacks['error'](errno, msg, data)

    def __return_handler(cstruct, typ, d):
        key = 0 if d is None else d
        data = None
        try: data = cbdatas.get(key)
        except KeyError: pass
        Network._callbacks['return'](typ, data)

    def __timeout_handler(cstruct, d):
        key = 0 if d is None else d
        data = None
        try: data = cbdatas.get(key)
        except KeyError: pass
        Network._callbacks['timeout'](data)

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

    def hook_timeout(self, callback, data):
        key = cbdatas.add(data)
        self._timeout_handler = Network._TimeoutCallbackType(Network.__timeout_handler)
        Network._callbacks['timeout'] = callback
        self._clib.zc_hook_timeout(self._cstruct, self._timeout_handler, key)


""" test, to be removed """
nw = Network()
r_data ="r data"
e_data = 'e data'
t_data = 't data'

def return_callback(typ, data):
    print("return callback: type={0}, data={1}".format(typ, data))

def error_callback(errno, msg, data):
    print("error callback: errno={0}, msg={1}, data={2}".format(errno, msg, data))

def timeout_callback(data):
    print("timeout callback: data={0}".format(data))

nw.hook_return(return_callback, r_data)
nw.hook_error(error_callback, e_data)
nw.hook_timeout(timeout_callback, t_data)

nw.set_timeout(2,1)
nw.disable_timeout()
nw.set_timeout(2,1)


nw.connect('localhost', 4242)

nw.run()
