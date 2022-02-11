#!/usr/bin/env python
# -*- coding: utf-8 -*-

'''
Envoi de données vers l'Arduino (série)
'''

import serial
import serial.tools.list_ports

arduino = serial.Serial("/dev/ttyACM0", 9600, timeout=1)

while True:
	answer=str(arduino.readline())
	if (answer):
		print(answer,"/n")


