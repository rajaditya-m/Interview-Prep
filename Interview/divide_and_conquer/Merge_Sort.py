
def merge_sort(arr):
    n = len(arr)
    if n<2:
        return arr
    h1 = arr[0:int(n/2)]
    h2 = arr[int(n/2):]
    h1_sorted = merge_sort(h1)
    h2_sorted = merge_sort(h2)
    arr_sorted = merge(h1_sorted, h2_sorted)
    return arr_sorted

def merge(a,b):
    a_n = len(a)
    b_n = len(b)
    ab = []
    i,j = 0,0
    while i < a_n and j < b_n:
        if a[i] < b[j]:
            ab.append(a[i])
            i += 1
        else:
            ab.append(b[j])
            j += 1
    if i != a_n:
        ab.extend(a[i:])
    elif j != b_n:
        ab.extend(b[j:])
    return ab

a = [4,4,4,4,4]
print(merge_sort(a))