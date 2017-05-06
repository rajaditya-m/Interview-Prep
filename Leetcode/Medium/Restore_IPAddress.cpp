class Solution {
public:
std::vector<std::string> restoreIPHelper(std::string s,int num)
{
	std::vector<std::string> res;
	if(num==1)
	{
		int len = s.length();
		if(len>0 && len<4)
		{
			bool hasLeading = false;
			if(len==2 && s[0]=='0')
			{
				hasLeading = true;
			}
			if(len==3 && ((s[0]=='0' && s[1]=='0')||(s[0]=='0' && s[1]!='0')))
			{
				hasLeading = true;
			}
			if(!hasLeading)
			{
				int x = atoi(s.c_str());
				if(x>=0 && x<256)
				{
					std::ostringstream oss;
					oss << s ;
					std::string r(oss.str());
					res.push_back(r);
				}
			}
		}
	}
	else
	{
		//Take 3 numbers 
		std::vector<std::string> res1;
		int len = s.length();
		if(len>0)
		{
			std::string s1 = s.substr(0,1); 
			std::string r1 = s.substr(1); 
			int i1 = atoi(s1.c_str());
			if(i1>=0 && i1<256)
			{
				res1 = restoreIPHelper(r1,num-1);
				for(int i=0;i<res1.size();i++)
				{
					std::ostringstream oss;
					oss << s1 << "." << res1[i];
					res.push_back(oss.str());
				}
			}
		}
		if(len>1)
		{
			std::string s2 = s.substr(0,2); 
			if(s2[0]!='0')
			{
				std::string r2 = s.substr(2); 
				int i2 = atoi(s2.c_str());
				if(i2>=0 && i2<256)
				{
					res1 = restoreIPHelper(r2,num-1);
					for(int i=0;i<res1.size();i++)
					{
						std::ostringstream oss;
						oss << s2 << "." << res1[i];
						res.push_back(oss.str());
					}
				}
			}
		}
		if(len>2)
		{
			std::string s3 = s.substr(0,3);
			bool hasLeadingZeros = false;
			if((s3[0]=='0' && s3[1]=='0')||(s3[0]=='0' && s3[1]!='0'))
				hasLeadingZeros = true;
			if(!hasLeadingZeros)
			{
				std::string r3 = s.substr(3); 
				int i3 = atoi(s3.c_str());
				if(i3>=0 && i3<256)
				{
					res1 = restoreIPHelper(r3,num-1);
					for(int i=0;i<res1.size();i++)
					{
						std::ostringstream oss;
						oss << s3 << "." << res1[i];
						res.push_back(oss.str());
					}
				}
			}
		}
	}
	return res;
}


 std::vector<std::string> restoreIpAddresses(std::string s)
 {
	   return restoreIPHelper(s,4);   
 }
};