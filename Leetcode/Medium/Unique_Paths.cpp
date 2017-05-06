class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int> > sum(m,std::vector<int>(n,0));
        sum[0][0] = 1;
        for(int i=1;i<m;i++)
            sum[i][0] = 1;
        for(int i=1;i<n;i++)
            sum[0][i] = 1;
        for(int r=1;r<m;r++)
        {
            for(int c=1;c<n;c++)
            {
                    sum[r][c] = (sum[r][c-1] + sum[r-1][c]);
            }
        }
        return sum[m-1][n-1];
    }
};