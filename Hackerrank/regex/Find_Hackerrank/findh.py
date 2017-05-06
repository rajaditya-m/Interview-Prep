import re

pmst = re.compile("^hackerrank(\W|$)")
pmend = re.compile("(\W|^)hackerrank$")

N = int(input())

for x in range(0,N):

	line = input()

	hasinstart = pmst.search(line)
	hasinend = pmend.search(line)

	if(hasinstart and hasinend):
		print('0')
	elif(hasinstart):
		print('1')
	elif(hasinend):
		print('2')
	else:
		print('-1')

