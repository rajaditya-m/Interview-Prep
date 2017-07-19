def genAllArrangement(arr):
    if not arr:
        return []
    if len(arr)==1:
        return [[arr[0]]]
    res = []
    for i in range(0,len(arr)):
        #swap i and 0 
        tmp = arr[0]
        arr[0]=arr[i]
        arr[i]=tmp
        newArr = arr[1:]
        recResult = genAllArrangement(newArr)
        for elemList in recResult:
            elemList.insert(0,arr[0])
            res.append(elemList)
    return res

def pickDerangement(list_arr):
    numD = 0
    for arrangement in list_arr:
        derangement = True
        for idx,elem in enumerate(arrangement):
            if elem==idx:
                derangement = False
                break
        if derangement:
            print(arrangement)
            numD += 1
    print(numD)

def r(n):
    if n==0:
        return 1
    elif n==1:
        return 0
    return (n-1)*(r(n-1)+r(n-2))

def iter_r(n):
    largeNum = 1000000007
    #largeNum = int(largeNum)
    print(largeNum)
    if n==0:
        return 1
    if n==1:
        return 0
    r_i_2 = 1
    r_i_1 = 0
    r_i = 0
    for i in range(2,n+1):
        step1 = (r_i_2 + r_i_1)%largeNum
        #r_i = (i-1)*(r_i_1+r_i_2)
        r_i = ((i-1)*step1)%largeNum
        r_i_2 = r_i_1
        r_i_1 = r_i
    return r_i

def combinatoricDerangement(arr):
    if len(arr)==1:
        return []
    if len(arr)==2:
        return [arr[1],arr[0]]
    for i in range(1,len(arr)):
        #let elem_0 swap with elem_i
        first = arr[i]
        #rec_set_1 this is just everything from 1......i-1,i+1,...n-1
        #rec_set_2 this is just everything from 1.......n-1
        rec_2 = arr[1:]
        rec_1 = arr[1:i-1] + arr[i+1:]
        res1 = combinatoricDerangement(rec_1)
        res2 = combinatoricDerangement(rec_2)
        print(res1)
        print(res2)
        


n=13
# arr = list(range(0,n)) 
# allArrange = genAllArrangement(arr)
# pickDerangement(allArrange)
# print(r(n))
print(iter_r(n))
print(2290792932)
# arr = [0,1,2]
# print(genAllArrangement(arr))