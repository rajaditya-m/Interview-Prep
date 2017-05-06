class Solution {
public:

std::vector<std::string> getLetterVector(char x)
{
     std::vector<std::string> result;
     std::string i;
    switch(x)
            {
                case '2' : i="a"; result.push_back(i); i = "b" ; result.push_back(i); i = "c" ; result.push_back(i); break;
                case '3' : i="d"; result.push_back(i); i = "e" ; result.push_back(i); i = "f" ; result.push_back(i); break;
                case '4' : i="g"; result.push_back(i); i = "h" ; result.push_back(i); i = "i" ; result.push_back(i); break;
                case '5' : i="j"; result.push_back(i); i = "k" ; result.push_back(i); i = "l" ; result.push_back(i); break;
                case '6' : i="m"; result.push_back(i); i = "n" ; result.push_back(i); i = "o" ; result.push_back(i); break;
                case '7' : i="p"; result.push_back(i); i = "q" ; result.push_back(i); i = "r" ; result.push_back(i); i = "s" ; result.push_back(i); break;
                case '8' : i="t"; result.push_back(i); i = "u" ; result.push_back(i); i = "v" ; result.push_back(i); break;
                case '9' : i="w"; result.push_back(i); i = "x" ; result.push_back(i); i = "y" ; result.push_back(i); i = "z" ; result.push_back(i); break;
                
            }
            return result;
}



    vector<string> letterCombinations(string digits)
    {
        std::vector<std::string> result;
        int len = digits.length();
        if(!len)
        {
            result.push_back("");
            return result;
        }
        std::vector<std::string> first = getLetterVector(digits[0]);
        if(len>1)
        {
            std::string rest = digits.substr(1);
            std::vector<std::string> retVal = letterCombinations(rest);
            for(int i=0;i<first.size();i++)
            {
                std::string prefix = first[i];
                for(int j=0;j<retVal.size();j++)
                {
                    std::string suffix = retVal[j];
                    std::string final = prefix + suffix;
                    result.push_back(final);
                }
            }
        }
        else
        {
            result = first;
        }
        return result;
    }
};