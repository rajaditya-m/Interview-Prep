#include <iostream>
#include <cstdlib>

int NthFibonacci(int n)
{
	if( n==1 || n==2 )
	{
		return 1;
	}
	else
	{
		return NthFibonacci(n-1) + NthFibonacci(n-2);
	}
}

int main()
{
	int n=20;
	std::cout << "The fibonacci number at " << n << " is " << NthFibonacci(n) << "\n";
	return(EXIT_SUCCESS);
}