import os
import rttInfoClient
#import Te_CommonInput
import platform
#RUNSYSTEM=Te_CommonInput.InputPara_DIC['RUNSYSTEM']

RUNSYSTEM="RTT"
systemMsg=RUNSYSTEM
if RUNSYSTEM=='AUTO':  
    systemMsg=platform.system()      
    if 'CYGWIN' in systemMsg:
        RUNSYSTEM="Cygwin"
    elif 'Linux' in systemMsg:
        RUNSYSTEM="Linux"
    elif 'cli' in systemMsg:
        RUNSYSTEM="RTT"
    else:
        RUNSYSTEM="Windows"

WCFSERVICEEN=False
#if (Te_CommonInput.InputPara_DIC['WCFSERVICEEN']=="True") and ('RTT' in systemMsg):
#    WCFSERVICEEN=True

PASS='PASS'
FAIL='FAIL'

  
rtp=rttInfoClient.rtp
if WCFSERVICEEN:
    import clr   
    clr.AddReference('System.ServiceModel') 
    clr.AddReference('RttInfo')

    from System import  *
    import System.ServiceModel
    import serviceConfig

    from RttInfo.RttInfoService import IRttInfoService
    from RttInfo.ViSaService import IViSaService
    from RttInfo.SerialService import ISerialService
    from RttInfo.RumaService import IRumaService
    WCFSERVICE=serviceConfig.WCFSERVICE
    if len(WCFSERVICE.split(":"))!=2:
        WCFSERVICE="127.0.0.1:8733"
    rttInfoService = System.ServiceModel.ChannelFactory[IRttInfoService](
    System.ServiceModel.BasicHttpBinding(),
    System.ServiceModel.EndpointAddress("http://"+WCFSERVICE+"/RttInfoService/"))
    Rtt = rttInfoService.CreateChannel()  

    VisaService = System.ServiceModel.ChannelFactory[IViSaService](
    System.ServiceModel.BasicHttpBinding(),
    System.ServiceModel.EndpointAddress("http://"+WCFSERVICE+"/ViSaService/"))
    Visa = VisaService.CreateChannel()

    SerialService = System.ServiceModel.ChannelFactory[ISerialService](
    System.ServiceModel.BasicHttpBinding(),
    System.ServiceModel.EndpointAddress("http://"+WCFSERVICE+"/SerialService/"))
    Serial = SerialService.CreateChannel()

    RumaService = System.ServiceModel.ChannelFactory[IRumaService](
    System.ServiceModel.BasicHttpBinding(),
    System.ServiceModel.EndpointAddress("http://"+WCFSERVICE+"/RumaService/"))
    Ruma = RumaService.CreateChannel()
else:
    Rtt=rttInfoClient.Rtt()
    Visa =rttInfoClient.Visa()
    Serial=rttInfoClient.Serial()
    Ruma=rttInfoClient.Ruma()


visalist=["SA.Command","SG.Command","RF-Box.","ISG1.Command","DC5767A.","SG2.Command","RF-Box2.","ISG2.Command"];
def cmd(sendcmd,delay=0,filename=""):
    return rtp.cmd(sendcmd,delay,filename)    
def testValueInit(testlink,testname,unit='None',target='None',testvalue='',condition='None',result='FAIL',remarks='',step=0):   
    return testlink,testname,unit,target,testvalue,condition,result,remarks,step
def resultExport(testlink='None',testname='None',condition='None',target='None',testvalue='None',unit='None',result='None',remarks=' '):
    Rtt.resultExport(testlink,testname,condition,target,testvalue,unit,result,remarks)
  
def valueDataExport(sheetName,paraValueList,split):
    Rtt.valueExport(sheetName, paraValueList,split)   
    
def MsgBox(Prompt, Stytle="YesNo", Title=""):
    msg=rtp.cmd("Rtt.MsgBox#%s#%s#%s"%(Prompt,Stytle,Title),1)
    #msg=Rtt.MsgBox("MsgBox Test","YesNoCancel","MSGBOX")
    return msg
def InputBox(Prompt, Title="Note", DefaultValue="", Xpos=-1, Ypos=-1):
    input=rtp.cmd("Rtt.InputBox#%s#%s#%s#%i#%i"%(Prompt,Title,DefaultValue,Xpos,Ypos,),1)
    #input=Rtt.InputBox("InputBox Input Test","InputBox","Default",100,100)
    return input
    
