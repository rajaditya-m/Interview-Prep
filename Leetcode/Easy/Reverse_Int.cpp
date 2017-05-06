class Solution {
public:
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
};