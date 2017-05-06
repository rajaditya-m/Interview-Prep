#include <iostream>

void foo1(std::string const& s)
{
	std::cout << s << "\n";
}

void foo2(std::string const& s)
{
 	s[2] = '2'; 
 	std::cout << s << "\n";
}

int main()
{
	std::string str = "Google";
	foo2(str);
}