def nearestGreater(a):
    st = []
    n = len(a)
    res_r = [-1]*n   
    res_l = [-1]*n
    res = [-1]*n
    for idx,num in enumerate(a):
        if idx==0:
            st.append((idx,num))
        else:
            if st:
                while st and st[-1][1]>num:
                    top_elem = st.pop()
                    res_r[top_elem[0]]=idx
            st.append((idx,num))
    st = []
    for idx in range(n-1,-1,-1):
        num = a[idx]
        if idx==n-1:
            st.append((idx,num))
        else:
            if st:
                while st and st[-1][1]>num:
                    top_elem = st.pop()
                    res_l[top_elem[0]]=idx
            st.append((idx,num))
    max_rect = -1
    for i in range(n):
        ls = -1
        rs = n
        if res_l[i]!=-1:
            ls = res_l[i]
        if res_r[i]!=-1:
            rs = res_r[i]
        #there are three candidates
        ls += 1
        rs -= 1 
        c = a[i]*(rs-ls+1)
        # print(ls,rs,a[i])
        max_rect = max(max_rect,c)
    return max_rect

a = [2,1,5,6,2,3]
print(nearestGreater(a))