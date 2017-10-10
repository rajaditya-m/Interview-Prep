import queue
def skyline(b):
    tab=[0]*25
    for i in b:
        l = i[0]
        r = i[1]
        h = i[2]
        for j in range(l,r):
            tab[j] = max(tab[j],h)
    for i in range(25):
        if i>0 and tab[i]!=tab[i-1]:
            print(i,tab[i])
    print(tab)

def skyline2(b):
    pq = queue.PriorityQueue()
    for i in b:
        pq.put((i[0],'L',i[2]))
        pq.put((i[1],'R',i[2]))
    tab = []
    while not pq.empty():
        tab.append(pq.get())
    print(tab)




b = [ [2,9,10], [3,7,15], [5,12,12], [15,20,10], [19,24,8]] 
skyline2(b)
skyline(b)