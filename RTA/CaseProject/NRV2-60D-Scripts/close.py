#!/lib/bin/python
# -*- coding: utf-8 -*-
import socket
import os
import subprocess
def kill_process () :
    cmd = "C:\Progra~2\Ericsson\TCA\Bin\TSL\Release\TSL.exe"
    ret1 = subprocess.Popen(cmd,stdout=subprocess.PIPE,stderr=subprocess.PIPE,shell=True)

    subprocess.Popen.terminate(ret0)
    print "kill process end"
    return


if __name__ == '__main__':
    command = 'taskkill /F /IM TSL.exe'
    ret0 = subprocess.Popen(command,stdout=subprocess.PIPE,stderr=subprocess.PIPE,shell=True)
    ret0.communicate()
    lines = ret0.stdout.readlines()
    if not lines or len(lines) == 0:
        line = ret0.stderr.readlines()
    subprocess.Popen.terminate(ret0) 
    kill_process()
    print 'end'
