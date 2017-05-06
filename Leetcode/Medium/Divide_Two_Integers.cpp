class Solution {
public:
int divide(int dividend, int divisor) 
{
	bool hasNeg = false;
	long long int dividendL = dividend;
	long long int divisorL = divisor;
	if(dividendL<0 && divisorL<0)
	{
		dividendL = -dividendL;
		divisorL = -divisorL;
	}
	else if(dividendL<0)
	{
		dividendL = -dividendL;
		hasNeg = true;
	}
	else if(divisorL<0)
	{
		divisorL = -divisorL;
		hasNeg = true;
	}
	long long int quotient = 0;
	while(dividendL>divisorL)
	{
		long long int copyDivisor = divisorL;
		long long int multiplicand = 1;
		while(dividendL>copyDivisor)
		{
			copyDivisor = copyDivisor<<1;
			multiplicand = multiplicand<<1;
		}
		copyDivisor = copyDivisor>>1;
		multiplicand = multiplicand>>1;
		dividendL -= copyDivisor; 
		quotient += multiplicand;
	}
	if(dividendL==divisorL)
		quotient++;
	return (hasNeg?-quotient:quotient);
}
};