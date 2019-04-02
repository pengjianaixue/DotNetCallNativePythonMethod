#!/usr/bin/python
# -*- coding: utf-8 -*-
import os
if __name__ == '__main__':
    saFile = os.path.dirname(os.path.realpath(__file__)) + '\\' +'matlab'+'\\'+'DL_EVM'
    path=saFile.replace('\\','/' )
    print path
