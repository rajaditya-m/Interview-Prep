
def longestIncreasingSubsequence(sequence):
    n = len(sequence)
    dp_table = [0]*n
    for i in range(n):
        dp_table[i] = 1
        for j in range(i-1,-1,-1):
            if sequence[j]<sequence[i]:
                dp_table[i] = max(dp_table[i], dp_table[j]+1)
    return max(dp_table)

import bisect

def longestIncreasingSubsequence_nln(sequence):
    n = len(sequence)
    end_points = [0]*n
    lis = 1
    end_points[0] = sequence[0]
    for i in range(1,n):
        elem = sequence[i]
        if elem<end_points[0]:
            end_points[0] =  elem
        elif elem>end_points[lis-1]:
            end_points[lis] = elem
            lis += 1
        else:
            insert = bisect.bisect_left(end_points,elem,0,lis)
            end_points[insert] = elem
    print(end_points)
    return lis

def numLIS(sequence):
    n = len(sequence)
    dp_table  = [1]*n
    dp_table2 = [1]*n
    for i in range(n):
        max_len,count = 1,0
        for j in range(i):
            if sequence[j]<sequence[i]:
                if max_len<dp_table[j]+1:
                    max_len = dp_table[j]+1
                    count = 0
                if max_len==dp_table[j]+1:
                    count += dp_table2[j]
        dp_table[i] = max_len
        dp_table2[i] = max(count,dp_table2[i])
    lis = max(dp_table)
    nlis = 0
    for i in range(n):
        if lis==dp_table[i]:
            nlis += dp_table2[i]
    return nlis




seq = [1, 231, 2, 4, 89, 32, 12, 234, 33, 90, 34, 100]
seq = [2, 5, 3, 7, 11, 8, 10, 13, 6]
# seq = [1,3,5,4,7]
# seq = [2,2,2,2,2]
seq = [1,2,4,3,5,4,7,2]
# print(longestIncreasingSubsequence(seq))
# print(longestIncreasingSubsequence_nln(seq))
print(numLIS(seq))