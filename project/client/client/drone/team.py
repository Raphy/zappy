MaxMessages = 100

""" For testing purpouses """
class TestMessage:
    def __init__(self, drone_id, time, message = None):
        self._drone_id = drone_id
        self._time = time
        self._message = message

    def __repr__(self):
        return "{0}: [{1}]".format(self._time, self._drone_id)

    @property
    def drone_id(self):
        return self._drone_id

    @drone_id.setter
    def drone_id(self, drone_id):
        self._drone_id = drone_id

    @property
    def time(self):
        return self._time

    @time.setter
    def time(self, time):
        self._time = time

    @property
    def message(self):
        return self._message

    @message.setter
    def message(self, message):
        self._message = message


class DroneInfo:
    def __init__(self, drone_id):
        self._id = drone_id
        self._level = 1
        self._messages = []
        self._orientation = None

    @property
    def id(self):
        return self._id

    @id.setter
    def id(self, value):
        assert value is not None, "id should not be set to None"
        self._id = value

    @property
    def level(self):
        return self._level

    @level.setter
    def level(self, value):
        self._level = value

    @property
    def messages(self):
        return self._messages

    @messages.setter
    def messages(self, message):
        if len(self._messages) == MaxMessages:
            self._messages.pop();
        self._messages.append(message)

    def lastMessageTime(self):
        return self._messages[-1].time



class Team:
    def __init__(self):
        self._teammates = []

    def __addDrone(self, message):
        drone = DroneInfo(message.drone_id)
        drone.messages(message)
        self._teammates.append(drone)

    def __removeDrone(self, drone_id):
        self._teammates = [drone for drone in self._teammates if drone.id != drone_id]

    def teamManager(self, message):
        """ Send to the team a message and he'll update the team information """
        drone = next((drone for drone in self._teammates if drone.id == message.drone_id), None)

        if drone == None:
            self.__addDrone(message)
        else:
            drone.messages(message)

if __name__ == "__main__":
    import datetime

    """ DroneInfo testing """
    drone = DroneInfo(1)
    assert drone.id == 1
    assert drone.level == 1
    assert drone.messages == []

    drone.id = 3 
    drone.level = 5
    drone.messages = TestMessage(1, datetime.datetime.now())
    assert drone.messages != []

    print (drone.messages)

    """ Team testing """