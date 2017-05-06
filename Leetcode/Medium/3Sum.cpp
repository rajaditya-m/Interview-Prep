class Solution {
public:
	std::vector<std::vector<int> > threeSum(std::vector<int> &num)
	{
		std::sort(num.begin(),num.end());
		std::vector<std::vector <int> > result ;
		int first = 0;
		int cmpIdx = num.size()-1;
		while(first<cmpIdx)
		{
			int second = first+1;
			int third = num.size()-1;
			while(second<third)
			{
				int sumNow = num[first] + num[second];
				if(sumNow + num[third] > 0)
				{
					third--;
				}
				else if(sumNow + num[third] < 0 )
				{
					second++;
				}
				else
				{
					std::vector<int> resVec;
					resVec.push_back(num[first]);
					resVec.push_back(num[second]);
					resVec.push_back(num[third]);
					result.push_back(resVec);
					second++;
					third--;
					while(second<third && num[second]==num[second-1])
					    second++;
					while(second<third && num[third]==num[third+1])
					    third--;
				}
			}
			while(first<cmpIdx && num[first]==num[first+1])
				first++;
			first++;
		}
		return result;
    } 
};