class Solution {
public:
   std::string longestCommonPrefix(std::vector<std::string> &strs)
{
       std::string ans = "";
	   if(strs.empty() || strs[0].empty())
		   return ans;
       for(int k=1;k<=strs[0].size();k++)
       {
            std::string onePrefix = strs[0].substr(0,k);
            for(int j=1;j<strs.size();j++)
            {
                std::string cur = strs[j];
				if(cur.length()<k)
					return ans;
				std::string subs = cur.substr(0,k);
				if(strcmp(subs.c_str(),onePrefix.c_str()))
				{
					return ans;
				}
            }
			ans = onePrefix;
        }
	   return ans;
    }
};