class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        if(x<10)
            return true;
        //Get first digit 
        int mul = 1;
        while(x/mul>=10)
        {
            mul = mul*10;
        }
        while(x)
        {
            int firstDig = x/mul;
            int lastDig = x%10;
            if(firstDig!=lastDig)
                return false;
            int middles = (x%mul)/10;
            x = middles;
            mul /= 100;
        }
        return true;
    }
};