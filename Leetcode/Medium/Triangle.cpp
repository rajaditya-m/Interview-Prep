class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        std::vector<int> prevRow;
        prevRow.push_back(triangle[0][0]);
        int n = triangle.size();
        int minimumSoFar = triangle[0][0];
        for(int i=1;i<n;i++)
        {
            std::vector<int> thisRow;
            int thisRowMinSum = INT_MAX;
            for(int j=0;j<triangle[i].size();j++)
            {
                int cand1 = INT_MAX;
                int cand2 = INT_MAX;
                if(j-1>=0)
                {
                    cand1 = triangle[i][j]+prevRow[j-1];
                }
                if(j<prevRow.size())
                {
                    cand2 = triangle[i][j]+prevRow[j];
                }
                int c = std::min(cand1,cand2);
                thisRow.push_back(c);
                thisRowMinSum = std::min(thisRowMinSum,c);
            }
            prevRow = thisRow;
            minimumSoFar = thisRowMinSum;
        }
        return minimumSoFar;
    }
};