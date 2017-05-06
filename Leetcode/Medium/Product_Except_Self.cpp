class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> res(n,1);
    int leftAccum = 1;
    for(int i=1;i<n;i++){
        leftAccum *= nums[i-1];
        res[i] *= leftAccum;
    }
    int rightAccum = 1;
    for(int i=n-2;i>=0;i--){
        rightAccum *= nums[i+1];
        res[i] *= rightAccum;
    }
    return res;
}
};