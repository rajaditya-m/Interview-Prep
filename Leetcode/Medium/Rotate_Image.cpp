class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        int** placeholder = new int*[n];
        
        for(int k=0;k<n;k++)
            placeholder[k] = new int[n];
            
        for(int r=0;r<n;r++)
        {
            for(int c=0;c<n;c++)
            {
                placeholder[c][r] = matrix[r][c];    
            }
        }
        for(int c=0;c<n;c++)
        {
            for(int r=0;r<n;r++)
            {
                matrix[r][c] = placeholder[r][n-1-c];       
            }
        }
        
    }
};