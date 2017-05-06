class Solution {
public:
int longestValidParentheses(std::string s)
{
        std::stack<int> st;
        int len = s.length();
		bool lastPopped = false;
		std::vector<int> track(len,-1);
        for(int i=0;i<len;i++)
        {
            char x = s[i];
            if(x=='(')
            {
                st.push(i);
				track[i] = 0;
            }
            else if(x==')')
            {
                if(!st.empty())
                {
                    int k = st.top();
					st.pop();
                    track[i] = (i-k+1);
					for(int a=k;a<i;a++)
						track[a] = 0;
                }
            }
        }
		while(!st.empty())
		{
			int x = st.top();
			track[x] = -1;
			st.pop();
		}
		int longestLen = 0;
		int sumSoFar = 0;
		for(int i=0;i<len;i++)
		{
			//std::cout << track[i] << "--\n";
			if(track[i]==-1)
			{
				if(sumSoFar>longestLen)
				{
					longestLen = sumSoFar;
				}
				sumSoFar = 0;
			}
			else
			{
				sumSoFar += track[i];
			}
		}
		if(sumSoFar>longestLen)
			longestLen = sumSoFar;
		return longestLen;
 }
};