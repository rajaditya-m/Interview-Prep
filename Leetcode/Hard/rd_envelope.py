class Solution(object):
    def maxEnvelopes(self, envelopes):
        """
        :type envelopes: List[List[int]]
        :rtype: int
        """
        if not envelopes:
            return 0
        envelopes.sort(key = lambda x:x[0])
        #a variant of LIS
        n = len(envelopes)
        dp_table = [1]*n
        max_e = 1
        for i in range(n):
            for j in range(0,i):
                if envelopes[j][1]<envelopes[i][1] and envelopes[j][0]<envelopes[i][0]:
                    dp_table[i] = max(dp_table[i],dp_table[j]+1)
            max_e = max(max_e,dp_table[i])
        print(envelopes)
        print(dp_table)
        return max_e



obj = Solution()
e = [[5,4],[6,4],[6,7],[2,3]]
print(obj.maxEnvelopes(e))