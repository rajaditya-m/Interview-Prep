class Solution {
public:
    void sortColors(int A[], int n)
	{
		int prev = -1;
		int cur = 0;
		int last = n-1;
		while(cur<=last)
		{ 
			if(A[cur]==1)
			{
				cur++;
			}
			else if(A[cur]==0)
			{
				int temp = A[prev+1];
				A[prev+1] = A[cur];
				A[cur] = temp;
				prev++;
				cur++;
			}
			else if(A[cur]==2)
			{
				int temp = A[last];
				A[last] = A[cur];
				A[cur] = temp;
				last--;
			}
		}
	}
};