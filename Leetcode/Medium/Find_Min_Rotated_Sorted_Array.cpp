class Solution {
public:
    int findMin(vector<int> &num) {
        return findPivot(num,0,num.size()-1);
    }
    
    int findPivot(std::vector<int>& A, int start, int end)
    {
        if(start>end)
            return 0;
        if(start==end)
            return A[end];
        int mid = (start+end)/2;
        if(mid+1<=end && A[mid+1]<A[mid])
            return A[mid+1];
        else if(A[mid]>A[end])
            return findPivot(A,mid+1,end);
        return findPivot(A,start,mid);
    }
};