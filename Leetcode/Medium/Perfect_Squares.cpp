class Solution {
public:
bool isPerfectSquare(int n)
{
	int sq = (int)sqrt(n);
	if(sq*sq==n)
		return true;
	else 
		return false;
}

int numSquares(int n) 
{
  int* table = new int[n+1];
	for(int i=0;i<=n;i++)
	{
		if(isPerfectSquare(i))
			table[i]=1;
		else
			{
			  int min = 9999999;
				int minIdx = -1;
				int lim = (int)sqrt(i);
				for(int j=1;j<=lim;j++)
				{
					int c = table[i-(j*j)];
					if(c<min)
					{
						min = c;
						minIdx = j;
					}
				}
				table[i] = table[i-(minIdx*minIdx)]+1;
			}
		//std::cout << table[i] << "\n";
	}
	return table[n];

}
};