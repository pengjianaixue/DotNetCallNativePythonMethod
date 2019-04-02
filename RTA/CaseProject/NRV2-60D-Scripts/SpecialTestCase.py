#!/lib/bin/python
# -*- coding: utf-8 -*-
import socket
import os
import sys
import re
import time
from TestFrame import *
import TestFrame

DIRECT = 'direct'
INDIRECT = 'indirect'

#image0=0
#Radio_App0=1
image1Pos = 7
Radio_App1=8

class loadInstall(TestCase):
    'Load_Install'

    def configTestStep(self):
        self.setKeyCase()
        self.setTargetType('TRXM')


    def RunCommand(self,cmd):
        conn = socket.socket()
        try:
            output = []
            conn.settimeout(5)
            conn.connect((TestFrame.address,TestFrame.port))
##            conn.send('\n')
##            conn.recv(2048)
            print cmd
            conn.send('%s\n' % cmd)
            self.log('$ %s\n' % cmd)
            conn.settimeout(12)
            while True:
                reply = conn.recv(1024)
                output += reply.split('\n')
        except Exception as e:
            self.log('Socket Error: %s\n'%e)
            pass
        finally:
            conn.close()
            result = []
            print output
            if output == []:
                result.append('No Response')
                return result
            for line in output:
                if not line=='$' and not line=='\n' and not line=='\r':
                    regex = 'connection'
                    flag = re.search(regex, line)
                    if flag == None:
                        self.log(line+'\n')
                        result.append(line)
            return result
        
    def burnSre(self,target,flashRegion,sreFile):
        self.log('burnSre(%d,%d,%s)\n'%(target,flashRegion,sreFile))
        updateResult = True
        fileError = True
        try:
            fd= open(sreFile,'rb',0)
            sreLength = os.path.getsize(sreFile)
            fileError = False
            s = socket.socket()
            s.connect((TestFrame.address,TestFrame.port))
            res = s.recv(1024)
            self.log(res)
            time.sleep(60)
            command = 'program %d 0x%x 0x%x\n' %(target,flashRegion,sreLength)
            s.send(command)
            self.log(command)
            res = s.recv(1024)
            self.log(res)
            if (res == None):
                self.log( 'time out')
                fd.close()
                s.close()
                os._exit(0)

            if (None == re.search('successful', res) and None == re.search('over', res)):
                self.log( 'Erase flash failed!!!')
                fd.close()
                s.close()
                os._exit(0) 

            times = 0
            while True:
                p = os.popen("ping %s" % address)
                out = p.read()
                print out

                if (times >= 60):
                    self.powerOffOn()
                    times = 0

                    fd = open(sreFile,'rb',0)
                    sreLength = os.path.getsize(sreFile)
                    fileError = False
                    s = socket.socket()
                    s.connect((TestFrame.address,TestFrame.port))
                    res = s.recv(1024)
                    self.log(res)
                    time.sleep(60)
                    command = 'program %d 0x%x 0x%x\n' %(target,flashRegion,sreLength)
                    s.send(command)
                    self.log(command)
                    res = s.recv(1024)
                    self.log(res)
                    if (res == None):
                        self.log( 'time out')
                        fd.close()
                        s.close()
                        os._exit(0)
                    if (None == re.search('successful', res) and None == re.search('over', res)):
                        self.log( 'Erase flash failed!!!')
                        fd.close()
                        s.close()
                        os._exit(0)
                if (None != re.search('Sent = 4, Received = 4, Lost = 0', out) and None == re.search('Destination host unreachable', out)):
                    break
                elif (None != re.search('=32', out) and None != re.search('TTL=255', out)):
                    break
                elif (None != re.search('=32', out) and None != re.search('TTL=254', out)):
                    break
                elif (None != re.search(' = 4', out) and None != re.search(' = 0 (0% ', out)):
                    break
                times = times + 1


            cnt=0
            Repeat = True
            progress = 0
            self.log('start to send sre file\n')
            while Repeat:
                data = fd.read(1024)
                if not data:
                    Repeat = False
                else:
                    s.send(data)
                    cnt = cnt + 1024
                    if progress < cnt * 100 / sreLength:
                        progress = cnt * 100 / sreLength
                        print(progress,"%")
                        self.log('Transmit bytes: %d, Total bytes: %d, Progress: %d percents\n' %(cnt,sreLength,progress))
            res = s.recv(1024)
            self.log(res)
        except Exception as e:
            if fileError:
                self.log('File opeartion fail, the err is %s\n' % e)
            else:
                self.log('Socket opeartion fail, the err is %s\n' % e)
            updateResult = False
        finally:
            fd.close()
            s.close()
            return updateResult

    def burnLoad(self,target,flashRegion,binFile):
        self.log('burnLoad(%d,%d,%s)\n'% (target,flashRegion,binFile))
        updateResult = True
        fileError = True
        try:
            fd = open(binFile,'rb',0)
            binLength = os.path.getsize(binFile)
            fileError = False
            s = socket.socket()
            s.connect((TestFrame.address,TestFrame.port))
            res = s.recv(1024)
            self.log(res)
            time.sleep(60)
            command = 'program %d 0x%x 0x%x\n' %(target,flashRegion,binLength)
            s.send(command)
            self.log(command)
            res = s.recv(1024)
            self.log(res)
            if (res == None):
                self.log( 'time out')
                fd.close()
                s.close()
                os._exit(0)

            if (None == re.search('successful', res) and None == re.search('over', res)):
                self.log( 'Erase flash failed!!!')
                fd.close()
                s.close()
                os._exit(0) 
            times = 0
            while True:
                p = os.popen("ping %s" % address)
                out = p.read()
                self.log(out)
####if too long time cant ping,restart now
                if (times >= 60):
                    self.powerOffOn()
                    times = 0

                    fd = open(binFile,'rb',0)
                    binLength = os.path.getsize(binFile)
                    fileError = False
                    s = socket.socket()
                    s.connect((TestFrame.address,TestFrame.port))
                    res = s.recv(1024)
                    self.log(res)
                    time.sleep(60)
                    command = 'program %d 0x%x 0x%x\n' %(target,flashRegion,binLength)
                    s.send(command)
                    self.log(command)
                    res = s.recv(1024)
                    self.log(res)
                    if (res == None):
                        self.log( 'time out')
                        fd.close()
                        s.close()
                        os._exit(0)
                    if (None == re.search('successful', res) and None == re.search('over', res)):
                        self.log( 'Erase flash failed!!!')
                        fd.close()
                        s.close()
                        os._exit(0) 

                if (None != re.search('Sent = 4, Received = 4, Lost = 0', out) and None == re.search('Destination host unreachable', out)):
                    break
                elif (None != re.search('=32', out) and None != re.search('TTL=255', out)):
                    break
                elif (None != re.search('=32', out) and None != re.search('TTL=254', out)):
                    break
                elif (None != re.search(' = 4', out) and None != re.search(' = 0 (0% ', out)):
                    break
                times = times+1

            cnt = 0
            Repeat = True
            progress = 0
            self.log('start to send bin file\n')
            while Repeat:
                data = fd.read(1024)
                if not data:
                    Repeat = False
                else:
                    s.send(data)
                    cnt = cnt + 1024
                    if progress < cnt * 100 / binLength:
                        progress = cnt * 100 / binLength
                        print (progress,"%")
                        self.log( 'Transmit bytes: %d, Total bytes: %d, Progress: %d percents\n' % (cnt,binLength,progress))
            res = s.recv(1024)
            self.log(res)
        except Exception as e:
            if fileError:
                self.log('File opeartion fail, the err is %s\n' % e)
            else:
                self.log('Socket opeartion fail, the err is %s\n' % e)
            updateResult = False
        finally:
            fd.close()
            s.close()
            return updateResult
    
    def powerOffOn(self):
        self.log('pwerOffOn....\n')
        RtpAddress = '127.0.0.1'
        RtpPort = 8001
        try:
            conn = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
            conn.connect((RtpAddress, RtpPort))
            delay = 0
            self.log('power off\n')
            command = 'DC5767A.OUTP OFF'
            cmd = command + '$' + str(delay)
            conn.sendto(cmd, (RtpAddress, RtpPort))
            result = conn.recv(25000)
            self.log(result)
            self.log('sleep 10s.')
            time.sleep(10)
            command = 'DC5767A.OUTP ON'
            cmd = command + '$' + str(delay)
            print ('=====power on')
            self.log('power on\n') 
            conn.sendto(cmd, (RtpAddress, RtpPort))
            result = conn.recv(25000)
            self.log(result)
            time.sleep(80)
        except Exception as e:
            self.log('Fail to send command to RTP')
            self.log('Error: %s' % e)
            conn.close()
            return None
        finally:
            conn.close()
            return result

    def checkBurnResult(self,target,loadRegion,binFile):
        self.log('checkBurnResult(%d,%d,%s)\n' %(target,loadRegion,binFile))
        fileType=os.path.splitext(binFile)[1]
        filetmp='.bin'
        if fileType == filetmp:
            if target == 0:
                output = self.RunCommand('lmclist')
            else:
                                                                               #output--slot state,curr,proddate,Type,SwPid
                output = self.RunCommand('trxm %d lmclist' % (target-1))
            regionInfo = []
            regex = '.*(0|1)\s+([a-zA-Z]*)\s+(\d*)\s+(Yes|No)\s+(\d*\\.\s?\S*)\s+(\S*)\s+(\S*)'
            for index,line in enumerate(output):
                if index >0:
                    result = re.match(regex,line)
                    if result==None:
                        pass
                    else:
                        regionInfo.append({'region':int(result.group(1)),
                                           'state':result.group(2),
                                           'size':result.group(3),
                                            'cuur':result.group(4),
                                            'prodDate':result.group(5),
                                            'type':result.group(6),
                                            'swPid':result.group(7)})
            for regionItem in regionInfo:
                if regionItem['region']==loadRegion and regionItem['swPid'].replace('%','_') in binFile.replace('%','_'):
                    return True
            self.log('Expected load is not in region %d\n'%loadRegion)
            return False
                                                                            
        else:
            return True
        
#o槽位和1槽位，image0对应0槽位，image1对应1槽位，image0在flash0区域中，image1在flash7区域中
    def reboot(self,target,flashRegion):
        #self.log('reboot(%d,%d)\n' % (target, flashRegion))
        if target == 0:
            self.RunCommand('reboot %d'% flashRegion)                           
        else:
            self.RunCommand('trxm %d reboot %d' % (target-1,flashRegion))
              
    def checkConnectionStatus(self,target):
        self.log('checkConnectionStatus(%d)\n' % (target))
        if target == 0:
            waitTime = 0
            while True:
                try:
                    waitTime +=10
                    self.log('Trying to re-connect to card ...\n')
                    s = socket.socket()
                    s.settimeout(10)
                    s.connect((TestFrame.address,TestFrame.port))
                    s.close()
                    return True
                except:
                    s.close()
                    if waitTime>=600:
                        self.log('Fail to connect to card\n')
                        return False
        else:
            waitTime = 0
            while True:
                if waitTime > 60:
                    self.log('iLink fail for TRXM%d'% (target-1))
                    return False
                output = self.RunCommand('rru status')
                #print (output)
                if len(output) < 15:
                    self.log('rru status response failure')
                    return False
                ltuStatus = output[2]
                iLinkOam = output[(target-1)*2+3]
                iLinkData = output[(target-1)*2+4]
                cpri0 = output[7]
                regexLtu = 'LTU Status: Lock\r'
                regexOam = 'ILINK %d OAM: OK\r'% (target-1)
                regexData = 'ILINK %d DATA: OK\r'%(target-1)
                regexCpri0 = 'CPRI 0: Sync \r'
                self.log (output[2])
                self.log (regexLtu)
                result1 = re.match(regexOam,iLinkOam)
                result2 = re.match(regexData,iLinkData)
                result3 = re.match(regexLtu,ltuStatus)
                result4 = re.match(regexCpri0,cpri0)
                if result1==None or result2==None or result3==None or result4==None:
                    waitTime += 10
                    self.log('iLink status not availabe, retry 10s later...\n') 
                    time.sleep(10)
                else:
                    return True
        

    def checkRunningStatus(self,target,targetRegion):
        self.log('checkRunningStatus(%d,%d)\n' % (target,targetRegion))
        if target == 0:
            output = self.RunCommand('lmclist')
        else:
            output = self.RunCommand('trxm %d lmclist' % (target-1))
        regionInfo = []
        regex = '.*(0|1)\s+([a-zA-Z]*)\s+(\d*)\s+(Yes|No)\s+(\d*\\.\s?\S*)\s+(\S*)\s+(\S*)'
        for index,line in enumerate(output):
            if index > 0:
                result = re.match(regex,line)
                if result==None:
                    pass
                else:
                    regionInfo.append({ 'region':int(result.group(1)),
                                        'state':result.group(2),
                                        'size':result.group(3),
                                        'cuur':result.group(4),
                                        'prodDate':result.group(5),
                                        'type':result.group(6),
                                        'swPid':result.group(7)})
        for regionItem in regionInfo:
            if regionItem['region']==targetRegion and regionItem['state']=='working' and regionItem['cuur']=='Yes':
                self.log('Running expected load\n')
                return True
        self.log('Expected load is not running\n')
        return False

    def run(self):

        super(loadInstall,self).preRun()

        bpLoad = self.arg1[0]
        trxmLoad = self.arg1[1]
        bpSre  = self.arg1[2]
        trxmSre=self.arg1[3]
        trxm_res = [False,False]
        needinstall = False
        result1=''
        result2=''
        result3=''
        
        TestFrame.bpStatus = True
        TestFrame.trxmStatus = [False,False]        
        if not self.checkConnectionStatus(0):
            self.setFaultInfo('Fail to connect to target card\n')
            TestFrame.bpStatus = False
            return False
        
        if TestFrame.targetType == 'BP':
            for i in range(TestFrame.trxmPos+1):
                if (TestFrame.trxmPos < 2)==(TestFrame.trxmPos==i):
                    if not self.checkConnectionStatus(i+1):
                        TestFrame.trxmStatus[i] = False
                    else:
                        TestFrame.trxmStatus[i] = True
            if TestFrame.trxmStatus == [False,False]:
                self.setFaultInfo('RRU status is not available')
                return False
        
        output = self.RunCommand('lmclist')
        regex = '.*(0|1)\s+([a-zA-Z]*)\s+(\d*)\s+(Yes|No)\s+(\d*\\.\s?\S*)\s+(\S*)\s+(\S*)'
        for index,line in enumerate(output):
            if index ==1:
                result = re.match(regex,line)
                result1 = None
                if not result == None:
                    result1 = result.group(2)
                    self.log('Check BP working slot \n')
                
        output = self.RunCommand('trxm 0 lmclist')
        regex = '.*(0|1)\s+([a-zA-Z]*)\s+(\d*)\s+(Yes|No)\s+(\d*\\.\s?\S*)\s+(\S*)\s+(\S*)'
        for index,line in enumerate(output):
            if index == 1:
                result = re.match(regex,line)
                result2 = None
                if not result == None:
                    result2 = result.group(2)
                    self.log('Check TRXM0 working slot \n')
        
##        output = self.RunCommand('trxm 1 lmclist')
##        regex = '.*(0|1)\s+([a-zA-Z]*)\s+(\d*)\s+(Yes|No)\s+(\d*\\.\s?\S*)\s+(\S*)\s+(\S*)'
##        for index,line in enumerate(output):
##            if index == 1:
##                result = re.match(regex,line)
##                result3 = None
##                if not result == None:
##                    result3 = result.group(2)
##                    self.log('Check TRXM1 working slot \n')
        if (result1 == 'working') and (result2 == 'working') :
            self.log('BP TRXM0 working in slot0 \n')
            pass
        else:
##            for i in range(2):
##                self.reboot(i+1,0)                                 
            self.log('BP TRXM0 TRXM1 working in slot1,wait for reboot to slot 0 \n')
            self.reboot(0,0)
            time.sleep(180)


        TestFrame.bpStatus = True
        TestFrame.trxmStatus = [False,False]        
        if not self.checkConnectionStatus(0):
            self.setFaultInfo('Fail to connect to target card\n')
            TestFrame.bpStatus = False
            return False
        
        if TestFrame.targetType == 'BP':
            for i in range(TestFrame.trxmPos+1):
                if (TestFrame.trxmPos < 2)==(TestFrame.trxmPos==i):
                    if not self.checkConnectionStatus(i+1):
                        TestFrame.trxmStatus[i] = False
                    else:
                        TestFrame.trxmStatus[i] = True
            if TestFrame.trxmStatus == [False,False]:
                self.setFaultInfo('RRU status is not available')
                return False


        if TestFrame.targetType == 'BP':
            TestFrame.bpStatus = False


##             Dont install if version same
            if self.checkBurnResult(0,1,bpLoad):
                TestFrame.trxmStatus = [True,True]
                for i in range(TestFrame.trxmPos+1):
                    if ((TestFrame.trxmPos < 2)==(TestFrame.trxmPos==i)) and not self.checkBurnResult(i+1,1,trxmLoad):
                        needinstall = True
                        TestFrame.trxmStatus[i] = False
                if needinstall == False:
                    TestFrame.bpStatus = True
                    self.log('BP TRXM already install, dont need do again!reboot now \n')
                    self.reboot(0,1)
                    time.sleep(420)
                    return True
            self.log('BP TRXM need install,start now \n')
            TestFrame.trxmStatus = [False,False]
            resultbp1 = False
            while resultbp1 == False:
                resultbp1 = self.burnLoad(0,image1Pos,bpLoad)
            resultbp2 = False
            while resultbp2 == False:
                resultbp2 = self.burnSre(0,Radio_App1,bpSre)
            for i in range(TestFrame.trxmPos+1):
                time.sleep(30)
                if (TestFrame.trxmPos < 2)==(TestFrame.trxmPos==i):
                    if not self.checkConnectionStatus(i+1):                
                        self.setFaultInfo('ILink for TRXM%d is not OK\n' % i)
                        trxm_res[i] = False
                    else:
                        resulttrxm1 = False
                        while resulttrxm1 == False:
                            resulttrxm1 = self.burnLoad(i+1,image1Pos,trxmLoad)
                        resulttrxm2 = False
                        while resulttrxm2 == False:
                            resulttrxm2 = self.burnSre(i+1,Radio_App1,trxmSre)
                        trxm_res[i] = True

            
##                for i in range(2):
##                    if trxm_res[i]==True:
##                        self.reboot(i+1,1)                                 
##                    else:
##                        self.reboot(i+1,0)                                 
                self.reboot(0,1)
                time.sleep(420)
                    
            
##                if not self.checkConnectionStatus(0):
##                    self.setFaultInfo('Fail to re-connect to BP after reboot\n')
##                    return False

##                if not self.checkRunningStatus(0,1):
##                    self.setFaultInfo('Fail to reboot BP from region 1\n')
##                    return False
                
                TestFrame.bpStatus = True

                if trxm_res == [False,False]:
                    self.setFaultInfo('All configured TRXMs burn load fail\n')
                    return False

                for i in range(TestFrame.trxmPos+1):
                    if (TestFrame.trxmPos < 2)==(TestFrame.trxmPos==i) and (trxm_res[i]==True): 
##                        if not self.checkConnectionStatus(i+1):
##                            self.setFaultInfo('ILink for TRXM%d is not OK after reboot\n' % i)
##                            trxm_res[i] = False
##                        elif not self.checkRunningStatus(i+1,1):
##                            self.setFaultInfo('Fail to reboot TRXM%d from region 1\n' % i)
##                            trxm_res[i] = False
##                        else:
                        TestFrame.trxmStatus[i] = True
                            
                if ( TestFrame.trxmPos == 2 and not trxm_res == [True,True]) or (TestFrame.trxmPos <2 and trxm_res[TestFrame.trxmPos] == False):
                    self.setFaultInfo('Fail to burn load and reboot all configured TRXMs to/from region 1\n')
                    return False
                return True          
            else:
##                self.reboot(1,0)
##                self.reboot(2,0)
                self.reboot(0,0)
                self.setFaultInfo('Fail to burn BP Load to flash')
                return False
                
        elif TestFrame.targetType == 'TRXM':
            TestFrame.bpStatus = False
            if self.burnLoad(0,image1Pos,trxmLoad) and self.checkBurnResult(0,1,trxmLoad):
                self.reboot(0,1)
                if not self.checkConnectionStatus(0):
                    self.setFaultInfo('Fail to re-connect to TRXM after reboot\n')
                    return False
                if not self.checkRunningStatus(0,1):
                    self.setFaultInfo('Fail to reboot TRXM to region 1')
                    return False
                else:
                    TestFrame.bpStatus = True
                    return True
            else:
                self.reboot(0,0)
                self.setFaultInfo('Fail to burn TRXM Load to flash')
                return False

class Reboot(TestCase):
    'Reboot'

    def RunCommand(self,cmd):
        conn = socket.socket()
        try:
            output = []
            conn.settimeout(1)
            conn.connect((TestFrame.address,TestFrame.port))
            conn.send('\n')
            conn.recv(2048)
            conn.send('%s\n' % cmd)
            self.log('$ %s\n' % cmd)
            conn.settimeout(1)
            while True:
                reply = conn.recv(1024)
                output += reply.split('\n')
        except Exception as e:
            print (e)
        finally:
            conn.close()
            result = []
            for line in output:
                if not line=='$':
                    self.log(line+'\n')
                    result.append(line)
            if not len(result):
                result += ['No response from board']
            return result


    def reboot(self,operateType,targetTrxm,flashRegion):
        self.log('reboot(%s,%d,%d)\n' % (operateType,targetTrxm, flashRegion))
        if operateType == DIRECT:
            self.RunCommand('reboot %d'% flashRegion)
        else:
            self.RunCommand('trxm %d reboot %d' % (targetTrxm,flashRegion))


    def configTestStep(self):
        self.setKeyCase()
        self.setTargetType('TRXM')

    def run(self):
        if TestFrame.targetType == 'BP':
            self.reboot(INDIRECT,0,0)
            self.reboot(INDIRECT,1,0)
        self.reboot(DIRECT,0,0)
        time.sleep(120)
        return True
            
if __name__ == '__main__':
        
        l = loadInstall('a','b','c','d')
        target = 0
        loadRegion = 1
        #binFile = 'H:\nrv2\dailyBuild\NRV2_P1A78\CXP9035535%2_P1A78.bin'
        binFile = 'H:\nrv2\dailyBuild\NRV2_P1A78\CXP9034975%2_P1A78.bin'
        print('checkBurnResult(%d,%d,%s)\n' %(target,loadRegion,binFile))
        fileType=os.path.splitext(binFile)[1]
        filetmp='.bin'
        if fileType == filetmp:
            if target == 0:
                output = l.RunCommand('lmclist')
            else:
                print '1'                                                                   #output--slot state,curr,proddate,Type,SwPid
                output = l.RunCommand('trxm %d lmclist' % (target-1))
            regionInfo = []
            regex = '.*(0|1)\s+([a-zA-Z]*)\s+(\d*)\s+(Yes|No)\s+(\d*\\.\s?\S*)\s+(\S*)\s+(\S*)'
            print output
            for index,line in enumerate(output):
                if index >0:
                    result = re.match(regex,line)
                    if result==None:
                        pass
                    else:
                        regionInfo.append({'region':int(result.group(1)),
                                           'state':result.group(2),
                                           'size':result.group(3),
                                            'cuur':result.group(4),
                                            'prodDate':result.group(5),
                                            'type':result.group(6),
                                            'swPid':result.group(7)})
            for regionItem in regionInfo:
                if regionItem['region']==loadRegion and regionItem['swPid'].replace('%','_') in binFile.replace('%','_'):
                    print('Expected load is not in region %d\n'%loadRegion)
