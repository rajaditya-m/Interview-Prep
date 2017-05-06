#include <iostream>
#include <cstdlib>

typedef unsigned int uint32_t;

void toBinary(uint32_t n)
{
	if(n==0 || n== 1)
	{
		std::cout << n;
		return ;
	}
	toBinary(n/2);
	std::cout << (n%2);
}

int bitChange(uint32_t a, uint32_t b)
{
	uint32_t x = a ^ b;
	//now we have to count the number of 1's in x
	int count = 0;
	while(x!=0)
	{
		bool res = x & 1;
		if(res)
			count++;
		x = x >> 1;
	}
	return count;
}

int main()
{
	uint32_t a=31,b=14;
	std::cout << "Number of bit-flips required to change " << a << " to " << b << " is " << bitChange(a,b) << "\n"; 
	return(EXIT_SUCCESS);
}