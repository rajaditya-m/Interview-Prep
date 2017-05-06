class Solution {
public:
    bool isNumber(char x)
	{
		switch(x)
		{
		case '1' : 
		case '2' :
		case '3' :
		case '4' :
		case '5' :
		case '6' :
		case '7' :
		case '8' :
		case '9' :
		case '0' : return true;
		default: return false;
		}
	}

	bool isAcceptibleSuffix(char x)
	{
		switch(x)
		{
		case '\t' :
		case ' ' :
		case '+' :
		case '-' : return true;
		default : return false;
		}
	}

	int atoi(const char* str)
	{
		bool isPositive = true;
		bool suffixCheck = true;
		bool finished = false;
		std::stack<char> s;
		while(*str)
		{
			if(suffixCheck)
			{
				if(isAcceptibleSuffix(*str))
				{
					if(*str=='-' || *str=='+')
					{
					    if(*str=='-')
					        isPositive = false;
						suffixCheck = false;
					}
				}
				else if(isNumber(*str))
				{
					suffixCheck = false;
					s.push(*str);
				}
				else 
				{
					break;
				}
			}
			else if(isNumber(*str))
			{
				s.push(*str);
			}
			else
			{
				break;
			}
			str++;
		}
		long long int recons = 0;
		int powerIdx = 0;
		int sign = 1;
		if(!isPositive)
			sign = -1;
		while(!s.empty())
		{
			char c = s.top();
			s.pop();
			int x = c-'0';
			long long int addend = x*pow(10,powerIdx);
			recons += addend;
			powerIdx++;
		}
		if(!isPositive)
			recons *= -1;
	if(recons<INT_MIN)
		return INT_MIN;
	else if(recons>INT_MAX)
		return INT_MAX;
	else
		return recons;
	}
};