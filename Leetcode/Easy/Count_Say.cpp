#include <sstream>

class Solution {
public:
    string countAndSay(int n) {
        std::string res;
        if(n==1)
            res = "1";
        else
        {
            std::string last = countAndSay(n-1);
            int len = last.length();
            char lastD = '#';
            int counter=0;
            for(int i = 0;i<len;i++)
            {
                char c = last[i];
                if(c==lastD)
                {
                    counter++;
                }
                else
                {
                    if(lastD!='#')
                    {
                        std::stringstream ss;
                        ss << counter << lastD;
                        res =  res + ss.str();
                    }
                    counter = 1;
                    lastD = c;
                }
            }
            std::stringstream ss;
            ss << counter << lastD;
            res =  res + ss.str();
        }
        return res;
    }
};