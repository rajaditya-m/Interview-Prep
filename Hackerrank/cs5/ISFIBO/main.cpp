#include <iostream>
#include <cmath>

int main()
{
	long long int num = 3;
	double d = (double)num;
	double sqrt5 = sqrt(5);
	double phi = (1.0+sqrt5)*0.5;
	double val = num*phi + 0.5;
	double logphi = log(phi);
	double susp_n = log(val)/log(phi);
	int n = floor(susp_n);
	//Now calculate teh two umbers
	int nc1 = (int)n;
	int nc2 = nc1+1;
	double appx1 = pow(phi,nc1)/sqrt5;
	double appx2 = pow(phi,nc2)/sqrt5;
	std::cout << (long long int)appx1 << "\n";
	std::cout << (long long int)appx2 << "\n";
	if(appx1==num || appx2==num)
		std::cout << "IsFibo" << "\n";
	else
		std::cout << "IsNotFibo" << "\n";
}