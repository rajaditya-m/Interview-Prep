class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int** sum = new int*[rows];
        for(int k=0;k<rows;k++)
            sum[k] = new int[cols];
        
        sum[0][0] = grid[0][0];
        
        for(int r=0;r<rows;r++)
        {
            for(int c=0;c<cols;c++)
            {
                if(r==0 && c==0)
                    continue;
                int topCand = 0;
                int leftCand = 0;
                if(r-1>=0)
                {
                    topCand = sum[r-1][c]+grid[r][c];
                }
                else
                {
                    topCand = INT_MAX;
                }
                if(c-1>=0)
                {
                    leftCand = sum[r][c-1] + grid[r][c];
                }
                else
                {
                    leftCand = INT_MAX;
                }
                sum[r][c] = std::min(topCand,leftCand);
            }
        }
        
        return sum[rows-1][cols-1];
    }
};