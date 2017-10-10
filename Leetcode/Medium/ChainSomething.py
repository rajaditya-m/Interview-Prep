class Solution:
    def findLongestChain(self, pairs):
        n = len(pairs)
        table = [0]*n
        for i in range(0,n):
            for j in range(0,i):
                if pairs[j][1] < pairs[i][0]:
                    table[i] = max(table[j]+1 if table[j] else 2, table[i])
        return max(table)

obj = Solution()
l = [[1,2], [2,3], [3,4]]
print(obj.findLongestChain(l))