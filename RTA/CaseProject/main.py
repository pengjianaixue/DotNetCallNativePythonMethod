import sys
import numpy as np
import matplotlib.pyplot as pt
def main(a,b):
    x = np.arange(0,5,0.1)
    y = np.sin(x)
    pt.plot(x,y)
    pt.ion()
    pt.pause(3)
    pt.close()
    return str(a +b)

if __name__ ==  '__main__':
    print("this is test case demo ")
    main(1, 2)
    print("python run finish")
    pass