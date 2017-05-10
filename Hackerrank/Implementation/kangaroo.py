#Assume there exists 4 numbers x1,v1,x2,v2

x1 = 0
v1 = 3
x2 = 4
v2 = 2
n_int = None
n_div = None
if(v2-v1==0):
    if(x1==x2):
	    print('YES')
    else:
	    print('NO')
if(x2-x1<0 and v1-v2<0):
	n_int = (x1-x2)%(v2-v1)
	n_div = (x1-x2)/(v2-v1)
else:
    n_int = (x2-x1)%(v1-v2)
    n_div = (x2-x1)/(v1-v2)

print(n_int)
if (not n_int and n_div>0):
		print('YES')
else:
		print('NO')
