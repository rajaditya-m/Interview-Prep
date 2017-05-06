class Solution {
public:
    int maxSubArray(int A[], int n) {
        int prevSum = A[0];
        int maxSum = A[0];
        for(int i=1;i<n;i++)
        {
            int curSum = prevSum + A[i];
            prevSum = std::max(curSum,A[i]);
            if(prevSum>maxSum)
                maxSum = prevSum;
        }    
        return maxSum;
        
    }
};