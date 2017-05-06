class Solution {
public:
    int search(int A[], int n, int target) {
        int start = 0;
        int end = n-1;
        while(start<=end)
        {
            int mid = (start+end)/2;
            if(A[mid]==target)
            {
                return mid;
            }
            //Check if left half is sorted
            if(A[start]<=A[mid]) //left half if sorted
            {
                if(target>=A[start] && target<A[mid])
                    end = mid-1;
                else
                    start = mid+1;
            }
            else
            {
                if(target<=A[end] && A[mid]<target)
                    start = mid+1;
                else
                    end = mid-1;
            }
        }
        return -1;
    }
};