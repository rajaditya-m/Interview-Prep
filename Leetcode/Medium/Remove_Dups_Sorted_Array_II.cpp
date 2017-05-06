class Solution {
public:
    int removeDuplicates(int A[], int n) {
       if(n<2)
        return n;
       int i = 0;
       int j=1;
       //implement correction 
       if(A[i]==A[i+1])
       {
           i++;
           j++;
       }
       while(i<n && j<n)
       {
           if(A[i]==A[j])
           {
               j++;
           }
           else
           {
               i++;
               A[i]=A[j];
               j++;
               if(j<n && A[i]==A[j])
               {
                   i++;
                   A[i]=A[j];
                   j++;
               }
           }
       }
        return (i+1);
    }
};