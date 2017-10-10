def twokey(n):
    dp_table = [[999999]*(n+1) for _ in range(n+1)]
    dp_table[1][0] = 0
    for i in range(1,n+1):
        if 2*i <= n:
            dp_table[2*i][i] = dp_table[i][i//2] + 2 
    for i in range(1,n+1):
        for j in range(1,i):
            print(i,j,dp_table[i][j],i-j,j,dp_table[i-j][j])
            dp_table[i][j] = min(dp_table[i][j],dp_table[i-j][j]+1) #paste operation
    print(dp_table)
    print(min(dp_table[n]))

def twokey(n):
    dp_table = [i for i in range(n+1)]
    if i <= 1:
        return 0
    for i in range(2,n+1):
        for j in range(2,i):
            if i%j==0:
                dp_table[i] = dp_table[j] + i//j
    return dp_table[-1]