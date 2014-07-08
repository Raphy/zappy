print("initializing module {0} ...".format(__name__))

from . import orientation
from . import vision
from . import inventory

class Knowledge:

    def __init__(self, drone, vision, team):
        self.drone = drone
        self.vision = vision
        self.team = team

    def update_vision(self, vision_str):
        vision_str = vision_str.stip().lstrip('{').rstrip('}')
        case_tab = vision_str.split(',')
        for lenght in range(self.drone.level + 1):
            width = lenght * 2 + 1
            for width_pos, case in enumerate(case_tab[:width]):
                self.__update_vision_case(case, lenght, width_pos - int(lenght / 2))
            case_tab = case_tab[width:]

    def update_orientation_left(self):
        self.drone.orienation.turn_left()

    def update_orientation_right(self):
        self.drone.orientation.turn_right()

    def update_position_forward(self):
        self.__update_position_move(self.drone.orientation.value)

    def update_position_kicked(self, src_orient_rel):
        src_orient_abs = src_orient_rel.to_absolute()
        src_orient_abs.turn_back()
        self.__update_position_move(src_orient_rel.value)

    def __update_position_move(self, direction):
        if direction == orientation.North:
            self.vision.move_north()
        elif direction == orientation.South:
            self.vision.move_south()
        elif direction == orientation.West:
            self.vision.move_west()
        elif direction == orientation.East:
            self.vision.move_east()
        else:
            raise ValueError('bad value for drone orientation')

    def __make_object(self, obj_name):
        obj = None
        if obj_name == 'joueur':
            obj = vision.VisibleObject.new_player()
        elif obj_name == 'nourriture':
            obj = vision.VisibleObject.new_food()
        else:
            try:
                stone_type = inventory.Stone[obj_name]
                obj = vision.VisibleObject.new_stone(stone_type)
            except KeyError:
                print("An OVNI has be seen: '{0}'".format(obj_name))
        return obj

    def __make_objects_list(self, case):
        return [obj for obj in \
            (self.__make_object(obj_name) for obj_name in case.split()) \
            if obj is not None]

    def __update_vision_case(self, case, lenght_pos, width_pos):
        o_val = self.drone.orienation
        x_pos = None
        y_pos = None
        if o_val == orientation.North:
            x_pos, y_pos = width_pos, lenght_pos
        elif o_val == orientation.South:
            x_pos, y_pos = -1 * width_pos, -1 * lenght_pos
        elif o_val == orientation.West:
            x_pos, y_pos = -1 * lenght_pos, -1 * width_pos
        elif o_val == orientation.East:
            x_pos, y_pos = lenght_pos, width_pos
        else:
            raise ValueError('bad value for drone orientation')
        self.vision.set(x_pos, y_pos, self.__make_objects_list(case))
