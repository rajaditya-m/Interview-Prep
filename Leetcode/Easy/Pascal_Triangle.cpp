class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        std::vector<std::vector<int> > res;
        int n = 1;
        std::vector<int> prev ;
        if(numRows)
        {
            std::vector<int> first;
            first.push_back(1);
            res.push_back(first);
            numRows--;
            prev = res[0];
        }
        while(numRows)
        {
            std::vector<int> cur(n+1);
            for(int i=1;i<n;i++)
            {
                cur[i] = prev[i]+prev[i-1];
            }
            cur[0] = 1;
            cur[n] = 1;
            res.push_back(cur);
            prev = cur;
            n++;
            numRows--;
        }
        return res;
    }
};