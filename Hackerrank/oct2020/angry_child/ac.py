import bisect

N = int(input())
K = int(input())
arr = []
cur_max = 0
cur_min = 0
cur_unf = 0
for i in range(0,N):	
	cur = int(input())
	bisect.insort(arr,cur)

can=arr[K-1]-arr[0]
for d in range(1,N-K+1):
	pecan = arr[d+K-1]-arr[d]
	if(pecan<can):
		can = pecan

print(can)
