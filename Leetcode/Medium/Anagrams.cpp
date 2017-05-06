class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        int numStrs = strs.size();
        std::vector<std::string> result;
        std::map<std::string,int> indexMap;
        std::set<int> anagrams;
        for(int i=0;i<numStrs;i++)
        {
            std::string cur = strs[i];
            std::sort(cur.begin(),cur.end());
            //Now we have a sorted string
            std::map<std::string,int>::iterator itt;
            itt = indexMap.find(cur);
            //Unique element insert it 
            if(itt==indexMap.end())
            {
                indexMap.insert(std::pair<std::string,int>(cur,i));
            }
            else
            {
                anagrams.insert(itt->second);
                result.push_back(strs[i]);
            }
        }
        //Now we put all those original words
        std::set<int>::iterator its;
        for(its=anagrams.begin();its!=anagrams.end();its++)
        {
            result.push_back(strs[*its]);
        }
        return result;
    }
};