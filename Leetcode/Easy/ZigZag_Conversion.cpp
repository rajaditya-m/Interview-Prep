class Solution {
public:
    std::string convert(std::string s, int nRows)
{
	std::vector<std::string> all;
	all.resize(nRows,"");
	int cur = 0;
	bool finished = false;
	while(!finished)
	{
		for(int i=0;i<nRows;i++)
		{
			if(cur<s.length())
			{
				all[i].push_back(s[cur]);
				cur++;
			}
			else
			{
				finished = true;
				break;
			}
		}
		for(int i=nRows-2;i>=1;i--)
		{
			if(cur<s.length())
			{
				all[i].push_back(s[cur]);
				cur++;
			}
			else
			{
				finished = true;
				break;
			}
		}
	}
	std::string res = "";
	for(int i=0;i<nRows;i++)
		res += all[i];
	return res;
}
};