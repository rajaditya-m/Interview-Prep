def lcs(a,b):
    m = len(a)
    n = len(b)
    dp_table = [[0]*(n+1) for _ in range(m+1)]
    for i in range(m):
        for j in range(n):
            if a[i]==b[j]:
                dp_table[i+1][j+1] = dp_table[i][j]+1
            else:
                dp_table[i+1][j+1] = max(dp_table[i][j+1],dp_table[i+1][j])
    lcs_rev = []
    i = m
    j = n
    while i>0 and j>0:
        if a[i-1]==b[j-1]:
            lcs_rev.append(a[i-1])
            i -= 1
            j -= 1
        elif dp_table[i-1][j]>dp_table[i][j-1]:
            i -= 1
        else:
            j -= 1
    lcs = ''.join(lcs_rev[::-1])
    print(lcs)
    return dp_table[m][n]

a = 'abazdc'
b = 'bacbad'
print(lcs(a,b))
