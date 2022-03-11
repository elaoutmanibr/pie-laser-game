import serial,time

class Player:
	def __init__(self, ID):
		self.ID = ID
		self.health = 100
		self.shots = 0 # tirs réussi
		self.is_paralysed = 0;
	
	def damage(self,D):
		self.health -= D
	
	def shot(self):
		self.shots += 1
	
	def touched(self, attackerID, playersList):
		self.health -= 40
		for l in playersList:
			if (l.ID==attackerID):
				l.shot()
				break
		return


if __name__ == '__main__':
	print('Running. Press CTRL-C to exit.')
	with serial.Serial("/dev/ttyACM0", 9600, timeout=1) as arduino:
		time.sleep(0.1) #wait for serial to open
		if arduino.isOpen():
			print("{} connected!".format(arduino.port))
			try:	
				nb = int(input("Nombre de joueurs:"))
				p = "Player"
				L = []
				
				#Creation de joueurs
				for i in range(nb):
					p += str(i)
					player = Player(p)
					L += [player]
					p = "Player"
				
				
				
				while True:
					cible = L[0]
					print(cible.ID ,"est l'arduino (cible)")
					print("Health : ", cible.health)
					attackerID = input("Vous êtes quel joueur ? ")
					cible.touched(attackerID,L)
					msg = "is_paralysed"
					arduino.write(msg.encode())
					time.sleep(3)
					msg = "off"
					arduino.write(msg.encode())
					time.sleep(0.1)
					if (cible.health<=0) :
						print("is killed")
						msg = "is_killed"
						arduino.write(msg.encode())
						time.sleep(1)
						msg = "off"
						arduino.write(msg.encode())
						time.sleep(1)
						msg = "is_killed"
						arduino.write(msg.encode())
						time.sleep(1)
						msg = "off"
						arduino.write(msg.encode())
						time.sleep(1)
						print("end")
						break
				
			except KeyboardInterrupt:
				print("KeyboardInterrupt has been caught.")
