class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        n = len(prices)
        k = 2
        dp_table = [[0]*n for _ in range(k+1)]
        for kk in range(1,k+1): 
            for i in range(1,n):
                for j in range(0,i):
                    dp_table[kk][i] = max(dp_table[kk][i], dp_table[kk][i-1], dp_table[kk-1][j] + prices[i]-prices[j])
        print(dp_table)
        return dp_table[k][n-1]

obj = Solution()
print(obj.maxProfit([6,1,3,2,4,7]))