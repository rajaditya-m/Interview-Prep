class Solution {
public:
    bool wordBreak(std::string s, std::unordered_set<std::string> &dict) {
        std::vector<std::vector<bool> > occurs(s.size(),std::vector<bool>(s.size(),false));
		int len = s.size();
		//Contains all the words which are in the set
        for(int i=0;i<len;i++)
		{
			for(int j=i;j<len;j++)
			{
				occurs[i][j] = (dict.find(s.substr(i,j-i+1))!=dict.end());
			}
		}
		//Now we do the loop 
		for(int i=0;i<len;i++)
		{
			for(int j=i;j<len;j++)
			{
				for(int k=i;k<=j;k++)
				{
					if(!occurs[i][j])
						occurs[i][j] = occurs[i][k]&& occurs[k+1][j];
				}
			}
		}

		return occurs[0][len-1];

        
    }
};