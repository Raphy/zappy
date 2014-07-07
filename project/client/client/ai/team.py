class TeamInfo:

    def __init__(self):
        self.teammates = {}
        self.messages = []

    def getDrone(self, drone_id):
        return self.teammates[drone_id] if self.teammates != {} else None

    def addDrone(self, drone_info):
        self.teammates[drone_info.id] = drone_info

    def messages_with_type(self, type_):
        return (message for message in self.messages if type_ == type(message))