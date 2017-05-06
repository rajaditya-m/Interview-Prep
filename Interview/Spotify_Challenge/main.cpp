#include <iostream>
#include <cstdlib>

long long int reverseInBinary(long long int num)
{
	int bit;
	long long int res=0;
	while(num)
	{
		bit = num%2;
		res = (res<<1)|bit;
		num = num/2;
	}
	return res;
}

int main()
{
	long long int num;
	std::cin >> num;
	std::cout << reverseInBinary(num);
}