class TeamInfo:

    def __init__(self):
        self.teammates = {}

    def getDrone(self, drone_id):
        return self.teammates[drone_id] if self.teammates != {} else None

    def addDrone(self, drone_info):
        self.teammates[drone_info.id] = drone_info