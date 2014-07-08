print("initializing module {0} ...".format(__name__))

from enum import Enum, unique
from datetime import datetime

class FoodPocket:

    START_NUMBER = 10

    def __init__(self, start_number=START_NUMBER, update_time=None):
        self.update(start_number, update_time)

    def __str__(self):
        return "{0}(delay:{1})".format(self.remaining,
            int(datetime.now().timestamp()) - self.update_time)

    def start_supplying(self):
        self.update(self.START_NUMBER)

    def update(self, remaining, update_time=None):
        self.remaining = remaining
        self.update_time = update_time

    def add(self, n=1):
        self.remaining += n

    @property
    def remaining(self):
        return self._remaining

    @property
    def update_time(self):
        return self._update_time

    @remaining.setter
    def remaining(self, value):
        assert type(value) == int 
        self._remaining = value

    @update_time.setter
    def update_time(self, value):
        if value is None:
            value = int(datetime.now().timestamp())
        assert type(value) == int 
        self._update_time = value

@unique
class Stone(Enum):
    linemate = 1
    deraumere = 2
    sibur = 3
    mendiane = 4
    phiras = 5
    thystame = 6    

class StonesPocket:
    """
    For exemple, linemate quantity can be reached by using:
        - self.linemate 
        - self['linemate']
        - self[Stone.linemate]
    """

    def __init__(self):
        object.__setattr__(self, '_stones', {stone: 0 for stone in Stone})

    def __str__(self):
        str_gen = ("{0}:{1}".format(str(stone.name), n) for stone, n in self._stones.items())
        return "|".join(str_gen)

    def __getattr__(self, name):
        try:
            return self[Stone[name]]
        except KeyError:
            return None

    def __setattr__(self, name, value):
        try:
            self[Stone[name]] = value
        except KeyError:
            pass

    def __getitem__(self, index):
        if type(index) == str:
            return getattr(self, index)
        elif type(index) == Stone:
            try:
                return self._stones[stone_type]
            except KeyError:
                pass
        return None

    def __setitem__(self, index, value):
        if type(index) == str:
            setattr(self, index, value)
        elif type(index) == Stone:
            if value >= 0:
                try:
                    self._stones[index] = value
                except KeyError:
                    pass

    def __iter__(self):
        return iter(self._stones.items())

    def consume(self, stone_type, n=1):
        assert type(stone_type) == Stone
        self.set(stone_type, self.get(stone_type) - n)

    def add(self, stone_type, n=1):
        assert type(stone_type) == Stone
        self.set(stone_type, self.get(stone_type) + n)

class Inventory:

    def __init__(self):
        self._food_pocket = FoodPocket(0)
        self._stones_pocket = StonesPocket()

    def __str__(self):
        return "Inventory({0}):\n\tfood: {1}\n\tstones: {2}"\
            .format(hex(id(self)), self.food_pocket, self.stones_pocket)

    def update_from_str(self, s, time=None):
        tab = s.strip(' \t\n').lstrip('{').rstrip('}').split(",")
        for entry in tab:
            values = entry.split()
            if len(values) == 2:
                try:
                    name, quantity = values[0], int(values[1])
                    if name == 'nourriture':
                        self.food_pocket.update(quantity, time)
                    else:
                        self.stones_pocket[name] = quantity
                except ValueError:
                    pass

    def to_sendable_str(self):
        food_str ="{"+"nourriture {0}, ".format(self.food_pocket.remaining)
        stone_str_gen = ("{0} {1}".format(stone.name, n) for stone, n in self.stones_pocket)
        return food_str + ", ".join(stone_str_gen) + "}"

    @property
    def food_pocket(self):
        return self._food_pocket

    @property
    def stones_pocket(self):
        return self._stones_pocket


""" tests """
"""
i = Inventory()
i2 = Inventory()

print(i)

i.food_pocket.update(54)
i.stones_pocket.linemate = 42
i.stones_pocket.phiras = 21

print(i)
print(i.to_sendable_str())

i2.update_from_str(i.to_sendable_str())
print(i2)
print(i2.to_sendable_str())
"""