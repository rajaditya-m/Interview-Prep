class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int counterM, counterN = 0;
        int endM = m-1;
        counterM = counterN = 0;
        while(counterM<=endM && counterN<n)
        {
            if(A[counterM]>B[counterN])
            {
                //Push all the elements from counterM....endM by one place
                for(int k=endM+1;k>=counterM+1;k--)
                    A[k] = A[k-1];
                //Shift  endM by one place
                endM++;
                //Insert the element in B[counterN] to A[counterM] which is currently blank now
                A[counterM] = B[counterN];
                //Increment both counterM and counterN
                counterM++;
                counterN++;
            }
            else
            {
                counterM++;
            }
            
        }
        //There are elements left in B to process
        if(counterN<n)
        {
            int endP = endM+1;
            for(int j=counterN;j<n;j++)
                A[endP++] = B[j];
        }
    }
};