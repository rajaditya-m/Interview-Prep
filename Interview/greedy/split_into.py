import queue 

def isPossible(nums):
    pq = queue.PriorityQueue()
    count_dict = {}
    for n in nums:
        count_dict[n] = count_dict.get(n,0)+1
    for key,value in count_dict.items():
        pq.put((key,value))
    num_seqs = 0
    while not pq.empty():
        item1 = pq.get()
        item2, item3 = None, None
        if not pq.empty():
            item2 = pq.get()
        if not pq.empty():
            item3 = pq.get()
        if not item2 or not item3:
            break 
        num_seqs += 1
        if item1[1]>1:
            pq.put((item1[0],item1[1]-1))
        if item2[1]>1:
            pq.put((item2[0],item2[1]-1))
        if item3[1]>1:
            pq.put((item2[0],item2[1]-1))
    return num_seqs>1

nn = [1,2,3,4,4,5]
print(isPossible(nn))