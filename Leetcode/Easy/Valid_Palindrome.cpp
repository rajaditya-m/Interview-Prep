class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.length()-1;
        while(start<=end)
        {
            while(!isalnum(s[start]) && start<=end)
                start++;
            while(!isalnum(s[end]) && end>start)
                end--;
            if(start<=end && toupper(s[start])!=toupper(s[end]))
                return false;
            start++;
            end--;
        }
        return true;
    }
};