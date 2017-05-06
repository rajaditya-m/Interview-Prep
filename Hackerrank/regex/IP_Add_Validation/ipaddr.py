import re

pmipv4 = re.compile('^(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$')
pmipv6 = re.compile('^([0-9a-f]{1,4}):([0-9a-f]{1,4}):([0-9a-f]{1,4}):([0-9a-f]{1,4}):([0-9a-f]{1,4}):([0-9a-f]{1,4}):([0-9a-f]{1,4}):([0-9a-f]{1,4})$')

N = int(input())

for x in range(0,N):
	str = input()
	isipv4 = pmipv4.match(str)
	isipv6 = pmipv6.match(str)
	if(isipv4):
		print('IPv4')
	elif(isipv6):
		print('IPv6')
	else:
		print('Neither')


