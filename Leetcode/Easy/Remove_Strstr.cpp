class Solution {
public:
   int strStr(char *haystack, char *needle) {
       if(!*needle)
       {
           return 0;
       }
        int res = -1;
        int counter = 0;
        char* ncopy = needle;
        char* backPtr = haystack;
        while( *ncopy)
        {
            ncopy++;
            backPtr++;
        }
        backPtr--;
        while(*backPtr)
        {
            if(*haystack==*needle)
            {
                char *nc = needle;
                char* hc = haystack;
                while(*nc!='\0' && *nc==*hc)
                {
                    nc++; hc++;
                }
                if(*nc=='\0')
                {
                    res = counter;
                    break;
                }
            }
            haystack++;
            counter++;
            backPtr++;
        }
        return res;
    }
};