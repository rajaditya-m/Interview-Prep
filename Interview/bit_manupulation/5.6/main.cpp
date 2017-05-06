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

uint32_t bitSwap(uint32_t n)
{
	uint32_t left_mask = 0xAAAAAAAA;
	uint32_t n_odd_masked = n & left_mask;
	uint32_t n_odd_even = n_odd_masked >> 1;
	uint32_t right_mask = 0x55555555;
	uint32_t n_even_masked = n & right_mask ;
	uint32_t n_even_odd = n_even_masked << 1;
	uint32_t fin_res = n_even_odd | n_odd_even;
	return fin_res;
}

int main()
{
	uint32_t x = 2451541560;
	std::cout << "Value of string before:";
	toBinary(x);
	std::cout << "\n";
	uint32_t res = bitSwap(x);
	std::cout << "Value of string after :";
	toBinary(res);
	std::cout << "\n";
	return(EXIT_SUCCESS);
}