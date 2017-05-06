class Solution {
public:
    std::string multiplyDigs(std::string s, char x)
	{
		int carry = 0;
		int xD = x-'0';
		std::string resStr = "";
		for(int i=s.length()-1;i>=0;i--)
		{
			int dig1 = s[i]-'0';
			int res = dig1*xD;
			res += carry;
			int resdig0 = res%10;
			int resdig1 = res/10;
			std::string x;
			x.push_back(resdig0+'0');
			resStr = x + resStr;
			carry = resdig1;
		}
		if(carry>0)
		{
			std::string x;
			x.push_back(carry+'0');
			resStr = x + resStr;
		}
		return resStr;
	}

	std::string add(std::string num1, std::string num2)
	{
		int l1 = num1.length();
		int l2 = num2.length();
		int newLen = l1;
		if(l1>l2)
		{
			int diff = l1-l2;
			std::string zeroPad ;
			while(diff)
			{
				zeroPad.push_back('0');
				diff--;
			}
			num2 =  zeroPad + num2;
		}
		else if(l1<l2)
		{
			int diff = l2-l1;
			std::string zeroPad ;
			while(diff)
			{
				zeroPad.push_back('0');
				diff--;
			}
			num1 =  zeroPad + num1;
			newLen = l2;
		}
		std::string resStr;
		int carry = 0;
		for(int i=newLen-1;i>=0;i--)
		{
			int dig1 = num1[i]-'0';
			int dig2 = num2[i]-'0';
			int sum = dig1 + dig2 + carry;
			int resdig0 = sum%10;
			carry = sum/10;
			std::string x;
			x.push_back(resdig0+'0');
			resStr = x + resStr;
		}
		if(carry>0)
		{
			std::string x;
			x.push_back(carry+'0');
			resStr = x + resStr;
		}
		return resStr;
	}

	std::string multiply(std::string num1, std::string num2)
	{
		std::string val = "000";
		int pow = 0;
		for(int s2 = num2.length()-1;s2>=0;s2--)
		{
			std::string intres = multiplyDigs(num1,num2[s2]);
			int counter = pow;
			while(counter)
			{
				intres.push_back('0');
				counter--;
			}
			std::string sumRes = add(intres,val);
			val = sumRes;
			pow++;
		}
		//Delete leading zeros
		int countLeadingZeros=0;
		int idx = 0;
		while(val[idx++]=='0')
			countLeadingZeros++;
		if(countLeadingZeros==val.length())
			return val.substr(0,1);
		else if(countLeadingZeros>0)
		{
			return val.substr(countLeadingZeros);
		}
		return val;
	}
};