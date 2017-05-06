class Solution {
public:
   int numDecodings(std::string s) {
	//Base case 0/1/2
	int len = s.length();
	std::vector<int> dptable(len,0);
	//Populate the first two entries
	if(len==0)
		return 0;
	int x1,x2,x;
	x1 = s[0]-'0';
	if(x1)
		dptable[0] = 1;
	else
	    return 0;
	for(int k=1;k<len;k++)
	{
		int xC = s[k]-'0';
		int xP = s[k-1]-'0';
		int x = xP*10+xC;
		if(x>9 && x<=26)
		{
			if(k>2)
			{
				dptable[k] += dptable[k-2];
			}
			else
			{
				dptable[k] = 1;
			}
		}
		if(xC)
		{
			dptable[k] += dptable[k-1];
		}
	}
	return dptable[len-1];
}
};