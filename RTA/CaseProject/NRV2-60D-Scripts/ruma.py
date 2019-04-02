import rttInfo
import os,time,re
import traceback,datetime
import math
g_vsaDevHdlDic = {}

def __getVSAIDStr(DevID):
    if int(DevID)==1:
        VSADevIDStr = 'Rumaster.'
    else:
        VSADevIDStr = 'Rumaster.'
    return VSADevIDStr

def __getModelName():
    RuMasterName = 'CT10'
    return RuMasterName

def __getVSAInstanse(DevID,CpriPort='1A'):
    global g_vsaDevHdlDic
    vKeyword = str(DevID)+'_'+str(CpriPort)
    if not g_vsaDevHdlDic.has_key(vKeyword):
        vsaInstance = __createVSAInstance(DevID,CpriPort)
        g_vsaDevHdlDic[vKeyword] = vsaInstance
    return g_vsaDevHdlDic[vKeyword]
    
def __createVSAInstance(DevID,CpriPort):
    try:
        vDevModle = __getModelName()
        module_meta = __import__(vDevModle.upper()+str('Lib'))
        class_meta = getattr(module_meta, vDevModle) 
        deviceAdress = __getVSAIDStr(DevID)
        return class_meta(deviceAdress,CpriPort)
    except Exception,e: 
        quit()
        
def getCPRIVersion(DevID,CpriPort):
    '''
            @date:    2017-8-21
            @function:   Get Rumaster Cpri version.
            @param DevID:  device ID |1|2|3|4|.....|N|
            @type DevID: int
            @param CpriPort:  How much Rumaster CpriPort number which you use it |1A|1B|2A|2B|3A|3B|........
            @type CpriPort: string
            @rtp CpriVersion: Cpri port version
            @rtt CpriVersion: str|1|2|3|.....
    '''
    vVSAInstanse = __getVSAInstanse(DevID,CpriPort)
    return vVSAInstanse.getCPRIVersion()

def setRxCaptureToFile(DevID,CpriPort,FileMode,Filename):
    '''
    @date:    2017-8-21
    @function:   Get Rumaster Cpri version.
    @param DevID:  device ID |1|2|3|4|.....|N|
    @type DevID: int
    @param CpriPort:  How much Rumaster CpriPort number which you use it |1A|1B|2A|2B|3A|3B|........
    @type CpriPort: string
    @param FileMode: Capture File Mode ;|cru|cul|ccu|cul2|cul3|
    @type FileMode: str
    @param Filename: Capture File Name
    @type Filename: str
    @rtp none
    @rtt none
    '''
    vVSAInstanse = __getVSAInstanse(DevID,CpriPort)
    vVSAInstanse.setRxCaptureToFile(FileMode,Filename)

def setFlowDataMode(DevID,CpriPort,FlwDir,FileType,flowdatamode):
    '''
    @date:    2017-7-21
    @function:   Set Rumaster Flow Data Mode.
    @param DevID:  device ID |1|2|3|4|.....|N|
    @type DevID: int
    @param CpriPort:  How much Rumaster CpriPort number which you use it
    @type CpriPort: int
    @param FlwDir:  TX or RX carrier ; |TX|RX|
    @type FlwDir: str 
    @param FileType: which file type need to set HF BF ; |IQ|AXC|
    @type FileType: str
    @param flowdatamode: set CT10 flow data mode ; |Carrier|RAW|
    @type flowdatamode: str             
    '''
    vVSAInstanse = __getVSAInstanse(DevID,CpriPort)
    vVSAInstanse.setFlowDataMode(FlwDir,FileType,flowdatamode)

def setFrameFlowCondition(DevID,CpriPort,FileType,FlwDir,StartCondition,StartPara='0|0|0|0',StopCondition='NEVER',StopPara='0|0|0|0'):
    '''
    @date:    2017-7-24
    @function:   set Start and Stop Flow Condition TYPE and condition value
    @param DevID:  device ID |1|2|3|4|.....|N|
    @type DevID: int
    @param CpriPort:  How much Rumaster CpriPort number which you use it |1A|1B|2A|2B|3A|3B|........
    @type CpriPort: string
    @param FileType: which file type need to set HF BF ; |IQ|AXC|
    @type FileType: str
    @param FlwDir:  TX or RX carrier ; |TX|RX|
    @type FlwDir: str  
    @param StartCondition:  Start condition ; |NONE|TRIG_IN|CPRI_TIME|FIRST_NON_IDLE|FSINFO|FRAME_PRE_START|RADIO_FRAME|
    @type StartCondition: str 
    @param StartPara: set CT10  Rumaster Flow Start Condition parameter; FRAME_PRE_START: HF|BF   ;  CPRI_TIME: BFN OFFSET|BFN|HF|BF 
    @type StartPara: str
    @param StopCondition: set CT10  Rumaster Flow Stop Condition ; |NEVER|FLOW_STOP_COND_CPRI_TIME|FLOW_STOP_COND_TRIG_IN|CPRI_TIME_LENGTH|
    @type StopCondition: str
    @param StopPara: set CT10  Rumaster Flow Stop Condition parameter; CPRI_TIME_LENGTH: 	BFN|HF|BF
    @type StopPara: str
    @rtp none
    @rtt none
    '''
    vVSAInstanse = __getVSAInstanse(DevID,CpriPort)
    vVSAInstanse.setFrameFlowCondition(FileType,FlwDir,StartCondition,StartPara,StopCondition,StopPara)

def setCarReleAll(DevID,CpriPort,FlwDir):
    '''
    @date:    2017-7-21
    @function:   delete all carrier(TX or RX) in ct10
    @param DevID:  device ID |1|2|3|4|.....|N|
    @type DevID: int
    @param CpriPort:  How much Rumaster CpriPort number which you use it |1A|1B|2A|2B|3A|3B|........
    @type CpriPort: string
    @param FlwDir: TX or RX carrier ; |TX|RX|
    @type FlwDir: str
    @rtp none
    @rtt none
    '''
    vVSAInstanse = __getVSAInstanse(DevID,CpriPort)
    vVSAInstanse.setCarReleAll(FlwDir)

def setCarRelease(DevID,CpriPort,TcaCarID,FlwDir):
    '''
    @date:    2017-7-21
    @function:   delete one carrier(TX or RX) in ct10
    @param DevID:  device ID |1|2|3|4|.....|N|
    @type DevID: int
    @param CpriPort:  How much Rumaster CpriPort number which you use it |1A|1B|2A|2B|3A|3B|........
    @type CpriPort: string
    @param TcaCarID: TX or RX carrier ID ;|0|1|.....
    @type TcaCarID: INT
    @param FlwDir: TX or RX carrier ; |TX|RX|
    @type FlwDir: str
    @rtp none
    @rtt none
    '''
    vVSAInstanse = __getVSAInstanse(DevID,CpriPort)
    vVSAInstanse.setCarRelease(TcaCarID,FlwDir)

def setCarAdd(DevID,CpriPort,sr,IQPosition,FlwDir):
    '''
    @date:    2017-7-21
    @function:   add one carrier(TX or RX) in ct10
    @param DevID:  device ID |1|2|3|4|.....|N|
    @type DevID: int
    @param CpriPort:  How much Rumaster CpriPort number which you use it |1A|1B|2A|2B|3A|3B|........
    @type CpriPort: string
    @param sr: Carrier sample rate ;|3.84|5.76|7.68|11.52|15.36|19.20|23.04|30.72|
    @type sr: float
    @param IQPosition: Carrier start iq position ; |0|1|2|3|4|5|6|7|......
    @type IQPosition: int
    @param FlwDir: TX or RX carrier ; |TX|RX|
    @type FlwDir: str
    @rtp none
    @rtt none
    '''
    vVSAInstanse = __getVSAInstanse(DevID,CpriPort)
    return vVSAInstanse.setCarAdd(sr,IQPosition,FlwDir)

def setCarConfig(DevID,CpriPort,FlwDir,carrNr,TcaCarID,sr,IQPosition,GainSwitch,DigtalGain,FsinfoAddress,FsinfoHf,FsinfoBf,SyncMode):
    '''
    @date:    2017-7-21
    @function:   Config one carrier(TX or RX) in ct10
    @param DevID:  device ID |1|2|3|4|.....|N|
    @type DevID: int
    @param CpriPort:  How much Rumaster CpriPort number which you use it |1A|1B|2A|2B|3A|3B|........
    @type CpriPort: string
    @param FlwDir: TX or RX carrier ; |TX|RX|
    @type FlwDir: str
    @param carrNr: TX or RX carrier number ;|0|1|.....
    @type carrNr: INT
    @param TcaCarID: TX or RX carrier ID ;|0|1|.....
    @type TcaCarID: INT
    @param sr: Carrier sample rate ;|3.84|5.76|7.68|11.52|15.36|19.20|23.04|30.72|
    @type sr: float
    @param IQPosition: Carrier start iq position ; |0|1|2|3|4|5|6|7|......
    @type IQPosition: int
    @param GainSwitch: CT10 digital gain control switch ; |True|false|
    @type GainSwitch: str
    @param DigtalGain: CT10 digital gain control value ;  Scope= -60dB~+6dB
    @type DigtalGain: float
    @param FsinfoAddress: Fs info address num ;  |0|1|2......
    @type FsinfoAddress: int
    @param FsinfoHf: Fs info hyper frame num ;  scope = 0~149
    @type FsinfoHf: int
    @param FsinfoBf: Fs info basic frame num ;  scope = 0~255
    @type FsinfoBf: int
    @param SyncMode: ;  RX frame Sync mode ; FSINFO|CUSTOM|RX_TIMING
    @type SyncMode: str
    @rtp none
    @rtt none
    '''
    vVSAInstanse = __getVSAInstanse(DevID,CpriPort)
    vVSAInstanse.setCarConfig(FlwDir,carrNr,TcaCarID,sr,IQPosition,GainSwitch,DigtalGain,FsinfoAddress,FsinfoHf,FsinfoBf,SyncMode)

def setIqFileLoad(DevID,CpriPort,IQFilePath,IQFileName):
    '''
    @date:    2017-7-24
    @function:   Load IQ File
    @param DevID:  device ID |1|2|3|4|.....|N|
    @type DevID: int
    @param CpriPort:  How much Rumaster CpriPort number which you use it |1A|1B|2A|2B|3A|3B|........
    @type CpriPort: str
    @param IQFilePath: IQ File path ; eg:  C:\TestVectors\\
    @type IQFilePath: str
    @param IQFileName: IQ File name ; eg:  9.8G_30Bit_1C_20_19.20_ETM11.cdl3  
    @type IQFileName: str
    @rtp none
    @rtt none
    '''
    vVSAInstanse = __getVSAInstanse(DevID,CpriPort)
    vVSAInstanse.setIqFileLoad(IQFilePath,IQFileName)

def setAxcFileLoad(DevID,CpriPort,cpcFilePath,cpcFileName):
    '''
    @date:    2017-7-24
    @function:   Load axc file
    @param DevID:  device ID |1|2|3|4|.....|N|
    @type DevID: int
    @param CpriPort:  How much Rumaster CpriPort number which you use it |1A|1B|2A|2B|3A|3B|........
    @type CpriPort: string
    @param CPCFilePath: CPCFile path ; eg:  C:\TestVectors\\
    @type CPCFilePath: str
    @param CPCFileName: CPC File name ; eg:  38_149-197.cpc
    @type CPCFileName: str
    @rtp none
    @rtt none
    '''
    vVSAInstanse = __getVSAInstanse(DevID,CpriPort)
    vVSAInstanse.setAxcFileLoad(cpcFilePath,cpcFileName)

def setPlayBackStatus(DevID,CpriPort,Switch):
    '''
    @date:    2017-7-24
    @function:   Turn on or turn off CT10 digital power
    @param DevID:  device ID |1|2|3|4|.....|N|
    @type DevID: int
    @param CpriPort:  How much Rumaster CpriPort number which you use it |1A|1B|2A|2B|3A|3B|........
    @type CpriPort: string
    @param Switch: CT10 digital power switch ; |ON|OFF|
    @type Switch: str
    @rtp none
    @rtt none
    '''
    vVSAInstanse = __getVSAInstanse(DevID,CpriPort)
    if Switch =='ON':
        vVSAInstanse.setStartPlayBack()
    elif Switch =='OFF':
        vVSAInstanse.setStopPlayBack()
    else:
        printlog='================================='   
        printlog='Digital Power Switch Error!!!  Switch = ' + str(Switch)   
        printlog='================================='   

def setStartCapture(DevID,CpriPort,flowdatatype):
    '''
    @date:    2017-7-24
    @function:   Turn on or turn off CT10 digital power
    @param DevID:  device ID |1|2|3|4|.....|N|
    @type DevID: int
    @param CpriPort:  How much Rumaster CpriPort number which you use it |1A|1B|2A|2B|3A|3B|........
    @type CpriPort: string
    @param flowdatatype: type of flow ; |IQ|AXC|ECP|
    @type flowdatatype: str
    @rtp none
    @rtt none
    '''
    vVSAInstanse = __getVSAInstanse(DevID,CpriPort)
    vVSAInstanse.setStartCapture(flowdatatype)

def setStopCapture(DevID,CpriPort,flowdatatype):
    '''
    @date:    2017-7-24
    @function:   Turn on or turn off CT10 digital power
    @param DevID:  device ID |1|2|3|4|.....|N|
    @type DevID: int
    @param CpriPort:  How much Rumaster CpriPort number which you use it |1A|1B|2A|2B|3A|3B|........
    @type CpriPort: string
    @param flowdatatype: type of flow ; |IQ|AXC|ECP|
    @type flowdatatype: str
    @rtp none
    @rtt none
    '''
    vVSAInstanse = __getVSAInstanse(DevID,CpriPort)
    vVSAInstanse.setStopCapture(flowdatatype)

def getAllCapturedData(DevID,CpriPort,filePath,fileName,fileFormat):
    '''
    @date:    2017-7-21
    @function:   Export All the Capture Data
    @param filePath: Capture File path
    @type filePath: str
    @param fileName: Capture File Name
    @type fileName: str
    @param fileFormat: Capture File Mode ;|cru|cul|ccu|cul2|cul3|
    @type fileFormat: str
    @return :the capture status
            type:dictionary
            result_dic['exist']:boole, True | False, capture sucess:return True,capture sucess:return False
            result_dic['filename']:the capture file name                                                                                                                                
    '''
    vVSAInstanse = __getVSAInstanse(DevID,CpriPort)
    vVSAInstanse.getAllCapturedData(filePath,fileName,fileFormat)

def setFrameHFBF(DevID,CpriPort,FileType,FlwDir,HF,BF):
    '''
    @date:    2017-7-24
    @function:   generate capture data
    @param DevID:  device ID |1|2|3|4|.....|N|
    @type DevID: int
    @param CpriPort:  How much Rumaster CpriPort number which you use it |1A|1B|2A|2B|3A|3B|........
    @type CpriPort: string
    @param FileType: which file type need to set HF BF ; |IQ|AXC|
    @type FileType: str
    @param FlwDir:  TX or RX carrier ; |TX|RX|
    @type FlwDir: str  
    @param HF: Fs info hyper frame num ;  scope = 0~149
    @type HF: int
    @param BF: Fs info basic frame num ;  scope = 0~255
    @type BF: int
    @rtp none
    @rtt none
    '''
    vVSAInstanse = __getVSAInstanse(DevID,CpriPort)
    vVSAInstanse.setFrameHFBF(FileType,FlwDir,HF,BF)

def setOutputTrig(DevID,CpriPort,TrigPort,TrigSource):
    '''
    @date:    2017-7-24
    @function:   turn on output trigger
    @param DevID:  device ID |1|2|3|4|.....|N|
    @type DevID: int
    @param CpriPort:  How much Rumaster CpriPort number which you use it |1A|1B|2A|2B|3A|3B|........
    @type CpriPort: string
    @param TrigPort: which port need to output trigger ; |1|2|3|......
    @type TrigPort: int
    @param TrigSource: trigger source type ; |CPC|CTT|DYNAMIC_GAIN|FSINFO_CHANGED|RXK285|TXK285|
    @type TrigSource: str  
    @rtp none
    @rtt none
    '''
    vVSAInstanse = __getVSAInstanse(DevID,CpriPort)
    vVSAInstanse.setOutputTrig(TrigPort,TrigSource)

def setTriggerAdjustment(DevID,TrigPort,pulseoffset,pulseWidth,finePhaseAdjuse):
    '''
    @date:    2017-8-30
    @function:   adjust the trigger offset, length, and fine phase
    @param TrigPort: which port need to output trigger ; |0|1|2|3|......
    @type TrigPort: int
    @param pulseoffset: trigger offset
    @type pulseoffset: int  
    @param pulseWidth: trigger length
    @type pulseWidth: unsigned int 
    @param finePhaseAdjuse: fine phase
    @type finePhaseAdjuse: int 
    @rtp none
    @rtt none
    '''
    vVSAInstanse = __getVSAInstanse(DevID)
    vVSAInstanse.setTriggerAdjustment(TrigPort,pulseoffset,pulseWidth,finePhaseAdjuse)
    
def setCPRILineRate(DevID,CpriPort,LineRate):
    '''
    @date:    2017-7-24
    @function:   set ct10 line rate
    @param DevID:  device ID |1|2|3|4|.....|N|
    @type DevID: int
    @param CpriPort:  How much Rumaster CpriPort number which you use it |1A|1B|2A|2B|3A|3B|........
    @type CpriPort: string
    @param LineRate: Cpri port line rare ; |2.5|4.9|9.8|10.1|......
    @type LineRate: float
    @rtp none
    @rtt none
    '''
    vVSAInstanse = __getVSAInstanse(DevID,CpriPort)
    vVSAInstanse.setCPRILineRate(LineRate)

def setCPRIVersion(DevID,CpriPort,CPRI_Ver):
    '''
    @date:    2017-7-24
    @function:   set ct10 cpri version on one cpri port
    @param DevID:  device ID |1|2|3|4|.....|N|
    @type DevID: int
    @param CpriPort:  How much Rumaster CpriPort number which you use it |1A|1B|2A|2B|3A|3B|........
    @type CpriPort: string
    @param CPRI_Ver: Cpri version ; |1|2|
    @type CPRI_Ver: int
    @rtp none
    @rtt none
    '''
    vVSAInstanse = __getVSAInstanse(DevID,CpriPort)
    vVSAInstanse.setCPRIVersion(CPRI_Ver)

def setCPRIScrambSeed(DevID,CpriPort,ScrambSeed):
    '''
    @date:    2017-7-24
    @function:   set ct10 cpri ScrambSeed on one cpri port
    @param DevID:  device ID |1|2|3|4|.....|N|
    @type DevID: int
    @param CpriPort:  How much Rumaster CpriPort number which you use it |1A|1B|2A|2B|3A|3B|........
    @type CpriPort: string
    @param ScrambSeed: CPRI Scramb Seed ; 0~9999
    @type ScrambSeed: int
    @rtp none
    @rtt none
    '''
    vVSAInstanse = __getVSAInstanse(DevID,CpriPort)
    vVSAInstanse.setCPRIScrambSeed(ScrambSeed)

def getFrameFlowCondition(DevID,CpriPort,FileType,FlwDir):
    '''
    @date:    2017-7-24
    @function:   get Start and Stop Flow Condition TYPE and condition value
    @param DevID:  device ID |1|2|3|4|.....|N|
    @type DevID: int
    @param CpriPort:  How much Rumaster CpriPort number which you use it |1A|1B|2A|2B|3A|3B|........
    @type CpriPort: string
    @param FileType: which file type need to get condition value ; |IQ|AXC|
    @type FileType: str
    @param FlwDir:  TX or RX carrier ; |TX|RX|
    @type FlwDir: str  
    @rtp FlowData : "StartCondition,StartPara,StopCondition,StopPara"
                    StartPara format:
                        FRAME_PRE_START: |NA|NA|HF|BF   ;  CPRI_TIME: BFN OFFSET|BFN|HF|BF 
                    StopPara format :
                        CPRI_TIME_LENGTH: |NA|BFN|HF|BF   
    @rtt FlowData :str           
    '''
    vVSAInstanse = __getVSAInstanse(DevID,CpriPort)
    FlowData = vVSAInstanse.getFrameFlowCondition(FileType,FlwDir)
    return FlowData

def setAxcContainerSize(DevID,CpriPort,FlwDir,ContainerSize):
    '''
    @date:    2017-7-24
    @function:   Set Basic Frame AXC container size(dont support TX)
    @param DevID:  device ID |1|2|3|4|.....|N|
    @type DevID: int
    @param CpriPort:  How much Rumaster CpriPort number which you use it |1A|1B|2A|2B|3A|3B|........
    @type CpriPort: string
    @param FlwDir:  only support RX carrier ; |RX|
    @type FlwDir: str  
    @rtp ContainerSize : AXC container size ; |20|25|30| unit:bit
    @rtt ContainerSize :int               
    '''
    vVSAInstanse = __getVSAInstanse(DevID,CpriPort)
    vVSAInstanse.setAxcContainerSize(FlwDir,ContainerSize)

def getAxcContainerSize(DevID,CpriPort,FlwDir):
    '''
    @date:    2017-7-24
    @function:   get Basic Frame AXC container size(dont support TX)
    @param DevID:  device ID |1|2|3|4|.....|N|
    @type DevID: int
    @param CpriPort:  How much Rumaster CpriPort number which you use it |1A|1B|2A|2B|3A|3B|........
    @type CpriPort: string
    @param FlwDir:  only support RX carrier ; |RX|
    @type FlwDir: str  
    @rtp ContainerSize : AXC container size ; |20|25|30| unit:bit
    @rtt ContainerSize :int               
    '''
    vVSAInstanse = __getVSAInstanse(DevID,CpriPort)
    vVSAInstanse.getAxcContainerSize(FlwDir)

def getRuHwInfo(DevID,CpriPort,RruCascadePos):
    '''
    @date:    2017-7-24
    @function:   get the RU HW info
    @param DevID:  device ID |1|2|3|4|.....|N|
    @type DevID: int
    @param CpriPort:  How much Rumaster CpriPort number which you use it |1A|1B|2A|2B|3A|3B|........
    @type CpriPort: string
    @param RruCascadePos:  the RU cascade positon
    @type RruCascadePos: str 
    @return info_dic: the link ru HW information 
        @description:
            info_dic{'getStatus'} = True | False. type:boole.
            info_dic['errorInfo'] = 'error info' | 'None'. type:string.
            @if get information:
                info_dic['ProductNumber'] = 'KRC 161 684/1'. type:string.
                info_dic['Revision'] = 'R1B'. type:string.
                info_dic['ProductName'] = 'RRU8818B41E'. type:string.
                info_dic['ProductionDate'] = ''. type:string.
                info_dic['SerialNumber'] = 'D123456'. type:string.
                @note:if get sw info,example:
                    ProductNumber:KRC 161 684/1;Revision:R1B;ProductName:RRU8818B41E;ProductionDate:2017;SerialNumber:D123456
    @return type:dicitonary                                          
    '''
    vVSAInstanse = __getVSAInstanse(DevID,CpriPort)
    HWInfo = vVSAInstanse.getRuHwInfo(RruCascadePos)
    return HWInfo

def setRestartRuApp(DevID,CpriPort,RruCascadePos,SW_Version,checkFlag = 'True',delayTime = '600'):
    '''
    @date:    2017-7-24
    @function:   restart ru app to specified SW_Version
    @param DevID:  device ID |1|2|3|4|.....|N|
    @type DevID: int
    @param CpriPort:  How much Rumaster CpriPort number which you use it |1A|1B|2A|2B|3A|3B|........
    @type CpriPort: string
    @param RruCascadePos:  Ru cascade position number in ct10
    @type RruCascadePos: int 
    @param SW_Version:  software full name include pid. example:CXP9033285%1_AUBOOT
    @type SW_Version: str  
    @param checkFlag: = True | False.  after restart APP check app restart status, untill out of time.
    @type checkFlag: str
    @param delayTime: = the out of time(seconds) that check the restart status. 
    @type delayTime: int
    @return result_dic:
        result_dic['flag'] = True|False| ,type: boolean , Whether the command succeeds or not
        result_dic['remark'] = the remark information
    @return result_dic : dictionary                     
    '''
    vVSAInstanse = __getVSAInstanse(DevID,CpriPort)
    return vVSAInstanse.setRestartRuApp(RruCascadePos,SW_Version,checkFlag,delayTime)
    
def setDelRuApp(DevID,CpriPort,ruCascadePos,ruSwApp,appSlotOrPid = 'pid'):
    '''
    @date:    2017-7-24
    @function:   delete ru app to specified SW_Version
    @param DevID:  device ID |1|2|3|4|.....|N|
    @type DevID: int
    @param CpriPort:  How much Rumaster CpriPort number which you use it |1A|1B|2A|2B|3A|3B|........
    @type CpriPort: string
    @param ruCascadePos:  Ru cascade position number in rumaster
    @type ruCascadePos: int 
    @param ruSwApp:  software full name include pid
    @type ruSwApp: str  
    @param appSlotOrPid:  delete the APP by app slot or app pid. appSlotOrPid = slot | pid. default = pid.
                        if appSlotOrPid = slot, ruSwApp = APP1 | APP2 | APP3. if ruSwApp = APP1 that mean delete the RU software of specified slot APP1.
                        if appSlotOrPid = pid, ruSwApp = ru app version, that mean delete the specified ru app version.
    @type appSlotOrPid: str  
    @return result_dic:
        result_dic['flag'] = True|False| ,type: boolean , Whether the command succeeds or not
        result_dic['remark'] = the remark information
    @return result_dic : dictionary                     
    '''
    vVSAInstanse = __getVSAInstanse(DevID,CpriPort)
    return vVSAInstanse.setDelRuApp(ruCascadePos,ruSwApp,appSlotOrPid) 

def setUpgradeRuApp(DevID,CpriPort,ruCascadePos,appFilePath,appFileName,restart = 'True',force='False'):
    '''
    @date:    2017-7-24
    @function:   Upgrade ru app to specified SW_Version
    @param DevID:  device ID |1|2|3|4|.....|N|
    @type DevID: int
    @param CpriPort:  How much Rumaster CpriPort number which you use it |1A|1B|2A|2B|3A|3B|........
    @type CpriPort: string
    @param ruCascadePos:  Ru cascade position number in ct10
    @type ruCascadePos: int
    @param appFilePath:  software file path
    @type appFilePath: str 
    @param appFileName:  software file name
    @type appFileName: str            
    @param restart:  Whether to restart Upgrade SW_Version or not ; |True|False|
    @type restart: boolean 
    @param force:  Upgrade SW_Version forcible or not ; |True|False|. if True,upgrade the APP forcible even if there is no empty APP slot. default = 'False'
    @type force: boolean
    @return result_dic:
        result_dic['flag'] = True|False| ,type: boolean , Whether the command succeeds or not
        result_dic['remark'] = the remark information
    @return result_dic : dictionary                                        
    '''
    vVSAInstanse = __getVSAInstanse(DevID,CpriPort)
    return vVSAInstanse.setUpgradeRuApp(ruCascadePos,appFilePath,appFileName,restart,force) 

def getHwSn(DevID):
    '''
    @date:    2017-7-24
    @function:   get Ru master hardware SN
    @param DevID:  device ID |1|2|3|4|.....|N|
    @type DevID: int
    @rtp HWSN : Ru master hardware SN ; example:T01F289493
    @rtt HWSN : str                                             
    '''
    vVSAInstanse = __getVSAInstanse(DevID)
    return vVSAInstanse.getHardSn()

def getRefStatus(DevID,CpriPort):
    '''
    @date:    2017-7-24
    @function:   get ru master  reference type 
    @param DevID:  device ID |1|2|3|4|.....|N|
    @type DevID: int
    @param CpriPort:  How much Rumaster CpriPort number which you use it |1A|1B|2A|2B|3A|3B|........
    @type CpriPort: string
    @rtp RefType : ru master reference tyoe
    @rtt RefType : str. example: EXT_REF | INT_REF | APP_REF1                                       
    '''
    vVSAInstanse = __getVSAInstanse(DevID,CpriPort)
    return vVSAInstanse.getRefStatus()

def setRefType(DevID,CpriPort,RefType):
    '''
    @date:    2017-8-24
    @function:   set ru master  reference type 
    @param DevID:  device ID |1|2|3|4|.....|N|
    @type DevID: int
    @param CpriPort:  How much Rumaster CpriPort number which you use it |1A|1B|2A|2B|3A|3B|........
    @type CpriPort: string
    @param RefType:  Ru master reference type ; |EXT|INT|
    @type RefType: string
    @rtp none 
    @rtt none                                        
    '''
    vVSAInstanse = __getVSAInstanse(DevID,CpriPort)
    vVSAInstanse.setRefType(RefType)

def setRxIqCapture(DevID,cpriPort,iqFilePath,iqFileName,iqFileFormat):
    '''
    @date:    2017-8-24
    @function:   set Ru master restart Ru
    @param DevID:  device ID |1|2|3|4|.....|N|
    @type DevID: int
    @param CpriPort:  How much Rumaster CpriPort number which you use it |1A|1B|2A|2B|3A|3B|........
    @type CpriPort: string
    @return: RX capture result 
    @return: type boole
            capture success:return True
            capture fail:return  False                                            
    '''
    vVSAInstanse = __getVSAInstanse(DevID,CpriPort)
    vVSAInstanse.setRxIqCapture(iqFilePath,iqFileName,iqFileFormat)

def setRxIqCaptureAndExport(DevID,CpriPort,iqFilePath,iqFileName,iqFileFormat):
    '''
    @date:    2017-8-24
    @function:   set setRxIqCaptureAndExport
    @param DevID: rumaster device ID
    @type DevID: str
    @param CpriPort: How much Rumaster CpriPort number which you use it |1A|1B|2A|2B|3A|3B|....
    @type CpriPort: str
    @param iqFilePath:  device ID |1|2|3|4|.....|N|
    @type iqFilePath: int
    @param iqFileName:  How much Rumaster CpriPort number which you use it |1A|1B|2A|2B|3A|3B|........
    @type iqFileName: string
    @param iqFileFormat:  How much Rumaster CpriPort number which you use it |1A|1B|2A|2B|3A|3B|........
    @type iqFileFormat: string
    @return: RX capture result 
                type:dictionary
                result_dic['exist']:boole, | True | False,capture sucess:return True,capture sucess:return False
                result_dic['filename']: the capture file name                                             
    '''       
    vVSAInstanse = __getVSAInstanse(DevID,CpriPort)
    return vVSAInstanse.setRxIqCaptureAndExport(iqFilePath,iqFileName,iqFileFormat)
    pass
    
def setTxAxcMode (DevID, CpriPort, txAxcMode):
    '''set L1 Reset(base on RU cpri port that has been used)
    @param rumaDeviceId:  Ru master device ID |1|2|3|4|.....|N|
    @type rumaDeviceId: int
    @param cpriPort:  the RU master CPRI port ID
    @type cpriPort: string
    @param txAxcMode:  the TX AXC Mode. range: | NO_AXC | AUTO_AXC | CPC_FILES | CPC_MERGE 
            AXC mode 
            NO_AXC: No AXC 
            AUTO_AXC: Auto AXC from RAW data or Carrier Setup, Generate f rom carrier setup.
            CPC_FILES: AXC generated from CPC files, Use a single cpc file.
            CPC_MERGE: FS info f rom carrier setup is merged w ith the selected cpc f ile. FS
                        Info in the CPC-f ile is updated if a matching carrier is found in carrier setup,
                        otherw ise it is deleted. If the carrier setup contains carriers that are not
                        present in the cpc-f ile, new FS Info packets are added to the cpc-f ile.
                        A new cpc f ile is generated and can be exported by clicking on Save.
                    
    @type txAxcMode: string
    '''
    vVSAInstanse = __getVSAInstanse(DevID,CpriPort)
    return vVSAInstanse.setTxAxcMode(txAxcMode)

def getRuSwInfo(DevID,CpriPort,Physpos):
    '''
    @date:    2017-8-24
    @function:   get the RU sw info
    @param DevID:  device ID |1|2|3|4|.....|N|
    @type DevID: int
    @param CpriPort:  How much Rumaster CpriPort number which you use it |1A|1B|2A|2B|3A|3B|........
    @type CpriPort: string
    @param RruCascadePos:  the RU cascade positon
    @type RruCascadePos: str
    @return info_dic: the link ru software information 
        @description:
            info_dic{'getStatus'} = True | False. type:boole.
            info_dic['errorInfo'] = 'error info' | 'None'. type:string.
            @if get information:
                info_dic['BOOT'] = 'CXP9033285%1_AUBOOT' | ''. type:string.
                info_dic['APP1'] = 'CXP9033285%2_xxxxx1' | ''. type:string.
                info_dic['APP2'] = 'CXP9033285%2_xxxxx2' | ''. type:string.
                info_dic['APP3'] = 'CXP9033285%2_xxxxx3' | ''. type:string.
                info_dic['ACTIVE'] = 'CXP9033285%2_xxxx' | ''. type:string.
                @note:if get sw info,example:
                    BOOT:CXP9033285%1_AUBOOT;APP1:;APP2:;APP3:CXP9033285%2_R3C03;ACTIVE:CXP9033285%2_R3C03
    @return type:dicitonary                                          
    '''
    vVSAInstanse = __getVSAInstanse(DevID,CpriPort)
    return vVSAInstanse.getRuSwInfo(Physpos)

def getIsLinkRu(DevID,CpriPort):
    '''
    @date:    2017-8-24
    @function:   get the CPRI port is link a RU
    @param DevID:  device ID |1|2|3|4|.....|N|
    @type DevID: int
    @param CpriPort:  How much Rumaster CpriPort number which you use it |1A|1B|2A|2B|3A|3B|........
    @type CpriPort: string
    @return isRulink: the RU link status. True|False
    @return type:boole                                          
    '''
    vVSAInstanse = __getVSAInstanse(DevID,CpriPort)
    return vVSAInstanse.getIsLinkRu()

def getIsLinkRu2(DevID,CpriPort,Physpos):
    '''
    @date:    2017-8-24
    @function:   get the CPRI port and cascade position is link a RU
    @param DevID:  device ID |1|2|3|4|.....|N|
    @type DevID: int
    @param CpriPort:  How much Rumaster CpriPort number which you use it |1A|1B|2A|2B|3A|3B|........
    @type CpriPort: string
    @para Physpos: the RU cascade position
    @type Physpos: int
    @return isRulink: the RU link status. True|False
    @return type:boole                                          
    '''
    vVSAInstanse = __getVSAInstanse(DevID,CpriPort)
    return vVSAInstanse.getIsLinkRu2(Physpos)

def getRuAppList(DevID,CpriPort,ruCascadePos):
    '''
    @date:    2017-8-24
    @function:   get the RU APP list
    @param DevID:  device ID |1|2|3|4|.....|N|
    @type DevID: int
    @param CpriPort:  How much Rumaster CpriPort number which you use it |1A|1B|2A|2B|3A|3B|........
    @type CpriPort: string
    @param ruCascadePos:  the RU cascade positon
    @type ruCascadePos: str
    @return appList_dic: the APP PID list and getAPP information flag
            appList_dic['getStatus']: True | False
            appList_dic['applist']: {'CXP9033285%1_AUBOOT':'APP1'}, app dictionary
    @return type: dicitonary                                          
    '''
    vVSAInstanse = __getVSAInstanse(DevID,CpriPort)
    return vVSAInstanse.getRuAppList(ruCascadePos)

def getRuLmcName(DevID,CpriPort,ruCascadePos):
    '''
    @date:    2017-8-24
    @function:   get the RU LMC name
    @param DevID:  device ID |1|2|3|4|.....|N|
    @type DevID: int
    @param CpriPort:  How much Rumaster CpriPort number which you use it |1A|1B|2A|2B|3A|3B|........
    @type CpriPort: string
    @param ruCascadePos:  the RU cascade positon
    @type ruCascadePos: str
    @return result_dic: the RU LMC name
            result_dic['getStatus']: True | False
            result_dic['lmcName']: 'CXP9033285', string.
    @return type: dicitonary                                          
    '''
    vVSAInstanse = __getVSAInstanse(DevID,CpriPort)
    return vVSAInstanse.getRuLmcName(ruCascadePos)

def setRuAppUpgradeOnline(rumaDevId, ruMarketName,rumaCpriPort,cascadePos,lmcName,restart = 'False',force = 'False',onlinePath = "/proj/cdiv/NGR_LFT/dailyLMC/",localPath = "C:\\RTT\\LMC\\"):  
    #*******************************************************************
    '''        function name: setRuAppUpgradeOnline
    @date:          2017-9-16
    @function:      get RU upgrade the LMC app of newest vesion from on line sever
    @parameter  rumaDevId: the rumaster device comunication ID. defasult = '1'
    @type       rumaDevId: string
    @parameter  ruMarketName: the ru product name. example:RRU8818B41E
    @type       ruMarketName: string
    @parameter  rumaCpriPort: the CPRI of rumaster that connect to current RRU
    @type       rumaCpriPort: string
    @parameter  cascadePos: the cascade of current RRU
    @type       cascadePos: string
    @parameter  lmcName: the ru app pid neme. example:CXP9029033
    @type       lmcName: string
    @parameter  restart: whether u need to restart the app after load successed. = Ture | False
    @type       restart: string
    @param force:  Upgrade SW_Version forcible or not ; |True|False|. if True,upgrade the APP forcible even if there is no empty APP slot. default = 'False'
    @type force: boolean
    @parameter  onlinePath: the on line file path of sever. default = "/proj/cdiv/NGR_LFT/dailyLMC/"
    @type       onlinePath: string
    @parameter  localPath: the local file path of down load APP from on line sever. default = "C:\\RTT\\LMC\\"
    @type       localPath: string
    @return     result_dic: 
                result_dic['remark'] = return the log information. 
                result_dic['flag'] = True | False
                result_dic['appPid'] = CXP9029033%2_R1A01. return the new app name load from remote sever.
    @return type:               
    '''
    #*******************************************************************
    result_dic = {}      
    ruHwInfo = getRuHwInfo(rumaDevId,rumaCpriPort,cascadePos) 
    ruLmcName = getRuLmcName(rumaDevId,rumaCpriPort,cascadePos)
    tempMarketName =  ruMarketName.replace('_', '').strip()
    try:
        tempLmcName = re.findall(r'\w+',lmcName)[0]
    except:
        tempLmcName = ''
    if tempLmcName == ruLmcName['lmcName']:
        if remoteLinkCheck():
            onlineAppName = getRuAppPidFromOnlinePath(lmcName,onlinePath)
            if onlineAppName['flag']:                
                appPid = onlineAppName['appPid']
                tempReturn = downRuAppFromOnlineToLocal(appPid,onlinePath,localPath)
                appPid = tempReturn['appPid']
                tempReturn = setUpgradeRuApp(rumaDevId,rumaCpriPort,cascadePos,localPath,appPid,restart,force)
                if tempReturn['flag']:
                    printstr = 'Upgrade the RU:'+str(ruMarketName)+' app to LMC: '+str(appPid)+' successed!'
                    result_dic['remark'] = printstr
                    result_dic['flag'] = True
                    result_dic['appPid'] = appPid
                    return result_dic 
                else:
                    printstr = 'Upgrade the RU:'+str(ruMarketName)+' app to LMC: '+str(appPid)+' failed! error code:'+str(tempReturn['remark'])
                    result_dic['remark'] = printstr
                    result_dic['flag'] = False
                    result_dic['appPid'] = ''
                    return result_dic 
            else:
                printstr = 'get the LMC: '+str(lmcName)+' from remote sever:'+str(onlinePath)+' failed!'
                result_dic['remark'] = printstr
                result_dic['flag'] = False
                result_dic['appPid'] = ''
                return result_dic 
        else:
            printstr = 'The remote sever connect check failed!'
            result_dic['remark'] = printstr
            result_dic['flag'] = False
            result_dic['appPid'] = ''
            return result_dic 
    else:
        printstr = 'The input RU product name is:'+str(ruMarketName) + ', the input LMC is:'+str(lmcName) + '. the RU product name get from TCA is:'+str(ruHwInfo["ProductName"]) + ', the RU lmc name from TCA is:'+str(ruLmcName['lmcName']) + ', there one information not match at least!'
        result_dic['remark'] = printstr
        result_dic['flag'] = False
        result_dic['appPid'] = ''
        return result_dic 
        pass

def setRuAppUpgradeLocal(rumaDevId,ruMarketName,rumaCpriPort,cascadePos,appPid,restart = 'False',force = 'False',localPath = "C:\\RTT\\LMC\\"):  
    #*******************************************************************
    '''        function name: setRuAppUpgradeOnline
    @date:          2017-9-16
    @function:      get RU upgrade the LMC app of newest vesion from on line sever
    @parameter  rumaDevId: the rumaster device comunication ID.
    @type       rumaDevId: string
    @parameter  ruMarketName: the ru product name. example:RRU8818B41E
    @type       ruMarketName: string
    @parameter  rumaCpriPort: the CPRI of rumaster that connect to current RRU
    @type       rumaCpriPort: string
    @parameter  cascadePos: the cascade of current RRU
    @type       cascadePos: string
    @parameter  appPid: the APP full name of RU. example:CXP9029033%2_R1A01
    @type       appPid: string
    @parameter  restart: whether u need to restart the app after load successed. = Ture | False
    @type       restart: string
    @param force:  Upgrade SW_Version forcible or not ; |True|False|. if True,upgrade the APP forcible even if there is no empty APP slot. default = 'False'
    @type force: boolean
    @parameter  localPath: the local file path of down load APP from on line sever. default = "C:\\RTT\\LMC\\"
    @type       localPath: string
    @return     result_dic: 
                result_dic['remark'] = return the log information. 
                result_dic['flag'] = True | False
                result_dic['appPid'] = CXP9029033%2_R1A01. return the new app name load from remote sever.
    @return type:               
    '''
    #*******************************************************************
    result_dic = {}   
    result_dic['appPid'] =  appPid  
    ruHwInfo = getRuHwInfo(rumaDevId,rumaCpriPort,cascadePos) 
    ruLmcName = getRuLmcName(rumaDevId,rumaCpriPort,cascadePos)
    tempMarketName =  ruMarketName.replace('_', '').strip()
    try:
        tempLmcName = re.findall(r'\w+',lmcName)[0]
    except:
        tempLmcName = ''
    if tempLmcName == ruLmcName['lmcName']: 
        tempReturn = setUpgradeRuApp(rumaDevId,rumaCpriPort,cascadePos,localPath,appPid,restart,force)
        if tempReturn['flag']:
            printstr = 'Upgrade the RU:'+str(ruMarketName)+' app to APP: '+str(appPid)+' successed!'
            result_dic['remark'] = printstr
            result_dic['flag'] = True
            return result_dic 
        else:
            printstr = 'Upgrade the RU:'+str(ruMarketName)+' app to APP: '+str(appPid)+' failed! error code:'+str(tempReturn['remark'])
            result_dic['remark'] = printstr
            result_dic['flag'] = True
            return result_dic           
    else:
        printstr = 'The input RU LMC name is:'+str(lmcName) + '. the RU lmc name get from TCA is:'+str(ruLmcName['lmcName']) + ', there LMC not match!'
        result_dic['remark'] = printstr
        result_dic['flag'] = False
        return result_dic 
        pass

def setL1Reset(DevID,CpriPort):
    '''
    @date:    2017-7-24
    @function:   restart Ru to boot version by rumaster
    @param DevID:  device ID |1|2|3|4|.....|N|
    @type DevID: int
    @param CpriPort:  How much Rumaster CpriPort number which you use it |1A|1B|2A|2B|3A|3B|........
    @type CpriPort: string
    @rtp none 
    @rtt none                                        
    '''
    vVSAInstanse = __getVSAInstanse(DevID,CpriPort)
    vVSAInstanse.setL1Reset()

def remoteLinkCheck():
    #*******************************************************************
    '''        function name: remote link Check
    @date:          2017-9-16
    @function:      check the RRU APP release sever remote link status.
    @parameter:     none
    @return remote_status: True | False       
    @return type :boolean
                for example: True | False
    '''
    #*******************************************************************

    dataStr=rttInfo.cmd("Remote.ls",1)
    if  dataStr!=None and  dataStr.find("RTT-ACK")==-1 and dataStr!="":
        return True
    else:
        printStr = 'The remote sever connect check failed!'
        rttInfo.MsgBox(printStr, Stytle="YesNo", Title="")
        return False

def getRuAppPidFromOnlinePath(lmcName,onlinePath = "/proj/cdiv/NGR_LFT/dailyLMC/"):
    #*******************************************************************
    '''        function name: getRuAppPidFromOnlinePath
    @date:          2017-9-16
    @function:      get the APP lmc name of newest vesion from on line sever
    @parameter  lmcName: the ru app pid neme. example:CXP9029033
    @type       lmcName: string
    @parameter  onlinePath: the on line file path of sever. default = "/proj/cdiv/NGR_LFT/dailyLMC/"
    @type       onlinePath: string
    @return     result_dic: 
                result_dic['appPid'] = 'CXP9029033%2_R1A01.xlf' or 'CXP9029033%2_R1A01'. if get app name fail return the error log. 
                result_dic['flag'] = True | False
    @return type:               
    '''
    #*******************************************************************
    result_dic = {}
    try:       
        remoteCmd="cd "+onlinePath+";ls -t "+lmcName+"*|head -1"
        dataStr=rttInfo.cmd("Remote."+remoteCmd)
        if  (dataStr!=None and dataStr.find("RTT-ACK")==-1 and dataStr!="") or (dataStr.find("No such file or directory")==-1 and dataStr.find("cannot access")==-1):
            data=re.findall(lmcName+r'%\w+.xlf',dataStr)
            if not data:                
                data=re.findall(lmcName+r'%\w+',dataStr)
                if not data:
                    printstr = "Upgrade file not found match,RemotePathFile:"+dataStr+",lmcName:"+str(lmcName)
                    result_dic['appPid'] = printstr
                    result_dic['flag'] = False
                    return result_dic 
            printstr = "Match Upgrade RU APP File:"+str(data)
            result_dic['appPid'] = data[0]
            result_dic['flag'] = True
            return result_dic 
        else:
            printstr = "Upgrade file not found match,"+"Remote.#"+str(remoteCmd)+":"+str(dataStr)+";lmcName:"+str(lmcName)
            result_dic['appPid'] = printstr
            result_dic['flag'] = False
            return result_dic                  
    except Exception,e:  
        result_dic['appPid'] = str(e)
        result_dic['flag'] = False
        return result_dic

def downRuAppFromOnlineToLocal(appPid,remotePath = "/proj/cdiv/NGR_LFT/dailyLMC/",localPath = "C:\\RTT\\Data\\DownLoad\\"):
    #*******************************************************************
    '''        function name: downRuAppFromOnlineToLocal
    @date:          2017-9-16
    @function:      down load the RU app from on line sever to local file path
    @parameter  appPid: the ru app pid neme. example:'CXP9029033%2_R1A01.xlf' or 'CXP9029033%2_R1A01'.
    @type       appPid: string
    @parameter  remotePath: the on line file path of sever. default = "/proj/cdiv/NGR_LFT/dailyLMC/"
    @type       remotePath: string
    @parameter  localPath: the local file path of sever. default = "C:\\RTT\\Data\\DownLoad"
    @type       localPath: string
    @return     result_dic: 
                result_dic['appPid'] = the remark information. if down load failed, then return the log information.
                result_dic['flag'] = True | False
    @return type:               
    '''
    #*******************************************************************
    result_dic = {}
    try:        
        remoteFile = remotePath + '\\' + str(appPid)
        data=rttInfo.cmd("Remote.WCP.Get#"+remoteFile+"#"+localPath,1)
        if data!="done":
            returnStr = " Fail:"+"Remote.WCP.Get#"+remoteFile+"#"+localPath+"["+str(data)+"]"
            result_dic['appPid'] = returnStr
            result_dic['flag'] = False
            return result_dic
        else:
            result_dic['appPid'] = appPid
            result_dic['flag'] = True
            return result_dic
    except Exception,e:  
        result_dic['appPid'] = e
        result_dic['flag'] = False
        return result_dic

class cpcGenerator():   
    '''ruma cpc file generator parameters
    @param 'AntNum' :   default = '8'. TX RF number. type: int
    @param 'CarNum' :   default = '3'. TX Carrier number. type: int
    @param 'BFN'    :   default = '1'. Radio frame number of the received package. type: int
    @param 'HF'     :   default = '149'. Hyper frame number of the received package. type: int
    @param 'BF'     :   default = '200'. Basic frame number of the received package. type: int
    @param 'FSO'    :   default = '0'. frame start offset. type: int
    @param 'Tdd_DLUL_Config': default = '3'. TDD UL and DL config. type: int
    @param 'Tdd_SF_Config'  : default = '8'. TDD special frame config. type: int
    @param 'AxC_ID' :   default = '1'. AXC ID. type: int
    @param 'CDL_Modulation' : default = '64QAM'. CDL(CPRI Down Link) IQ modulation. type: string
    @param 'SPBS_EN':   default = 'OFF'. SPBS enable flag. type: string
    @param 'HFN_Offset'     : default = '3'. HFN Offset. type: int
    @param 'PCL'    : default = '1'. The payload container length. type: int
                   PCL = 0 -> 0..8 bytes payload, PCL = 1 -> 9..16 bytes payload, PCL = 2 -> 17..24 bytes payload, ?                    .., PCL = 15 -> 121..128 bytes payload, PCL = 16 -> 129..256 bytes payload, PCL = 17 -> 257..384 bytes payload                 ?                    .., PCL = 61 -> 5889..6016 payload, PCL = 62 -> 6017..6144 bytes payload, PCL = 63 -> No payload container length defined, 
    @param 'SF_Structure'   : default = '3'. type: int
                    The SF structure information states what kind of frame structure, cyclic prefix and other kind of subframe related information that is used in the current subframe. 
                    Interpretation of SF type is implemented in higher level software and is not defined in this document
    @param 'Tdd_Format'     : default = {'0':'DSUUUDSUUU','1':'DSUUDDSUUD','2':'DSUDDDSUDD','3':'DSUUUDDDDD','4':'DSUUDDDDDD','5':'DSUDDDDDDD','6':'DSUUUDSUUD','7':'DDDDDDDDDD'}. the TDD DL and UL config format, according to 3GPP. type: dict
    @param 'SF_Format'      : default = {'0':6592,'1':19760,'2':21952,'3':24144,'4':26336,'5':6592,'6':19760,'7':21952,'8':24144}. the TDD special frame config format, according to 3GPP. type: dict
    @param 'Nta_Offset'     : default = '624'. number of Ts advance definied in TS36.211 (see last chapter). type: int
    @param 'SubFramNum'     : default = '10'.  the sub frame number. type: int
    @param 'FilePath'       : default = "C:\RTT\CommonInput\\". The CPC file path. type: string
    '''
    AntNum = 8
    CarNum = 3
    BFN = 2             # maximum two 10ms frame can be supported by cpc file
    F_TRIG = [1,2]        # Frame number which output trigger, start with 1;
    HF = 149            # (HF,BF) for DL FS info, which needs to take FSO into consideration
    BF = 200
    FSO = 0             # frame start offset, in the unit of 'nano-second', FSO = 700000 means 700us ahead
    Tdd_DLUL_Config = 3  # TDD configuration according to TS36.211
    Tdd_SF_Config = 8   # Special subframe configuration according TS36.211
    AxC_ID = 1          # this needs to be compatible with IE included in carrier setup message (DC_TR_SETUPx_REQ)
    CDL_Modulation = '64QAM'   # DL modulation scheme (highest modulation used in transmission) 'QPSK','16QAM' or '64QAM' 
    SPBS_EN = 'ON'     # symbol based power saving (supported, but not yet verified), 1-on, 0-off
    LM3_EN = 'OFF'            # for E-UTRA-LM3 test model, 1-on, 0-off

    # =====================================================================
    # =========== calc SFinfo HFN position (70-500us ahead of IQ data) ====
    HFN_Offset = 3  # 3 HfnOffset for 200us, which is within 70-500us        
    PCL = 2        # 3 BF for one SF info
    # need to check PCL (payload container length)
    # PCL = 0 means 0-8 bytes
    # PCL = 1 means 9-16 bytes
    # PCL = 2 means 17-24 bytes
    # so it is 0 for FS info (3 bytes)
    SF_Structure = 3 
    # =========== TDD and SF configuration format =========================
    Tdd_Format = {'0':'DSUUUDSUUU','1':'DSUUDDSUUD','2':'DSUDDDSUDD','3':'DSUUUDDDDD','4':'DSUUDDDDDD','5':'DSUDDDDDDD','6':'DSUUUDSUUD','7':'DDDDDDDDDD'}
    SF_Format = {'0':6592,'1':19760,'2':21952,'3':24144,'4':26336,'5':6592,'6':19760,'7':21952,'8':24144}    # length of DwPTS, in the unit of Ts (1 clock of 30.72MHz)
    # =========== time advance and modulation value =======================
    Nta_Offset = 624   # number of Ts advance definied in TS36.211 (see last chapter)
    #function cpc_gen2
    # =============== note of info ========================================
    # this script generates .cpc files for TCA usage, given configurable
    # paramters listed as below (basic understanding of CPRI IWD is the
    # pre-requisite for users)
    # =========== configurable parameters =================================
    # =========== writing SFinfo ================================================================================================================
    # type 2 frame structure (TDD) with normal CP, only 1 we support      
    SubFramNum = 10
    FilePath = "C:\RTT\CommonInput\\"

    def __init__(self,param_dic = ''):        
        if type(param_dic) == dict:
            try:
                self.AntNum = param_dic['AntNum']
                self.CarNum = param_dic['CarNum']
                self.BFN = param_dic['BFN']
                self.HF = param_dic['HF']
                self.BF = param_dic['BF']
                self.FSO = param_dic['FSO']
                self.Tdd_DLUL_Config = param_dic['Tdd_DLUL_Config']
                self.Tdd_SF_Config = param_dic['Tdd_SF_Config']
                self.AxC_ID = param_dic['AxC_ID']
                self.CDL_Modulation = param_dic['CDL_Modulation']
                self.SPBS_EN = param_dic['SPBS_EN']
                self.HFN_Offset = param_dic['HFN_Offset']
                self.PCL = param_dic['PCL']
                self.SF_Structure = param_dic['SF_Structure']
                self.Tdd_Format = param_dic['Tdd_Format']
                self.SF_Format = param_dic['SF_Format']
                self.Nta_Offset = param_dic['Nta_Offset']
                self.SubFramNum = param_dic['SubFramNum']
                self.FilePath = param_dic['FilePath']
            except Exception, e:
                print e

    def __getSymbolPwr(self,TDD_format_selected,Foffset,SPBS_EN = False,LM3_EN = False):
        symPower = []
        DwPTS_len = self.SF_Format[str(self.Tdd_SF_Config)]
        DwPTS_sym_len = int(math.floor(DwPTS_len/(2048+144)))
        for i in range(10):
            temp = []
            for j in range(14):
                temp.append(0)
            symPower.append(temp)

        for Sfidx in range(10):
            if TDD_format_selected[Sfidx] == 'D':
                powerboost = int('111011', 2)
                for i in range(len(symPower[Sfidx])):
                    symPower[Sfidx][i]= powerboost  ##bin2dec('111011')   # b'111011 stands for 0dB power boost
            elif TDD_format_selected[Sfidx] == 'S':
                powerboost = int('111011', 2)
                for i in range(DwPTS_sym_len):                         
                    symPower[Sfidx][i]= powerboost   ##bin2dec('111011')
        phyCH = [[1]*14]*10
        if SPBS_EN:
           phyCH = [[1,0,0,0,1,0,0,1,1,1,1,1,0,1],
                    [1,0,1,0,1,0,0,1,0,0,0,1,0,0],
                    [1,0,0,0,1,0,0,1,0,0,0,1,0,0],
                    [1,0,0,0,1,0,0,1,0,0,0,1,0,0],
                    [1,0,0,0,1,0,0,1,0,0,0,1,0,0],
                    [1,0,0,0,1,0,0,1,0,0,0,1,0,1],
                    [1,0,1,0,1,0,0,1,0,0,0,1,0,0],
                    [1,0,0,0,1,0,0,1,0,0,0,1,0,0],
                    [1,0,0,0,1,0,0,1,0,0,0,1,0,0],
                    [1,0,0,0,1,0,0,1,0,0,0,1,0,0]]
        elif LM3_EN:
            phyCH = [[1,0,0,0,1,0,0,1,1,1,1,1,0,1],
                     [1,0,1,0,1,0,0,1,0,0,0,1,0,0],
                     [1,0,0,0,1,0,0,1,0,0,0,1,0,0],
                     [1,0,0,0,1,0,0,1,0,0,0,1,0,0],
                     [1,0,0,0,1,0,0,1,0,0,0,1,0,0],
                     [1,0,0,0,1,0,0,1,0,0,0,1,0,1],
                     [1,0,1,0,1,0,0,1,0,0,0,1,0,0],
                     [1,1,1,1,1,1,1,1,1,1,1,1,1,1],
                     [1,1,1,1,1,1,1,1,1,1,1,1,1,1],
                     [1,1,1,1,1,1,1,1,1,1,1,1,1,1]];
        for i in range(int(Foffset)):
            temp = phyCH[i]
            phyCH = phyCH + [temp]
        phyCH = phyCH[int(Foffset):]
        for i in range(len(symPower)):
            for j in range(len(symPower[i])):
                symPower[i][j] = symPower[i][j] * phyCH[i][j]
        return symPower