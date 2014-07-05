print("initializing module {0} ...".format(__name__))

from .drone_id import DroneId
from .msg_time import MsgTime

class Base:

    _magic = '?A_^'
    _separator = ':'

    @staticmethod
    def __ctor_magic(value):
        if value != Base._magic:
            raise ValueError("bad magic code")
        return value

    def __parse_str(self, s):
        fields = s.split(self._separator)
        if len(fields) < len(self.fields_order):
            return False
        try:
            for (name, ctor), value in zip(self.fields_order, fields):
                setattr(self, name, ctor(value))
        except:
            return False
        return True 

    @classmethod
    def from_str(cls, s):
        instance = cls()
        if instance.__parse_str(s):
            return instance
        else:
            return None

    @classmethod
    def from_scratch(cls, *args, **kwargs):
        instance = cls()
        for f_name, f_ctor in instance.fields_order:
            if f_name in kwargs:
                setattr(instance, f_name, kwargs[f_name])
        return instance

    def __init__(self):
        print("base init for", hex(id(self)))
        self.fields_order = []
        self.add_field('magic', self.__ctor_magic, str)
        self.add_field('emitter_id', DroneId.from_str, DroneId)
        self.add_field('counter', int)
        self.add_field('time', MsgTime.from_str, MsgTime)
        self.add_field('team_name', str)

    def __str__(self):
        return self._separator.join((str(getattr(self, name)) for name, _ in self.fields_order))

    def add_field(self, name, ctor, field_type=None):
        field_type = ctor if field_type is None else field_type  
        assert type(field_type) == type

        def fget(self):
            return getattr(self, '_' + name)

        def fset(self, value):
            if type(value) != field_type:
                raise TypeError("invalid type {0} for attribute '{1}' (must be {2})"
                    .format(type(value), name, field_type))
            setattr(self, '_' + name, value)

        setattr(self.__class__, name, property(fget, fset))
        self.fields_order += [(name, ctor)]

    """ getters """
    @property
    def fields_order(self):
        return self._fields_order

    """ setters """
    @fields_order.setter
    def fields_order(self, value):
        assert type(value) == list
        self._fields_order = value


""" exemple """
class Extended(Base):
    def __init__(self):
        super().__init__()
        self.add_field('added', str)


""" tests, to be removed """
"""
d = DroneId.from_machine()
print(d, hex(id(d)))
m = Base.from_scratch(emitter_id=d, counter=24, time=MsgTime.now())
print(m)
s = str(m)
m2 = Base.from_str(s)
print (m2)

m3 = Extended.from_scratch(emitter_id=d, counter=1, added="toto", time=MsgTime.from_str("654657"))
print(m3)
m4 = Extended.from_str("sqdqsdqs+qsdqsdd465d4dq")
print(m4)
"""

