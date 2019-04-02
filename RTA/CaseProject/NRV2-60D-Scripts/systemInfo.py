import socket
import writeFile

HOSTNAME=""
HOSTADDR=""
def getSystemHostInfo():
    global HOSTNAME
    global HOSTADDR
    
    if HOSTADDR and HOSTADDR!="":     
        return HOSTNAME,HOSTADDR
    else:
        HOSTNAME = socket.getfqdn(socket.gethostname())
        HOSTADDR = socket.gethostbyname(HOSTNAME)
        if HOSTADDR and HOSTADDR!="":     
            return HOSTNAME,HOSTADDR
    writeFile.writeLog('Get Host Address Fail!','E'); 
    return False,False
