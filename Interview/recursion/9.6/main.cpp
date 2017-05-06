#include <iostream>
#include <cstdlib>
#include <set>
#include <string>

std::string insert_paren_pair(std::string &str,int loc)
{
	std::string substr1 = str.substr(0,loc+1);
	std::string substr2 = str.substr(loc+1);
	std::string retstr = substr1 + "()" + substr2;
	return retstr;
}

std::set<std::string> generate_paren(int len)
{
	std::set<std::string> ret_val;
	if(len==1)
	{
		ret_val.insert("()");
	}
	else
	{
		std::set<std::string> interim = generate_paren(len-1);
		std::set<std::string>::iterator it;
		std::string::iterator sit;
		for(it = interim.begin();it != interim.end();++it)
		{
			std::string cur = *it;
			//1st append the plus and try to add the result
			ret_val.insert("()"+cur);
			//Next do element by element and see the result 
			int len_c = cur.length();
			for(int idx=0;idx<len_c;idx++)
			{
				if(cur[idx]=='(')
					ret_val.insert(insert_paren_pair(cur,idx));
			}
		}
	}
	return ret_val;
}

void printSet(std::set<std::string> st)
{
	std::set<std::string>::iterator it;
	for(it=st.begin();it!=st.end();++it)
	{
		std::cout << *it << "\n";
	}
}

int main()
{
	int len;
	std::cout << "Input the value of n:";
	std::cin >> len;
	std::set<std::string> res = generate_paren(len);
	printSet(res);
	return (EXIT_SUCCESS);
}
