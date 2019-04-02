import socket
import time
import re
import os
try : #try to import matlab engine
  import matlab.engine
  is_mat_available = 1
except ImportError :
  is_mat_available = 0
  print "Warning: Matlab is not available!\n"
  pass


#################################################################
Version = "1.0"
#Provides below modules log capture:
##################################################################

# General write register method based on register list.

IP = "10.166.149.47"
port = 32002
# IP = "127.0.0.1"
# port = 23

reminder = { 'symbol_0_13_27': "Capture consecutive symbols by input x-y, x-y belongs to (0-13) or (14-27):\n" , 'symbol_0_13':"Capture consecutive symbols by input x-y, x-y belongs to (0-13):\n", 'branch_0_15_31' : "Capture consecutive branches by input x-y, x-y belongs to (0-15) or (16-31):\n",'branch_0_31' : "Capture consecutive branches by input x-y, x-y belongs to (0-31):\n", 'branch_0_15':"Capture consecutive branches by input x-y, x-y belongs to (0-15):\n" ,'layer_0_15': "Capture consecutive layers by input x-y, x-y belongs to (0-15):\n"}

def establish_socket () :
  s = socket.socket()
  print "connecting board ... ... ..."
  s.connect((IP, port))
  print "connect board successful"

  return s

#Define board ID based on whether need to capture TRXM log via BP.
def board_judge (via_bp) :

  global trxm_id_cmd, trxm_id, is_via_bp_wr
  if via_bp == "n" :
    trxm_id_cmd = ""
    trxm_id = ""
    is_via_bp_wr = "false"
  elif via_bp == "y" :
    is_via_bp_wr = "true"
    trxm = 0
    if trxm == 0 :
      trxm_id_cmd = "trxm 0"
      trxm_id = 0
    elif trxm == 1 :
      trxm_id_cmd = "trxm 1"
      trxm_id = 1
    else :
      print "Wrong trxm id input!!!"
      raw_input()
      main()
  else :
    print "Wrong input!!!"
    raw_input()
    main()

  return

#Define the logger start address based on DDR version or not.
def ddr_judge (ddr) :

  global addr_L1_bp,addr_L1_trxm

  if ddr == "y" :
    addr_L1_bp = "0xE1000000"
    addr_L1_trxm = "0xD1000000"
    is_via_bp = 'y'
    board_judge(is_via_bp)
  elif ddr == "n" :
    addr_L1_bp = "0xd1000000"
    addr_L1_trxm = "0XC1000000"
    board_judge("n")
  else :
    print ("Please input correct option!!!")
    main()

  return

#General write register method based on input register list.
def write_register (register_list,s) :

  i = 0

  while(i < len(register_list)):
    s.send(trxm_id_cmd + " " + "hwyFpga" + " " + "w" + " " + register_list[i] + " " +register_list[i+1] + "\n")
    print trxm_id_cmd + " " + register_list[i] + "  " + register_list[i+1]
    i = i + 2
    time.sleep(1)

  try :
    res = s.recv(10240)
  finally :
    s.close
    return

#General read register method based on input register list. Will return a list.
def read_register(register_list,s) :

  result = []
  i = 0
  time.sleep(2)
  while(i < len(register_list)):
    s.send(trxm_id_cmd + " " + "hwyFpga" + " " + "r" + " " + register_list[i] + "\n")
    time.sleep(1)
    res = s.recv(1024)
    result.append(res)

    i = i + 1
  s.close

  return result

#Verify whether TRXM L1 logger is triggered by "0x810e" register value.
def verify_logger_triggered(s) :

  res = read_register(["0x810e"],s)
  flag = "false"

  if re.search(r'0x1000000',res[0]) :
    flag = "true"

  return flag

#Verify whether BP logger is triggered by "0x60e" register value.
def verify_bp_logger_triggered(s) :

  res = read_register(["0x60e"],s)
  flag = "false"
  print res
  if int(res[0].split("0x")[3].split(".")[0],16)>>24 == 1 :
    flag = "true"

  return flag

def call_matlab (func) :
  print "Matlab is runing..."
  eng = matlab.engine.start_matlab()
  eng.func(nargout=0)

  return

#General split string method by "-".
def split_symbol (symbols) :

  p = re.compile(r'-')
  symbol_scope = p.split(symbols)

  symbol_start = int(symbol_scope[0])

  if len(symbol_scope) == 1 :
    symbol_end = symbol_start
  else :
    symbol_end = int(symbol_scope[1])

  return [symbol_start,symbol_end]

def log_transform (file_name,module) :

  transformed_file = open(file_name + '_transformed.txt','wb')
  original_file = open(file_name + '.txt',"rb")
  fsize = os.path.getsize(file_name + '.txt')
  if module == "legacy0" or module == "legacy1" :
    for i in range(int(fsize/4)):
      a = original_file.read(4)
      b = a[3] + a[2] + a[1] + a[0]
      transformed_file.write("0x" + b.encode('hex')+ "\n")
  else :
    for i in range(int(fsize/4)):
      
      a = original_file.read(4)
      b = a[3] + a[2] + a[1] + a[0]
      if i % int(fsize/4/20) == 0:
        recv_percent = round(i * 100 / (fsize/4))
        print str(recv_percent)+' %'
      transformed_file.write(b)
  print '100.0%'
  transformed_file.close()
  original_file.close()

  return

# General read loggeer method.
def read_logger (module_name,channel,symbol_i,s):

  timestamp = time.strftime("%Y-%m-%d_%H.%M.%S", time.localtime())
  filename = module_name + "_" + "channel"+ str(channel) + "_" + str(timestamp)
  regs = "0X10000"
  flash_area = "1"

  if symbol_i == "legacy0" : #Legacy branch 0-15
    saddr = "0XF0300000"
    mode = "2"
    regs = "0X40000"
  elif symbol_i == "legacy1" : #Legacy branch 16-31
    saddr = "0XF0400000"
    mode = "2"
    regs = "0X40000"
  elif symbol_i == "bp" : # For BP
    saddr = addr_L1_bp
    mode = "0"
    filename = 'C:/Users/test/PycharmProjects/nrv2/case/matlab/Cal_ul_delay_1cc/' + module_name + "_" + "channel" + str(channel)
  else :
    saddr = addr_L1_trxm
    mode = "0"
    filename = 'C:/Users/test/PycharmProjects/nrv2/case/matlab/Cal_ul_delay_1cc/' + module_name + "_" + "channel"+ str(channel) + "_" + "symbol" + symbol_i


  addr = long(saddr, 16)
  length = long(regs, 16)
  md = long(mode, 10)

  if md == 0:
    bytes = 4
  else :
    bytes = 12




  fd = open(filename + ".txt", "wb", 0)
  if is_via_bp_wr == "true" :

    s.send("bp_rd_trxm_mem " + str(trxm_id) + " " + flash_area + " " + saddr + " " + regs + "\n")
    bytes = 4
  else :
                s.send("readblock" + saddr + " " + regs + " " + mode + "\n")
  total_len = 0
  
  percent_prev = 0
  recv_percent = 0
 
  while True:
    data = s.recv(1024)
    
    if not data:
      break
    else :
      fd.write(data)
      total_len += len(data)

    if length*bytes <= total_len:
      break
    percent_prev = recv_percent
    recv_percent = round(total_len * 100 / (length*bytes))
    if recv_percent != percent_prev :
      print str(recv_percent)+'%'
  print '100.0%'
  time.sleep(2)
  
  fd.close()
  
  
  if is_via_bp_wr == "true" :
    print "transform data..."
    log_transform(filename,symbol_i)

  print "rx_sync capture done"
  print "file : ", filename+'_transformed.txt'
  return




#UL rx sync output
def rx_sync_output () :

  reg_list = ['0x0701','0x0','0x810b','0x00004000','0x810c','0x3fffffff','0x8201','0x00000004','0x8106','0x00002000','0x8109','0x00000000','0x810a','0x00000000','0x810d','0x00000000','0x810d','0x00000001']
  branch = '16'
  sf_num = 0
  slot_num = 0
  symbol = "0"
  module = "rx_sync_out" + "_sf" + str(sf_num) + "_slot" + str(slot_num)
  [branch_start,branch_end] = split_symbol(branch)
  
  s = establish_socket ()

  def loop_wr_symbol (branch,symbol_s,regs) :
    new_1e02_value = 0xF689
    [symbol_start,symbol_end] = split_symbol (symbol_s)
    while(symbol_start <= symbol_end) :
      regs[3] = hex((symbol_start<<16) + 0x4000 + (sf_num<<26) + (slot_num<<21)).rstrip("L")
      print 'write configuration...'
      write_register(regs,s)
      is_triggered = verify_logger_triggered(s)
      if is_triggered == "true" :
        print 'start reading logger...'
        read_logger (module,str(branch),str(symbol_start),s)
      else :
        print "error : logger is not triggered !!!"
        return 
      symbol_start = symbol_start + 1
    return
      


  reg_list[0] = "0x0781"
  reg_list[9] = "0x1400"
  
  
  reg_list[1] = hex(branch_start%16/2).rstrip("L")
  loop_wr_symbol (branch_start,symbol,reg_list)
  branch_start = branch_start + 2
  res = read_register(["0x1e02"],s)
  regx = "Value:"
  msg_list = res[0].split(regx)
  old_1e02_value = msg_list[-1].split(':')[0] 
  print 'REG 0x1e02 old value = ',old_1e02_value
  
  print 'Call matlab to calculate the new value of REG 0x1e02...'
  eng = matlab.engine.start_matlab()
  eng.path(eng.path(), r'C:/Users/test/PycharmProjects/nrv2/case/matlab/Cal_ul_delay_1cc')
  new_value = eng.TimeCorr1sym_cal(old_1e02_value)
  new_1e02_value = '0x' + new_value
  print 'REG 0x1e02 new value=',new_1e02_value
  write_register(["0x1e02",new_1e02_value],s)

  s.close
  print "Socket closed"
  

  return



def CalAndWriteRxSync() :

  print 'Capture RX_SYNC to Calculate the new value of REG 0x1e02...'
  print "Script Version: " + Version
  is_ddr = 'y'
  
  ddr_judge(is_ddr)
  rx_sync_output()

  return

if __name__ == "__main__":
    CalAndWriteRxSync()
