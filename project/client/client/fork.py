#!/usr/bin/env python3

import subprocess
import sys

class fork:
    def __init__(self, cmd = "./client.py"):
        self._cmd = cmd

    @property
    def cmd(self):
        return self._cmd

    @cmd.setter
    def cmd(self, cmd):
        self._cmd = cmd

    def new_process(self, *arg):
        assert (self._cmd != None)
        tab = []
        tab.append(self._cmd)
        for item in arg:
            tab.append(item)
        print (tab)
        subprocess.Popen(tab)

def test_fork_launch():
        f = fork('python3')
        loops = int(sys.argv[3])
        while (loops > 0):
            print("Father: Loops left: {0}".format(loops))
            f.new_process('./fork.py', '2', '5')
            time.sleep(int(sys.argv[2]))
            loops -= 1

if __name__ == "__main__":
    import time
    if len(sys.argv) < 3:
        print("Usage: {0} script_type wait_value [loops]".format(sys.argv[0]))
    elif len(sys.argv) == 4 and int(sys.argv[1]) == 1:
        print ("Launching script")
        test_fork_launch()
        print ("Father Died")
    elif int(sys.argv[1]) == 2:
        print ("Successfuly called test2.py child")
        time.sleep(int(sys.argv[2]))
        print ("Child Died")