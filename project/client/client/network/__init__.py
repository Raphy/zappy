print("initializing package {0} ...".format(__name__))

from .lib_bind import LibBind

from ctypes import *

class Network:
    """A bind to the client side of the zappy C library"""

    ErrorCallbackType = CFUNCTYPE(c_void_p, c_int, c_char_p, c_void_p)
    ReturnCallbackType = CFUNCTYPE(c_void_p, c_uint, c_void_p)
    TimeoutCallbackType = CFUNCTYPE(c_void_p, c_void_p)

    def __init__(self):
        self._clib = LibBind('./libzappy.so')
        self._clib.bind_funct('zc_new', [], [c_void_p])
        self._clib.bind_funct('zc_delete', [c_void_p], [])
        self._clib.bind_funct('zc_main', [c_void_p], [])
        self._clib.bind_funct('zc_connect', [c_void_p, c_char_p, c_int], [c_int])
        self._clib.bind_funct('zc_disable_timeout', [c_void_p], [])
        """
        self._clib.bind_funct('zc_set_timeout', [c_void_p], [])
        self._clib.bind_funct('zc_get_timeout')
        """
        self._clib.bind_funct('zc_hook_errno',\
            [c_void_p, Network.ErrorCallbackType, c_void_p], [])
        self._clib.bind_funct('zc_hook_callback',\
            [c_void_p, Network.ReturnCallbackType, c_void_p], [])
        self._clib.bind_funct('zc_hook_timeout',\
            [c_void_p, Network.TimeoutCallbackType, c_void_p], [])

        self._cstruct = self._clib.zc_new()
        if self._cstruct.value is None:
            raise RuntimeError

    def __del__(self):
        if hasattr(self, '_clib')\
        and hasattr(self, '_cstruct')\
        and self._cstruct is not None:
            self._clib.zc_delete(self._cstruct)

    def connect(self, host, port):
        res = self._clib.zc_connect(\
            self._cstruct, c_char_p(host.encode('utf-8')), c_int(port))
        return res.value

    def run(self):
        self._clib.zc_main(self._cstruct)

    def set_timeout(self, sec, usec):
        pass

    def get_timeout(self):
        pass

    def disable_timeout(self):
        self._clib.disable_timeout(self._cstruct)

    def hook_error(self, callback, data):
        def error_handler(cstruct, errno, msg, d):
            msg = msg.value.decode('utf-8') if msg.value else None 
            callback(errno.value, msg, data)
        handler = Network.ErrorCallbackType(error_handler)
        self._clib.zc_hook_errno(self._cstruct, handler, c_void_p(None))

    def hook_return(self, callback, data):
        def return_handler(cstruct, typ, d):
            callback(typ.value, data) 
        handler = Network.ReturnCallbackType(return_handler)
        self._clib.zc_hook_callback(self._cstruct, handler, c_void_p(None))

    def hook_timeout(self, callback, data):
        def timeout_handler(cstruct, d):
            callback(typ.value, data) 
        handler = Network.TimeoutCallbackType(timeout_handler)
        self._clib.zc_hook_timeout(self._cstruct, handler, c_void_p(None))


nw = Network()