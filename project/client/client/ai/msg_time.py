from datetime import datetime

class MsgTime:

    _validity_duration = 60

    @classmethod
    def from_str(cls, s_timestamp):
        assert type(s_timestamp) == str
        try:
            return cls(int(float(s_timestamp)))
        except ValueError:
            return None

    @classmethod
    def now(cls):
        return cls(int(datetime.now().timestamp()))

    def __init__(self, timestamp):
        self.timestamp = timestamp

    def __str__(self):
        return str(self.timestamp)

    @property
    def timestamp(self):
        return self._timestamp

    @timestamp.setter
    def timestamp(self, value):
        self._timestamp = int(value)

    def is_expired(self):
        return datetime.now().timestamp() - self.timestamp \
                > self._validity_duration

    def is_still_valid(self):
        return not self.is_expired()


""" tests, to be removed """
"""
m = MsgTime.now()
print (m, m.is_expired(), m.is_still_valid())
m2=MsgTime.from_str("654646")
print (m2, m2.is_expired(), m2.is_still_valid())
"""