print("initializing module {0} ...".format(__name__))

_datas = {}
_nextkey = 0

def add(data):
    global _datas
    global _nextkey
    assert(_nextkey not in _datas)
    _datas[_nextkey] = data
    _nextkey += 1
    return _nextkey - 1

def get(key):
    global _datas
    return _datas[key]

def set(key, data):
    global _datas
    if key not in _datas:
        raise KeyError
    else:
        _datas[key] = data
