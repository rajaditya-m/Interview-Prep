#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

//std::set<std::string> permutations(std::string s, int len)
//{

//}

std::string insert_char_at(std::string &str, char c, int loc)
{
	int len = str.length();
	if(loc>len)
	{
		std::cout << "[ERROR] Invalid position to insert.\n";
		exit(EXIT_FAILURE);
	}
	std::string sub_str1 = str.substr(0,loc);
	std::string	sub_str2 = str.substr(loc,len-loc);
	std::string fin_string = sub_str1 + c + sub_str2;
	return fin_string;
}

std::vector<std::string > permutations(std::string &str)
{
	std::vector<std::string> result;
	int len = str.length();
	if(len==1)
	{
		result.push_back(str);
	}
	else
	{
		std::vector<std::string> interim;
		std::string from2nd = str.substr(1);
		interim = permutations(from2nd);
		std::vector<std::string>::iterator it;
		for(it = interim.begin();it != interim.end();it++)
		{
			std::string cur_str = *it;
			int cur_str_len = cur_str.length();
			for(int loc=0;loc<=cur_str_len;++loc)
			{
				result.push_back(insert_char_at(cur_str,str[0],loc));
			}
		}
	}
	return result;
}	

void printVector(std::vector<std::string> &vec)
{
	std::vector<std::string>::iterator it;
	for(it = vec.begin();it!= vec.end();it++)
	{
		std::cout << *it << "\n";
	}
}

int main()
{
	std::string test = "ABCD";
	std::vector<std::string> res = permutations(test);
	printVector(res);
	return (EXIT_SUCCESS);
}