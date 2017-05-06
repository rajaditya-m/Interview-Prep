#include <iostream>
#include <cstdlib>

#define SWAPI(x,y) int t;t=x;x=y;y=t;

typedef unsigned int uint32_t;
typedef unsigned char byte;

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

void drawHorizontalLine(byte screen[], uint32_t width, uint32_t len, uint32_t x1,uint32_t x2, uint32_t y)
{
	bool skipSetting = false;
	//find the row location
	uint32_t row_offset = (width/8) * y;
	// make sure x1 is always smaller than x2
	if(x1>x2)
		SWAPI(x1,x2);
	uint32_t x1_interbyte_offset = x1%8;
	uint32_t x2_interbyte_offset = x2%8;
	uint32_t x1_col_offset = x1/8;
	uint32_t x2_col_offset = x2/8;
	//Find all full bytes to fill
	uint32_t full_byte_start = x1_col_offset;
	uint32_t full_byte_end =x2_col_offset; 
	if(x1_interbyte_offset!=0)
	{
		full_byte_start++;
		skipSetting = true;
	}
	if(x2_interbyte_offset!=7)
	{
		full_byte_end--;
		skipSetting = true;
	}
	//Now set all the full bytes
	for(int idx=full_byte_start;idx<=full_byte_end;idx++)
	{
		screen[row_offset+idx] = 'X';
	}

	if(!skipSetting)
	{
		//Now we create a mask for the left one 
		uint32_t mask_left = (~0 >> x1_interbyte_offset);
		screen[row_offset+x1_col_offset] |= mask_left;
		//Also for the right one 
		uint32_t mask_right = ~(~0 >> (x2_interbyte_offset+1));
		screen[row_offset+x2_col_offset] |= mask_right;
	}
}

int main()
{
	byte x[] = {1,2,3};
	drawHorizontalLine(x,3,1,2,4,1);
	return(EXIT_SUCCESS);
}

