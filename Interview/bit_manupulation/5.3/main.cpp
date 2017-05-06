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

bool getBit(uint32_t n, int i)
{
	return (((1<<i) & n)!=0);
}

uint32_t getNext(uint32_t n)
{
	//1st get the location of the rightmost non-trailing zero
	// Also number of 1's and 0's that occur before it 
	bool right_most_one_found = false;
	int p=-1;
	int c_1=0,c_0=0;
	for(int loc=0;loc<32;loc++)
	{
		if(getBit(n,loc))
		{
			right_most_one_found = true;
			c_1++;
		}
		else if(!getBit(n,loc) && !right_most_one_found )
		{
			c_0++;
		}
		else if(right_most_one_found)
		{
			p = loc;
			break; 
		}
	}
	if(p==-1)
	{
		std::cout << "[ERROR] No higher number exists that has the same number of 1's.";
	}
	//Change the zero at p to 1
	n |= (1<<p);
	//Clear all bits to the right of p
	uint32_t mask_c = (~0 << p);
	uint32_t right_cleared_n = n & mask_c;
	// add c_1 number of 1's after moving c_0 spaces
	uint32_t mask_f = ~(~0 << (c_1-1));
	uint32_t fin_res = right_cleared_n | mask_f;
	return fin_res;
}

uint32_t getPrev(uint32_t n)
{
	//1st get the location of the rightmost non-trailing one
	//and also the number of trailing 0s and 1s
	bool right_most_zero_found = false;
	int p=-1;
	int c_1=0,c_0=0;
	for(int loc=0;loc<32;loc++)
	{
		if(!getBit(n,loc))
		{
			right_most_zero_found = true;
			c_0++;
		}
		else if(getBit(n,loc) && !right_most_zero_found )
		{
			
			c_1++;
		}
		else if(right_most_zero_found)
		{
			p = loc;
			break; 
		}
	}
	//Now flip the bit to 0
	n &= (~(1<<p));
	//Next clear all the bits from p onwards to 1
	uint32_t mask_c = (~0 << p);
	uint32_t right_cleared_n = n & mask_c;
	//Next add c_1+1 1s immediately after cleared p
	c_1++;
	uint32_t mask_f = (~(~0 << c_1)) << (p-c_1);
	uint32_t fin_res = right_cleared_n | mask_f;
	return fin_res;
}

int main()
{
	uint32_t n = 10115;
	getPrev(n);
	std::cout << "Next larger number after " << n << " is " <<  getNext(n) << "\n";
	std::cout << "Next smaller number before " << n << " is " <<  getPrev(n) << "\n";
	return (EXIT_SUCCESS);
}