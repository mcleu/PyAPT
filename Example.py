# -*- coding: utf-8 -*-
"""
Example code showing how to control Thorlabs TDC Motors using PyAPT
V1.2
20141125 V1.0    First working version
20141201 V1.0a   Updated to short notation
20150324 V1.1    Added more descriptions
20150417 V1.2    Implemented motor without serial

Michael Leung
mcleung@stanford.edu
"""

# Import APTMotor class from PyAPT
from PyAPT import APTMotor
import time

# Create object corresponding to the motor.
Motor1 = APTMotor(83828393, HWTYPE=31) # The number should correspond to the serial number.
# Use help APTMotor to obtain full list of hardware (HW) supported.

# Note: You can control multiple motors by creating more APTMotor Objects


# Obtain current position of motor
print(Motor1.getPos())

# You can control multiple motors by creating more APTMotor Objects
# Serial numbers can be added later by using setSerialNumber and initializeHardwareDevice
# This functionality is particularly useful in the GUI setup.
Motor2 = APTMotor()
Motor2.setSerialNumber(83828393)
Motor2.initializeHardwareDevice()
print(Motor2.getPos())

# Move motor forward by 1mm, wait half a second, and return to original position.
# mRel is move relative. mAbs is move absolute (go to position xxx)
Motor1.mRel(1) # advance 1mm
time.sleep(.5)
Motor1.mRel(-1) # retract 1mm

time.sleep(1)

# Move motor forward by 1mm, wait half a second, and return to original position, at a velocity of 0.5mm/sec
motVel = 0.5 #motor velocity, in mm/sec
Motor1.mcRel(1, motVel) # advance 1mm
time.sleep(.5)
Motor1.mcRel(-1, motVel) # retract 1mm


# Clean up APT object, free up memory
Motor1.cleanUpAPT()
