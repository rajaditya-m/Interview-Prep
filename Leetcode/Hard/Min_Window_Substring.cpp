class Solution {
public:
    string minWindow(string S, string T) {
        std::vector<int> needToFind(128,0);
        std::vector<int> hasFound(128,0);
        for(int k=0;k<T.length();k++)
        {
            needToFind[T[k]]++;
        }
        int minWLen = INT_MAX;
        int minWStart = -1;
        int count = 0;
        int begin = 0;
        for(int k=0;k<S.length();k++)
        {
            if(needToFind[S[k]]==0)
                continue;
            hasFound[S[k]]++;
            if( hasFound[S[k]]<=needToFind[S[k]])
                count++;
                
            if(count==T.length())
            {
                while(needToFind[S[begin]]==0 || (hasFound[S[begin]]>needToFind[S[begin]]))
                {
                    if(hasFound[S[begin]]>needToFind[S[begin]])
                    {
                        hasFound[S[begin]]--;
                    }
                    begin++;
                }
                int wLen = k-begin+1;
                if(wLen<minWLen)
                {
                    minWLen = wLen;
                    minWStart = begin;
                }
            }
        }
        std::string res;
        if(minWStart==-1)
        {
            res = "";
        }
        else
        {
            res = S.substr(minWStart,minWLen);
        }
        return res;
        
        
    }
};