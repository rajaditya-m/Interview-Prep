def median(a,b):
    m = len(a)
    n = len(b)
    if m>n:
        a,b = b,a
        m,n = n,m
    #this ensures that len(b)>= len(a)
    imin = 0
    imax = m
    while imin<=imax:
        i = (imin+imax)//2
        j = (m+n+1)//2 - i
        if i<m and j>0 and b[j-1]>a[i]:
            imin = i+1
        elif i>0 and j<n and a[i-1]>b[j]:
            imax = i-1
        else:
            #many edge cases to handle here
            if i==0: 
                max_left = b[j-1]
            elif j==0:
                max_left = a[i-1]
            else:
                max_left = max(a[i-1],b[j-1])
            
            if (m+n)%2==1:
                return max_left

            if i==m: 
                min_right = b[j]
            elif j==n:
                min_right = a[i]
            else:
                min_right = min(a[i],b[j])

            return (min_right+max_left)/2.0

            
    