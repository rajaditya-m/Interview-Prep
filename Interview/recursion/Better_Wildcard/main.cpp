#include <iostream>
#include <cstdlib>

bool match_wildcard(std::string str, std::string pattern)
{
	if(pattern[0]=='\0')
		return true;
	if(str[0]=='\0')
		return false;
	int pat_len = pattern.length();
	int str_len = str.length();
	int idx;
	std::string from1pat = pattern.substr(1);
	std::string from1str = str.substr(1);
	if(pattern[0]=='.')
	{
		return match_wildcard(from1str,from1pat);
	}
	else if(pattern[0]=='*')
	{
		for(int idx=0;idx<str_len;idx++)
		{
			std::string fromi = str.substr(idx);
			if(match_wildcard(fromi,from1pat))
				return true;
		}
	}
	else if(pattern[0]==str[0])
		return match_wildcard(from1str,from1pat);
	return false;
}

int main()
{
	std::string x = "BANANA";
	std::string wc = "BA?A*";
	std::cout << match_wildcard(x,wc);
}