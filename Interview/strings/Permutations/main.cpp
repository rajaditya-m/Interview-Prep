#include <iostream>
#include <cstring>
#include <vector>

std::vector<std::string>& computePermutation(std::string str)
{
	std::vector<std::string> result;
	int len = str.length();
	if(len==1)
	{
		result.push_back()
	}
	else
	{
		for(int i=0;i<len;i++)
		{
			char temp =str[0];
			str[0] = str[i];
			str[i] = temp;
			std::string truncated = str.substr(0);
			std::vector<std::string> residues = computePermutation(truncated);
			std::vector<std::string>::iterator it;
			for(it=residues.begin();it!=residues.end();++it)
			{
				std::string newstr = str[0] + (*it);
				result.push_back(newstr);
			}
		}
	}
	return result;

}


int main()
{
	std::string s = "ABC";
	std::vector<std::string> res = computePermutation(s);
	std::vector<std::string>::iterator it;
	for(it=res.begin();it!=res.end();++it)
	{
		std::cout << *it << "\n";
	}
}