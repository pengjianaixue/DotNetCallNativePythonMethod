#!/usr/bin/python
# -*- coding: utf-8 -*-
from TestFrame import *
from FormalTestStep import *
import TestFrame
import time
from MatlabTestStep import *
from RtpTestStep import *


class Version(TestCase):
    'Version'
    def configTestStep(self):
        self.addTestStep(show_version(TestFrame.trxmPos))
        self.addTestStep(TRXM(show_version(TestFrame.trxmPos)))
        self.addTestStep((hwyFpga_read(0x107)))
        self.addTestStep((hwyFpga_read(0x108)))
        self.addTestStep(TRXM(hwyFpga_read(0x107)))
        self.addTestStep(TRXM(hwyFpga_read(0x108)))

class LTU(TestCase):
    'LTU'
    def configTestStep(self):
        self.addTestStep(ltu_TC1(TestFrame.trxmPos))

class CPRI_sync(TestCase):
    'CPRI_sync'
    def configTestStep(self):
        self.addTestStep(cpri_sync_TC2(TestFrame.trxmPos))

class OAM_ILINK_TRXM0(TestCase):
    'OAM_ILINK_TRXM0'
    def configTestStep(self):
        self.addTestStep(oam_ilink_trxm0_TC3(TestFrame.trxmPos))

class OAM_ILINK_TRXM1(TestCase):
    'OAM_ILINK_TRXM1'
    def configTestStep(self):
        self.addTestStep(oam_ilink_trxm1_TC4(TestFrame.trxmPos))

class DATA_ILINK_TRXM0(TestCase):
    'DATA_ILINK_TRXM0'
    def configTestStep(self):
        self.addTestStep(data_ilink_trxm0_TC5(TestFrame.trxmPos))

class DATA_ILINK_TRXM1(TestCase):
    'DATA_ILINK_TRXM1'
    def configTestStep(self):
        self.addTestStep(data_ilink_trxm1_TC6(TestFrame.trxmPos))

class UE_LTU(TestCase):
    'UE_LTU'
    def configTestStep(self):
        self.addTestStep(ue_ltu_TC1(TestFrame.trxmPos))

class UE_CPRI_sync(TestCase):
    'UE_CPRI_sync'
    def configTestStep(self):
        self.addTestStep(ue_cpri_sync_TC2(TestFrame.trxmPos))

class UE_OAM_ILINK_TRXM0(TestCase):
    'UE_OAM_ILINK_TRXM0'
    def configTestStep(self):
        self.addTestStep(ue_oam_ilink_trxm0_TC3(TestFrame.trxmPos))

class UE_DATA_ILINK_TRXM0(TestCase):
    'UE_DATA_ILINK_TRXM0'
    def configTestStep(self):
        self.addTestStep(ue_data_ilink_trxm0_TC5(TestFrame.trxmPos))

class JESD204B_TX_RX_TRXM0(TestCase):
    'JESD204B_TX_RX_TRXM0'
    def configTestStep(self):
        self.addTestStep(jesd204b_TX_RX_TRXM0_TC7(TestFrame.trxmPos))

class JESD204B_TX_RX_TRXM1(TestCase):
    'JESD204B_TX_RX_TRXM1'
    def configTestStep(self):
        self.addTestStep(jesd204b_TX_RX_TRXM1_TC8(TestFrame.trxmPos))

class CARRIER_CTRL(TestCase):
    'CARRIER_CTRL'
    def configTestStep(self):
        self.setTargetType('BP')
        #self.addTestStep(TRXM(hwyFpga_write(0x129, 0x00000000)))
        #self.addTestStep(TRXM(hwyFpga_write(0x12a, 0x00000000)))
        #self.addTestStep(TRXM(hwyFpga_write(0x12b, 0x00000000)))
        #self.addTestStep(TRXM(hwyFpga_write(0x12c, 0x00000000)))
        #self.addTestStep(TRXM(hwyFpga_write(0x12d, 0x00000000)))
        #self.addTestStep(TRXM(hwyFpga_write(0x12e, 0x00000000)))
        
        self.addTestStep(hwyFpga_write(0x114,0x0000203e))
        self.addTestStep(TRXM(wgt_evm_step()))
        #self.addTestStep(TRXM(dvga_crsetup_off()))
        #self.addTestStep(TRXM(pa_tcmp_on_all()))
        self.addTestStep(carrier_setup())
        #time.sleep(120)

        # self.addTestStep(TRXM(hwyFpga_write(0x1e0f, 0x20000)))
        # self.addTestStep(TRXM(hwyFpga_write(0x9803, 0)))
        # self.addTestStep(TRXM(hwyFpga_write(0xa803, 0)))
        # self.addTestStep(TRXM(hwyFpga_write(0x5000, 2)))
        # self.addTestStep(TRXM(hwyFpga_write(0x5200, 2)))
        ###self.addTestStep(carrier_list())
#        self.addTestStep(carrier_release())
#        self.addTestStep(carrier_list())
        ###time.sleep(120)

class PWR_DUC(TestCase):
    'PWR_DUC'
    
    def configTestStep(self):
        self.setTargetType('TRXM')
        for i in range(32):
            self.addTestStep(vca_getcorr(i))
            if i<16:
                self.addTestStep(hwyFpga_write(0x1206,0x00000008))
                self.addTestStep(hwyFpga_write(0x1407,0xA6AAAAA))
                self.addTestStep(hwyFpga_write(0x1409,pow(16,i,0x100000000)))  
                self.addTestStep(hwyFpga_write(0x140A,pow(16,i)/0x100000000))
                self.addTestStep(hwyFpga_write(0x1406,0x2))
                self.addTestStep(hwyFpga_write(0x1406,0x0))
                self.addTestStep(hwyFpga_write(0x1420+i,0x4000))
                self.addTestStep(pwrMeter_duc(i,0,-19,-17))                    
            else:
                self.addTestStep(hwyFpga_write(0x1306,0x00000008))
                self.addTestStep(hwyFpga_write(0x1507,0xA6AAAAA))
                self.addTestStep(hwyFpga_write(0x1509,pow(16,i-16,0x100000000)))
                self.addTestStep(hwyFpga_write(0x150A,pow(16,i-16)/0x100000000))
                self.addTestStep(hwyFpga_write(0x1506,0x2))
                self.addTestStep(hwyFpga_write(0x1506,0x0))
                self.addTestStep(hwyFpga_write(0x1520+i-16,0x4000))
                self.addTestStep(pwrMeter_duc(i,0,-19,-17))  

class PWR_DPD(TestCase):
    'PWR_DPD'
    
    def configTestStep(self):
        self.setTargetType('TRXM')
        self.addTestStep(hwyFpga_write(0x1206,0x00000008))
        self.addTestStep(hwyFpga_write(0x1407,0xA6AAAAA))
        self.addTestStep(hwyFpga_write(0x1406,0x2))
        self.addTestStep(hwyFpga_write(0x1406,0x0))
        self.addTestStep(hwyFpga_write(0x1306,0x00000008))
        self.addTestStep(hwyFpga_write(0x1507,0xA6AAAAA))
        self.addTestStep(hwyFpga_write(0x1506,0x2))
        self.addTestStep(hwyFpga_write(0x1506,0x0))              
        for i in range(32):
            if i<16:
                self.addTestStep(hwyFpga_write(0x1409,pow(16,i,0x100000000)))  
                self.addTestStep(hwyFpga_write(0x140A,pow(16,i)/0x100000000))
                self.addTestStep(hwyFpga_write(0x1420+i,0x4000))
                self.addTestStep(pwrMeter_dpd(i,0,-19,-16))
            else:
                self.addTestStep(hwyFpga_write(0x1509,pow(16,i-16,0x100000000)))
                self.addTestStep(hwyFpga_write(0x150A,pow(16,i-16)/0x100000000))
                self.addTestStep(hwyFpga_write(0x1520+i-16,0x4000))
                self.addTestStep(pwrMeter_dpd(i,0,-19,-16))

            
class PWR_ADC(TestCase):
    'PWR_ADC'
    
    def configTestStep(self):
        self.setTargetType('TRXM')
        for i in range(8):
            self.addTestStep(afe7689_rxtddon(i))
        for i in range(32):
            self.addTestStep(pwrMeter_rxadc(i,0,-90,-40))

class PWR_TOR(TestCase):
    'PWR_TOR'
    
    def configTestStep(self):
        self.setTargetType('TRXM')
##        for i in range(8):
##            self.addTestStep(afe7689_tortddon(i))
        for i in range(32):
            self.addTestStep(pwrMeter_tor(i,0,-80,-10))

class PWR_AGC(TestCase):
    'PWR_AGC'
    
    def configTestStep(self):
        self.setTargetType('TRXM')
        self.addTestStep(hwyFpga_write(0x1206,0x0000001C))
        self.addTestStep(hwyFpga_write(0x120a,0x11111111))
        self.addTestStep(hwyFpga_write(0x1306,0x0000001C))
        self.addTestStep(hwyFpga_write(0x130a,0x11111111))
        for i in range(8):
            self.addTestStep(afe7689_rxtddon(i))
        for i in range(32):
            if i<16:
                self.addTestStep(pwrMeter_agc(0,i,0,-100,-20)) 
            else:
                self.addTestStep(pwrMeter_agc(0,i,0,-100,-20)) 
        self.addTestStep(hwyFpga_write(0x1206,0x0))
        self.addTestStep(hwyFpga_write(0x120a,0x0))
        self.addTestStep(hwyFpga_write(0x1306,0x0))
        self.addTestStep(hwyFpga_write(0x130a,0x0))
        self.addTestStep(hwyFpga_write(0x121, 0x8888))
        time.sleep(30)



class CaptureCT11DataAndAnalyse(TestCase):
    'CaptureCT11DataAndAnalyse'

    def configTestStep(self):
        self.setTargetType('BP')
#        port = self.arg1[0]
#        link = self.arg1[1]
#        self.addTestStep(RfBox_SetAntPort(port,1))
        self.addTestStep(CT11_CaptureIQ('sourceData.cru', self.arg1[0]))
#        self.addTestStep(MatlabAnalyzeUlEvm(link,'sourceData.cru'))


class CPRI_PLUG_UNPLUG(TestCase):
    'CPRI_PLUG_UNPLUG'

    def configTestStep(self):
        for i in range(10):
            self.log('Loop times : %d\n' % i)
            self.addTestStep(CT11_LineRateSet('LR2_5'))
            self.addTestStep(cpri_unsync_TC2(TestFrame.trxmPos))
            self.addTestStep(CT11_LineRateSet('LR9_8'))
            self.addTestStep(cpri_sync_TC2(TestFrame.trxmPos))
        self.addTestStep(CT11_CarrierAdd())
        self.addTestStep(CT11_CarrierSet())
        self.addTestStep(CT11_StartPlayback())

class DL_1C_100M_64QAM_EVM(TestCase):
    'DL_1C_100M_64QAM_EVM'

    def configTestStep(self):

#        self.setTargetType('TRXM')
        link = self.arg1[0]        

        self.addTestStep(TRXM(vca_off_all()))
        self.addTestStep(TRXM(hwyFpga_write(0x121, 0x8888)))
        self.addTestStep(TRXM(hwyFpga_write(0x6000, 0x7f007f00)))
        self.addTestStep(TRXM(hwyFpga_write(0x1520, 0x4000)))
        self.addTestStep(TRXM(wgt_evm_step()))

        self.addTestStep(TRXM(hwyFpga_write(0x9803, 0)))
        self.addTestStep(TRXM(hwyFpga_write(0xa803, 0)))
        self.addTestStep(TRXM(hwyFpga_write(0x5000, 2)))
        self.addTestStep(TRXM(hwyFpga_write(0x5200, 2)))
        self.addTestStep(TRXM(hwyFpga_write(0x1406, 2)))
        self.addTestStep(TRXM(hwyFpga_write(0x1406, 0)))
        self.addTestStep(TRXM(hwyFpga_write(0x1506, 2)))
        self.addTestStep(TRXM(hwyFpga_write(0x1506, 0)))
        self.addTestStep(SA_CaptureData('DL_sourceData.csv', self.arg1[1]))
        self.addTestStep(MatlabAnalyzeDlEvm('DL_sourceData.csv', self.arg1[1]))

#        self.addTestStep(MatlabAnalyzeDlEvm('sourceData.csv'))
#        self.addTestStep(carrier_release())


class UL_1C_100M_64QAM_EVM(TestCase):
    'UL_1C_100M_64QAM_EVM'

    def configTestStep(self):
        #        self.setTargetType('TRXM')
        link = self.arg1[0]
        #        self.addTestStep(RfBox_SetAntPort(link,0))
      
        self.setTargetType('BP')
        self.addTestStep(SG_Init())
        self.addTestStep(TRXM(pa_off_all()))
        self.addTestStep(TRXM(hwyFpga_write(0x121, 0x8000aaaa)))
        self.addTestStep(TRXM(hwyFpga_write(0x123, 0xFF)))
        self.addTestStep(TRXM(hwyFpga_write(0x1209, 0x0)))
        self.addTestStep(TRXM(hwyFpga_write(0x120a, 0x0)))
        self.addTestStep(TRXM(hwyFpga_write(0x1309, 0x0)))
        self.addTestStep(TRXM(hwyFpga_write(0x130a, 0x0)))
        self.addTestStep(TRXM(hwyFpga_write(0x1206, 0x1E)))
        self.addTestStep(TRXM(hwyFpga_write(0x1206, 0x1C)))
        self.addTestStep(TRXM(hwyFpga_write(0x1306, 0x1E)))
        self.addTestStep(TRXM(hwyFpga_write(0x1306, 0x1C)))
        #self.addTestStep(SG_CalRxSync("'nr2\\NRv2_1ms_97.92MHz_64QAM_t.wv'"))
        #self.addTestStep(SG_LoadArbFile("'nr2\\NRv2_UL_TV_3264RE_ZI1.wv'")) 
        self.addTestStep(TRXM(hwyFpga_write(0x1e02, 0xF685)))  
#         0x1e02 change by version 302:0xF669
        self.addTestStep(TRXM(wgt_clear_step()))
        self.addTestStep(TRXM(axi_write(0xd0010000,0x00004000)))
        self.addTestStep(CT11_CaptureIQ('UL_sourceData.cru', self.arg1[1]))
        time.sleep(10)

        
        self.addTestStep(MatlabAnalyzeUlEvm(self.arg1[0], 'UL_sourceData.cru', self.arg1[1]))
#        self.addTestStep(MatlabAnalyzeDlEvm('sourceData.csv'))
#        self.addTestStep(carrier_release())


class DL_PWRMeter(TestCase):
    'DL_PWRMeter'

    def configTestStep(self):
        self.setTargetType('TRXM')
        for i in range(8):
            self.addTestStep(pwrMeter_dpd(16,i,-60,-17))
            self.addTestStep(pwrMeter_duc(16,i,-60,-17))
            self.addTestStep(pwrMeter_tor(16,i,-60,-17))


class UL_PWRMeter(TestCase):
    'UL_PWRMeter'

    def configTestStep(self):
        self.setTargetType('TRXM')
        for i in range(9):
            self.addTestStep(pwrMeter_rxadc(16,i,-60,-10))
            self.addTestStep(pwrMeter_agc(0,16,i,-100,-30))


class SASetUpIQDataCase(TestCase):
    'SASetUpIQDataCase'
    def configTestStep(self):
        self.addTestStep(SASetUpIQData())


class SASetUpACLRCase(TestCase):
    'SASetUpACLRCase'
    def configTestStep(self):
        #self.addTestStep(SAInitACLR())
        self.addTestStep(SASetUpACLR())
        self.addTestStep(SA_Capture_ACLR_Data())

class SAPowerOffOnCase(TestCase):
    'SAPowerOffOnCase'
    def configTestStep(self):
        self.addTestStep(SA_PowerOffOn())

class GetRxsync(TestCase):
    'GetRxsync'
    def configTestStep(self):
        self.addTestStep(SG_CalRxSync("'NRv2_1ms_97.92MHz_64QAM_t.wv'"))
        self.addTestStep(SG_LoadArbFile("'NRv2_UL_TV_3264RE_ZI1.wv'"))

class DCDC_Check(TestCase):
    'DCDC_Check'

    def configTestStep(self):
        self.setTargetType('TRXM')
        resultRange = ((9.0,5.2,9.0,5.2,9.0,5.2,9.0,5.2),(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0),(3.3,2.5,1.8,1.2,1.2,0.9,0.9,1.8))
        currentCheck = ((True,True,True,True,False,False,False,False),(True,False,True,False,True,False,True,False),(True,True,True,True,False,True,False,True))
        for i in range(3):
            for j in range(8):
                if currentCheck[i][j]:
                    if not ((i == 2) and (j == 0)):
                        self.addTestStep(dcdc_sup(i,j,resultRange[i][j]*(1-0.05)*1000,resultRange[i][j]*(1+0.05)*1000))

class DCDC_Check_Bp(TestCase):
    'DCDC_Check_Bp'

    def configTestStep(self):
        self.setTargetType('BP')
        resultRange = ((-48.0,40.0,-48.0,40.0,5.2,3.7,3.3,2.5),(2.3,1.8,1.5,1.0,0.85,1.8,1.2,0.9),(17.0,14.0,19.0,20.0,1.2,0.9,0.9,1.8))
        currentCheck = ((True,False,True,False,True,True,True,True),(True,True,True,True,True,True,True,True),(False,False,False,False,False,False,False,False))
        for i in range(3):
            for j in range(8):
                if currentCheck[i][j]:
                    self.addTestStep(dcdc_sup(i,j,resultRange[i][j]*(1-0.05)*1000,resultRange[i][j]*(1+0.05)*1000))

class PA_Protect_OFF(TestCase):
    'PA_Protect_Off'
    def configTestStep(self):
        self.setTargetType('TRXM')
        self.addTestStep(hwyFpga_write(0x129, 0x00000000))
        self.addTestStep(hwyFpga_write(0x12a, 0x00000000))
        self.addTestStep(hwyFpga_write(0x12b, 0x00000000))
        self.addTestStep(hwyFpga_write(0x12c, 0x00000000))
        self.addTestStep(hwyFpga_write(0x12d, 0x00000000))
        self.addTestStep(hwyFpga_write(0x12e, 0x00000000))

class Temp_Read(TestCase):
    'Temp_Read'
    
    def configTestStep(self):
        self.setTargetType('TRXM')
        
        self.addTestStep(fpga_temp(0,-40,127))
        self.addTestStep(fpga_temp(1,-40,127))

class AFE7689_linkup(TestCase):
    'AFE7689_linkup'

    def configTestStep(self):
        self.setTargetType('BP')
        self.addTestStep(afe7689_linkup(0))
        for i in range(8):
                self.addTestStep(TRXM(afe7689_linkup(i)))


class AFE7689_checkStatus(TestCase):
    'AFE7689_Check_Status'

    def configTestStep(self):
        self.setTargetType('BP')
        self.addTestStep(afe7689_status(0))
        self.addTestStep(afe7689_204b_status(0))
        for i in range(8):
            self.addTestStep(TRXM(afe7689_status(i)))
            self.addTestStep(TRXM(afe7689_204b_status(i)))


class PA_Bias_Temp(TestCase):
    'PA_Bias_Temp'

    def configTestStep(self):
        self.setTargetType('TRXM')
        self.addTestStep(hwyFpga_write(0x121, 0x80000000))
        for i in range(32):
            if (i != 0) or (i != 16) or (i != 31):
                self.addTestStep(pa_on(i))
                self.addTestStep(pa_tcmp_on(i))
                self.addTestStep(pa_read_curr(i,50,220))
                self.addTestStep(pa_read_temp(i,-500,140))
                self.addTestStep(pa_tcmp_off(i))
                self.addTestStep(pa_off(i))

class DUC_Config(TestCase):
    'DUC_Cofig'

    def configTestStep(self):
        self.setTargetType('TRXM')
        self.addTestStep(hwyFpga_write(0x0D02, 0x00000002))
        self.addTestStep(hwyFpga_write(0x0D06, 0x00000008))
        self.addTestStep(hwyFpga_write(0x0D08, 0x0001dfff))
        self.addTestStep(hwyFpga_write(0x1206, 0x00000008))
        self.addTestStep(hwyFpga_write(0x1407, 0xA6AAAAA))
        self.addTestStep(hwyFpga_write(0x1409, 0x0))
        self.addTestStep(hwyFpga_write(0x140A, 0x0))
        self.addTestStep(hwyFpga_write(0x1406, 0x2))
        self.addTestStep(hwyFpga_write(0x1406, 0x0))
        for i in range(16):
            self.addTestStep(hwyFpga_write(0x1420+i, 0x4000))
     
        self.addTestStep(hwyFpga_write(0x0D82, 0x00000002))
        self.addTestStep(hwyFpga_write(0x0D86, 0x00000008))
        self.addTestStep(hwyFpga_write(0x0D88, 0x0001dfff))
        self.addTestStep(hwyFpga_write(0x1306, 0x00000008))
        self.addTestStep(hwyFpga_write(0x1507, 0xA6AAAAA))
        self.addTestStep(hwyFpga_write(0x1509, 0x0))
        self.addTestStep(hwyFpga_write(0x150A, 0x0))
        self.addTestStep(hwyFpga_write(0x1506, 0x2))
        self.addTestStep(hwyFpga_write(0x1506, 0x0))
        for i in range(16):
            self.addTestStep(hwyFpga_write(0x1520+i, 0x4000))            

class Tx_TDD_On(TestCase):
    'Tx_TDD_On'

    def configTestStep(self):
        self.setTargetType('TRXM')
        for i in range(8):
            self.addTestStep(afe7689_txtddon(i))

class Tor_TDD_On(TestCase):
    'Tor_TDD_On'

    def configTestStep(self):
        self.setTargetType('TRXM')
        for i in range(8):
            self.addTestStep(afe7689_tortddon(i))

class PA_bias_configuration(TestCase):
    'PA_bias_configuration'

    def configTestStep(self):
        self.setTargetType('TRXM')
        for i in range(32):
            if (i != 0) or (i != 2) or (i != 31):
                self.addTestStep(pa_on(i))
                self.addTestStep(pa_write_GMpa(i,0,4.0))
                self.addTestStep(pa_write_GMpa(i,1,2.6))
                self.addTestStep(pa_read_curr(i,100,200))
                self.addTestStep(pa_off(i))


class Check_rru_status(TestCase):
    'check_rru_status'

    def configTestStep(self):
        self.addTestStep(rru_status(TestFrame.trxmPos))
    
class AFE7689_TxNCO_Scan(TestCase):
    'AFE7689_TxNCO_Scan'

    def configTestStep(self):
        self.setTargetType('TRXM')
        for i in range(8):
            for j in range(20):
                self.addTestStep(afe7689_settxnco(j,0,3400000+j*10000))
            self.addTestStep(afe7689_status(i))
            self.addTestStep(afe7689_204b_status(i))    
            
class AFE7689_RxNCO_Scan(TestCase):
    'AFE7689_RxNCO_Scan'

    def configTestStep(self):
        self.setTargetType('TRXM')
        for i in range(8):
            for j in range(20):
                self.addTestStep(afe7689_setrxnco(j,0,3400000+j*10000))
            self.addTestStep(afe7689_status(i))
            self.addTestStep(afe7689_204b_status(i))  

class AFE7689_TorNCO_Scan(TestCase):
    'AFE7689_TorNCO_Scan'

    def configTestStep(self):
        self.setTargetType('TRXM')
        for i in range(8):
            for j in range(20):
                self.addTestStep(afe7689_settornco(j,1,3400000+j*10000))
            self.addTestStep(afe7689_status(i))
            self.addTestStep(afe7689_204b_status(i))  

class AFE7689_TxDSA_Scan(TestCase):
    'AFE7689_TxDSA_Scan'

    def configTestStep(self):
        self.setTargetType('TRXM')
        for i in range(8):
            for j in range(20):
                self.addTestStep(afe7689_settxdsa(j,0,5+j))
            self.addTestStep(afe7689_status(i))
            self.addTestStep(afe7689_204b_status(i)) 
        
class AFE7689_RxDSA_Scan(TestCase):
    'AFE7689_RxDSA_Scan'

    def configTestStep(self):
        self.setTargetType('TRXM')
        for i in range(8):
            for j in range(20):
                self.addTestStep(afe7689_setrxdsa(j,0,5+j))
            self.addTestStep(afe7689_status(i))
            self.addTestStep(afe7689_204b_status(i)) 
        
class AFE7689_TorDSA_Scan(TestCase):
    'AFE7689_TorDSA_Scan'

    def configTestStep(self):
        self.setTargetType('TRXM')
        for i in range(8):
            for j in range(20):
                self.addTestStep(afe7689_settordsa(j,1,5+j))
            self.addTestStep(afe7689_status(i))
            self.addTestStep(afe7689_204b_status(i))         
            
class DB_Save(TestCase):
    'Data base save test'

    def configTestStep(self):
        self.addTestStep(db_save("backup"))
        self.addTestStep(TRXM(db_save("backup")))

class Ddc_Duc_Gain(TestCase):
    'ddc_gain duc_gain test'

    def configTestStep(self):
        self.setTargetType('TRXM')
        for i in range(32):
            self.addTestStep(ducGain_set(i,-500))
            self.addTestStep(ducGain_get(i,-500))
            self.addTestStep(ddcGain_set(i,-400))
            self.addTestStep(ddcGain_get(i,-400))


class Carrier_Release(TestCase):
    'CARRIER_RELEASE'

    def configTestStep(self):
        self.addTestStep(carrier_list())
        self.addTestStep(carrier_release())
        self.addTestStep(carrier_list())

class RebootTC(TestCase):
    'RebootTC'

    def configTestStep(self):
        #self.addTestStep(SG_Restart())
        self.addTestStep(reboot_tc(0))
        

class UE_CPRI_PLUG_UNPLUG(TestCase):
    'UE_CPRI_PLUG_UNPLUG'

    def configTestStep(self):
        for i in range(10):
            self.log('Loop times : %d\n' % i)
            self.addTestStep(CT11_LineRateSet('LR2_5'))
            self.addTestStep(ue_cpri_unsync_TC2(TestFrame.trxmPos))
            self.addTestStep(CT11_LineRateSet('LR9_8'))
            self.addTestStep(ue_cpri_sync_TC2(TestFrame.trxmPos))
        self.addTestStep(CT11_CarrierAdd())
        self.addTestStep(CT11_CarrierSet())
        self.addTestStep(CT11_StartPlayback())

class VCA_CORR(TestCase):
    'VCA_CORR'

    def configTestStep(self):

#        self.setTargetType('TRXM')
                

        #self.addTestStep(TRXM(vca_off_all()))
        self.addTestStep(TRXM(vca_getcorr(16)))


class Check_PAP(TestCase):
    'Check_PAP'

    def configTestStep(self):

        self.addTestStep(check_pap(0x11c))
        self.addTestStep(TRXM(check_pap(0x146))) 


class RestartPC(TestCase):
    'VCA_CORR'

    def configTestStep(self):

#        self.setTargetType('TRXM')
                

        #self.addTestStep(TRXM(vca_off_all()))
        self.addTestStep(restartpctc())
