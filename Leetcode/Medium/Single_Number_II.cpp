class Solution {
public:
    int singleNumber(int A[], int n) {
        int bitcount = 0;
        int result = 0;
        for(int i=0;i<32;i++)
        {
            bitcount=0;
            for(int j=0;j<n;j++)
            {
                int res = A[j] & (1<<i) ;
                if(res)
                    bitcount++;
            }
            if(bitcount%3==1)
                result |= (1<<i);
        }
        return result;
    }
};