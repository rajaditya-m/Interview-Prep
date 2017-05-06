class Solution {
public:

    bool isNumber(std::string x)
    {
        int len = x.length();
        if(len>1)
            return true;
        if(x[0]=='+' || x[0]=='-' || x[0]=='*' || x[0]=='/')
            return false;
        return true;
    }

    int evalRPN(vector<string> &tokens) {
        std::stack<int> numStack;
        int numToken = tokens.size();
        for(int i=0;i<numToken;i++)
        {
            if(isNumber(tokens[i]))
            {
                int ival = atoi(tokens[i].c_str());
                numStack.push(ival);
            }
            else
            {
                int op1 = numStack.top();
                numStack.pop();
                int op2 = numStack.top();
                numStack.pop();
                int res;
                switch(tokens[i][0])
                {
                    case '+' : res = op2 + op1; break;
                    case '-' : res = op2 - op1; break;
                    case '*' : res = op2 * op1; break;
                    case '/' : res = op2 / op1; break;
                }
                numStack.push(res);
            }
        }
        return numStack.top();
    }
};