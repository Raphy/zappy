
from ctypes import *

class LibBind:
    """Make it easy to bind c library"""
    
    def __init__(self, libpath):
        """Raise an OSError if the lib could not be succesfully loaded"""
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

    def bind_funct(self, symbol, argtypes=[], restypes=None, used_name=None):
        """Raise an AttributeError if the symbol is undefined"""
        if used_name is None:
            used_name = symbol
        funct = self.__get_symbol(symbol)
        #print("binding function {0}: {1}".format(symbol, funct))
        self.__funct_config(funct, argtypes, restypes)
        self.__funct_add(used_name, funct)
