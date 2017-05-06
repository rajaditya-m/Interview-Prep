class Solution {
public:
    std::string longestPalindrome(std::string s)
	{
		int len = s.length();
		bool table[1000][1000] = {false};
		int maxlen=1;
		int maxstart=0;
		for(int i=0;i<len;i++)
		{
			table[i][i] = true;
		}
		for(int i=0;i<len-1;i++)
		{
			if(s[i]==s[i+1])
			{
				table[i][i+1] = true;
				maxlen = 2;
				maxstart = i;
			}
		}
		for(int l=3;l<=len;l++)
		{
			for(int i=0;i<len-l+1;i++)
			{
				int j = i+l-1;
				if(s[i]==s[j] && table[i+1][j-1])
				{
					maxlen = l;
					maxstart = i;
					table[i][j] = true;
				}
			}
		}
		return s.substr(maxstart,maxlen);
	}
};