# -*- coding: utf-8 -*-
"""
Example code showing how to control Thorlabs TDC Motors using PyAPT


V1.0
20141125 V1.0    First working version 

Michael Leung
mcleung@stanford.edu
"""

from APTMotorDriverSingle import APTMotor
import time

M1 = APTMotor(83828393) # The number should correspond to the serial number
# You can control multiple motors by creating more APTMotor Objects

print M1.getPosition()

#Move back and forth
MSam.moveRelative(1)
time.sleep(.5)
MSam.moveRelative(-1)


#Move at controlled speed
time.sleep(1)
MSam.moveRelCon(1, 0.5)
time.sleep(.5)
MSam.moveRelCon(-1, 0.5)
