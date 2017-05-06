class Solution {
public:
    int numTrees(int n)
	{
		int* count = new int[n+1];
		count[0] = 1;
		count[1] = 1;
		for(int len=2;len<=n;len++)
		{
			count[len] = 0;
			for(int i=1;i<=len;i++)
			{
				count[len] += (count[i-1]*count[len-i]);
			}
		}
		return count[n];
	}
};