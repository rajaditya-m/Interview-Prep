
def get_inversions_and_sort(arr):
    n = len(arr)
    if n<2:
        return [0,arr] 
    h1 = arr[0:int(n/2)]
    h2 = arr[int(n/2):]
    h1_inv, h1_sorted = get_inversions_and_sort(h1)
    h2_inv, h2_sorted = get_inversions_and_sort(h2)
    merged_inv, arr_sorted = merge_and_count(h1_sorted, h2_sorted)
    return [h1_inv+h2_inv+merged_inv, arr_sorted]

def merge_and_count(a,b):
    a_n = len(a)
    b_n = len(b)
    ab = []
    i,j,inv = 0,0,0
    while i < a_n and j < b_n:
        if a[i] <= b[j]:
            ab.append(a[i])
            i += 1
        else:
            inv += (a_n-i)
            ab.append(b[j])
            j += 1
    if i != a_n:
        ab.extend(a[i:])
    elif j != b_n:
        ab.extend(b[j:])
    return [inv,ab]

a = [4,3,1,5,14]
print(get_inversions_and_sort(a))