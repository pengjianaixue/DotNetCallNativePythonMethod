#!/lib/bin/python

import re
import socket
import os
import sys
import time
from TestFrame import *
import TestFrame
from reg1e02calculate import *
import reg1e02calculate
import subprocess
import close
from close import *

RtpAddress = '127.0.0.1'
RtpPort = 8001


class RtpTestStepBase(TestStep):
    'RtpTestStepBase'

    def sendCmd(self, command, delay=0, fileName=None):
        self.log('sendCmd')
        if not fileName == None:
            cmd = command + '$' + str(delay) + '$' + fileName
        else:
            cmd = command + '$' + str(delay)
        self.log(('$ %s' % cmd))

        try:
            conn = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
            conn.settimeout(120)
            conn.connect((RtpAddress, RtpPort))
            conn.sendto(cmd, (RtpAddress, RtpPort))
        except Exception as e:
            self.log('Fail to send command to RTP')
            self.log('Error: %s' % e)
            conn.close()
            return None

        try:
            #            retult = None
            result = conn.recv(25000)
            self.log(result)
        except Exception as e:
            self.log('Fail to receive data from RTP')
            self.log('Error: %s' % e)
        finally:
            conn.close()
            return result


class RfBoxTestStepBase(RtpTestStepBase):
    'RfBoxTestStepBase'

    DIRECT = ('DL', 'UL')
    SCPI_DIC = {
        'ANT': {'DL': ('1101,1121,1141,1124',
                       '1102,1121,1142,1124',
                       '1103,1121,1143,1124',
                       '1104,1121,1144,1124',
                       '1105,1121,1145,1124',
                       '1106,1121,1146,1124',
                       '1112,1131,1152,1134',
                       '1113,1131,1153,1134'),
                'UL': ('1141,1124',
                       '1142,1124',
                       '1143,1124',
                       '1144,1124',
                       '1145,1124',
                       '1146,1124',
                       '1152,1124',
                       '1153,1124'),
                'RX_Only': '1156,1134',
                'SG2SA': '1134,1155,1115,1131,1122,1123', },
        'Link': {'DL': '1122,1123', 'EXT1': '1132,1133', 'UL': 'NONE'},
        'PathCmdHeader': 'ROUT:CLOS (@1102,1103)',
        'ERR': 'SYST:ERR?'
    }
    IEEE_488_2 = {'IDN': '*IDN?', 'CLS': '*CLS', 'RST': '*RST', 'Load_Set': '*LOD n', 'OPC': '*OPC',
                  'Save_Set': '*SAV n', 'Rest2Factory': '*FAC'}

    def send(self, cmd, delay=2000):
        if not self.sendCmd(cmd, delay, 'Send') == None:
            return True
        return False

    def sendAndRecv(self, cmd, delay=20000):
        self.log('sendAndRecv')
        if not self.sendCmd(cmd, delay, 'SendRead') == None:
            return True
        return False


class RfBox_SetAntPort(RfBoxTestStepBase):
    'RfBox_SetAntPort'

    def run(self):
        antId = self.arg1[0]
        direction = self.DIRECT[self.arg1[1]]
        cmdStr1 = 'RF-Box.ROUT:CLOS (@' + self.SCPI_DIC['ANT'][direction][antId] + ')'
        self.send(cmdStr1)
        # Currently the opc status command is not yet ready, so the following two lines will be comment
        # cmdStr2 = self.IEEE_488_2['OPC']
        # result = self.sendAndRecv(cmdStr2)
        return True


class CT11_CaptureIQ(RtpTestStepBase):
    'CT11_CaptureIQ'

    def run(self):
        loop_time = 0
        while loop_time < 5:
            rInterval = 20
            rCmd1 = 'StartCapture'
            rCmd2 = 'StopCapture'
            rCmd3 = 'ExportAllCapturedData'
            
            rCpriPort = '1A'
            rDataFormat = 'IQ'
            rSuffix = 'cru'
            time.sleep(rInterval)
            #rPath = os.path.dirname(os.path.realpath(__file__)) + '\\'+'temp'+'\\' +self.arg1[1]+'\\'+ self.arg1[0]
            rPath = 'C:/NRV2_TEST/' + TestFrame.address + "/" + TestFrame.timeDay + "/" + self.arg1[1]+"/"+ self.arg1[0]
            cmd = 'Rumaster.%s#%s#%s' % (rCmd1, rCpriPort, rDataFormat)
            self.sendCmd(cmd)
            time.sleep(rInterval)
            
            cmd = 'Rumaster.%s#%s#%s' % (rCmd2, rCpriPort, rDataFormat)
            self.sendCmd(cmd)
            time.sleep(rInterval)
            
            cmd = 'Rumaster.%s#%s#%s#%s' % (rCmd3, rCpriPort, rPath, rSuffix)
            self.sendCmd(cmd)
            time.sleep(60)
            
            if os.path.isfile(rPath):
                self.log('Success export data to %s' % rPath)
                print('Success export data to %s' % rPath)
                break
            else:
                self.log('Fail to export data')
                print('Fail to export data')
                command = 'taskkill /F /IM TSL.exe'
                ret0 = subprocess.Popen(command,stdout=subprocess.PIPE,stderr=subprocess.PIPE,shell=True)
                time.sleep(15)
                ret0.communicate()
                lines = ret0.stdout.readlines()
                if not lines or len(lines) == 0:
                    line = ret0.stderr.readlines()
                cmd = "C:\Progra~2\Ericsson\TCA\Bin\TSL\Release\TSL.exe"
                ret1 = subprocess.Popen(cmd,stdout=subprocess.PIPE,stderr=subprocess.PIPE,shell=True)
                time.sleep(15)
                subprocess.Popen.terminate(ret1)

                self.log('restart TCA,try again loop_time = %d' %loop_time)  
                print('restart TCA,try again loop_time = %d' %loop_time)  
                time.sleep(300)
                loop_time = loop_time + 1
        print('end function')
        return True

class CT11_LineRateSet(RtpTestStepBase):
    'CT11_CaptureIQ'

    def run(self):
        rInterval = 60
        rCmd = 'SetCpriConfig'
        rCpriPort = '1A'
        rLineRate = self.arg1[0]

        cmd = 'Rumaster.%s#LineRate#%s#%s' % (rCmd, rCpriPort, rLineRate)
        time.sleep(5)
        self.sendCmd(cmd)
        time.sleep(rInterval)
        return True

class CT11_CarrierAdd(RtpTestStepBase):
    'CT11_CarrierAdd'

    def run(self):
        rInterval = 0.5
        sa_command_list = ['1A#TX#0#0',
                           '1A#TX#1#4',
                           '1A#TX#2#8',
                           '1A#TX#3#12',
                           '1A#TX#4#16',
                           '1A#TX#5#20',
                           '1A#TX#6#24',
                           '1A#TX#7#28',
                           '1A#TX#8#32',
                           '1A#TX#9#36',
                           '1A#TX#10#40',
                           '1A#TX#11#44',
                           '1A#RX#0#0',
                           '1A#RX#1#4',
                           '1A#RX#2#8',
                           '1A#RX#3#12',
                           '1A#RX#4#16',
                           '1A#RX#5#20',
                           '1A#RX#6#24',
                           '1A#RX#7#28',
                           '1A#RX#8#32',
                           '1A#RX#9#36',
                           '1A#RX#10#40',
                           '1A#RX#11#44']

        for sa_command in sa_command_list:
            cmd = 'Rumaster.AddCarrier#%s#Frequency_30_72#LTE' % (sa_command)
            result= self.sendCmd(cmd)
            time.sleep(rInterval)
        return True

class CT11_CarrierSet(RtpTestStepBase):
    'CT11_CarrierSet'

    def run(self):
        rInterval = 0.5
        sa_command_list = ['1A#TX#0#true#0#LTE#Frequency_30_72#0',
                           '1A#TX#1#true#1#LTE#Frequency_30_72#8',
                           '1A#TX#2#true#2#LTE#Frequency_30_72#16',
                           '1A#TX#3#true#4#LTE#Frequency_30_72#24',
                           '1A#TX#4#true#5#LTE#Frequency_30_72#32',
                           '1A#TX#5#true#6#LTE#Frequency_30_72#40',
                           '1A#TX#6#true#8#LTE#Frequency_30_72#48',
                           '1A#TX#7#true#9#LTE#Frequency_30_72#56',
                           '1A#TX#8#true#10#LTE#Frequency_30_72#64',
                           '1A#TX#9#true#12#LTE#Frequency_30_72#72',
                           '1A#TX#10#true#13#LTE#Frequency_30_72#80',
                           '1A#TX#11#true#14#LTE#Frequency_30_72#88',
                           '1A#RX#0#true#0#LTE#Frequency_30_72#0',
                           '1A#RX#1#true#1#LTE#Frequency_30_72#8',
                           '1A#RX#2#true#2#LTE#Frequency_30_72#16',
                           '1A#RX#3#true#4#LTE#Frequency_30_72#24',
                           '1A#RX#4#true#5#LTE#Frequency_30_72#32',
                           '1A#RX#5#true#6#LTE#Frequency_30_72#40',
                           '1A#RX#6#true#8#LTE#Frequency_30_72#48',
                           '1A#RX#7#true#9#LTE#Frequency_30_72#56',
                           '1A#RX#8#true#10#LTE#Frequency_30_72#64',
                           '1A#RX#9#true#12#LTE#Frequency_30_72#72',
                           '1A#RX#10#true#13#LTE#Frequency_30_72#80',
                           '1A#RX#11#true#14#LTE#Frequency_30_72#88']

        for sa_command in sa_command_list:
            cmd = 'Rumaster.SetCarrierConfig#%s#false|0|0#0|0|0|0#0#0#CUSTOM' % (sa_command)
            result= self.sendCmd(cmd)
            time.sleep(rInterval)
        return True

class CT11_StartPlayback(RtpTestStepBase):
    'CT11_StartPlayback'

    def run(self):
        rInterval = 5
        rCmd = 'startplayback'
        rCpriPort = '1A'
        cmd = 'Rumaster.%s#%s#all' % (rCmd, rCpriPort)
        self.sendCmd(cmd)
        time.sleep(rInterval)
        return True

class SA_CaptureData(RtpTestStepBase):
    'SA_CaptureData'

    def run(self):
        rInterval = 60
        saCmd = 'SA.Command:'
        saExport = ':MMEM:STOR:RES '
        time.sleep(10)
        #saFile = os.path.dirname(os.path.realpath(__file__)) + '\\' +'temp'+'\\'+self.arg1[1]
        #os.makedirs(saFile)
        #saPath = os.path.dirname(os.path.realpath(__file__)) + '\\' +'temp'+'\\'+self.arg1[1]+ '\\' + self.arg1[0]
        saPath = 'C:/NRV2_TEST/' + TestFrame.address + "/" + TestFrame.timeDay + "/" + self.arg1[1]+'/'+ self.arg1[0]
        cmd = '%s%s%s' % (saCmd, saExport, saPath)
        print cmd
        self.sendCmd(cmd)
        time.sleep(rInterval)
        
        if os.path.isfile(saPath):
            self.log('Success export data to %s' % saPath)
            mark = 'MeasResult0'
            scriptFileName = saPath
            with open(scriptFileName, 'r+') as f:
                lines = f.readlines()
                f.seek(0)
                f.truncate()
                lineNum = 0
                isFindMark = False
                for line in lines:
                    lineNum = lineNum + 1
                    if mark in line:
                        if lineNum == 9:
                            isFindMark = True
                            break
                if isFindMark:
                    del lines[0]
                for line in lines:
                    f.write(line)
            return True
        else:
            self.log('Fail to export data')
            return False


class SASetUpIQData(RtpTestStepBase):
    'SA_Setup'
    def run(self):
        rInterval = 0.5
        saCmd = 'SA.Command:'
        sa_command_list = [' ',
                           ':INST:SEL BASIC',
                           ':CORR:SA:GAIN 0',
                           ':CONF:WAV',
                           ':DISP:WAV:VIEW IQ',
                           ':FREQ:CENT 3500MHz',
                           ':WAV:SWE:TIME 10 ms',
                           ':WAV:SRAT 122.88 MHz',
                           ':TRIG:WAV:SOUR EXT1']

        for sa_command in sa_command_list:
            cmd = '%s%s' % (saCmd, sa_command)
            result= self.sendCmd(cmd)
            if not result =='RTT-ACK':
                self.log('Fail to sand command to SA. Restart RTT!')
                return False
            time.sleep(rInterval)
        return True

class SAInitACLR(RtpTestStepBase):
    'SA_Setup_For_ACLR'

    def run(self):
        rInterval = 0.5
        saCmd = 'SA.Command:'
        sa_command_list = [':SYST:PRESET',
                           ':INST:SEL LTETDD',
                           ':CONF:ACP',
                           ':TRIG:ACP:SOUR EXT1',
                           ':SWE:EGAT ON',
                           ':SWE:EGAT:TIME 10ms',
                           ':SWE:EGAT:DELay 0ms',
                           ':SWE:EGAT:LENG 1ms',
                           ':FREQ:CENT 2330MHz',
                           ':DISP:ACP:VIEW:WIND:TRAC:Y:RLEV 40',
                           ':POW:ATT 20',
                           ':ACP:AVER OFF',
                           ':ACP:SWE:TIME 50ms',]

        for sa_command in sa_command_list:
            cmd = '%s%s' % (saCmd, sa_command)
            result= self.sendCmd(cmd)
            if not result =='RTT-ACK':
                self.log('Fail to sand command to SA. Restart RTT!')
                return False
            time.sleep(rInterval)
        time.sleep(5)
        return True


class SASetUpACLR(RtpTestStepBase):
    'SA_Setup_For_ACLR'

    def run(self):
        rInterval = 0.5
        saCmd = 'SA.Command:'
        sa_command_list = [':INST SA',
                           ':SYST:PRESET',
                           ':FREQ:CENT 3.5GHz',
                           ':CORR:SA:GAIN -42',
                           ':CONF:ACP',
                           ':ACP:CARR:COUN 1',
                           ':ACP:CARR:LIST:WIDT 100MHz',
                           ':ACP:CARR:LIST:BAND 97.92MHz',
                           ':ACP:OFFS:LIST 100MHz,200MHz,300MHz',
                           ':ACP:OFFS:LIST:BAND 92.16MHz,92.16MHz',
                           ':ACP:OFFS:LIST:STAT 1,1',
                           ':ACP:SWE:TIME 100ms',
                           ':ACP:BAND 200kHz',
                           ':SWE:EGAT:SOUR EXT1',
                           ':SWE:EGAT ON',
                           ':SWE:EGAT:DEL 5ms',
                           ':SA.Command:SWE:EGAT:LENG 1ms',
                           ':ACP:AVER OFF',
                           ':POWer:RANGe:OPTimize IMMediate']

        for sa_command in sa_command_list:
            cmd = '%s%s' % (saCmd, sa_command)
            result= self.sendCmd(cmd)
            if not result =='RTT-ACK':
                self.log('Fail to sand command to SA. Restart RTT!')
                return False
            time.sleep(rInterval)
        return True


class SA_Capture_ACLR_Data(RtpTestStepBase):
    'SA_Capture_ACLR_Data'

    def run(self):
        #return True
        rInterval = 20
        saCmd = 'SA.Command:'
        saExport = ':FETC:ACP? '

        cmd = '%s%s' % (saCmd, saExport)
        time.sleep(8)
        result= self.sendCmd(cmd)
        result= list(result.split(','))
        failstate=1
        if float(result[3])<33 or float(result[3])>37:
            self.log('fail at Ref Carrier %s dBc' % float(result[3]))
            #failstate=0
        if float(result[4])>-45:
            self.log('fail at A Lower ACP %s dBc' % float(result[4]))
            #failstate = 0
        if float(result[6])>-45:
            self.log('fail at A  Upper ACP %s dBc' % float(result[6]))
            #failstate = 0
        if float(result[8])>-50:
            self.log('fail at B Lower ACP %s dBc' % float(result[8]))
            #failstate = 0
        if float(result[10])>-50:
            self.log('fail at B Upper ACP %s dBc' % float(result[10]))
            #failstate = 0
        if failstate==1:
            return True
        else:
            return False
        time.sleep(rInterval)

class SA_PowerOffOn(RtpTestStepBase):
    'SA_PowerOffOn'
    def run(self):
        rInterval = 50
        saCmd = 'DC5767A.OUTPut '
        OFF = 'OFF'
        ON = 'ON'
        self.log('SA_PowerOffOn power to: %s ' % OFF)
        cmd = '%s%s' % (saCmd, OFF)
        times = 0
        while True:
            result= self.sendCmd(cmd)
            if None != result:
                break
            if times > 5:
                return False

            times = times + 1
        time.sleep(5)
        self.log('SA_PowerOffOn power to: %s ' % ON)
        cmd = '%s%s' % (saCmd, ON)
        times = 0
        while True:
            result= self.sendCmd(cmd)
            if None != result:
                break
            if times > 5:
                return False

            times = times + 1
        time.sleep(rInterval)
        return True

class SG_Restart(RtpTestStepBase):
    'SG_Restart'
    def run(self):
        rInterval = 5
        saCmd = 'SG.Command:system:reboot'
        self.log('SG_Restart now')
        result= self.sendCmd(saCmd)
        time.sleep(rInterval)
        return True

class SG_CalRxSync(RtpTestStepBase):
    'SG_CalRxSync'
    def run(self):
        rInterval = 1
        rCmd = 'SG.Command::SOURce:BB:ARB:WAV:SEL '

        rFilePath = self.arg1[0]

        cmd = '%s%s' % (rCmd, rFilePath)
        self.sendCmd(cmd)
        time.sleep(rInterval)

        saCmd = 'SG.Command:'
        sa_command_list = ['OUTP1 OFF',
                           'OUTP1  ON'
                           ]

        for sa_command in sa_command_list:
            cmd = '%s%s' % (saCmd, sa_command)
            result= self.sendCmd(cmd)
            time.sleep(rInterval)
        CalAndWriteRxSync()
        return True

class SG_LoadArbFile(RtpTestStepBase):
    'SG_LoadArbFile'
    def run(self):
        rInterval = 1
        rCmd = 'SG.Command::SOURce:BB:ARB:WAV:SEL '

        rFilePath = self.arg1[0]

        cmd = '%s%s' % (rCmd, rFilePath)
        self.sendCmd(cmd)
        time.sleep(rInterval)

        saCmd = 'SG.Command:'
        sa_command_list = ['OUTP1 OFF',
                           'OUTP1  ON'
                           ]

        for sa_command in sa_command_list:
            cmd = '%s%s' % (saCmd, sa_command)
            result= self.sendCmd(cmd)
            time.sleep(rInterval)
        return True

class SG_Init(RtpTestStepBase):
    'SG_Restart'
    def run(self):
        rInterval = 1
        rCmd = 'SG.Command:OUTP1  ON'
        self.sendCmd(rCmd)
        time.sleep(rInterval)

        saCmd = 'SG.Command:SOURce1:'
        sa_command_list = ['FREQ 3500MHz',
                           'POW -15dBm' ,
                           'IQ:STAT ON'
                           ]

        for sa_command in sa_command_list:
            cmd = '%s%s' % (saCmd, sa_command)
            result= self.sendCmd(cmd)
            time.sleep(rInterval)
        return True
