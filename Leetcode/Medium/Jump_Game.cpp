class Solution {
public:
    bool canJump(int A[], int n) {
        int largestJump = A[0];
        for(int i=1;i<n;i++)
        {
            if(largestJump<i)
                return false;
            largestJump = std::max(largestJump,A[i]+i);
        }
        if(largestJump>=n-1)
            return true;
        else
            return false;
            
    }
};