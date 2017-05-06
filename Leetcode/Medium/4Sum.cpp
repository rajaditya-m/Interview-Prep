class Solution {
public:
    std::vector<std::vector<int> > fourSum(std::vector<int> num, int target)
{
	std::sort(num.begin(),num.end());
	std::vector<std::vector<int> > result;
	int n = num.size();
	int first = 0;
	int second = 0;
	int fourth = n-1;
	int counter = 0;
	for(first = 0;first<n-3;first++)
	{
	    if(first!=0)
	    {
	        if(num[first]==num[first-1])
	            continue;
	    }
	    for(second = first+1;second<n-2;second++)
	    {
	        if(second!=first+1)
	        {
	            if(num[second]==num[second-1])
	                continue;
	        }
	        int third = second+1;
    		int fourth = n-1;
    		int interSum = num[first] + num[second];
    		while(third<fourth)
    		{
    			int sum = interSum + num[third] + num[fourth];
    			if(sum<target)
    			{
    				third++;
    			}
    			else if(sum>target)
    			{
    				fourth--;
    			}
    			else 
    			{
    				std::vector<int> comp;
    				comp.push_back(num[first]);
    				comp.push_back(num[second]);
    				comp.push_back(num[third]);
    				comp.push_back(num[fourth]);
    				result.push_back(comp);
    				third++;
    				fourth--;
    				while(third<fourth && num[third]==num[third-1])
					    third++;
					while(third<fourth && num[fourth]==num[fourth+1])
					    fourth--;
    			}
    		}
	    }
	}
	return result;
}
};