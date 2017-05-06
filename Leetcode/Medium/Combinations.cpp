class Solution {
public:

    vector<vector<int> > combine(int n, int k)
    {
        std::vector<int> org;
	    for(int i=1;i<=n;i++)
		    org.push_back(i);
	    return getCombinations(org,k,0,n-1);        
    }
    
    std::vector<std::vector<int> > getCombinations(std::vector<int> arr, int k, int nStart, int nEnd)
{
	std::vector<std::vector<int> > result;
	int num = (nEnd-nStart+1);
	//Base case
	if(num>=k && k==1)
	{
		for(int i = nStart;i<=nEnd;i++)
		{
			std::vector<int> tempVec;
			tempVec.push_back(arr[i]);
			result.push_back(tempVec);
		}
	}
	else if(num>=k)
	{
		//Get all the vectors from [nStart, nEnd]
		for(int i=nStart;i<nEnd;i++)
		{
			int curElem = arr[i];
			std::vector<std::vector<int> > retRes = getCombinations(arr,k-1,i+1,nEnd);
			int rowLen = retRes.size();
			for(int j=0;j<rowLen;j++)
			{
				std::vector<int> vv = retRes[j];
				vv.insert(vv.begin(),curElem);
				result.push_back(vv);
			}
		}
	}
	return result;
}
};