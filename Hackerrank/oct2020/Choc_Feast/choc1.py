N = int(input())

for i in range(0,N):

	money_left,cost_choc,free_choc_num = map(int,input().split())

	choc_count = int(money_left/cost_choc) 
	wrapper_left = choc_count

	while(wrapper_left>=free_choc_num):
		new_choc = int(wrapper_left/free_choc_num)
		choc_count += new_choc
		wrapper_left = wrapper_left%free_choc_num
		wrapper_left += new_choc

	print(choc_count)