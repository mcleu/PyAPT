# -*- coding: utf-8 -*-
"""
APT Motor Controller GUI for Thorlabs

V1.0
20150417 V1.0    First working version

Michael Leung
mcleung@stanford.edu
"""
DEBUG = True

#Title: OpenFFOCT
version='1.0'
#Date: April 17, 2015
#Python Version 2.7.9


import os
import platform
import sys
from PyQt4.QtCore import *
from PyQt4.QtGui import *

import numpy as np
import struct
import time
# import multiprocessing


from PyAPT import APTMotor
# TODO: Implement multiprocess and OpenCL
#MULTIPROCESS = False
#USEOCL = False
class MainWindow(QMainWindow):
    def __init__(self, parent=None):
        """
        Main window
        """
        self.setWindowTitle("OpenFFOCT "+version)

        #Set central widget - Main Scan window
        self.mainWindow = MainScanWindow(self.dataObject)
        self.setCentralWidget(self.mainWindow)

        #Set main toolbar
        mainToolBar = self.addToolBar("Tools")


    def closeEvent(self, event):
        """
        Clean up child widgets before exit
        1) Close the active COM port before application exit
        2) Kill the child process if MULTIPROCESS is True
        """
        self.mcuWidget.MCU.close()
        self.mainWindow.dataObject.terminate()

        event.accept()

class widgetAPT(QWidget):
    def __init__(self, parent = None, serial=00000000):
        super(widgetAPT, self).__init__(parent)
        self.resize(200, 200)
        #self.move(100, 100)
        #setGeometry sets both location and size
        #self.setGeometry(50, 50, 1180, 900)
        self.setWindowTitle('APT Motor')
        #self.m = APTMotor(0)

        # QT GridLayout
        # TODO: Implement GridLayout
        #grid = QGridLayout()

        # Layout objects
        sAuthor = QLabel("QT-APT", self)
        sAuthor.resize(100, 20)
        sAuthor.move(100, 0)
        sAuthor.setAlignment(Qt.AlignRight)
        sVersion = QLabel("v1.0.0", self)
        sVersion.resize(100, 20)
        sVersion.move(100, 15)
        sVersion.setAlignment(Qt.AlignRight)
        sEmail = QLabel("Michael Leung", self)
        sEmail.resize(100, 40)
        sEmail.move(100, 35)
        sEmail.setAlignment(Qt.AlignRight)


        # Motor Serial Number
        sSer = QLabel("Serial:", self)
        sSer.resize(60, 20)
        sSer.move(0, 0)
        self.txtSerial = QSpinBox(self)
        self.txtSerial.resize(70,20)
        self.txtSerial.move(30,0)
        self.txtSerial.setRange(0, 99999999)
        self.txtSerial.setSingleStep(1)
        self.txtSerial.setValue(83840946)
        # qle.textChanged[str].connect(self.onChanged) #do onChanged when changed
        self._Motor_ = APTMotor()

        # Motor Connect
        self.btnConnect = QPushButton("Connect", self)
        self.btnConnect.setStyleSheet("background-color: grey")
        self.btnConnect.setText("Connect")
        self.btnConnect.setCheckable(True)
        self.btnConnect.setToolTip("Connect to Motor")
        self.btnConnect.resize(50, 20)
        self.btnConnect.move(105, 0)
        self.btnConnect.clicked[bool].connect(self.connectAPT)

        sPos = QLabel("Pos:", self)
        sPos.resize(60, 20)
        sPos.move(0, 25)
        self.txtPos = QDoubleSpinBox(self)
        self.txtPos.resize(60, 20)
        self.txtPos.move(30, 25)
        #self.txtPos.setMaxLength(7)
        self.txtPos.setRange(0, 20)
        self.txtPos.setSingleStep(.1)
        self.txtPos.setDecimals(5)
        self.txtPos.setValue(0.0000000)
        self.txtPos.setToolTip("Current Motor Position")
        #self.txtPos.setValidator( QDoubleValidator(0, 100, 2) )
        self.txtPos.setEnabled(False)

        # Go to position
        btnGOp = QPushButton("Go", self)
        btnGOp.resize(25, 20)
        btnGOp.move(95, 25)
        btnGOp.clicked.connect(lambda: self.motAbs(float(self.txtPos.text())))

        # Movement buttons
        btnN3 = QPushButton("-100", self)
        btnN3.resize(30, 20)
        btnN3.move(0, 50)
        btnN3.clicked.connect(lambda: self.motRel(-.1))

        btnN2 = QPushButton("-10", self)
        btnN2.resize(30, 20)
        btnN2.move(30, 50)
        btnN2.clicked.connect(lambda: self.motRel(-.01))

        btnN1 = QPushButton("-1", self)
        btnN1.resize(30, 20)
        btnN1.move(60, 50)
        btnN1.clicked.connect(lambda: self.motRel(-.001))

        btnP1 = QPushButton("+1", self)
        btnP1.resize(30, 20)
        btnP1.move(100, 50)
        btnP1.clicked.connect(lambda: self.motRel(.001))

        btnP2 = QPushButton("+10", self)
        btnP2.resize(30, 20)
        btnP2.move(130, 50)
        btnP2.clicked.connect(lambda: self.motRel(.01))

        btnP3 = QPushButton("+100", self)
        btnP3.resize(30, 20)
        btnP3.move(160, 50)
        btnP3.clicked.connect(lambda: self.motRel(.1))


        sVel = QLabel("Vel:", self)
        sVel.resize(60, 20)
        sVel.move(0, 75)
        self.txtVel = QDoubleSpinBox(self)
        self.txtVel.resize(60, 20)
        self.txtVel.move(30, 75)
        #self.txtVel.setMaxLength(7)
        self.txtVel.setRange(0, 2.2)
        self.txtVel.setSingleStep(.1)
        self.txtVel.setValue(0.00000)
        self.txtVel.setToolTip("Current Motor Position")
        self.txtVel.setEnabled(False)
        # Go to velocity
        btnGOv = QPushButton("Go", self)
        btnGOv.resize(25, 20)
        btnGOv.move(95, 75)
        btnGOv.clicked.connect(lambda: self._Motor_.setVel(float(self.txtVel.text())))

        sBack = QLabel("Backlash:", self)
        sBack.resize(60, 20)
        sBack.move(130, 75)
        self.cbBacklash = QCheckBox(self)
        self.cbBacklash.resize(60, 20)
        self.cbBacklash.move(180, 75)


        self.show()

    def connectAPT(self, pressed):
        if pressed:
            #APT Motor connect
            Serial = int(self.txtSerial.text())
            self._Motor_.setSerialNumber(Serial)
            self._Motor_.initializeHardwareDevice()

            # Success
            self.btnConnect.setStyleSheet("background-color: green")
            self.btnConnect.setText("Connected")

            self.txtSerial.setEnabled(False)
            self.txtPos.setEnabled(True)
            # Update text to show position
            self.txtPos.setValue( self._Motor_.getPos() )

            self.txtVel.setEnabled(True)
            _, _, maxVel = self._Motor_.getVelocityParameters()
            self.txtVel.setValue( maxVel )

            return True
        else:
            #APT Motor disconnect
            self._Motor_.cleanUpAPT()
            # Success
            self.btnConnect.setStyleSheet("background-color: grey")
            self.btnConnect.setText("Connect")

            self.txtSerial.setEnabled(True)
            self.txtPos.setEnabled(False)
            self.txtVel.setEnabled(False)
            self.txtPos.setValue(0.0000)
            self.txtPos.setToolTip("Current Motor Position")
            return True

    def motRel(self, relDistance):
        if self.cbBacklash.isChecked() :
            self._Motor_.mbRel(relDistance)
        else:
            self._Motor_.mRel(relDistance)
        # Update text to show position
        self.txtPos.setValue( self._Motor_.getPos() )

    def motAbs(self, absDistance):
        if self.cbBacklash.isChecked() :
            self._Motor_.mbAbs(absDistance)
        else:
            self._Motor_.mAbs(absDistance)
        # Update text to show position
        self.txtPos.setValue( self._Motor_.getPos() )

if __name__ == '__main__':
    app = QApplication(sys.argv)
    #splash_pix = QPixmap('')
    #splash = QSplashScreen(splash_pix, Qt.WindowStaysOnTopHint)
    #splash.show()
    form = widgetAPT()
    #form.setWindowState(Qt.WindowMaximized)
    #form.show()
    #splash.finish(form)
    sys.exit(app.exec_())
