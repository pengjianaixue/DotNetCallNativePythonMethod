#!/lib/bin/python
import matlab.engine
import os
import TestFrame
from TestFrame import TestStep
from TestFrame import *


UlConfig_Nsc            = 1
UlConfig_PatternSF      = 'DDDSUDDDSU'
UlConfig_PatternSS      = 'T20-G2-R6'
UlConfig_Modulation     = '64QAM'
UlConfig_beforeTA       = 0
UlConfig_fCompensation  = 0
UlConfig_ZeroInsert     = 0


DlConfig_TM             = 'TM31'
DlConfig_CellId         = 1
DlConfig_Nsc            = 1
DlConfig_PatternSF      = 'DDDSUDDDSU'
DlConfig_PatternSS      = 'T20-G2-R6'
DlConfig_beforeTA       = 1
DlConfig_ZeroInsert     = 1


class CruFile(object):
        def put(self,src):
                self.__file = src
        def get(self):
                return self.__file


class MatlabAnalyzeUlEvm(TestStep):
        'MatlabAnalyzeUlEvm'
        
        def run(self):
                AntPort = self.arg1[0]
                start = 0 + AntPort % 4 * 24 
                end = 23 + AntPort % 4 * 24
                cruFileName = self.arg1[1]    
                testResult = True
                try:
                        eng = matlab.engine.start_matlab()
                        #saFile = os.path.dirname(os.path.realpath(__file__)) + '\\' +'temp'+'\\'+self.arg1[2]
                        saFile = 'C:/NRV2_TEST/' + TestFrame.address + "/" + TestFrame.timeDay + "/" + self.arg1[2]
                        #subFile=saFile.replace('\\','/' )
                        eng.path(eng.path(), r'C:/Users/test/PycharmProjects/nrv2/case/matlab/UL_EVM')
                        #eng.path(eng.path(), subFile)
                        EVM = eng.Top_UL_EVM(cruFileName, saFile)
                        # EVM = eng.NR_UL_EVM_PythonInterface(cruFileName,start,end,UlConfig_Nsc,UlConfig_PatternSF,UlConfig_PatternSS,UlConfig_Modulation,UlConfig_beforeTA,UlConfig_fCompensation,UlConfig_ZeroInsert)
                        eng.quit()
                except Exception as e:
                        self.log('Error when invoke Matlab: %s' % e)
                        testResult = False
                finally:
                        eng.quit()
                        if testResult:
                                self.log('EVM is %f'%EVM)
                                
                                if EVM > 0.12:
                                        return False
                                else:
                                        return True
                        else:
                                return True



class MatlabAnalyzeDlEvm(TestStep):
        'MatlabAnalyzeDlEvm'

        def run(self):
                csvFileName = self.arg1[0]
                testResult = True

                try:
                        eng = matlab.engine.start_matlab()  
                        #saFile = os.path.dirname(os.path.realpath(__file__)) + '\\' +'temp'+'\\'+self.arg1[1]
                        saFile = 'C:/NRV2_TEST/' + TestFrame.address + "/" + TestFrame.timeDay + "/" + self.arg1[1]
                        #subFile=saFile.replace('\\','/' )
                        eng.path(eng.path(), r'C:/Users/test/PycharmProjects/nrv2/case/matlab/DL_EVM')
                        #eng.path(eng.path(), subFile)
                        EVM = eng.Top_evm(csvFileName, saFile)
                        #EVM = eng.Top_evm(csvFileName,DlConfig_TM,DlConfig_CellId,DlConfig_Nsc,DlConfig_PatternSF,DlConfig_PatternSS,DlConfig_beforeTA,DlConfig_ZeroInsert)
                        eng.quit()
                except Exception as e:
                        self.log('Error when invoke Matlab: %s' % e)
                        testResult = False
                finally:
                        eng.quit()
                        if testResult:
                                self.log('EVM is %f'%EVM)
                                if EVM > 0.15:
                                        return False
                                else:
                                        return True
                        else:
                                pass
                        return testResult                
                
                
                
                
