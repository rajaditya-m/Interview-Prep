class Solution {
public:

std::vector<std::vector<int> >  generateMatrix(int n)
{
	std::vector<std::vector<int> > mat(n,std::vector<int>(n,0));
	int startR = 0;
	int startC = 0;
	int len = n;
	int val = 1;
	while(len>0)
	{
		for(int c=startC;c<startC+len;c++)
		{
			mat[startR][c] = val;
			val++;
		}
		for(int r=startR+1;r<startR+len;r++)
		{
			mat[r][startC+len-1] = val;
			val++;
		}
		for(int c=startC+len-2;c>=startC;c--)
		{
			mat[startR+len-1][c] = val;
			val++;
		}
		for(int r = startR+len-2;r>=startR+1;r--)
		{
			mat[r][startC] = val;
			val++;
		}
		startC++;
		startR++;
		len=len-2;
	}
	return mat;
}

};