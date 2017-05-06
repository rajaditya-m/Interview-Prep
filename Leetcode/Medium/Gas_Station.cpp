class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        std::vector<int> diff;
        for(int i=0;i<n;i++)
        {
            diff.push_back(gas[i]-cost[i]);
        }
        int rs = 0;
        int res = 0;
        bool flag = false;
        for(int k=0;k<n;k++)
        {
            if(diff[k]>=0)
            {
                if(!flag)
                {
                    res = k;
                    flag = true;
                }
            }
            rs += diff[k];
            if(rs<0 && diff[k]<0)
            {
                flag = false;
            }
        }
        if(rs>=0)
            return res;
        return -1;
    }
};