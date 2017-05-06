class Solution {
public:
    vector<vector<string>> partition(string s)
    {
        std::vector<std::vector<std::string> > result;
        int num = s.length();
        if(num==1)
        {
            std::vector<std::string> res; 
            res.push_back(s);
            result.push_back(res);
        }   
        else
        {
            for(int i=1;i<=num;i++)
            {
                std::string split = s.substr(0,i);
                if(isPalindrome(split))
                {
                    std::string restStr = s.substr(i);
                    std::vector<std::vector<std::string> > retRes = partition(restStr);
                    std::vector<std::vector<std::string> >::iterator it;
                    for(it=retRes.begin();it!=retRes.end();++it)
                    {
                        std::vector<std::string> oneElem = *it;
                        oneElem.insert(oneElem.begin(),split);
                        result.push_back(oneElem);
                    }
                    if(restStr.length()==0)
                    {
                        std::vector<std::string> lastOne;
                        lastOne.push_back(split);
                        result.push_back(lastOne);
                    }
                }
            }
        }
        return result;
    }
    
   bool isPalindrome(std::string s)
   {
       int len = s.length();
       int start = 0;
       int end = len-1;
       while(start<end)
       {
           if(s[start]!=s[end])
                return false;
            start++;
            end--;
       }
       return true;
   }
};