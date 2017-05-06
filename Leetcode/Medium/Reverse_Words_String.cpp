class Solution {
public:
void reverseWords(std::string &s)
	{
		s.push_back(' ');
		std::stack<std::string> st;
		int wordstart = 0;
		std::string word;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]==' ')
			{
				if(word.length()>0)
				{
					st.push(word);
					word = "";
				}
			}
			else
			{
				word.push_back(s[i]);
			}
		}
		s = "";
		while(!st.empty())
		{
			std::string cur = st.top();
			st.pop();
			//Last element check
			if(st.empty())
				s += cur;
			else
				s += (cur+" ");
		}
	}
};