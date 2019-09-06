import sys
import numpy as np

import time
# from numba import jit

def WirteLogToRTSTerminal(log=''):
    print(log)
    sys.stdout.flush()
    pass

if __name__ ==  '__main__':

    WirteLogToRTSTerminal("******************* EVM  Case  start ******************")
    WirteLogToRTSTerminal("Setup Carrier")
    time.sleep(1)
    WirteLogToRTSTerminal("Release Carrier")
    WirteLogToRTSTerminal("******************* EVM  Case  Finish*****************")

    pass