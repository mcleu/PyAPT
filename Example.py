# -*- coding: utf-8 -*-
"""
Example code showing how to control Thorlabs TDC Motors using PyAPT


V1.0
20141125 V1.0    First working version
20141201 V1.0a   Updated to short notation
20150324 V1.1    Added more descriptions

Michael Leung
mcleung@stanford.edu
"""

# Import APTMotor class from PyAPT
from PyAPT import APTMotor
import time

# Create object corresponding to the motor.
M1 = APTMotor(83828393, HWTYPE=31) # The number should correspond to the serial number.
# Use help APTMotor to obtain full list of hardware (HW) supported.

# Note: You can control multiple motors by creating more APTMotor Objects


# Obtain current position of motor
print M1.getPos()

# Move motor forward by 1mm, wait half a second, and return to original position.
# mRel is move relative. mAbs is move absolute (go to position xxx)
M1.mRel(1) # advance 1mm
time.sleep(.5)
M1.mRel(-1) # retract 1mm

time.sleep(1)

# Move motor forward by 1mm, wait half a second, and return to original position, at a velocity of 0.5mm/sec
motVel = 0.5 #motor velocity, in mm/sec
M1.mcRel(1, motVel) # advance 1mm
time.sleep(.5)
M1.mcRel(-1, motVel) # retract 1mm


# Clean up APT object, free up memory
M1.cleanUpAPT()
