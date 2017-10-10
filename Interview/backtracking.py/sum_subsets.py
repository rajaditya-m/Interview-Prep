def sumSubsets(arr, num):
    if not arr:
        return [[]]
    if arr[0]>num:
        return [[]]
    n = len(arr)
    ans = []
    for i in range(n):
        if i!=0:
            if arr[i]==arr[i-1]:
                continue
        first = arr[i]
        rem = arr[i+1:]
        new_target = num-first
        if new_target==0:
            ans.append([first])
        elif new_target>0:
            rec = sumSubsets(rem, new_target)
            for rec_list in rec:
                if rec_list:
                    rec_list.insert(0,first)
                    ans.append(rec_list)
        else:
            break
    return ans
    
print(sumSubsets([1,2,2,3,4,5],5))