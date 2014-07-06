print("initializing module {0} ...".format(__name__))

class Base:

    def __init__(self):
        self.response = None
        self.answered = False

    def send(self, network):
        raise NotImplementedError("{0}: 'send' method not implemented"\
            .format(self.__class__.__name__))

    """ Must return True if the response corresponds, and set self.answered to True,
    if the command has been fully aswered """
    def accept(self, response):
        res = self.intern_accept(response)
        assert type(res) == bool, "{0}: 'intern_accept' method must return a boolean"\
            .format(self.__class__.__name__)
        return res

    def intern_accept(self, response):
        raise NotImplementedError("{0}: 'intern_accept' method not implemented"\
            .format(self.__class__.__name__))


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
    def __init__(self):
        super().__init__()
    def send(self, network):
        network.send_cmd_forward()

class TurnLeft(_RetOk):
    def __init__(self):
        super().__init__()
    def send(self, network):
        network.send_cmd_left()


class TurnRight(_RetOk):
    def __init__(self):
        super().__init__()
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
            self.success == 'False'
        else:
            return False
        self.answered = True
        return True

class Kick(_RetOkKo):
    def __init__(self):
        super().__init__()
    def send(self, network):
        #network.send_cmd_kick()
        pass

""" Take """

class _TakeObject(_RetOkKo):
    def __init__(self, obj_name):
        super().__init__()
        self.obj_name = obj_name
    def send(self, network):
        #network.send_cmd_take(self.obj_name)
        pass

class TakeStone(_TakeObject):
    def __init__(self, stone_type):
        super().__init__(stone_type.name)
        self.stone_type = stone_type

class TakeFood(_TakeObject):
    def __init__(self):
        super().__init__('nourriture')

""" Put """
class _PutObject(_RetOkKo):
    def __init__(self, obj_name):
        super().__init__()
        self.obj_name = obj_name
    def send(self, network):
        #network.send_cmd_put(self.obj_name)
        pass

class PutStone(_PutObject):
    def __init__(self, stone_type):
        super().__init__(stone_type.name)
        self.stone_type = stone_type

class PutFood(_PutObject):
    def __init__(self):
        super().__init__('nourriture')

""" Others """
class LookUp(Base):
    def __init__(self):
        super().__init__()
    #def intern_accept(self, response):
    #    pass

class LookInventory(Base):
    def __init__(self):
        super().__init__()
    #def intern_accept(self, response):
    #    pass

class StartIncantation(Base):
    def __init__(self):
        super().__init__()
    #def intern_accept(self, response):
    #    pass

class SlotNumber(Base):
    def __init__(self):
        super().__init__()
    #def intern_accept(self, response):
    #    pass

