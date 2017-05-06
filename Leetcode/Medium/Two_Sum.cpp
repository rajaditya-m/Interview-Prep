class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        std::unordered_map<int,int> assocMap;
        std::vector<int> result;
        int idx = 0;
        for(auto it=numbers.begin();it!=numbers.end();it++)
        {
            assocMap.insert(std::pair<int,int>(*it,idx));
            idx++;
        }
        int numelems = numbers.size();
        for(int i=0;i<numelems;i++)
        {
            int comp = target-numbers[i];
            auto itt = assocMap.find(comp);
            if(itt==assocMap.end())
                continue;
            else
            {
                if(itt->second==i)
                    continue;
                if(i+1<((itt->second)+1))
                {
                    result.push_back(i+1);
                    result.push_back((itt->second)+1);
                }
                else
                {
                    result.push_back((itt->second)+1);
                    result.push_back(i+1);
                }
                break;
            }
        }
        return result;
    }
};