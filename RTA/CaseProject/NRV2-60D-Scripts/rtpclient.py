# -*- coding: utf-8 -*-
#Created on 20150409
#Change on 20160623

#@author: etbcffg

#
# -*- coding: cp936 -*-

import sys

from socket import *
class client:
    ip = '127.0.0.1' 
    port = 8001
     
    def __init__(self,ip = '127.0.0.1',port = 8001):
        self.ip = ip
        self.port = port       
        print 'RTT client obj imported'

    def address(self,IP,port):
        self.ip = IP
        self.port = port
        print 'Server address:',self.ip,':',self.port
       
    def commandline(self):
        client = socket(AF_INET,SOCK_STREAM)
        addr=(self.ip, self.port)
        while True:
            command=raw_input("Please input comannds\n")
            if(command=="end"):
                break
            try:
                    #send=cmdlist[idx]+"$"+str(delay)+'\0'
                client.sendto(command,addr)
            except:
                (ErrorType, ErrorValue, ErrorTB) = sys.exc_info()
                print "Connect server failed: ", ErrorValue
                continue
            data="Reply from server:\n"
            try:
                data+=client.recv(25000)
            except:
                (ErrorType, ErrorValue, ErrorTB) = sys.exc_info()
                print "Connect server failed: ", ErrorValue
                continue
            print data
        client.close()

    def cmd(self,command,delay=0,filename=''):
        client = socket(AF_INET,SOCK_DGRAM)
        client.connect((self.ip, self.port))
        addr=(self.ip, self.port)
        if '$' in command:
            command = command.replace('$', '')
        cmdlist = command.split('\n')
          
        for idx in range(0,len(cmdlist)):
            try:
                if(filename!=''):
                    sendcmd=cmdlist[idx]+"$"+str(delay)+"$"+filename
                else:
                    sendcmd=cmdlist[idx]+"$"+str(delay)
                client.sendto(sendcmd,addr)
##                client.send(sendcmd)
            except:
                (ErrorType, ErrorValue, ErrorTB) = sys.exc_info()
                return 'fail to send command to server'

            try:
                data=client.recv(25000)
            except:
                (ErrorType, ErrorValue, ErrorTB) = sys.exc_info()
                return 'fail to receive message from server'
                                
        else:
            pass
                    
        client.close()
        return data

    def tcpcmd(self,command,delay=0,filename=''):
        client = socket(AF_INET,SOCK_STREAM)
        client.connect((self.ip, self.port))
        addr=(self.ip, self.port)
        if '$' in command:
            print '[WARNING]'+command+' ,the $ character will be replaced with a null character!!!'
            command = command.replace('$', '')
        cmdlist = command.split('\n')
          
        for idx in range(0,len(cmdlist)):
            try:
                if(filename!=''):
                    sendcmd=cmdlist[idx]+"$"+str(delay)+"$"+filename
                else:
                    sendcmd=cmdlist[idx]+"$"+str(delay)
                client.sendall(sendcmd)
##                client.send(sendcmd)
            except:
                (ErrorType, ErrorValue, ErrorTB) = sys.exc_info()
                print 'fail to send command to server'

            try:
                data=client.recv(2500000)
            except:
                (ErrorType, ErrorValue, ErrorTB) = sys.exc_info()
                print 'fail to receive message from server'
                                
        else:
            pass
                    
        client.close()
        return data
    
    def gcmd(self,command,delay=0,filename=''):
        data = ''
        for i in rang(5):
            data = cmd(command,delay,filename)
            if data == 'RTT-ACK' or data == '':
                time.sleep(300*i)
                continue
            else:
                break

        return data
                
        
    def pcmd(self,command,delay=0,filename=''):
        client = socket(AF_INET,SOCK_DGRAM)
        client.connect((self.ip, self.port))
        addr=(self.ip, self.port)
        cmdlist = command.split('\n')
          
        for idx in range(0,len(cmdlist)):
            try:
                if(filename!=''):
                    sendcmd=cmdlist[idx]+"$"+str(delay)+"$"+filename
                else:
                    sendcmd=cmdlist[idx]+"$"+str(delay)
                client.sendto(sendcmd,addr)
##                client.send(sendcmd)
            except:
                (ErrorType, ErrorValue, ErrorTB) = sys.exc_info()
                return 'fail to send command to server'

            try:
                data=client.recv(25000)
            except:
                (ErrorType, ErrorValue, ErrorTB) = sys.exc_info()
                return 'fail to receive message from server'
                                
        else:
            pass
                    
        client.close()
        print data
        return data      

    
