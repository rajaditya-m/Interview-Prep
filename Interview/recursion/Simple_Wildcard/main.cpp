#include <iostream>
#include <cstdlib>

void print_wildcard(std::string str,std::string prefix)
{
	if(str[0]=='\0')
	{
		std::cout << prefix << "\n";
		return;
	}
	std::string from1 = "";
	from1 = str.substr(1);
	if(str[0]=='?')
	{
		print_wildcard("0"+from1,prefix);
		print_wildcard("1"+from1,prefix);
	}
	else
	{
		prefix += str[0];
		print_wildcard(from1,prefix);
	}
}

int main()
{
	std::string x = "1?00?101";
	print_wildcard(x,"");
}