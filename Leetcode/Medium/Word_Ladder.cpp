class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        std::queue<std::pair<std::string,int> > q;
        std::unordered_set<std::string> occured;
        occured.insert(start);
        q.push(std::pair<std::string,int>(start,0));
        while(!q.empty())
        {
            std::string s = q.front().first;
            int depth = q.front().second;
            if(!s.compare(end))
                return depth+1;
            q.pop();
            for(int i=0;i<s.length();i++)
            {
                char ignore = s[i];
                int ig = ignore-'a';
                for(int j=0;j<=26;j++)
                {
                    std::string x = s;
                    if(j==ig)
                        continue;
                    x[i] = 'a'+j;
                    auto it = dict.find(x);
                    if(it!=dict.end())
                    {
                        if(occured.find(x)==occured.end())
                        {
                           q.push(std::pair<std::string,int>(x,depth+1));
                           occured.insert(x);
                        }
                    }
                }
            }
        }
        return 0;
    }
};