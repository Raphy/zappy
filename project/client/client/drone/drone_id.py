print("initializing module {0} ...".format(__name__))

import os
import uuid
import hashlib

class DroneId:
    """
    Contains a hash generated from a pid and an uuid.
    The hash is in fact the string representation of the real hash.
    A instance of DroneId can be created without argument by taking
    the current pid and a pseudo-random uuid, or from the hash string of an
    existing player.
    """

    """ Multiple constructors """
    @classmethod
    def from_str(cls, s):
        instance = cls()
        instance.__build_from_str(s)
        return instance
 
    @classmethod
    def from_machine(cls):
        instance = cls()
        instance.__build_from_machine()
        return instance

    def __init__(self):
        self._hash = None

    def __str__(self):
        return self._hash

    def __repr__(self):
        return self.__str__()

    def __eq__(self, other):
        return self._hash == other._hash

    def __ne__(self, other):
        return (self == other) == False

    def __build_from_str(self, s):
        self._hash = s

    def __build_from_machine(self):
        md5 = hashlib.md5()
        md5.update(bytes(str(os.getpid()), 'ascii'))
        md5.update(uuid.uuid1().bytes)
        hash_bytes = md5.digest()
        self._hash = ""
        for b in hash_bytes:
            hexa = hex(b)[2:]
            if len(hexa) < 2:
                hexa = "0" + hexa
            self._hash += hexa

if __name__ == "__main__":

    """ Tests """

    d1 = DroneId()
    d2 = DroneId(str(d1))
    d3 = DroneId()
    assert(d1 == d2)
    assert(d1 != d3)
