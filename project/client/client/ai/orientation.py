print("initializing module {0} ...".format(__name__))

""" Constantes """
Origin = None

North = 0
West = 1
South = 2
East = 3

Trigo = 1
Clock = -Trigo
Trigo45 = 0.5
Clock45 = -Trigo45
Double = 2
Zero = 0

class Orientation4:
    """
    Contains an orientation value which can be : North, South, West, East.
    """
    def __init__(self, value):
        self._value = value

    @property
    def value(self):
        return self._value

    @value.setter
    def value(self, value):
        self._value = value
        self._mod()

    def _mod(self):
        self._value = (self._value + 4) % 4

class Orientation8(Orientation4):
    """
    Extend the basic Orientation4 with a complement which can be Zero, Trigo45 or Clock45.
    The basic Orientation4 value can also be Origin (None) to say that the source and
    the listener are in the same case.
    """

    def __init__(self, value, complement=Zero):
        super().__init__(value)
        self._complement = complement

    @property
    def value(self):
        return (self._value, self._complement)

    @value.setter
    def value(self, values):
        """ Set value and complement with tuple, or just value. """
        if type(values) != tuple:
            self._value = values
        else:
            self._value, self._complement = values
        self._mod()

    def to_absolute(self, drone_o):
        """
        Create a new Orientation8 from a drone-relative angle to an absolute angle.
        If the relative value is Origin, the absolute value will still be Origin.
        """
        absolute = Orientation8(self._value, self._complement)
        if absolute._value is not Origin:
            absolute.value = absolute._value + drone_o.value
        return absolute

    def to_relative(self, drone_o): 
        """ Inverse of to_absolute. """
        relative = Orientation8(self._value, self._complement)
        if relative.value is not Origin:
            relative.value = relative._value - drone_o._value
        return relative



""" Tests """
"""
o = Orientation4(Origin)
assert(o.value == Origin)
o.value = South
assert(o.value == South)

o = Orientation8(South)
assert(o.value == (South, Zero))
o = Orientation8(North, Trigo45)
assert(o.value == (North, Trigo45))
o.value = South
assert(o.value == (South, Trigo45))
o.value = (South, Clock45)
assert(o.value == (South, Clock45))

drone_o = Orientation4(North)
rel_o = Orientation8(West, Trigo45)
abs_o = rel_o.to_absolute(drone_o)
assert(abs_o.value == (West, Trigo45))
rel2_o  = abs_o.to_relative(drone_o)
assert(rel2_o.value == (West, Trigo45))

drone_o.value = West
abs_o = rel_o.to_absolute(drone_o)
assert(abs_o.value == (South, Trigo45))
abs_o.value = (North, Zero)
rel_o = abs_o.to_relative(drone_o)
assert(rel_o.value == (East, Zero))
"""

