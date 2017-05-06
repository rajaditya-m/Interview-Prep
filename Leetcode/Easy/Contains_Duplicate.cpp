class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       std::unordered_set<int> hashtable;
       for(auto it = nums.begin();it!=nums.end();it++){
           auto ith = hashtable.find(*it);
           if(ith == hashtable.end())
             hashtable.insert(*it);
           else
             return true; 
       }
       return false;
    }
};