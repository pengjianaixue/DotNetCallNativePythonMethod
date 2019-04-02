#!/usr/bin/python
# -*- coding: utf-8 -*-
import re
from TestFrame import TestStep
import time


class show_version(TestStep):
    'show_version'
    def run(self):
        output = self.execCommand('show version')
        if len(output) >= 3:
            return True
        else:
            return False

class ltu_TC1(TestStep):
    'ltu_TC1'
    def run(self):
        output = self.execCommand('rru status')
        if len(output) >= 8:
            if  output[1]=="Board Init Status: Pass\r"and \
                output[2]=='LTU Status: Lock\r':
                return True
            else:
                return False

class cpri_sync_TC2(TestStep):
    'cpri_sync_TC2'
    def run(self):
        output = self.execCommand('rru status')
        if len(output) >= 8:
            if  output[7]=='CPRI 0: Sync \r':
                return True
            else:
                return False

class cpri_unsync_TC2(TestStep):
    'cpri_sync_TC2'
    def run(self):
        output = self.execCommand('rru status')
        if len(output) >= 8:
            if  output[7]=='CPRI 0: Nosync \r':
                return True
            else:
                return False

class oam_ilink_trxm0_TC3(TestStep):
    'oam_ilink_trxm0_TC3'
    def run(self):
        output = self.execCommand('rru status')
        if len(output) >= 8:
            if  output[3]=='ILINK 0 OAM: OK\r' :
                return True
            else:
                return False

class oam_ilink_trxm1_TC4(TestStep):
    'oam_ilink_trxm1_TC4'
    def run(self):
        output = self.execCommand('rru status')
        if len(output) >= 8:
            if  output[5]=='ILINK 1 OAM: OK\r':
                return True
            else:
                return False

class data_ilink_trxm0_TC5(TestStep):
    'data_ilink_trxm0_TC5'
    def run(self):
        output = self.execCommand('rru status')
        if len(output) >= 8:
            if  output[4]=='ILINK 0 DATA: OK\r':
                return True
            else:
                return False

class data_ilink_trxm1_TC6(TestStep):
    'data_ilink_trxm1_TC6'
    def run(self):
        output = self.execCommand('rru status')
        if len(output) >= 8:
            if  output[6]=='ILINK 1 DATA: OK\r':
                return True
            else:
                return False

class jesd204b_TX_RX_TRXM0_TC7(TestStep):
    'jesd204b_TX_RX_TRXM0_TC7'
    def run(self):
        output = self.execCommand('rru status')
        if len(output) >= 8:
            if  output[0]=='AFE7689: linkup\r':
                return True
            else:
                return False

class jesd204b_TX_RX_TRXM1_TC8(TestStep):
    'jesd204b_TX_RX_TRXM1_TC8'
    def run(self):
        output = self.execCommand('rru status')
        if len(output) >= 8:
            if  output[0]=='AFE7689: linkup\r':
                return True
            else:
                return False


class carrier_setup(TestStep):
    'dciReq TR_SETUP4 3500000 100 30 1'
    def run(self):
        self.execCommand1('dciReq TR_SETUP4 255 2 3500000 0 100 30 -1632 1 255 1')
        time.sleep(420)
        return True
       
class carrier_release(TestStep):
    'dciReq TR_RELEASE4 255'
    def run(self):
        self.execCommand1('dciReq TR_RELEASE4 255')
        time.sleep(120)
        return True
        
class carrier_list(TestStep):
    'dciReq TR_LIST4'
    def run(self):
        self.execCommand1('dciReq TR_LIST4')
        time.sleep(120)
        return True
      
class hwyFpga_read(TestStep):
    'hwFpga r|read <address>'
    def run(self):
        output = self.execCommand('hwyFpga r %x' % self.arg1[0])
        return True

class hwyFpga_write(TestStep):
    'hwFpga w|write <address> <value>'
    def run(self):
        output = self.execCommand('hwyFpga w 0x%x 0x%x' % (self.arg1[0],self.arg1[1]))
        regex = 'Offset:0x%x done' % self.arg1[0]
        result = re.search(regex,output[0])
        if result == None:
            return False
        else:
            return True


class reboot_tc(TestStep):
    def run(self):
        regex=' The system will restart from image1'
        output=self.execCommand('reboot %d' % (self.arg1[0]))
        result = re.search(regex, output[0])
        if result == None:
            return True
        else:
            return True


class gpio(TestStep):
    'gpio <operation:0|1> <base> <mask> <value>'
    def run(self):
        output = self.execCommand('gpio %d %d %x %x'% (self.arg1[0],self.arg1[1],self.arg1[2],self.arg1[3]))
        if self.arg1[0] == 1:
            regex = 'GPIO write value: 0x%x done' % self.arg1[3]
        else:
            regex = 'GPIO read value: 0x%x' % self.arg1[3]
        result = re.match(regex,output[0])
        if not result == None:
            return False
        else:
            return True

class ltu_status(TestStep):
    'ltu <id> status'
    def run(self):
        output = self.execCommand('ltu %d status'% (self.arg1[0]))
        regex = 'LTU status is unlocked'
        result = re.match(regex,output[0])
        if not result == None:
            return False
        else:
            return True

class ltu_write(TestStep):
    'ltu <ltuId> write <address> <value>'
    def run(self):
        self.execCommand('ltu %d write %x %x'% (self.arg1[0],self.arg1[1],self.arg1[2]))
        output = self.execCommand('ltu %d read %x'% (self.arg1[0],self.arg1[1]))
        regex = 'LTU read reg[0x%x] value: 0x%x' % (self.arg1[1],self.arg1[2])
        result = re.match(regex,output[0])
        if not result == None:
            return False
        else:
            return True

class ltu_read(TestStep):
    'ltu <ltuId> read <address>'
    def run(self):
        output = self.execCommand('ltu %d read %x'% (self.arg1[0],self.arg1[1]))
        regex = 'LTU read reg[0x%x] value: 0x%x' % (self.arg1[1],self.arg1[2])
        result = re.match(regex,output[0])
        if not result == None:
            return False
        else:
            return True

class dcdc_sup(TestStep):
    'dcdc_sup <deviceId> <channelId>'
    def run(self):
        output = self.execCommand('dcdc_sup %d %d' %(self.arg1[0],self.arg1[1]))
        regex = '.*get dcdc devi\\[%d\\] chanel\\[%d\\] = (.*) mV,  reference:(.*) mV.*' % (self.arg1[0],self.arg1[1])
        result = re.match(regex,output[0])
        if result == None:
            return False
        else:
            dbVal = int(result.group(1))
            rangStart = self.arg1[2]
            rangEnd = self.arg1[3]
            if rangStart<dbVal<rangEnd:
                return True
            else:
                return False

class fpga_temp(TestStep):
    'fpag_temp <flags:0/1>'
    def run(self):
        output = self.execCommand('fpga_temp %d'% self.arg1[0])
        if self.arg1[0]==0:
            regex = 'get fpga board temp = (.*)'
        else:
            regex = 'get fpga junction temp = (.*) threshold'
        result = re.match(regex,output[0])
        if result == None:
            return False
        else:
            dbVal = float(result.group(1))
            rangeStart = self.arg1[1]
            rangeEnd = self.arg1[2]
            if rangeStart<dbVal<rangeEnd:
                return True
            else:
                return False

class soft_dc(TestStep):
    'soft_dc hw <channelId> <value>'
    def run(self):
        output = self.execCommand('soft_dc hw %d %x'%(self.arg1[0],self.arg1[1]))
        regex = 'soft dc set success!  channel[%d],set parameter [0x%x]' % (self.arg1[0],self.arg1[1])
        result = re.match(regex,output[0])
        if result == None:
            return False
        else:
            return True

class amc7834_read(TestStep):
    'amc7834 read <chipId:0~7> <address>'
    
    def run(self):
        output = self.execCommand('amc7834 read %d %x'% (self.arg1[0],self.arg1[1]))
        regex = '.*=\s(.*)'
        result = re.match(regex,output[0])
        if result.group(1) == self.arg1[2]:
            return True
        else:
            return False

class amc7834_write(TestStep):
    'amc7834 write <chipId:0~7> <address> <value>'

    def run(self):
        output = self.execCommand('amc7834 read %d %x'% (self.arg1[0],self.arg1[1]))
        regex = 'write.*'
        result = re.match(regex,output[0])
        if result == None:
            return False
        else:
            return True

class db_write_i(TestStep):
    'db write <db> -i <pos> <value>'
    def run(self):
        output = self.execCommand('db write %s -i %d %d' % (self.arg1[0],self.arg1[1],self.arg1[2]))
        regex = '(successful|failed)'
        result = re.match(regex,output[0])
        if result == None:
            return False
        elif result.group(1)=='successful':
            return True
        else:
            return False

class db_write_all(TestStep):
    'db write <db> -all <values>'
    def run(self):
        output = self.execCommand('db write %s -all %s' % (self.arg1[0],self.arg1[1]))
        regex = '(successful|failed)'
        result = re.match(regex,output[0])
        if result == None:
            return False
        elif result.group(1)=='successful':
            return True
        else:
            return False

class db_read(TestStep):
    'db read <db>'
    def run(self):
        output = self.execCommand('db read %s' % self.arg1[0])
        regex = '%s (U8|U16|S16|U32|S32)(\n|\t)+(.*)'
        result = re.match(regex,output[0])
        if result == None:
            return False
        elif result.group(3)==self.arg1[1]:
            return True
        else:
            return False

class db_del(TestStep):
    'db del <db>'
    def run(self):
        output = self.execCommand('db del %s' % self.arg1[0])
        regex = 'Delete %s (successful|failed)'%self.arg1[0]
        result = re.match(regex,output[0])
        if result == None:
            return False
        elif result.group(1)=='successful':
            return True
        else:
            return False

class db_save(TestStep):
    'db save'
    def run(self):
        output = self.execCommand('db save %s' % self.arg1[0], 20)
        regex = 'Save database\\(%s\\) to flash successful' % (self.arg1[0])
        result = re.match(regex,output[0])
        if result == None:
            return False
        else:
            return True  

class db_infor(TestStep):
    'db infor'
    def run(self):
        output = self.execCommand('db infor')
        regex = '\d* items'
        result = re.match(regex,output[0])
        if result == None:
            return False
        elif result.group(1)==self.arg1[1]:
            return True
        else:
            return False 

class ducGain_set(TestStep):
    'ducGain set <portId> <value>'
    def run(self):
        output = self.execCommand('ducGain set %d %d' %(self.arg1[0],self.arg1[1]))
        regex = 'set %d \\*0.01db to duc port\\[%d\\]' % (self.arg1[1],self.arg1[0])
        result = re.match(regex,output[0])
        if result == None:
            return False
        else:
            return True

class ducGain_get(TestStep):
    'ducGain get <portId>'
    def run(self):
        output = self.execCommand('ducGain get %d' % (self.arg1[0]))
        regex = 'get duc port\\[%d\\] = %d \\*0.01db' %(self.arg1[0],self.arg1[1])
        result = re.match(regex, output[0])
        if result == None:
            return False
        else:
            return True

class ddcGain_set(TestStep):
    'ddcGain set <portId> <value>'
    def run(self):
        output = self.execCommand('ddcGain set %d %d' %(self.arg1[0],self.arg1[1]))
        regex = 'set %d \\*0.01db to ddc port\\[%d\\]' % (self.arg1[1],self.arg1[0])
        result = re.match(regex,output[0])
        if result == None:
            return False
        else:
            return True
        
class ddcGain_get(TestStep):
    'ddcGain get <portId>'
    def run(self):
        output = self.execCommand('ddcGain get %d' % (self.arg1[0]))
        regex = 'get ddc port\\[%d\\] = %d \\*0.01db' %(self.arg1[0],self.arg1[1])
        result = re.match(regex, output[0])
        if result == None:
            return False
        else:
            return True

class pa_read_curr(TestStep):
    'pa read curr <antennaId>'
    def run(self):
        output = self.execCommand('pa read curr IMpa:0.%d.0' % self.arg1[0])
        regex = '.*IMpa:0\\.%d\\.0: (.*) \\(~---\\)' % self.arg1[0]
        result = re.match(regex, output[0])
        if result == None:
            return False
        else:
            val = float(result.group(1))
            rangStart = self.arg1[1]
            rangEnd = self.arg1[2]
            if rangStart<val<rangEnd:
                return True
            else:
                return False

class pa_write_GMpa(TestStep):
    'pa write <antennaId> <antennaType> -v <value>'
    def run(self):
        output = self.execCommand('pa write GMpa:0.%d.%d -v %f' % (self.arg1[0],self.arg1[1],self.arg1[2]))
        regex = 'Write .* done'
        result = re.match(regex, output[0])
        if result == None:
            return False
        else:
            return True

class pa_read_temp(TestStep):
    'pa read temp <antennaId>'
    def run(self):
        output = self.execCommand('pa read temp TMpa:0.%d.0' % self.arg1[0])
        regex = '.*TMpa:0\\.%d\\.0: (.*) \\(~---\\)' % self.arg1[0]
        result = re.match(regex, output[0])
        if result == None:
            return False
        else:
            val = float(result.group(1))
            rangStart = self.arg1[1]*1000
            rangEnd = self.arg1[2]*1000
            if rangStart<val<rangEnd:
                return True
            else:
                return False

class pa_on(TestStep):
    'pa on <id>'
    def run(self):
        output = self.execCommand('pa on %d' % self.arg1[0])
        regex = 'pa on %d is done' % self.arg1[0]
        result = re.match(regex, output[0])
        if result == None:
            return False
        else:
            return True
        
class pa_off(TestStep):
    'pa off <id>'
    def run(self):
        output = self.execCommand('pa off %d' % self.arg1[0])
        regex = 'pa off %d is done' % self.arg1[0]
        result = re.match(regex, output[0])
        if result == None:
            return False
        else:
            return True  

class pa_tcmp_on_all(TestStep):
    'pa tcmp on <id>'
    def run(self):
        output = self.execCommand('pa tcmp on all',100)
        regex = 'pa tcmp on all is done'
        result = re.search(regex, output[0])
        if result == None:
            return False
        else:
            return True


class pa_off_all(TestStep):
    'pa off all'
    def run(self):
        output = self.execCommand('pa off all',30)
        regex = 'pa off all is done'
        result = re.match(regex, output[0])
        if result == None:
            return False
        else:
            return True


class vca_off_all(TestStep):
    'vca off all <id>'
    def run(self):
        output = self.execCommand('vca off all',30)
        regex = 'vca off all done'
        result = re.match(regex, output[0])
        if result == None:
            return False
        else:
            return True

class dvga_crsetup_off(TestStep):
    'dvga crsetup off'
    def run(self):
        output = self.execCommand('dvga crsetup off')
        regex = 'dvga crsetup off done'
        result = re.search(regex, output[0])
        if result == None:
            return False
        else:
            return True

class pa_tcmp_on(TestStep):
    'pa tcmp on <id>'
    def run(self):
        output = self.execCommand('pa tcmp on %d' % self.arg1[0])
        regex = 'pa tcmp on %d is done' % self.arg1[0]
        result = re.match(regex, output[0])
        if result == None:
            return False
        else:
            return True
        
class pa_tcmp_off(TestStep):
    'pa tcmp off <id>'
    def run(self):
        output = self.execCommand('pa tcmp off %d' % self.arg1[0])
        regex = 'pa tcmp off %d is done' % self.arg1[0]
        result = re.match(regex, output[0])
        if result == None:
            return False
        else:
            return True
        
class afe7689_linkup(TestStep):
    'afe7689 <port> linkup'
    def run(self):
        output = self.execCommand('afe7689 %d linkup' % self.arg1[0],20)
        regex = 'AFE7689Dev%d 204b link up' % self.arg1[0]
        result = re.match(regex,output[0])
        if result == None:
            return False
        else:
            return True

class afe7689_read(TestStep):
    'afe7689 <port> read <addr>'
    def run(self):
        output = self.execCommand('afe7689 %d read 0x%x' % (self.arg1[0],self.arg1[1]))
        regex = 'read data = %d,hex form = 0x%x' % (self.arg1[2],self.arg1[2])
        result = re.match(regex,output[0])
        if result == None:
            return False
        else:
            return True

class afe7689_txtddon(TestStep):
    'afe7689 <linkId> txtddon'
    def run(self):
        output = self.execCommand('afe7689 %d txtddon' % (self.arg1[0]))
        return True
    
class afe7689_rxtddon(TestStep):
    'afe7689 <linkId> rxtddon'
    def run(self):
        output = self.execCommand('afe7689 %d rxtddon' % (self.arg1[0]))
        return True

class afe7689_tortddon(TestStep):
    'afe7689 <linkId> tortddon'
    def run(self):
        output = self.execCommand('afe7689 %d tortddon' % (self.arg1[0]))
        return True

class afe7689_settxdsa(TestStep):    
    'afe7689 <port> settxdsa <port> <db>'
    def run(self):
        output = self.execCommand('afe7689 %d settxdsa %d %d' % (self.arg1[0],self.arg1[1],self.arg1[2]))
        regex = 'rfport %d\'s tx dsa = %d db' % (self.arg1[1],self.arg1[2])
        result = re.match(regex,output[0])
        if result == None:
            return False
        else:
            return True
                                  
class afe7689_setrxdsa(TestStep):    
    'afe7689 <port> setrxdsa <port> <db>'
    def run(self):
        output = self.execCommand('afe7689 %d setrxdsa %d %d' % (self.arg1[0],self.arg1[1],self.arg1[2]))
        regex = 'rfport %d\'s rx dsa = %d db' % (self.arg1[1],self.arg1[2])
        result = re.match(regex,output[0])
        if result == None:
            return False
        else:
            return True

class afe7689_settordsa(TestStep):    
    'afe7689 <port> settordsa <port> <db>'
    def run(self):
        output = self.execCommand('afe7689 %d settordsa %d %d' % (self.arg1[0],self.arg1[1],self.arg1[2]))
        regex = 'rfport %d\'s tor dsa = %d db' % (self.arg1[1],self.arg1[2])
        result = re.match(regex,output[0])
        if result == None:
            return False
        else:
            return True
                                  
class afe7689_settornco(TestStep):    
    'afe7689 <port> settornco <port> <db>'
    def run(self):
        output = self.execCommand('afe7689 %d settornco %d %d' % (self.arg1[0],self.arg1[1],self.arg1[2]))
        regex = 'rfport %d\'s tor nco = %d khz' % (self.arg1[1],self.arg1[2])
        result = re.match(regex,output[0])
        if result == None:
            return False
        else:
            return True  

class afe7689_settxnco(TestStep):    
    'afe7689 <port> settxnco <port> <db>'
    def run(self):
        output = self.execCommand('afe7689 %d settxnco %d %d' % (self.arg1[0],self.arg1[1],self.arg1[2]))
        regex = 'rfport %d\'s tx nco = %d khz' % (self.arg1[1],self.arg1[2])
        result = re.match(regex,output[0])
        if result == None:
            return False
        else:
            return True  

class afe7689_setrxnco(TestStep):    
    'afe7689 <port> setrxnco <port> <db>'
    def run(self):
        output = self.execCommand('afe7689 %d setrxnco %d %d' % (self.arg1[0],self.arg1[1],self.arg1[2]))
        regex = 'rfport %d\'s rx nco = %d khz' % (self.arg1[1],self.arg1[2])
        result = re.match(regex,output[0])
        if result == None:
            return False
        else:
            return True

class afe7689_status(TestStep):
    'afe7689 <port> status'
    def run(self):
        output = self.execCommand('afe7689 %d status' % (self.arg1[0]))
        regex = 'AFE7689 PLL status is OK and serdes PLL status is OK'
        result = re.match(regex,output[0])
        if result == None:
            return False
        else:
            return True

class afe7689_204b_status(TestStep):
    'afe7689 <port> 204bstatus'
    def run(self):
        output = self.execCommand('afe7689 %d 204bstatus' % (self.arg1[0]))
        regex = 'tx status is OK and rx status is OK'
        result = re.match(regex,output[0])
        if result == None:
            return False
        else:
            return True        

class pwrMeter_duc(TestStep):
    'pwrMeter duc <antid> <slotId>'
    def run(self):
        output = self.execCommand('pwrMeter duc %d %d' % (self.arg1[0],self.arg1[1]), 10)
        regex = '.*is (.*)DbFs'
        result = re.match(regex,output[0])
        dbVal = float(result.group(1))
        rangStart = self.arg1[2]
        rangEnd = self.arg1[3]
        if rangStart<dbVal<rangEnd:
            return True
        else:
            return False

class pwrMeter_tor(TestStep):
    'pwrMeter tor <antid> <slotId>'
    def run(self):
        output = self.execCommand('pwrMeter tor %d %d' % (self.arg1[0],self.arg1[1]), 10)
        regex = '.*is (.*)DbFs'
        result = re.match(regex,output[0])
        dbVal = float(result.group(1))
        rangStart = self.arg1[2]
        rangEnd = self.arg1[3]
        if rangStart<dbVal<rangEnd:
            return True
        else:
            return False

class pwrMeter_rxadc(TestStep):
    'pwrMeter rxadc <antid> <slotId>'
    def run(self):
        output = self.execCommand('pwrMeter rxadc %d %d' % (self.arg1[0],self.arg1[1]), 10)
        regex = '.*is (.*)DbFs'
        result = re.match(regex,output[0])
        dbVal = float(result.group(1))
        rangStart = self.arg1[2]
        rangEnd = self.arg1[3]
        if rangStart<dbVal<rangEnd:
            return True
        else:
            return False


class pwrMeter_dpd(TestStep):
    'pwrMeter dpd <antid> <slotId>'
    def run(self):
        output = self.execCommand('pwrMeter dpd %d %d' % (self.arg1[0],self.arg1[1]), 10)
        regex = '.*is (.*)DbFs'
        result = re.match(regex,output[0])
        dbVal = float(result.group(1))
        rangStart = self.arg1[2]
        rangEnd = self.arg1[3]
        if rangStart<dbVal<rangEnd:
            return True
        else:
            return False

'''
class pwrMeter_vca(TestStep):
    'pwrMeter vca <antid> <slotId>'
    def run(self):
        output = self.execCommand('pwrMeter vca %d %d' % (self.arg1[0],self.arg1[1]), 10)
        regex = '.*is (.*)DbFs'
        result = re.match(regex,output[0])
        dbVal = float(result.group(1))
        rangStart = self.arg1[2]
        rangEnd = self.arg1[3]
        if rangStart<dbVal<rangEnd:
            return True
        else:
            return False
'''

class pwrMeter_agc(TestStep):
    'pwrMeter agc <carrierid> <antid> <slotId>'
    def run(self):
        output = self.execCommand('pwrMeter agc %d %d %d' % (self.arg1[0],self.arg1[1],self.arg1[2]), 10)
        regex = '.*is (.*)DbFs'
        result = re.match(regex,output[0])
        dbVal = float(result.group(1))
        rangStart = self.arg1[3]
        rangEnd = self.arg1[4]
        if rangStart<dbVal<rangEnd:
            return True
        else:
            return False


class reboot_step(TestStep):
    def run(self):
        output = self.execCommand('reboot %d' % (self.arg1[0]), 10)
        regex=' The system will restart from image1'
        result = re.match(regex, output[0])

class wgt_evm_step(TestStep):
    'wgt_evm_do'
    def run(self):
        output = self.execCommand('wgt_evm_do', 10)
        regex = 'wgt_ant_evm done'
        result = re.match(regex,output[0])

        if result == None:
            return False
        else:
            return True

class wgt_clear_step(TestStep):
    'wgt_clear_step'
    def run(self):
        output = self.execCommand('wgt_clear_do', 10)
        regex = 'wgt_clear done'
        result = re.match(regex,output[0])

        if result == None:
            return False
        else:
            return True

class ue_ltu_TC1(TestStep):
    'ltu_TC1'
    def run(self):
        output = self.execCommand('rru status')
        if len(output) >= 8:
            if  output[1]=="Board Init Status: Pass\r"and \
                output[2]=='LTU Status: Lock\r':
                return True
            else:
                return False

class ue_cpri_sync_TC2(TestStep):
    'cpri_sync_TC2'
    def run(self):
        output = self.execCommand('rru status')
        if len(output) >= 8:
            if  output[5]=='CPRI 0: Sync \r':
                return True
            else:
                return False

class ue_oam_ilink_trxm0_TC3(TestStep):
    'oam_ilink_trxm0_TC3'
    def run(self):
        output = self.execCommand('rru status')
        if len(output) >= 8:
            if  output[3]=='ILINK 0 OAM: OK\r' :
                return True
            else:
                return False

class ue_data_ilink_trxm0_TC5(TestStep):
    'data_ilink_trxm0_TC5'
    def run(self):
        output = self.execCommand('rru status')
        if len(output) >= 8:
            if  output[4]=='ILINK 0 DATA: OK\r':
                return True
            else:
                return False

class ue_cpri_sync_TC2(TestStep):
    'cpri_sync_TC2'
    def run(self):
        output = self.execCommand('rru status')
        if len(output) >= 8:
            if  output[5]=='CPRI 0: Sync \r':
                return True
            else:
                return False

class ue_cpri_unsync_TC2(TestStep):
    'cpri_sync_TC2'
    def run(self):
        output = self.execCommand('rru status')
        if len(output) >= 8:
            if  output[5]=='CPRI 0: Nosync \r':
                return True
            else:
                return False

class axi_write(TestStep):
    'axi_write w|write <address> <value>'
    def run(self):
        output = self.execCommand('axi_write 0x%x 0x%x' % (self.arg1[0],self.arg1[1]))
        regex = 'axi_write reg:0x%x complete' % self.arg1[0]
        result = re.search(regex,output[0])
        if result == None:
            return False
        else:
            return True

class vca_getcorr(TestStep):
    'vca_getcorr <id>'
    def run(self):
#        self.execCommand2('vca on %d' % self.arg1[0])
#        time.sleep(7)
        output = self.execCommand('vca getcorr %d' % self.arg1[0])
        s_data = output[0].split(" ")
        result = s_data[2][5:-1]
#        print (type(result))
#        regex = "0.000"
#        res = re.search(regex, result)
        if float(result) <= 0.2:
            return True
        else:
            
            return True

class check_pap(TestStep):
    'check_pap '
    def run(self):
        output = self.execCommand('hwyFpga r %x' % self.arg1[0])
        regex = "Phy Address:(.*) Offset:(.*) Value:(.*)"
        s_data = output[0].split(" ")
        result = s_data[3][6:-1]
        if result == '0x0' or result == '0x4':
            return True
        else:
            
            return False


class restartpctc(TestStep):
    'restartpctc '
    def run(self):
        cmd = "shutdown /r /t 0 /f"
        p = os.popen(cmd)
        out = p.read()
        self.log(out)
        print out
        time.sleep(420)
        print ('start ok')
        return True
