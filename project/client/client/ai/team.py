from datetime import datetime

from . import message

class TeamMate:

    def __init__(self, drone_id, level, orientation):
        self.id = drone_id
        self.level = level
        self.orientation = orientation
        self.messages = []
        self.counter = None
        self.__upate_last_seen()

    def __upate_last_seen(self):
        self.last_seen = int(datetime.now().timestamp())
        
    def add_message(self, msg):
        self.messages.append(msg)
        self.counter = msg.counter
        self.__upate_last_seen()

    def is_valid_counter(self, counter):
        return counter is None or counter == self.counter + 1

class Team:

    def __init__(self):
        self.teammates = {}

    def __len__(self):
        return len(self.teammates)

    def has(self, drone_id):
        return drone_id.hash in self.teammates

    def get(self, drone_id):
        if drone_id.hash in self.teammates:
            return self.teammates[drone_id.hash]
        return None

    def add(self, drone):
        if drone.id.hash in self.teammates:
            return False
        self.teammates[drone.id.hash] = drone
        return True

    def delete(self, drone_id):
        if drone_id.hash in self.teammates:
            del self.teammates[drone_id.hash]
            return True
        return False

class TeamSync:

    def __init__(self, core):
        self.core = core
        self.messenger = core.messenger
        self.me = core.drone
        self.team = Team()

        self.__setup_handlers()

    def __setup_handlers(self):
        self.messenger.register(message.Identity, self.__handler_identity, self)

    @staticmethod
    def __handler_identity(message, direction, team_sync):

        orientation = direction.to_absolute(team_sync.me.orientation)
        if team_sync.team.has(message.emitter_id) == False:
            team_mate = TeamMate(message.emitter_id, message.level, orientation)
            team_sync.team.add(team_mate)
        else:
            team_mate = team_sync.team.get(message.emitter_id)
            team_mate.level = message.level
            team_mate.orientation = orientation
            team_mate.add_message(message)

    def get_team_size(self):
        return len(self.team) + 1