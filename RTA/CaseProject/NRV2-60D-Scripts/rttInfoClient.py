import rtpclient
import serviceConfig
rtp = rtpclient.client()
SOCKETUDP=serviceConfig.SOCKETUDP
if SOCKETUDP:
    udp=SOCKETUDP.split(":")
    if len(udp)==2:        
        rtp.address(udp[0], int(udp[1])) 
    else:
        rtp.address("127.0.0.1", 8001) 

class Serial:
    def Run(self,commands,delay=0):
        return rtp.cmd(commands,delay)
    def switchSerial(self,commands,delay=0):
        return rtp.cmd('RRU.SwitchSerial#'+commands,delay) 
    def Send(self,commands,delay=0):
        return rtp.cmd('RRU.Send('+commands+')',delay) 
    def SendString(self,commands,Prompt,timeout,delay=0):
        vStr = 'RRU.SendString('+commands+','+Prompt+','+ str(timeout)+')'
        return rtp.cmd(vStr,delay) 
    def ChangePrompt(self,Prompt,delay=0):
        return rtp.cmd('SerialChangePrompt('+Prompt+')',delay) 
class Visa:
    def Run(self,commands,delay=0,filename = ""):
        return rtp.cmd(commands,delay,filename)
    def Capture1(self,filepath,delay=5000):
        return rtp.cmd('Capture1',delay,filename)
    def Capture2(self,filepath,delay=5000):
        return rtp.cmd('Capture2',delay,filename)
class Ruma:
    def Run(self,commands,delay=0):
        return rtp.cmd(commands,delay)
class Rtt:
    def getLogPath(self):
        return rtp.cmd('RttRun.GetDataPathInfo#PRELOGPATH',1)
    def getPicturePath(self):
        return rtp.cmd('RttRun.GetDataPathInfo#PREPICTUREPATH',1)
    def getReportPath(self):
        return rtp.cmd('RttRun.GetDataPathInfo#PREREPORTPATH',1)
    def getConsoleLogName(self):
        return rtp.cmd('RttRun.GetDataPathInfo#ConsoleLogFile',1)   
    def setDataPath(self,reportPath,curReportName='Report',allReportName='AllReport',consoleLogFileName='Console.Log'):
        return rtp.cmd('RttRun.RunInit#reportPath#curReportName#allReportName#consoleLogFileName',1)   
         
    def resultExport(self,testlink='None',testname='None',condition='None',target='None',testvalue='None',unit='None',result='None',remarks=' '):
        testlink=testlink.replace(',','|')
        testname=testname.replace(',','|')
        condition=condition.replace(',','|')
        target=target.replace(',','|')
        testvalue=testvalue.replace(',','|')
        unit=unit.replace(',','|')
        result=result.replace(',','|')
        remarks=remarks.replace(',','|')    
        #writeFile.writeResult(testlink+','+testname+','+condition+','+target+','+testvalue+','+unit+','+result+','+remarks,writeFile.RESULTFILE)
        rtp.cmd('Report.AddAllData#'+testlink+','+testname+','+condition+','+target+','+testvalue+','+unit+','+result+','+remarks)   
    def valueExport(self,sheetName,paraValueList,split): 
        #writeFile.writeResult(paraValueList,writeFile.LOGPATH+r'/'+sheetName+'.txt')
        rtp.cmd('Report.AddValueData#'+sheetName+'#'+paraValueList+'#'+split) 
    def MsgBox(self,Prompt, Stytle="YesNo", Title=""):
        return rtp.cmd("Rtt.MsgBox#%s#%s#%s"%(Prompt,Stytle,Title),1)        
    def InputBox(self,Prompt, Title="Note", DefaultValue="", Xpos=-1, Ypos=-1):
        return rtp.cmd("Rtt.InputBox#%s#%s#%s#%i#%i"%(Prompt,Title,DefaultValue,Xpos,Ypos,),1)        
    def ScreenCapture(self,filePath=""):
        return rtp.cmd("Rtt.ScreenCapture#%s"%(filePath))
    def MsgWriteLine(self,msg=""):
        rtp.cmd("Rtt.MsgWrite#"+msg)
    def MsgWriteLineWithLevel(self,msg,level):
        '''level:msg level。T|E|W|C|D|""
            { "T",LogFile.Trace },
            { "",LogFile.Log},
            { "E",LogFile.Error },
            { "W",LogFile.Warning },
            { "C",LogFile.Command },
            { "D",LogFile.Debug}
        '''
        rtp.cmd("Rtt.MsgWrite#"+msg+"#"+level)