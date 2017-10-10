def removeDups(arr):
    found = set()
    m = 0
    for i in range(len(arr)):
        if not arr[i] in found:
            arr[m] = arr[i]
            m += 1
            found.add(arr[i])
    return m

def removeDupsAliter(arr):
    found = {}
    m = 0
    for i in range(len(arr)):
        if not arr[i] in found:
            arr[m] = arr[i]
            m += 1
            found[arr[i]] = True
        else:
            rmv = found[arr[i]]
            if rmv:
                found[arr[i]] = False
            else:
                arr[m] = arr[i]
                m += 1
                found[arr[i]] = True
    return m

def removeDupsAliter2(arr):
    items = [chr(i+ord('a')) for i in range(26)]
    items.append(' ')
    for i in items:
        rmv = False
        for j in range(len(arr)):
            if arr[j]==i:
                if rmv:
                    arr[j] = '$'
                rmv = not rmv
            
    m = 0
    for i in range(len(arr)):
        if arr[i]!='$':
            arr[m] = arr[i]
            m += 1
    return m



x = 'you got beautiful eyes'
xl = [l for l in x]
print(xl)
l = removeDupsAliter2(xl)
print(''.join(xl[0:l])) 