class Solution {
public:
    int searchInsert(int A[], int n, int target)
{
	int start = 0;
	int end = n-1;
	while(start<=end)
	{
		int mid = (start+end)/2;
		if(A[mid]==target)
			return mid;
		else if(target<A[start])
			return start;
		else if(target>A[end])
			return end+1;
		else if(target<A[mid])
		{
			end = mid-1;
		}
		else 
		{
			start= mid+1;
		}
	}
	return end;
}
};