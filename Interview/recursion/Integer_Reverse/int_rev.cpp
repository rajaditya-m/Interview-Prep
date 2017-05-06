#include <iostream>
#include <cstdlib>
#include <cmath>

int safe_to_add(int a,int b)
{
	long long c;
	c = (long long)a + b;
	if(c<INT_MIN||c>INT_MAX)
		return false;
	return true;
}

int reverse(int x)
{
	bool is_negative = false;
	if(x<0)
	{
		is_negative = true;
		x = abs(x);
	}
	int digits[11];
	int copy = x;
	int counter = 0;
	while(copy)
	{
		digits[counter++] = copy%10;
		copy = copy/10;
	}
	int res = 0;
	// std::cout << "Counter is " << counter << "\n";
	for(int i=0;i<counter;i++)
	{
		int base = (int)(pow(10,counter-i-1));
		int summand = digits[i]*base;
		bool proceed = safe_to_add(summand,res);
		if(proceed)
			res += summand;
		else 
			exit(EXIT_FAILURE);
	}
	if(is_negative)
		res = -res;
	return res;
}

int reverse_recursive(int x,int *idx)
{
	bool is_negative = false;
	if(x<0)
	{
		is_negative = true;
		x = abs(x);
	}
	int last_dig = x%10;
	int next = x/10;
	if(!next)
	{
		*idx = 1;
		if(is_negative)
			return -last_dig;
		else
			return last_dig;
	}
	else
	{
		int idx_refund;
		int reversed = reverse_recursive(next,&idx_refund);
		int base = pow(10,idx_refund);
		int res = base*last_dig+reversed;
		*idx = idx_refund + 1;
		if(is_negative)
			return -res;
		else
			return res;
	}
}

int main(int argc, char const *argv[])
{
	int placeholder;
	std::cout << reverse_recursive(123,&placeholder) << "\n";
	std::cout << reverse_recursive(-123,&placeholder) << "\n";
	std::cout << reverse_recursive(-100,&placeholder) << "\n";
	std::cout << reverse_recursive(100,&placeholder) << "\n";	
	return 0;
}