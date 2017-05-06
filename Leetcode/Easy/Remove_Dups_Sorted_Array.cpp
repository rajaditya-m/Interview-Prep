class Solution {
public:
    int removeDuplicates(int A[],int n)
    {
        if(n<2)
            return n;
        int i,j;
        i=0;
        j=1;
        while(i<n && j<n)
        {
            if(A[i]==A[j])
                j++;
            else
            {
                i++;
                A[i] = A[j];
                j++;
            }
        }
        return i+1;
    }
};