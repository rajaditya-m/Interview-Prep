class Solution(object):
    # def maxAreaOfIsland(self, grid):
    #     """
    #     :type grid: List[List[int]]
    #     :rtype: int
    #     """
    #     max_area = 0
    #     nr = len(grid)
    #     nc = len(grid[0])
    #     dp_table = [[0]*nc for _ in range(nr)]
    #     for r in range(nr):
    #         for c in range(nc):
    #             if grid[r][c]==1:
    #                 dp_table[r][c] = 1
    #                 if r-1>=0 and c-1>=0:
    #                     # dp_table[r-1][c]+dp_table[r][c-1]-dp_table[r-1][c-1]+1
    #                     if dp_table[r-1][c] and dp_table[r][c-1]:
    #                         dp_table[r][c] = max(dp_table[r-1][c]+dp_table[r][c-1]-dp_table[r-1][c-1]+1,dp_table[r][c])
    #                     else:
    #                         dp_table[r][c] = max(dp_table[r-1][c]+dp_table[r][c-1]+1,dp_table[r][c])
    #                     print(r,c,dp_table[r-1][c],dp_table[r][c-1],dp_table[r-1][c-1],dp_table[r][c])
    #                 elif r-1>=0:
    #                     dp_table[r][c] = max(dp_table[r-1][c]+1,dp_table[r][c])
    #                 elif c-1>=0:
    #                     dp_table[r][c] = max(dp_table[r][c-1]+1,dp_table[r][c])
    #                 max_area = max(max_area,dp_table[r][c])
    #     print(dp_table)
    #     return max_area

    def maxAreaOfIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        max_area = 0
        nr = len(grid)
        nc = len(grid[0])
        dp_table = [[0]*nc for _ in range(nr)]
        for r in range(nr):
            for c in range(nc):
                    area = 0
                    area = self.dfs_visit(grid,r,c,area)
                    max_area = max(max_area,area)
        print(grid)
        return max_area

    def dfs_visit(self,grid,r,c,seed):
        nr = len(grid)
        nc = len(grid[0])
        if r>=nr or r<0 or c>=nc or c<0:
            return seed
        if grid[r][c]==1:
            seed += 1
            grid[r][c] = 2 #mark as visited
            seed = self.dfs_visit(grid,r+1,c,seed)
            seed = self.dfs_visit(grid,r,c-1,seed)
            seed = self.dfs_visit(grid,r-1,c,seed)
            seed = self.dfs_visit(grid,r,c+1,seed)
        return seed
obj = Solution()
g = [[0,0,1,0,0,0,0,1,0,0,0,0,0],
     [0,0,0,0,0,0,0,1,1,1,0,0,0],
     [0,1,1,0,1,0,0,0,0,0,0,0,0],
     [0,1,0,0,1,1,0,0,1,0,1,0,0],
     [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
# g = [[0,0,0,0,0,0,0,0]]
print(obj.maxAreaOfIsland(g))


def foo(x):
    x += 1

d = 1
print(d)
foo(d)
print(d)                    