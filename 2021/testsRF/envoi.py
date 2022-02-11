#!/usr/bin/env python
# -*- coding: utf-8 -*-

'''
Envoi de données vers l'Arduino (série)
'''

import serial
import serial.tools.list_ports

arduino = serial.Serial("/dev/ttyACM0", 9600, timeout=1)
   
while True:
	message = str(input('message: '))
	arduino.write(message.encode())   # envoi du message série
	feedback = arduino.readline()[:-2]
	if feedback:
		print(feedback)
