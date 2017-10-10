def min_jumps(arr):
    if not arr:
        return 0
    n = len(arr)
    tr = n-1
    cur = n-1
    nj = 0
    while cur:
        if arr[cur-1] == 0:
            break
        elif arr[cur-1]+(cur-1)>=tr:
            cur = cur-1
            nj = 1 if nj == 0 else nj
        else:
            tr = cur
            nj = nj + 1
        print(tr, cur, nj)
    if not cur:
        if arr[0] >= tr:
            return nj
        else:
            return 0
    return 0

a = [4, 1, 2, 0, 2, 12]
print(min_jumps(a))