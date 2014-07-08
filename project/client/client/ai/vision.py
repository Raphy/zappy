print("initializing module {0} ...".format(__name__))

from collections import deque
from enum import Enum, unique

class VisibleObject:
    @unique
    class Type(Enum):
        player = 1
        food = 2
        stone = 3

    @classmethod
    def new_player(cls):
        return cls(cls.Type.player)

    @classmethod
    def new_food(cls):
        return cls(cls.Type.food)

    @classmethod
    def new_stone(cls, stone_type):
        return cls(cls.Type.stone, stone_type)

    def __init__(self, type_, value=None):
        self.type = type_
        self.value = value

    def __repr__(self):
        if self.is_player():
            return 'P'
        elif self.is_food():
            return 'F'
        elif self.is_stone():
            return self.get_stone().name[0]
        else:
            return '?'

    def is_player(self): return self.type == self.Type.player
    def is_food(self): return self.type == self.Type.food
    def is_stone(self): return self.type == self.Type.stone
    def get_stone(self): return self.value

class Vision:

    def __init__(self, distance):
        assert distance > 0
        self.distance = distance
        self.__setup_map()

    def __repr__(self):
        s=''
        for y in range(self.size-1,-1,-1):
            for x in range(self.size):
                s += str(self.map[x][y])
            s += '\n'
        return s

    @property
    def player_pos(self):
        """ in fatct, me as distance """
        return self.distance

    def grow_up(self, n):
        if n > 0:
            new_distance = self.distance + n
            new_size = self.__calc_map_size(new_distance)
            new_map = self.__make_empty_map(new_size)
            self.__copy_map(self.map, new_map, x_dst=n, y_dst=n)

            self.distance = new_distance
            self.size = new_size
            self.map = new_map

    def get(self, x, y):
        x, y = self.__to_real_coord(x, y)
        return [] if self.__out_of_bounds(x, y) else self.map[x][y]

    def add(self, x, y, obj):
        x, y = self.__to_real_coord(x, y)
        if self.__out_of_bounds(x, y) == False:
            self.map[x][y].append(obj)

    def set(self, x, y, objs):
        assert type(objs) == list 
        x, y = self.__to_real_coord(x, y)
        if self.__out_of_bounds(x, y) == False:
            self.map[x][y] = objs

    def reset(self, x, y):
        return self.set(x, y, [])

    def clear(self):
        for x, y, case in self.foreach_case():
            case.clear()

    def each_case(self):
        for x, column in enumerate(self.map):
            for y, case in enumerate(column):
                yield (x - self.player_pos, y - self.player_pos, case)
        raise StopIteration

    def each_object(self):
        for x, y, objs in self.foreach_case():
            for obj in objs:
                yield (x, y, obj)
        raise StopIteration

    def move_north(self):
        for x, column in enumerate(self.map):
            column.popleft()
            column.append([])

    def move_south(self):
        for x, column in enumerate(self.map):
            column.pop()
            column.appendleft([])

    def move_east(self):
        self.map.popleft()
        self.map.append(deque([ [] ] * self.size))

    def move_west(self):
        self.map.pop()
        self.map.appendleft(deque([ [] ] * self.size))

    def __setup_map(self):
        self.size = self.__calc_map_size(self.distance)
        self.map = self.__make_empty_map(self.size)

    def __out_of_bounds(self, x, y):
        return True if x < 0 or y < 0 or x >= self.size or y >= self.size else False

    def __to_real_coord(self, x, y):
        return (x + self.player_pos, y + self.player_pos)

    @staticmethod
    def __calc_map_size(distance):
        return distance * 2 + 1

    @staticmethod
    def __make_empty_deque(size):
        return deque(([] for _ in range(size)))

    @staticmethod
    def __make_empty_map(size):
        return deque( (Vision.__make_empty_deque(size) for _ in range(size)) )

    @staticmethod
    def __copy_map(map_src, map_dst, size=None,
                    x_src=0, y_src=0, x_dst=0, y_dst=0):
        if size is None:
            size = len(map_src)

        for x in range(size):
            for y in range(size):
                map_dst[x_dst + x][y_dst + y] = map_src[x_src + x][y_src + y]



""" tests """
"""
vision = Vision(1)

vision.add(0, 0, 42)
vision.add(1, 1, 21)
vision.set(1, 1, [84])
vision.reset(0, 0)
vision.add(-1, -1, 10.5)
print(vision)
vision.grow_up(1)
print(vision)
"""