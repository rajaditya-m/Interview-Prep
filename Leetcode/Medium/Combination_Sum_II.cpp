class Solution {
public:
    //Assumes array is sorted
    std::vector<std::vector<int> > helper(std::vector<int> &can, int target)
    {
        std::vector<std::vector<int> > res;
        if(can.size()<1)
        {
            return res;
        }
        else if(can[0]==target)
        {
            std::vector<int> j;
            j.push_back(can[0]);
            res.push_back(j);
            return res;
        }
		else if(can[0]>target)
		{
			return res;
		}
		else
		{
			//No dups in search 
			if(can.size()>1)
			{
				int nxt = 1;
				while(nxt<can.size() && can[nxt]==can[0])
					nxt++;
				if(nxt<can.size() && can[nxt]<=target)
				{
					std::vector<int> nv(can.begin()+nxt,can.end());
					std::vector<std::vector<int> > l = helper(nv,target);
					if(l.size()>0)
					{
						for(int k=0;k<l.size();k++)
						{
							std::vector<int> xx = l[k];
							res.push_back(xx);
						}
					}
				}
			}
			std::vector<int> nv(can.begin()+1,can.end());
			std::vector<std::vector<int> > l = helper(nv,target-can[0]);
			if(l.size()>0)
            {
                for(int k=0;k<l.size();k++)
                {
                    std::vector<int> xx = l[k];
                    xx.insert(xx.begin(),can[0]);
                    res.push_back(xx);
                }
            }
		}
        return res;
    }

	
std::vector<std::vector<int> > combinationSum2(std::vector<int> &candidates, int target) {
        std::sort(candidates.begin(),candidates.end());
        return helper(candidates,target);
    }
};