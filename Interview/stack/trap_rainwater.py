def nearestGreater(a):
    st = []
    n = len(a)
    res_r = []
    res_l = []
    for idx,num in enumerate(a):
        if idx==0:
            res_l.append(num)
        else:
            res_l.append(max(num,res_l[-1]))
    for idx in range(n-1,-1,-1):
        if idx==n-1:
            res_r.append(a[idx])
        else:
            res_r.append(max(res_r[-1],a[idx]))
    res_r.reverse()   
    wtr = 0
    for i in range(n):
        ll = res_l[i]
        lr = res_r[i]
        wtr += (min(ll,lr)-a[i])
    return wtr

a = [0,1,0,2,1,0,1,3,2,1,2,1]
print(nearestGreater(a))