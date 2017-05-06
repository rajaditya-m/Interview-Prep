class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int curRow = 0;
        int curCol = cols-1;
        while(curRow<rows && curCol>=0)
        {
            int cur = matrix[curRow][curCol];
            if(cur==target)
                return true;
            else if(cur<target)
            {
                curRow++;
            }
            else 
            {
                curCol--;
            }
        }
        return false;
    }
};