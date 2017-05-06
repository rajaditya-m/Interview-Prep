class Solution {
public:
std::vector<std::vector<int> > permuteAug(std::vector<int> arr, int start, int end)
{
	std::vector<std::vector<int> > result;
	int len = end-start+1;
	if(len==1)
	{
		std::vector<int> j;
		j.push_back(arr[start]);
		result.push_back(j);
	}
	else
	{
		for(int i=start;i<=end;i++)
		{
			int l = arr[start];
			arr[start] = arr[i];
			arr[i] = l;
			std::vector<std::vector<int> > intRes = permuteAug(arr,start+1,end);
			for(int k=0;k<intRes.size();k++)
			{
				std::vector<int> kV = intRes[k];
				kV.insert(kV.begin(),arr[start]);
				result.push_back(kV);
			}
			l = arr[start];
			arr[start] = arr[i];
			arr[i] = l;
		}
	}
	return result;
}

std::vector<std::vector<int> > permute(std::vector<int> &num)
{
	int n = num.size();
	return permuteAug(num,0,n-1);
}
  
};