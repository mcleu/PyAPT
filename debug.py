# -*- coding: utf-8 -*-
"""
Created on Mon Apr 13 11:18:48 2015

Michael Leung
mcleung@stanford.edu
"""

from ctypes import c_long, c_buffer, c_float, windll, pointer, WinError

# Return code 0 is success, 10005 is error
# Get error description by using WinError(ERRORNUM)
# WindowsError(0, 'The operation completed successfully.')

APT = windll.LoadLibrary('APTx86.dll')
print("DLL Loaded")
#print APT.EnableEventDlg(True)
#print("EventDialog True")
print APT.APTInit()

HWTYPE = 31


HWType = c_long(HWTYPE)
numUnits = c_long()
APT.GetNumHWUnitsEx(HWType, pointer(numUnits))


for ii in range(numUnits.value):
    HWSerialNum = c_long()
    hardwareIndex = c_long(ii)
    APT.GetHWSerialNumEx(HWType, hardwareIndex, pointer(HWSerialNum))
    print "SerialNo", ii
    print HWSerialNum.value


SERIALNUM = 83840946
SerialNum = c_long(SERIALNUM)
APT.InitHWDevice(SerialNum)


model = c_buffer(255)
softwareVersion = c_buffer(255)
hardwareNotes = c_buffer(255)
APT.GetHWInfo(SerialNum, model, 255, softwareVersion, 255, hardwareNotes, 255)
hwinfo = [model.value, softwareVersion.value, hardwareNotes.value]
print hwinfo