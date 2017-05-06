#include <iostream>
#include <cstdlib>
#include <vector>

bool is_palindrome(std::string s)
{
	int len = s.length();
	for(int j=0;j<(len/2);j++)
	{
		if(s[j]!=s[len-j-1])
			return false;
	}
	return true;
}


std::vector<std::vector<std::string> > partition(std::string s)
{
	int len = s.length();
	if(len==1)
	{
		std::vector<std::string> temp;
		temp.push_back(s);

		std::vector<std::vector<std::string> > res;
		res.push_back(temp);		
	}
	else
	{
		for(int i=1;i<=len-1;i++)
		{
			std::string part1 = x.substr(0,i);
			if(is_palindrome(part1))
			{
				std::vector<std::vector<std::string> > recursion_res = partition(part2);
				
			}
		}
	}
}



int main()
{
	std::string x = "abba";
	int len = x.length();
	for(int i=1;i<=len-1;i++)
	{
		std::string part1 = x.substr(0,i);
		std::string part2 = x.substr(i);
		std::cout << "[" << part1 << "," << part2 << "]\n";
	}
	std::cout << is_palindrome(x);
}