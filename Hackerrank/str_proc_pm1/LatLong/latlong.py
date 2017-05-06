import re

N = int(input())

pm = re.compile("^\([+|-]?(([0-8]?[0-9](\.[0-9]+)?)|90(\.0+)?), ([+|-]?((1[0-7][0-9](\.[0-9]+)?)|([0-9]?[0-9](\.[0-9]+)?)|(180(\.0+)?)))\)$")

for i in range(N):
	line = input()
	haslat = pm.search(line)
	if(haslat):
		print("Valid")
	else:
		print("Invalid")