#include <iostream>
#include <cstdlib>
#include <map>

bool isAnagram(std::string str1,std::string str2)
{
	std::map<char,int> assocMap;
	int len1 = str1.length();
	int len2 = str1.length();
	int idx;
	//Put everything in string 1 
	for(idx=0;idx<len1;idx++)
	{
		char cur = str1[idx];
		if(cur==' ')
			continue;
		int cur_val = assocMap[cur];
		assocMap[cur] = cur_val+1;
	}
	//Now decrement using string 2
	for(idx=0;idx<len2;idx++)
	{
		char cur = str2[idx];
		if(cur==' ')
			continue;
		int cur_val = assocMap[cur];
		assocMap[cur] = cur_val-1;
	}
	//Now test if every element of string 1 is 0
	for(idx=0;idx<len1;idx++)
	{
		char cur = str1[idx];
		if(cur==' ')
			continue;
		int cur_val = assocMap[cur];
		if(cur_val!=0)
			return false;
	}
	return true;
}


int main(int argc, char const *argv[])
{
	std::string str1,str2;
	std::cout << "Input string 1:";
	std::getline(std::cin,str1);
	std::cout << "Input string 2:";
	std::getline(std::cin,str2);
	bool res = isAnagram(str1,str2);
	std::string str_res =  (res?"true":"false");
	std::cout << str1 << " is an anagram of " << str2 << " : " << str_res << "\n";
	return (EXIT_SUCCESS);
}