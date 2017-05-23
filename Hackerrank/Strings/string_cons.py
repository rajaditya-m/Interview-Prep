def stringCost(s):
    lastEntry = [-1]*26
    cost = 0
    for i,c in enumerate(s):
        if lastEntry[ord(c)-ord('a')]==-1:
            cost+=1
            lastEntry[ord(c)-ord('a')]=i
    return cost

s1 = 'abcd'
print(stringCost(s1))
s2 = 'abab'
print(stringCost(s2))