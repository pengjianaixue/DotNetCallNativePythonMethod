#!/usr/bin/python
# -*- coding: cp936 -*-
import os
import time
import socket
import sys


#address = '192.168.1.10'
address = '10.166.149.47'
port = 32002
targetType = 'BP'
trxmPos = 0
usedInServer = False
#usedInServer = True
debug = False
#trxmStatus = [True,False]
trxmStatus = [True,True]
bpStatus = True
#useInCi = False
useInCi = True
timeDay= ''
nrv2Url = "http://cdkongfupanda.cdlab.cn.ao.ericsson.se:8000/"
        
class TestStep(object):
    'Unamed Step'
    def __init__(self,*arg1,**arg2):
                self.__name = self.__doc__
                self.arg1 = arg1
                self.arg2 = arg2
                self.cmdPre = ''

    def stepName(self):
            return self.__name

    def setLogFile(self,logFile):
            self.__logFile = logFile

    def log(self,content):
            if not content[-1] == '\n':
                    content += '\n'
            try:
                    fd = open(self.__logFile,'a')
                    fd.write(content)
            except:
                    print ('File access failure')
            finally:
                    fd.close()

    def run(self):
            return False

    def setPre(self,pre):
            self.cmdPre = pre

    def execCommand(self,cmd_,timeout=10):
            cmd = self.cmdPre+cmd_
            self.log('$%s\n' % cmd);
            result = None
            try:
                    conn = socket.socket()
                    conn.settimeout(10)
                    conn.connect((address,port))
                    conn.settimeout(timeout)
##                    conn.send('\n')
                    conn.recv(1024)
                    conn.send('%s\n' % cmd)
                    reply = conn.recv(1024)
                    result = reply.split('\n')
                    print result
            except Exception as e:
                    self.log('Socket Error: %s'%e)
            finally:
                    conn.close()
                    reVal = []
                    if result == None:
                            reVal.append('No Response')
                            return reVal
                    for line in result:
                            if not line=='$' and not line=='\n' and not line=='\r':
                                    self.log(line)
                                    reVal.append(line)
                    return reVal
                                
                
    def execCommand1(self,cmd_,timeout=120):
            cmd = self.cmdPre+cmd_
            self.log('$%s\n' % cmd);
            result = None
            try:
                    conn = socket.socket()
                    conn.settimeout(120)
                    conn.connect((address,port))
                    conn.settimeout(timeout)
##                    conn.send('\n')
                    conn.recv(1024)
                    conn.send('%s\n' % cmd)
                    time.sleep(10)
                    reply = conn.recv(1024)
#                    time.sleep(10)
#                    reply += conn.recv(1024)
                    result = reply.split('\n')
            except Exception as e:
                    self.log('Socket Error: %s'%e)
            finally:
                    conn.close()
                    reVal = []
                    if result == None:
                            reVal.append('No Response')
                            return reVal
                    for line in result:
                            if not line=='$' and not line=='\n' and not line=='\r':
                                    self.log(line)
                                    reVal.append(line)
                    return reVal

    def execCommand2(self,cmd_,timeout=120):
            cmd = self.cmdPre+cmd_
            self.log('$%s\n' % cmd);
            result = None
            try:
                    conn = socket.socket()
                    conn.settimeout(120)
                    conn.connect((address,port))
                    conn.settimeout(timeout)
                    conn.send('\n')
                    conn.recv(1024)
                    conn.send('%s\n' % cmd)
                    time.sleep(10)
                    reply = conn.recv(1024)
#                    time.sleep(10)
#                    reply += conn.recv(1024)
                    result = reply.split('\n')
            except Exception as e:
                    self.log('Socket Error: %s'%e)
            finally:
                    conn.close()
                    reVal = []
                    if result == None:
                            reVal.append('No Response')
                            return reVal
                    for line in result:
                            if not line=='$' and not line=='\n' and not line=='\r':
                                    self.log(line)
                                    reVal.append(line)
                    return reVal

class TRXM(TestStep):
        'TRXM Step'

        def __init__(self,step,trxm = -1):
                self.step = step
                self.target = trxm
                if trxm == -1:
                        self.target = trxmPos

        def run(self):
                if not self.target == 2:
                        self.step.setPre('trxm %d ' % self.target)
                        return self.step.run()
                else:
                        trxmRes = [True,True]
                        for i in range(2):
                                if trxmStatus[i]:
                                        self.step.setPre('trxm %d '%i)
                                        trxmRes[i] = self.step.run()
                                
                        result = trxmRes[0] and trxmRes[1]
                        return result

        def setLogFile(self,log):
                self.step.setLogFile(log)

        def stepName(self):
                return self.step.stepName()
                
class TestCase(object):
        'Unamed Case'
        def __init__(self,*arg1,**arg2):
                self.__name = self.__doc__
                self.__stepList = []
                self.__logName = ''
                self.__logPath = './'
                self.arg1 = arg1
                self.arg2 = arg2
                self.__block = False
                self.__seq = 0
                self.__faultInfo = ''
                self.__targetType = 'BP'
                self.__keyCase = False

        def addTestStep(self,testStep):
                self.__stepList.append(testStep)

        def setLogPath(self,path,seq=0):
                self.__logPath = path
                self.__seq = seq
                self.__logName = 'Case_%d.%s' % (self.__seq,self.__name)

        def getLogPath(self):
                return self.__logPath

        def setTargetType(self,target):
                self.__targetType = target

        def setKeyCase(self):
                self.__keyCase = True

        def configTestStep(self):
                pass

        def enableBlock(self):
                self.__block = True

        def isKeyCase(self):
                return self.__keyCase

        def skip(self):
                skip = False
                if self.__targetType == 'BP' and targetType == 'TRXM':
                        skip = True
                        self.setFaultInfo('Expected to run on %s but running target is %s'%(self.__targetType,targetType))
                else:
                        if bpStatus == False:
                                skip = True
                                self.setFaultInfo('BP is not avaiable, skip this TRXM case')
                        elif trxmStatus == [False,False]:
                                skip = True
                                self.setFaultInfo('Both TRXMs are not available, skip this case')
                return skip

        def preRun(self):
                self.__log = open('%s/%s'%(self.__logPath,self.__logName),'w')
                self.__log.close()

        def log(self,content):
                if not content[-1] == '\n':
                        content += '\n'
                self.__log = open('%s/%s'%(self.__logPath,self.__logName),'a')
                self.__log.write(content)
                sys.stdout.flush()
                self.__log.close()
                
        def getLogName(self):
                return self.__logName

        def getFaultInfo(self):
                return self.__faultInfo.replace('\n','<br>')

        def setFaultInfo(self,fault):
                if not fault[-1] == '\n':
                        fault += '\n'
                self.__faultInfo += fault

        def run(self):
                caseResult = True
                self.preRun()
               
                for index,stepItem in enumerate(self.__stepList):
                        stepAct = []
                        if self.__targetType == targetType:
                                stepAct.append(stepItem)
                        elif trxmPos == 2:
                                for i in range(2):
                                        if trxmStatus[i]:
                                                stepAct.append(TRXM(stepItem,i))
                        else:
                                stepAct.append(TRXM(stepItem,trxmPos))
                        
                        for stepActItem in stepAct:
                                stepActItem.setLogFile('%s/%s'%(self.__logPath,self.__logName))
                                
                        self.log("[Step %d] %s\n" % (index+1,stepItem.stepName()))
                        stepResult = True
                        for stepActItem in stepAct:
                                try:
                                        stepResult  =  stepActItem.run() and stepResult
                                except:
                                        stepResult = False
                                finally:
                                        pass
                        
                        if not stepResult:
                                if caseResult:
                                        self.__faultInfo = 'Fault at step %d' % (index+1)
                                        caseResult = False
                                else:
                                        self.__faultInfo +=',%d' % (index+1)
                                if self.__block:
                                        break
                return caseResult   

class TestSuit(object):
        def __init__(self,name="Unamed Test Suit"):
                self.__name = name
                self.__tcList = []

        def addTestCase(self,testCase):
                self.__tcList.append(testCase)

        def run(self):
                self.__totalTcCount = len(self.__tcList)
                self.__passTc = []
                self.__failTc = []
                self.__skipTc = []
#                usedInServer=True


                if usedInServer:
                        logPath = '/opt/log/nrv2/' + address + "/" + timeDay + "/" + self.__name
                elif useInCi :
                        logPath = 'C:/NRV2_TEST/' + address + "/" + timeDay + "/" + self.__name
                else:
                        logPath = './temp/'+ "/" + timeDay +"/" + self.__name
                logPath = logPath.replace("%","_")
                print logPath
                try:
                        os.makedirs(logPath)
                except:
                        pass

                keyFail = False
                for index,case in enumerate(self.__tcList):
                        case.setLogPath(logPath,index+1)
                        case.configTestStep()
                        print ('Processing case %d ...' % (index+1))
                        sys.stdout.flush()
                        if case.skip():
                                print ('Case %d skip' % (index+1))
                                sys.stdout.flush()
                                self.__skipTc.append((index+1,case))
                        else:
                                if case.run():
                                        print ('Case %d pass' % (index+1))
                                        sys.stdout.flush()
                                        self.__passTc.append((index+1,case))
                                else:
                                        if case.isKeyCase():
                                                keyFail = True
                                        print ('Case %d fail' % (index+1))
                                        sys.stdout.flush()
                                        self.__failTc.append((index+1,case))
                self.generateHTMLReport(logPath)

        def generateHTMLReport(self,path):
                result = 'Pass'
                if self.__totalTcCount == len(self.__passTc):
                        result = 'Pass'
                else:
                        result = 'Fail'
                        
                content = """<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<HTML>
<HEAD>
</HEAD>
<BODY>
<h2>Test Job: %s</h2>
<h4>Test Result: %s</h4>
<table>
<tr><td>Total:&nbsp;</td><td>%d</td></tr>
<tr><td>Pass: &nbsp;</td><td>%d</td></tr>
<tr><td>Fail: &nbsp;</td><td>%d</td></tr>
<tr><td>Skip: &nbsp;</td><td>%d</td></tr>"""% (self.__name,result,self.__totalTcCount,len(self.__passTc),len(self.__failTc),len(self.__skipTc))

# add pass test cases info
                content += """
<tr>
        <td>&nbsp;&nbsp;</td>
</tr>
<tr>
        <td>Pass test cases are below:</td>
</tr>
<tr>
        <td>Test Case</td><td>&nbsp;</td><td>Log File</td>
</tr>"""
                
                for item in self.__passTc:
                        if usedInServer:
                                htmlLogFullName = item[1].getLogPath().replace('/opt/log/NRV2_LOG',nrv2Url)+ '/'+ item[1].getLogName()
                        elif useInCi:
                                htmlLogFullName = item[1].getLogPath().replace('C:/NRV2_TEST/',nrv2Url) +  '/' + item[1].getLogName()
                        else:
                                htmlLogFullName = './'+ item[1].getLogName()
                        content += """
<tr>
        <td>TC%d.%s</td><td>&nbsp;</td><td><a href='%s'>%s</a></td>
</tr>""" %(item[0],item[1].__doc__,htmlLogFullName,item[1].getLogName())

# add fail test cases info
                content += """
<tr>
        <td>&nbsp;&nbsp;</td>  
</tr>
<tr>
        <td>Fail test cases are below:</td>
</tr>
<tr>
        <td>Test Case</td><td>&nbsp;</td><td>Log File</td><td>&nbsp;</td><td>Fault Reason</td>
</tr>"""
                
                for item in self.__failTc:
                        if usedInServer:
                                htmlLogFullName = item[1].getLogPath().replace('/opt/log/NRV2_LOG',nrv2Url)+ '/'+ item[1].getLogName()
                        elif useInCi:
                                htmlLogFullName = item[1].getLogPath().replace('C:/NRV2_TEST/',nrv2Url) + '/' + item[1].getLogName()
                        else:
                                htmlLogFullName = './'+ item[1].getLogName()
                        content += """
<tr>
        <td>TC%d.%s</td><td>&nbsp;</td><td><a href='%s'>%s</a></td><td>&nbsp;</td><td>%s</td>
</tr>""" %(item[0],item[1].__doc__,htmlLogFullName,item[1].getLogName(),item[1].getFaultInfo())


# add skip test cases info
                content += """
<tr>
        <td>&nbsp;&nbsp;</td>
</tr>
<tr>
        <td>Skip test cases are below:</td>
</tr>
<tr>
        <td>Test Case</td><td>&nbsp;</td><td>Skip Reason</td>
</tr>"""
                
                for item in self.__skipTc:
                        content += """
<tr>
        <td>TC%d.%s</td><td>&nbsp;</td><td>%s</td>
</tr>""" %(item[0],item[1].__doc__,item[1].getFaultInfo())

                content += """
<tr>
        <td>&nbsp;&nbsp;</td>
</tr>
<tr>
        <td>Analyze Dl EVM:</td><td>&nbsp;</td><td>Graphics:</td><td>
</tr>"""
                content +="""
<tr>
        <td>DL EVM constellation:</td><td>&nbsp;</td><td><a href=DL_evm_constellation.jpg>DL evm constellation </a></td>
</tr>"""
                content += """

<tr>
         <td>DL Amp_f(dB):</td><td>&nbsp;</td><td><a href=DL_Amp_f(dB).jpg>DL mp f(dB)</a></td>
 </tr>"""
                content += """
<tr>
         <td>DL Phase_f error(rad):</td><td>&nbsp;</td><td><a href=DL_Phase_f_error(rad).jpg>DL Phase f error(rad)</a></td>
</tr>"""
                content += """
<tr>
         <td>DL Phase_t error:</td><td>&nbsp;</td><td><a href=DL_Phase_t_error.jpg>DL Phase t error</a></td>
 </tr>"""
                content += """
<tr>
         <td>DL pos:</td><td>&nbsp;</td><td><a href=DL_pos.jpg>DL pos</a></td>
 </tr>"""
                content += """
<tr>
        <td>&nbsp;&nbsp;</td>
</tr>
<tr>
        <td>Analyze Ul EVM:</td><td>&nbsp;</td><td>Graphics:</td><td>
</tr>"""
                content += """
<tr>
        <td>UL l of first symbol is:</td><td>&nbsp;</td><td><a href=l of first symbol is.jpg>l of first symbol is</a></td>
</tr>"""
                content += """
<tr>
        <td>UL evm:</td><td>&nbsp;</td><td><a href=UL_evm.jpg>UL evm</a></td>
</tr>"""

                content += """</table></BODY></HTML></td>"""
                
                file = open('%s/Summary.html' % path,'w')
                file.write(content)
                file.close()
                realPath = os.path.realpath('%s/Summary.html' % path)
                print ('Test_Result: ' + result)
                if usedInServer:
                        realPath = realPath.replace('/opt/jcat-log/','http://cdjcat18.cdlab.cn.ao.ericsson.se:9999/')
                elif useInCi :
                        realPath = realPath.replace('H:\\nrv2\\log\\','http://cdjcat28.cdlab.cn.ao.ericsson.se:9999/nrv2/log/').replace("\\","/")

                       # pop= open(os.getenv("workspace") +)
                print ('Test Summary: '+ realPath)

#<LINK REL=stylesheet HREF=log.css TYPE="text/css">

