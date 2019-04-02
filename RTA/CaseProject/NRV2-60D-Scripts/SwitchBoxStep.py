import os
import time
import socket
import re
from TestFrame import *

switchbox_address = '10.166.149.70'
port = 1000

class SwitchBoxStep(TestStep):
    'SwitchBoxStep'
    def __init__(self,*arg1,**arg2):
        self.__name = self.__doc__
    
    def stepName(self):
        return self.__name

    def execCommand(self,cmd,timeout=1):
        self.log(cmd);
        result = None
        try:
            conn = socket.socket()
            conn.settimeout(5)
            conn.connect((switchbox_address, port))
            conn.settimeout(timeout)
 
            conn.send('%s\n' % cmd)
            reply = conn.recv(1024)
            
        except Exception,e:
            self.log('Socket Error: %s'%e)
        finally:
                conn.close()

        return reply

class DlSwitchBoxStep(SwitchBoxStep):
    'DlSwitchBoxStep'
    def run(self):
        output = self.execCommand('ANT 2,O1')
        regex = 'OK'
        result = re.search(regex, output)
        if result == None:
            return False
        else:
            return True

class UpSwitchBoxStep(SwitchBoxStep):
    'UpSwitchBoxStep'
    def run(self):
        output = self.execCommand('ANT 1,O1')
        regex = 'OK'
        result = re.search(regex,output)
        if result == None:
            return False
        else:
            return True

class DlSwitchBoxCase(TestCase):
    'DlSwitchBoxCase'
    def configTestStep(self):    
        self.addTestStep(DlSwitchBoxStep())
        
class UpSwitchBoxCase(TestCase):
    'UpSwitchBoxCase'
    def configTestStep(self):    
        self.addTestStep(UpSwitchBoxStep())
