class Solution(object):
    def numDistinctIslands(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        max_area = 0
        nr = len(grid)
        nc = len(grid[0])
        unique = set()
        dp_table = [[0]*nc for _ in range(nr)]
        for r in range(nr):
            for c in range(nc):
                    pnts = []
                    self.dfs_visit(grid,r,c,pnts)
                    if pnts:
                        mct = self.mean_center(pnts)
                        if not mct in unique:
                            unique.add(mct)
        print(unique)
        # print(grid)
        return len(unique)
    
    def mean_center(self,pnts):
        xa,ya = 0,0
        mcx = []
        mcy = []
        n = len(pnts)
        for x,y in pnts:
            xa += x
            ya += y
        xa = xa/float(n)
        ya = ya/float(n)
        for x,y in pnts:
            mcx.append(x-xa)
            mcy.append(y-ya)
        mcx.sort()
        mcy.sort()
        mcx.extend(mcy)
        return tuple(mcx)

    def dfs_visit(self,grid,r,c,seed):
        nr = len(grid)
        nc = len(grid[0])
        if r>=nr or r<0 or c>=nc or c<0:
            return seed
        if grid[r][c]==1:
            seed.append([r,c])
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

g = [[1,1,0,0,0],
[1,1,0,0,0],
[0,0,0,1,1],
[0,0,0,1,1]]


# g = [[0,0,1],[0,0,1],[1,1,0]]

g = [[1,1,0,0,1,0,1,1,1,1,1,0,0,0,1,1,0,1,0,1,1,1,1,0,0],[0,0,0,1,0,1,0,1,1,0,0,0,0,1,0,1,1,1,1,0,1,0,0,0,1],[1,0,1,0,1,1,0,0,1,1,1,0,0,0,1,0,0,1,1,1,1,1,1,0,1],[0,0,1,1,0,1,1,0,1,0,0,0,0,0,0,0,1,0,1,0,1,0,0,1,1],[1,1,0,1,1,1,1,1,0,0,1,0,0,1,1,1,1,1,1,0,0,0,0,0,1],[0,1,0,1,0,0,1,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1],[1,1,1,1,0,0,0,1,0,0,1,0,0,1,0,1,1,1,1,1,0,0,0,0,0],[0,1,1,1,1,1,0,1,0,0,0,1,0,1,1,1,0,0,1,0,0,0,0,1,1],[1,1,0,0,1,1,0,1,0,1,1,0,0,0,0,1,1,1,1,0,1,1,0,0,0],[0,1,1,1,1,0,1,1,0,1,1,0,1,1,0,1,0,0,0,0,1,0,1,1,1],[0,1,1,1,0,1,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,1,0],[1,0,0,1,0,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,0,1,1,1],[1,1,1,1,1,1,1,1,0,0,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1],[1,1,1,0,1,0,1,1,1,1,1,1,0,1,1,0,1,0,1,1,1,0,0,1,1],[0,0,0,1,1,0,1,1,1,0,1,1,1,1,1,1,0,1,1,0,0,0,0,1,0],[0,0,1,0,0,1,0,1,1,1,1,0,1,0,0,0,1,0,1,1,1,1,1,1,1],[0,0,1,1,1,1,0,1,1,0,0,1,1,1,0,0,1,0,1,0,1,1,0,1,1],[1,0,0,1,0,1,0,0,1,1,1,1,0,0,0,1,0,1,0,1,1,1,0,1,1],[0,0,0,0,1,0,0,1,0,1,0,0,0,1,1,1,0,1,0,0,0,1,0,0,0],[1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,1,1,0,1,1,1,0,0,0,1],[1,0,0,1,1,1,1,1,1,1,0,1,0,0,1,1,1,1,1,1,0,1,0,1,1],[1,1,0,0,0,0,0,0,1,0,1,0,1,0,0,1,0,1,0,1,0,0,0,0,0],[1,0,0,0,0,1,1,0,1,1,0,1,0,1,0,1,1,1,0,1,0,1,0,0,0],[0,1,1,0,1,1,0,1,0,1,0,1,1,1,1,1,0,1,0,0,1,1,0,1,1],[1,1,0,1,1,0,1,1,1,0,1,0,1,0,0,1,0,1,0,0,0,1,0,0,0],[0,1,0,0,1,0,0,0,0,0,0,1,0,1,1,0,1,1,0,1,1,1,0,0,0],[0,1,1,1,1,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,1,1,0,1],[1,0,0,1,1,1,0,0,0,1,0,1,0,0,0,0,0,0,1,1,0,0,0,0,0],[1,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,1,1,1,0,1,0,0,0,0],[0,0,0,1,0,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,0,0,1,1,0],[1,0,1,1,1,0,1,1,1,0,1,1,1,0,0,0,0,0,1,1,0,0,1,0,1],[0,1,1,0,0,0,0,1,0,1,0,0,1,0,1,1,1,1,0,0,0,1,1,0,0],[0,1,0,0,1,1,0,1,1,0,1,0,1,0,0,0,0,1,1,0,0,1,1,1,1],[0,0,1,0,1,1,1,1,0,1,1,1,0,1,0,1,1,1,1,1,1,1,1,0,0],[1,0,1,0,1,1,0,1,1,0,0,0,1,1,1,1,1,1,1,0,1,1,1,1,1],[1,0,1,0,1,1,1,0,1,0,1,0,1,1,0,0,1,1,0,0,1,1,0,0,1],[0,1,0,0,0,1,0,1,1,1,1,1,0,0,0,1,0,0,0,0,1,0,1,0,1],[0,0,1,0,1,0,1,1,0,0,0,0,0,0,0,0,1,0,0,1,1,1,0,0,1],[1,1,0,1,0,0,1,1,0,0,1,1,1,0,0,1,1,1,1,0,0,0,0,1,0],[1,0,0,0,0,0,0,1,0,0,0,1,0,1,0,1,0,1,1,1,0,0,0,0,0],[1,0,0,0,1,0,0,1,0,0,0,0,1,1,1,1,1,1,0,0,1,0,0,0,1],[0,1,0,1,0,1,1,0,0,1,1,1,0,1,0,0,0,1,1,0,0,1,1,1,0],[1,1,1,1,0,1,0,0,1,0,1,1,0,0,1,1,0,1,0,1,0,0,1,0,1],[1,0,0,1,0,1,0,1,0,0,1,0,1,0,0,0,1,1,0,1,1,1,0,0,0],[1,1,1,0,1,0,0,0,1,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0],[1,1,1,0,0,0,1,0,0,1,0,1,1,0,1,1,1,1,0,0,1,1,0,0,1],[0,1,1,0,1,0,0,1,0,0,0,0,1,0,1,1,1,1,1,0,1,1,1,0,1],[0,1,1,1,1,1,1,1,1,1,0,1,0,0,1,1,1,0,0,0,0,1,1,0,1],[0,0,1,0,1,1,0,0,1,1,1,0,1,0,0,0,1,0,1,0,1,0,1,1,0],[1,0,0,1,1,0,1,0,0,1,0,0,1,1,0,1,0,0,1,0,0,1,0,1,0]]
# g = [[0,0,0,0,0,0,0,0]]
print(obj.numDistinctIslands(g))
                 