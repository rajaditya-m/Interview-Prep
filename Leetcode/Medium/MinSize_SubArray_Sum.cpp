class Solution {
public:
int minSubArrayLen(int s, std::vector<int>& nums) {
    int n = nums.size();
    if(!n)
        return 0;
    int sumSoFar = 0;
    int maxLenSoFar = 0;
    int lenSoFar = 0;
    int startPos = 0;
    for(int i=0;i<n;i++){
        if(nums[i]>=s){
            sumSoFar = nums[i];
            maxLenSoFar = 1;
            startPos = i;
            break;
        }
        else if(sumSoFar+nums[i]>=s){
            sumSoFar += nums[i];
            lenSoFar++;
            for(int j=startPos;j<i;j++){
                if(sumSoFar-nums[j]>=s){
                    sumSoFar -= nums[j];
                    startPos++;
                    lenSoFar--;
                }
                else {
                    break;
                }
            }
            if(!maxLenSoFar || (maxLenSoFar && lenSoFar<maxLenSoFar))
                maxLenSoFar = lenSoFar;
        } else {
            sumSoFar += nums[i];
            lenSoFar++;
        }
    }

    return maxLenSoFar;

}

};