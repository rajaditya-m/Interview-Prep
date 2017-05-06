class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       std::unordered_map<int,int> hashtable;
       for(int i = 0; i < nums.size();i++){
           auto ith = hashtable.find(nums[i]);
           if(ith == hashtable.end())
             hashtable.insert(std::pair<int,int>(nums[i],i));
           else {
             if(abs(ith->second - i)<=k)
                return true;
             ith->second = i;
           }
       }
       return false;
    }
};