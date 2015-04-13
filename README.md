PyAPT
=====
Controlling Thorlabs APT using Python code using APT.dll and APT.lib, bypassing the activex controls.

PyAPT Supports the following motors:

Motor | HWTYPE | Description
------|--------|----------------
BSC001 | 11 | 1 Ch benchtop stepper driver
BSC101 | 12	| 1 Ch benchtop stepper driver
BSC002 | 13 | 2 Ch benchtop stepper driver
BDC101 | 14 | 1 Ch benchtop DC servo driver
SCC001 | 21 | 1 Ch stepper driver card (used within BSC102,103 units)
DCC001 | 22 | 1 Ch DC servo driver card (used within BDC102,103 units)
ODC001 | 24 | 1 Ch DC servo driver cube
OST001 | 25 | 1 Ch stepper driver cube
MST601 | 26 | 2 Ch modular stepper driver module
TST001 | 29 | 1 Ch Stepper driver T-Cube
TDC001 | 31 | 1 Ch DC servo driver T-Cube
LTSXXX | 42 | LTS300/LTS150 Long Travel Integrated Driver/Stages
L490MZ | 43 | L490MZ Integrated Driver/Labjack
BBD10X | 44 | 1/2/3 Ch benchtop brushless DC servo driver

**Installation**

Obtain APT.dll and APT.lib from Thorlabs directly, or from the ```APTDLLPack/DLL/``` folder, picking the correct version (```x86``` or ```x64```)
Place APT.dll, APT.lib and PyAPT.py in the folder from which the scripts will be executed, or in the main add-on folder for python.
You also require ThorlabsAPT software (obtainable from [ThorLabs APT Software page](http://www.thorlabs.us/software_pages/ViewSoftwarePage.cfm?Code=APT) )

**Running the code**

Ensure correct version (32 or 64 bit) APT.dll and APT.lib are in the folder containing the python script.
[```example.py```](example.py) contains an example of how to load the module, control the motor, and close the object.

**References**

[ThorLabs APT Software page](http://www.thorlabs.us/software_pages/ViewSoftwarePage.cfm?Code=APT)
[ThorLabs APT Documentation page](http://www.thorlabs.us/software/apt/APT_Communications_Protocol_Rev_14.pdf)

**Contact**

This is still a rough copy that I am improving as I work on my project. Please report any bugs, and feel free to email me comments or suggestions. Even better: make the changes and push them back to me!

Michael Leung
mcleung@stanford.edu
