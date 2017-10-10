class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        n = len(prices)
        diff = []
        for i in range(1,n):
            diff.append(prices[i]-prices[i-1])
        p = [0]*(n-1)
        for i in range(n-1):
            if i-3>=0:
                p[i] = max(p[i-3]+diff[i], p[i-3], p[i-1]+diff[i], diff[i],p[i-1],0)
            elif i-1>=0:
                p[i] = max(p[i-1]+diff[i], diff[i],p[i-1],0)
            else:
                p[i] = max(diff[i],0)
        print(p)
        return max(p)

l = [1,2,3,0,2]
obj = Solution()
print(obj.maxProfit(l))