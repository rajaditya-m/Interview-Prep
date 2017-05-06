class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        std::vector<std::vector<int> > dptable(rows,std::vector<int>(cols,0));
        bool foundobs = false;
        for(int r=0;r<rows;r++)
        {
            if(obstacleGrid[r][0]==1)
                foundobs = true;
            if(!foundobs)
                dptable[r][0] = 1;
        }
        foundobs = false;
        for(int c=0;c<cols;c++)
        {
            if(obstacleGrid[0][c]==1)
                foundobs = true;
            if(!foundobs)
                dptable[0][c] = 1;
        }
        for(int r=1;r<rows;r++)
        {
            for(int c=1;c<cols;c++)
            {
                if(obstacleGrid[r][c]==1)
                    continue;
                if(obstacleGrid[r-1][c]!=1)
                    dptable[r][c] += dptable[r-1][c];
                if(obstacleGrid[r][c-1]!=1)
                    dptable[r][c] += dptable[r][c-1];
            }
        }
        return dptable[rows-1][cols-1];
        
    }
};