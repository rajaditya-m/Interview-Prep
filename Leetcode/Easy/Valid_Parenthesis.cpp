class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;
        int len = s.length();
        for(int i=0;i<len;i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                st.push(s[i]);
            else if(s[i]==')' || s[i]=='}' || s[i]==']')
            {
                if(st.empty())
                    return false;
                char x = st.top();
                st.pop();
                if(s[i]==')' && x!='(')
                    return false;
                if(s[i]=='}' && x!='{')
                    return false;
                if(s[i]==']' && x!='[')
                    return false;
            }
        }
        return st.empty();
    }
};