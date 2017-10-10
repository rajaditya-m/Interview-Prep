def nlps(s):
    n = len(s)
    is_pali = [[False]*n for _ in range(n)]
    res = 0
    for i in range(n):
        res += 1
        is_pali[i][i] = True
    for i in range(n-1):
        if s[i]==s[i+1]:
            res += 1
            is_pali[i][i+1] = True
    for l in range(3,n+1):
        for i in range(0,n-l+1):
            j = i + l - 1
            if s[i] == s[j]:
                is_pali[i][j] = is_pali[i+1][j-1]
                if is_pali[i][j]:
                    res += 1
   return res

s = 'aaa'

nlps(s)