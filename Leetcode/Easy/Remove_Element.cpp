class Solution {
public:
    int removeElement(int A[], int n, int elem)
    {
        int newEnd = n-1;
        for(int i=0;i<=newEnd;i++)
        {
            if(A[i]==elem)
            {
                int temp = A[i];
                A[i] = A[newEnd];
                A[newEnd] = temp;
                newEnd--;
                i--;
            }
        }
        return newEnd+1;
    }
};