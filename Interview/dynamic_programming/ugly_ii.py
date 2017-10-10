class Solution(object):
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        res = [1]
        i,j,k = 0,0,0
        for l in range(1,n+1):
            candidate = min(res[i]*2,res[k]*3,res[k]*5)
            if candidate==res[-1]*2:
                i += 1
            if candidate==res[-1]*3:
                j += 1
            if candidate==res[-1]*5:
                k += 1
            res.append(candidate)
        return res[-1]