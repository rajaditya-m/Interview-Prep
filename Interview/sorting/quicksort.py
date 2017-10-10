import random

def qsort_helper(arr,left,right):
    if left>=right:
        return #already sorted
    r = partition(arr,left,right)
    qsort_helper(arr,left,r-1)
    qsort_helper(arr,r+1,right)


def partition(a,left,right):
    #randomly chose a pivot
    r = random.randint(left,right)
    #swap the last element with random
    a[right],a[r] = a[r],a[right]
    #so now the pivot is the end most element
    # invariants left....i is leq a[right]
    # i+1...j-1 is grt than a[right]
    # j....right-1 is untouched 
    i,j = left-1,left
    while j<right:
        if a[j]<=a[right]:
            #add aj to i
            i += 1
            a[i],a[j] = a[j],a[i]
        j += 1
    #at this point we have exhausted all elements 
    a[i+1],a[right] = a[right],a[i+1]
    return i+1

def kthorder_stat(arr,left, right, k):
    n = len(a)
    r = partition(arr,left,right)
    kp = r-left+1
    if k==kp:
        return arr[r]
    elif k<kp:
        return kthorder_stat(arr,left,r-1,k)
    else:
        return kthorder_stat(arr,r+1,right,k-kp)

a = [3,52,1,5,6,8]
qsort_helper(a,0,len(a)-1)
print(kthorder_stat(a,0,len(a)-1,1))