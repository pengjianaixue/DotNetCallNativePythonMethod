#!/usr/bin/python
# -*- coding: utf-8 -*-
import sys,os
sys.path.append('C:\\Users\\test\\PycharmProjects\\nrv2\\case')
from TestFrame import *
import TestFrame
from FormalTestCase import *
from SpecialTestCase import *
from SwitchBoxStep import *
import time

# import CarrierTestCase
# from CarrierTestCase import *

os.system("mount 10.166.128.28:/home/lteuser/jcat-log H:")
install=os.getenv("Install")
load_bp=os.getenv("load_bp.bin")
load_trxm=os.getenv("load_trxm.bin")
load_bp_Sre=os.getenv("load_bp.sre")
load_trxm_Sre=os.getenv("load_trxm.sre")


print "install=" + install
#if load_bp:
#print "load_bp name is : " + load_bp
#print "load_trxm name is : " + load_trxm
#print "load_bp_Sre name is : " + load_bp_Sre
#print "load_trxm_Sre name is : " + load_trxm_Sre

load_bp1="load_bp"
load_trxm1="load_trxm"

load_bp="load_bp.bin"
load_trxm="load_trxm.bin"
load_bp_Sre="load_bp.sre"
load_trxm_Sre="load_trxm.sre"

TestFrame.address = '10.166.149.47'
TestFrame.targetType = 'BP'
TestFrame.trxmPos = 0
TestFrame.usedInServer = False
TestFrame.debug = False
timestamp = time.strftime('%Y%m%d%H%M%S', time.localtime(time.time()))
TestFrame.timeDay= time.strftime('%Y%m%d', time.localtime(time.time()))

time.sleep(10)
loadLabel= ""
load_1=""
load_2=""
load_1_Sre=""
load_2_Sre=""

timestamp = time.strftime('%Y%m%d%H%M%S', time.localtime(time.time()))
TestFrame.timeDay= time.strftime('%Y%m%d', time.localtime(time.time()))
loadLabel = timestamp
needInstall = False
def LoadPathInit(arg):
    global load_1
    global load_2
    global load_1_Sre
    global load_2_Sre
    global needInstall
    loadPath="C:\\nrv2_ci\\workspace\\nrv2_RTT_manual_test\\"
    ATS = os.system("tasklist | findstr ATS").__str__()
    TSL = os.system("tasklist | findstr TSL").__str__()
    if ATS == 1 or TSL == 1:
        print "********* ATS OR TSL PROCESS NOT EXIST IN  WINDOWNS ************"
        sys.exit(1)
    if install != "false":
        print "*********** Need Install **************"
        load_1 = loadPath + load_bp
        load_2 = loadPath + load_trxm
        load_1_Sre =loadPath + load_bp_Sre
        load_2_Sre = loadPath + load_trxm_Sre
        loadlist=[load_1,load_2,load_1_Sre,load_2_Sre]
        print ("JOB_END_DESC: " + load_bp1 + "-" + load_trxm1)
        for load in loadlist :
            if not os.path.isfile(load):
                print("ERROR: Not found load :" + load)
                print ("******* PLS Upload pkg **********")
                sys.exit(1)
            else:
                needInstall= True
                print ("Found load :" + load)
    else:
                print ("Skip install load ")
    sys.stdout.flush()
        
	
    
def Intergration(arg):

    LoadPathInit(arg)
    #sys.exit(1)
    testSuit = TestSuit(loadLabel)
    if needInstall:
        print ("Start to install load ")
        sys.stdout.flush()
        #testSuit.addTestCase(loadInstall(load_1,load_1_Sre,load_2,load_2_Sre))
        
    #testSuit.addTestCase(DlSwitchBoxCase())
    testSuit.addTestCase(SASetUpIQDataCase())
    #testSuit.addTestCase(LTU_TC1())
    #testSuit.addTestCase(CPRI_sync_TC2())
    #testSuit.addTestCase(OAM_ILINK_TRXM0_TC3())
    #testSuit.addTestCase(OAM_ILINK_TRXM1_TC4())
    #testSuit.addTestCase(DATA_ILINK_TRXM0_TC5())
    #testSuit.addTestCase(DATA_ILINK_TRXM1_TC6())
    #testSuit.addTestCase(JESD204B_TX_RX_TRXM0_TC7())
    #testSuit.addTestCase(JESD204B_TX_RX_TRXM1_TC8())
    #testSuit.addTestCase(CARRIER_CTRL_TC9())

    #testSuit.addTestCase(PWR_DUC_TC10())

    #testSuit.addTestCase(PWR_DPD_TC11())
    #testSuit.addTestCase(PWR_TOR_TC13())
    #testSuit.addTestCase(PWR_ADC_TC12())
    #testSuit.addTestCase(PWR_TOR_TC13())
    #testSuit.addTestCase(PWR_AGC_TC15())

    #dlRfAntPort = 0
    #testSuit.addTestCase(DL_1C_100M_64QAM_EVM_TC21(dlRfAntPort, loadLabel))

    testSuit.addTestCase(UpSwitchBoxCase())
    testSuit.addTestCase(SASetUpACLRCase())

    #dlRfAntPort = 0
    #testSuit.addTestCase(UL_1C_100M_64QAM_EVM_TC21(dlRfAntPort, loadLabel))
    
    LOG_PATH="http://cdjcat28.cdlab.cn.ao.ericsson.se:9999/nrv2/log/" + TestFrame.address + "/" + TestFrame.timeDay + "/" +timestamp + "/" + "Summary.html"
    
    pop=open('temp.properties', 'w')
    pop.write("LOG_PATH=" + LOG_PATH + "\n" )
    pop.close()
    
    testSuit.run()
    
if __name__ == '__main__':
    Intergration(sys.argv)
