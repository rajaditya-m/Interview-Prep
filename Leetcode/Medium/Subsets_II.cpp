class Solution {
public:
    std::vector<std::vector<int> > subsetsWithDup(std::vector<int> &nums) {
	std::sort(nums.begin(),nums.end());
	std::unordered_map<int,int> dupCount;
	for(int i = 0;i<nums.size();i++){
		int j;
		for(j=i+1;j<nums.size();j++){
			if(nums[j]!=nums[i])
				break;
		}
		int numDups = j-i;
		if(numDups>1){
			dupCount.insert(std::pair<int,int>(nums[i],numDups));
		}
		i = j-1;
	}
	nums.erase(std::unique(nums.begin(),nums.end()),nums.end());
	//std::reverse(nums.begin(),nums.end());
	int nEff = nums.size();
	int lim = pow(2,nEff);
  std::vector< std::vector<int> > res;
  for(int i=0;i<lim;i++)
  {
      std::vector<std::vector<int> >resSet;
			std::vector<int> first;
			resSet.push_back(first);
      //Inspect the first n bits of lim
      int counter=0;
      while(counter!=nEff)
      {
          int res = (i>>counter)&1;
          if(!res)
          {
						int curNum = nums[counter];
						auto it = dupCount.find(curNum);
						if(it==dupCount.end()) {
							for(int i=0;i<resSet.size();i++)
								resSet[i].push_back(nums[counter]);
						}
						else {
							int numDups = it->second;
							int orgSize = resSet.size();
							for(int r=1;r<=numDups;r++){
								for(int i=0;i<orgSize;i++){
									if(r==1){
										resSet[i].push_back(nums[counter]);
									}
									else {
										std::vector<int> iveccopy(resSet[i]);
										for(int j=0;j<r-1;j++){
											iveccopy.push_back(nums[counter]);
										}
										resSet.push_back(iveccopy);
									}
								}
							}
						}
          }
          counter++;
      }
			for(int i=0;i<resSet.size();i++)
				res.push_back(resSet[i]);
  }
  return res;
} 
};