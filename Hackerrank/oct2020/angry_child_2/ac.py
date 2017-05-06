import itertools

def dVal(x):
	K = len(x)
	sum = 0
	for i in range(0,K-1):
		for j in range(i+1,K):
			sum += abs(x[j] - x[i])
	return sum



N = 100000 
K = 100000
arr = [10,100,300,200]

combinations = []

mini = -1
mincomb = []

for combinations in itertools.combinations(arr,3):
 	p = dVal(combinations)
 	if(mini==-1 or p<mini):
 		mini=p
 		mincomb = combinations
 	

print(mincomb,mini)
	# print(combinations)



