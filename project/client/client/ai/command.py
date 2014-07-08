print("initializing module {0} ...".format(__name__))

class Base:

    def __init__(self):
        self.response = None
        self.answered = False
        self.intern_execute = None

    def send(self, network):
        raise NotImplementedError("{0}: 'send' method not implemented"\
            .format(self.__class__.__name__))

    """ Must return True if the response corresponds, and set self.answered to True,
    if the command has been fully aswered """
    def accept(self, response):
        self.response = response
        res = self.intern_accept(response)
        assert type(res) == bool, "{0}: 'intern_accept' method must return a boolean"\
            .format(self.__class__.__name__)
        return res

    def intern_accept(self, response):
        raise NotImplementedError("{0}: 'intern_accept' method not implemented"\
            .format(self.__class__.__name__))

    def execute(self):
        if self.intern_execute is not None:
            self.intern_execute()


""" Returning Ok """

class _RetOk(Base):
    def __init__(self):
        super().__init__()

    def intern_accept(self, response):
        if response.strip() == 'OK':
            self.answered = True
            return True
        return False

class MoveForward(_RetOk):
    def __init__(self, knowledge):
        super().__init__()
        self.knowledge = knowledge

    def intern_execute(self):
        self.knowledge.update_position_forward()

    def send(self, network):
        network.send_cmd_forward()

class TurnLeft(_RetOk):
    def __init__(self, knowledge):
        super().__init__()
        self.knowledge = knowledge

    def intern_execute(self):
            self.knowledge.update_position_left()

    def send(self, network):
        network.send_cmd_left()

class TurnRight(_RetOk):
    def __init__(self, knowledge):
        super().__init__()
        self.knowledge = knowledge

    def intern_execute(self):
        self.knowledge.update_position_right()

    def send(self, network):
        network.send_cmd_right()


class Fork(_RetOk):
    def __init__(self):
        super().__init__()
    def send(self, network):
        #network.send_cmd_fork()
        pass

class Broadcast(_RetOk):
    def __init__(self, message):
        super().__init__()
        self.message = message

    def send(self, network):
        #network.send_cmd_broadcast(message)
        pass

""" Returning OK/KO """

class _RetOkKo(Base):
    def __init__(self):
        super().__init__()
        self.success = None

    def intern_accept(self, response):
        response = response.strip()
        if response == 'OK':
            self.success = True
        elif response == 'KO':
            self.success = False
        else:
            return False
        self.answered = True
        return True

    def intern_execute(self):
        if self.success == True:
            self.success_execute()

class Kick(_RetOkKo):
    def __init__(self):
        super().__init__()
    def send(self, network):
        #network.send_cmd_kick()
        pass

""" Take """
class _TakeObject(_RetOkKo):
    def __init__(self, obj_name, knowledge):
        super().__init__()
        self.obj_name = obj_name
        self.knowledge = knowledge

    def send(self, network):
        #network.send_cmd_take(self.obj_name)
        pass

class TakeStone(_TakeObject):
    def __init__(self, stone_type, knowledge):
        super().__init__(stone_type.name, knowledge)
        self.stone_type = stone_type

    def success_execute(self):
        self.knowledge.drone.inventory.stones_pocket.add(self.stone_type)

class TakeFood(_TakeObject):
    def __init__(self, knowledge):
        super().__init__('nourriture', knowledge)

    def success_execute(self):
        self.knowledge.drone.inventory.food_pocket.add()

""" Put """
class _PutObject(_RetOkKo):
    def __init__(self, obj_name, knowledge):
        super().__init__()
        self.obj_name = obj_name
        self.knowledge = knowledge

    def send(self, network):
        #network.send_cmd_put(self.obj_name)
        pass

class PutStone(_PutObject):
    def __init__(self, stone_type, knowledge):
        super().__init__(stone_type.name, knowledge)
        self.stone_type = stone_type

    def success_execute(self):
        self.knowledge.drone.inventory.stones_pocket.consume(self.stone_type)

class PutFood(_PutObject):
    def __init__(self, knowledge):
        super().__init__('nourriture', knowledge)

    def success_execute(self):
        self.knowledge.drone.inventory.food_pocket.add(-1)

""" Others """
class TeamName(Base):
    def __init__(self, team_name):
        super().__init__()
        self.team_name = team_name
        self.slot_number = None
        self.dimension = None

    def send(self, network):
        network.send_team_name(self.team_name)

    def intern_accept(self, response):
        if self.slot_number is None:
            return self.__accept_slot_number(response)
        else:
            return self.__accept_dimension(response)

    def __accept_slot_number(self, response):
        try:
            self.slot_number = int(response.strip())
        except ValueError:
            return False
        return True

    def __accept_dimension(self, response):
        tab = response.strip().split()
        if len(tab) != 2:
            return False
        try:
            self.dimension = (int(tab[0]), int(tab[1]))
        except ValueError:
            return False
        self.answered = True
        return True

class LookUp(Base):
    def __init__(self, knowledge):
        super().__init__()
        self.knowledge = knowledge

    def intern_accept(self, response):
        if response.lstrip()[0] != '{' or response.rstrip()[-1] != '}':
            return False
        self.answered = True
        return True

    def send(self, network):
        #network.send_cmd_lookup()
        pass

    def intern_execute(self):
        self.knowledge.update_vision(self.response)

class LookInventory(Base):
    def __init__(self, knowledge):
        super().__init__()
        self.knowledge = knowledge

    def intern_accept(self, response):
        if response.lstrip()[0] != '{' or response.rstrip()[-1] != '}':
            return False
        self.answered = True
        return True

    def intern_execute(self):
        self.knowledge.drone.inventory.update_from_str(self.response)

class StartIncantation(Base):
    def __init__(self, knowledge):
        super().__init__()
        self.knowledge = knowledge
    #def intern_accept(self, response):
    #    pass

class SlotNumber(Base):
    def __init__(self, knowledge):
        super().__init__()
        self.knowledge = knowledge
    #def intern_accept(self, response):
    #    pass

