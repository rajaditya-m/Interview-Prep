def editDistance(a,b):
    m = len(a)
    n = len(b)
    delcost = 1
    addcost = 10000000
    subcost = 30000000
    table = [[0]*(n+1) for _ in range(m+1)]
    for i in range(m+1):
        table[i][0] = delcost * i
    for j in range(n+1):
        table[0][j] = addcost * j
    for i in range(1,m+1):
        for j in range(1,n+1):
            if a[i-1]==b[j-1]:
                table[i][j] = table[i-1][j-1]
            else:
                table[i][j] = min(table[i-1][j] + delcost, table[i][j-1]+addcost, table[i-1][j-1]+subcost)
    print(table)
    return table[m][n]

def editDistanceOnlyDeletion(a,b):
    m = len(a)
    n = len(b)
    delcost = 1
    table = [[0]*(n+1) for _ in range(m+1)]
    prev_row = [[0]*(n+1)]
    cur_row = [[0]*(n+1)]
    for i in range(m+1):
        table[i][0] = delcost * i
    # for j in range(n+1):
        # table[0][j] = 0 * j
    for i in range(1,m+1):
        for j in range(1,n+1):
            if a[i-1]==b[j-1]:
                table[i][j] = table[i-1][j-1]
            else:
                table[i][j] = table[i-1][j] + delcost
    print(table)
    return table[m][n]
import copy
def editDistanceOnlyDeletion_2(a,b):
    m = len(a)
    n = len(b)
    delcost = 1
    prev_row = [0]*(n+1)
    cur_row = [0]*(n+1)
    for i in range(1,m+1):
        cur_row[0] = i
        for j in range(1,n+1):
            if a[i-1]==b[j-1]:
                cur_row[j] = prev_row[j-1]
            else:
                cur_row[j] = prev_row[j] + delcost
        prev_row = cur_row[:]
    print(cur_row)
    return cur_row[n]

a = 'abcde'
b = 'ace'
print(editDistanceOnlyDeletion_2(a,b))            