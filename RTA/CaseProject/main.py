import sysconfig
import os
import re
import matplotlib.pyplot as mat
import numpy as np
import time

def main(x,y):
    print("**************project start run**************\r\n")
    x = np.arange(1,100,0.1)
    y = np.sin(x)
    mat.plot(x,y)
    mat.ion()
    mat.pause(5)
    mat.close()
    print("\r\n**************project End run****************")
    #fdist.plot(30, cumulative=True)
if __name__ =="__main__":
    main(1,2)





