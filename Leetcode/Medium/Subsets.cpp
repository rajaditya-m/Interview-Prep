class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        int n = S.size();
        int lim = pow(2,n);
        std::vector< std::vector<int> > res;
        for(int i=0;i<lim;i++)
        {
            std::vector<int> resSet;
            //Inspect the first n bits of lim
            int counter=0;
            while(counter!=n)
            {
                int res = (i>>counter)&1;
                if(!res)
                {
                    resSet.push_back(S[counter]);
                }
                counter++;
            }
            std::sort(resSet.begin(),resSet.end());
            res.push_back(resSet);
        }
        return res;
    }
};