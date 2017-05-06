class Solution {
public:
    
int missingNumber(std::vector<int>& nums) {
    int sum = 0;
    int n = nums.size();
    for(auto it = nums.begin();it!=nums.end();it++){
        sum += (*it);
    }
    int expectedSum = (n*(n+1))/2;
    return expectedSum-sum;
}

};