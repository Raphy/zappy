from ctypes import *

class _LibBind:
    """Make it easy to bind c library"""
    
    def __init__(self, libpath):
        """raise an OSError if the lib could not be succesfully loaded"""
        self._lib = CDLL(libpath)
        self._functions = {}
    
    def __get_symbol(self, name):
        return getattr(self._lib, name)

    def __funct_add(self, name, funct):
        self._functions[name] = funct
        fget = lambda self: self._functions[name]
        setattr(self.__class__, name, property(fget))

    def __funct_config(self, funct, argtypes, restypes):
        funct.argtypes = argtypes
        funct.restypes = restypes

    def bind_funct(self, symbol, argtypes=[], restypes=[], used_name=None):
        if used_name is None:
            used_name = symbol
        funct = self.__get_symbol(symbol)
        self.__funct_config(funct, argtypes, restypes)
        self.__funct_add(used_name, funct)

class Network:
    """a bind to the client side of the zappy C librarie"""
    pass


if __name__ == '__main__':
    try:
        b = _LibBind("d")
        assert(False)
    except OSError as err:
        pass
    b = _LibBind('lib.so')
    b.bind_funct('toto')
    assert(b.toto() == 42)