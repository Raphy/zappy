print("initializing module {0} ...".format(__name__))

from .drone_id import DroneId
from .msg_time import MsgTime

class Base:

    _magic = '?A_^'
    _separator = ':'

    def __init__(self):
        print("base init for", hex(id(self)))
        self.fields_order = []
        self.add_field('magic', str, self.__ctor_magic)
        self.add_field('emitter_id', DroneId, DroneId.from_str)
        self.add_field('counter', int)
        self.add_field('time', MsgTime, MsgTime.from_str)
        self.add_field('team_name', str)

    def __str__(self):
        return self._separator.join((f_str(getattr(self, name)) for name, _, f_str in self.fields_order))        

    """ ctors """
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
        for f_name, _, _ in instance.fields_order:
            if f_name in kwargs:
                setattr(instance, f_name, kwargs[f_name])
        return instance

    """ public """
    def add_field(self, name, field_type, field_ctor=None, field_str=str):
        assert type(field_type) == type
        if field_ctor is None:
            field_ctor = field_type

        def fget(self):
            return getattr(self, '_' + name)
        def fset(self, value):
            if type(value) != field_type:
                raise TypeError("invalid type {0} for attribute '{1}' (must be {2})"
                    .format(type(value), name, field_type))
            setattr(self, '_' + name, value)

        setattr(self.__class__, name, property(fget, fset))
        self.fields_order += [(name, field_ctor, field_str)]

    """ getters """
    @property
    def fields_order(self):
        return self._fields_order

    """ setters """
    @fields_order.setter
    def fields_order(self, value):
        assert type(value) == list
        self._fields_order = value

    """ private """
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
            for (name, ctor, _), value in zip(self.fields_order, fields):
                setattr(self, name, ctor(value))
        except Exception as err:
            print("__parse_str:", err)
            return False
        return True 

""" exemple """
class Extended(Base):
    def __init__(self):
        super().__init__()
        self.add_field('added', str)

class InventoryMsg(Base):
    def __init__(self):
        super().__init__()
        self.add_field('inventory', str)

class GeneralResponceMsg(Base):
    def __init__(self):
        super().__init__()
        self.add_field('destination_id', DroneId)
        self.add_field('response', str) #Should be ok or ko
        self.add_field('to_message_type', type)

class GatheringMsg(Base):
    def __init__(self):
        super().__init__()
        self.add_field('level', str)
        self.add_field('posXY', tuple)

class GatheringCancelMsg(Base):
    def __init__(self):
        super().__init__()
        self.add_field('destination_id', DroneId)

class GatheringArrivedMsg(Base):
    def __init__(self):
        super().__init__()
        self.add_field('destination_id', DroneId)

#GatheringMsg.from_scratch(emitter_id=drone.id)




""" tests, to be removed """
"""
d = DroneId.from_machine()
print(d, hex(id(d)))
m = Base.from_scratch(emitter_id=d, counter=24, team_name='titi',time=MsgTime.now())
print(m)
s = str(m)
m2 = Base.from_str(s)
print (m2)

m3 = Extended.from_scratch(emitter_id=d, counter=1, team_name='titi2', added="toto", time=MsgTime.from_str("654657"))
print(m3)
m4 = Extended.from_str("sqdqsdqs+qsdqsdd465d4dq")
print(m4)

from .inventory import Inventory
i = Inventory()
i.food_pocket.update(12)
i.stones_pocket['deraumere'] = 42
m5 = InventoryMsg.from_scratch(emitter_id=d, counter=1, time=MsgTime.now(), team_name='titi', inventory=i.to_sendable_str())
print(m5)

m6 = InventoryMsg.from_str(str(m5))
print (m6)
"""
