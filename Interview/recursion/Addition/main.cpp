#include <iostream>
#include <cstdlib>

int addWithoutAdd(int x, int y)
{
	if(x==0)
		return y;
	else if(y==0)
		return x;
	else
	{
		int xorOP = (x^y);
		int andOp = (x&y);
		return addWithoutAdd(xorOP,andOp<<1);
	}
}


int main()
{
	int x=50; 
	int y=70;
	std::cout << "Result of addition of " << x << " and " << y << " is " << addWithoutAdd(x,y) << "\n";
	return(EXIT_SUCCESS);
}