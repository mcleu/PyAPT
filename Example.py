# -*- coding: utf-8 -*-
"""
Example code showing how to control Thorlabs TDC Motors using PyAPT


V1.0
20141125 V1.0    First working version
20141201 V1.0a   Updated to short notation

Michael Leung
mcleung@stanford.edu
"""

from PyAPT import APTMotor
import time

M1 = APTMotor(83828393) # The number should correspond to the serial number
# You can control multiple motors by creating more APTMotor Objects

print M1.getPos()

#Move back and forth
M1.mRel(1)
time.sleep(.5)
M1.mRel(-1)


#Move at controlled speed
time.sleep(1)
M1.mcRel(1, 0.5)
time.sleep(.5)
M1.mcRel(-1, 0.5)


M1.cleanUpAPT()