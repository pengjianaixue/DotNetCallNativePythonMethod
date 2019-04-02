#!/usr/bin/python
# -*- coding: utf-8 -*-
import sys
from TestFrame import *
import TestFrame
from FormalTestCase import *
from SpecialTestCase import *
from SwitchBoxStep import *
import ruma
from ruma import *

# import CarrierTestCase
# from CarrierTestCase import *

# Board address
# TestFrame.address = '10.166.128.90'
TestFrame.address = '10.166.149.47'




# TestFrame.address = '192.168.1.16'
#TestFrame.address = '192.168.1.10'
# Target Type indicate the type of card which the address above point to , its value can be 'BP' 'TRXM', 
TestFrame.targetType = 'BP'
# trxmPos indicate the trxm card configured on BP, it only work when targetType = 'BP', 0 indicates trxm0, 1 indicates trxm1, 2 indicates both TRXM0&TRXM1 are configured
TestFrame.trxmPos = 0
# True indicates that this script is used by Jenkins, False for other senarios
TestFrame.usedInServer = False
TestFrame.debug = False


def Intergration(arg):
    timestamp = time.strftime('%Y_%m_%d_%H_%M_%S', time.localtime(time.time()))
    loadLabel = 'temp_'+timestamp
    testSuit = TestSuit(loadLabel)
    #testSuit.addTestCase(loadInstall(arg[1],arg[2],arg[3],arg[4]))
    
   # testSuit.addTestCase(DlSwitchBoxCase())

    #testSuit.addTestCase(SASetUpIQDataCase())

    #testSuit.addTestCase(UE_LTU_TC1())
    #testSuit.addTestCase(UE_CPRI_sync_TC2())
    #testSuit.addTestCase(UE_OAM_ILINK_TRXM0_TC3())
    #testSuit.addTestCase(UE_DATA_ILINK_TRXM0_TC5())

    #testSuit.addTestCase(LTU_TC1())
    #testSuit.addTestCase(CPRI_sync_TC2())
    #testSuit.addTestCase(OAM_ILINK_TRXM0_TC3())
    #testSuit.addTestCase(OAM_ILINK_TRXM1_TC4())
    #testSuit.addTestCase(DATA_ILINK_TRXM0_TC5())
    #testSuit.addTestCase(DATA_ILINK_TRXM1_TC6())
    #testSuit.addTestCase(JESD204B_TX_RX_TRXM0_TC7())
    #testSuit.addTestCase(JESD204B_TX_RX_TRXM1_TC8())
    #testSuit.addTestCase(CARRIER_CTRL())

    #testSuit.addTestCase(PWR_DUC_TC10())
    #testSuit.addTestCase(PWR_DPD_TC11())
    #testSuit.addTestCase(PWR_TOR_TC13())
    #testSuit.addTestCase(PWR_ADC_TC12())
    #testSuit.addTestCase(PWR_TOR_TC13())
    #testSuit.addTestCase(PWR_AGC_TC15())

    #dlRfAntPort = 0
    #testSuit.addTestCase(DL_1C_100M_64QAM_EVM(dlRfAntPort, loadLabel))
    testSuit.addTestCase(UpSwitchBoxCase())
    #testSuit.addTestCase(SASetUpACLRCase())

 
    dlRfAntPort = 0
    testSuit.addTestCase(UL_1C_100M_64QAM_EVM(dlRfAntPort, loadLabel))

    #testSuit.addTestCase(release_reboot())

    #testSuit.addTestCase(UpSwitchBoxCase())
    #testSuit.addTestCase(SASetUpACLRCase())

    #dlRfAntPort = 0
    #testSuit.addTestCase(UL_1C_100M_64QAM_EVM_TC21(dlRfAntPort, loadLabel))
##

    testSuit.run()


if __name__ == '__main__':
    Intergration(sys.argv)
