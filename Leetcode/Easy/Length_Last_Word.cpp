class Solution {
public:
    int lengthOfLastWord(const char *s) 
    {
        int prev = 0;
        int cur = 0;
        bool spaceEncountered = false;
        while(*s)
        {
            if(*s==' ' && *(s-1)!=' ')
            {
                prev = cur;
                cur = 0;
                spaceEncountered = true;
            }
            else if(*s!=' ')
            {
                spaceEncountered = false;
                cur++;
            }
            s++;
        }
        if(spaceEncountered)
            return prev;
        return cur;
    }
    
};.