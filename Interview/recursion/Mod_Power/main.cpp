#include <iostream>
#include <cstdlib>

int modPower(int x, int y, int z)
{
	int acc = 1;
	int a = x % z;
	while(y>0)
	{
		if(y&1)
			acc = (acc * a)%z;
		y >>=1;
		a = (a*a)%z;
	}
	return acc;
}

int modPowerRec(int x, int y, int z, int acc)
{
	if(y==0)
		return acc;
	int a = x%z;
	if(y&1)
	{
		acc = (acc*a)%z;
	}
	int newy = y>>1;
	int newx = (a*a)%z;
	return modPowerRec(newx,newy,z,acc);
}

int main()
{
	int x = 100;
	int y= 2;
	int z = 13;
	std::cout << "The answer is " << modPower(x,y,z) << "\n";
	std::cout << "The answer using recusrion is " << modPowerRec(x,y,z,1) << "\n";
	return(EXIT_SUCCESS);
}