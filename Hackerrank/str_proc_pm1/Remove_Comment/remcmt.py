import re
import sys

startMult = re.compile('/\*')
endMult = re.compile('\*/')
simpleco = re.compile('//')

counter = 1
procMult = False
for line in sys.stdin:
	mstart = startMult.search(line)
	mend = endMult.search(line)
	hass = simpleco.search(line)
	ln = len(line)
	if(mstart and mend):
		print(line[mstart.start():mend.start()+2])
	elif(mstart):
		procMult = True
		print(line[mstart.start():ln-1])
	elif(mend):
		procMult = False
		print(line[:mend.start()+2])
	elif(hass):
		print(line[hass.start():ln-1])
	elif(procMult):
		print(line[:ln-1])
	

