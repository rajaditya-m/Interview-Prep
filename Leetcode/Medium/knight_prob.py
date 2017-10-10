import copy

class Solution(object):
    def knightProbability_bf(self, N, K, r, c):
        """
        :type N: int
        :type K: int
        :type r: int
        :type c: int
        :rtype: float
        """
        if r>=N or r<0 or c<0 or c>=N:
            return 0
        if K==0:
            return 1
        else:
            explore = [[-2,-1],[-1,-2],[-2,1],[-1,2],[2,-1],[1,-2],[2,1],[1,2]]
            tot_prob = 0
            for xd,yd in explore:
                v = self.knightProbability(N,K-1,r+xd,c+yd)
                tot_prob += v
            return tot_prob*0.125
    
    def knightProbability(self, N, K, r, c):
        """
        :type N: int
        :type K: int
        :type r: int
        :type c: int
        :rtype: float
        """
        dp_table = [[1]*N for _ in range(N)]
        dp_table_future = [[-1]*N for _ in range(N)]
        for k in range(1,K+1):
            for i in range(N):
                for j in range(N):
                    explore = [[-2,-1],[-1,-2],[-2,1],[-1,2],[2,-1],[1,-2],[2,1],[1,2]]
                    tot_prob = 0
                    for xd,yd in explore:
                        xn,yn = i+xd,j+yd
                        if xn>=N or xn<0 or yn<0 or yn>=N:
                            continue
                        tot_prob += dp_table[xn][yn]
                    dp_table_future[i][j] = tot_prob*0.125
            dp_table = copy.deepcopy(dp_table_future)
            # print(dp_table)
        print(dp_table[r][c])


obj = Solution()
print(obj.knightProbability(3,2,0,0))