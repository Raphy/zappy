#!/usr/bin/env python3

import subprocess
import sys

class Fork:
    def __init__(self, cmd = "./client.py"):
        self.cmd = cmd

    @property
    def cmd(self):
        return self._cmd

    @cmd.setter
    def cmd(self, cmd):
        assert cmd is not None
        self._cmd = cmd

    def new_process(self, *arg):
        tab = [self.cmd]
        for item in arg:
            tab.append(item)
        subprocess.Popen(tab)

if __name__ == "__main__":

    def test_fork_launch():
            f = Fork('python3')
            loops = int(sys.argv[3])
            while (loops > 0):
                print("Father: Loops left: {0}".format(loops))
                f.new_process('./fork.py', '2', '5')
                time.sleep(int(sys.argv[2]))
                loops -= 1

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