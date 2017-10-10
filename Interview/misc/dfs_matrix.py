def dfs(a, i, j, m, n, prev_sum):
    if i==m-1 and j==n-1:
        return prev_sum+a[i][j]

    r1,r2 = -9999,-9999

    if i+1<m:
        r1 = dfs(a, i+1, j, m ,n, prev_sum+a[i][j])
    
    if j+1<n:
        r2 = dfs(a, i, j+1, m, n, prev_sum+a[i][j])
    
    return max(r1,r2)

def whateves(matrix):
    prev = 0
    m = len(matrix)
    n = len(matrix[0])
    return dfs(matrix,0,0,m,n,prev)

b = [[1,2,3],
[4,5,6],
[7,8,9]]

print(whateves(b))