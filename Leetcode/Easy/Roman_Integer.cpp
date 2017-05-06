class Solution {
public:
    
    int value(char x)
    {
        switch(x)
        {
            case 'I' : return 1;
            case 'V' : return 5;
            case 'X' : return 10;
            case 'L' : return 50;
            case 'C' : return 100;
            case 'D' : return 500;
            case 'M' : return 1000;
            default : return -1;
        }
        return -1;
    }

    int romanToInt(string s) 
    {
        int prevval = -1;
        int result = 0;
        for(int i=0;i<s.size();i++)
        {
            int curval = value(s[i]);
            if(prevval==-1)
            {
                result = curval;
                prevval = curval;
            }
            else
            {
                if(prevval>=curval)
                {
                    result = result + curval;
                }
                else
                {
                    result = result + curval - (2*prevval);   
                }
                prevval = curval;
            }
        }
        return result;
    }
};