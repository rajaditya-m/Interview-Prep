#include <iostream>
#include <cstdlib>

void toBinary(unsigned int n)
{
	if(n==0 || n== 1)
	{
		std::cout << n;
		return ;
	}
	toBinary(n/2);
	std::cout << (n%2);
}

int main()
{
	unsigned int n = 1024;
	unsigned int m = 19;
	unsigned int i=2;
	unsigned int j=6;
	//Clear all bits of n between i and j 
	unsigned int right_sub_mask = ~(~0 << i);
	unsigned int left_sub_mask = (~0 << (j+1));
	unsigned int sub_mask =  right_sub_mask | left_sub_mask ;
	unsigned int cleared_n = n & sub_mask;
	unsigned int f_mask = m << i;
	unsigned int f_res = cleared_n | f_mask;
	toBinary(cleared_n);
	std::cout << "\n";

}

