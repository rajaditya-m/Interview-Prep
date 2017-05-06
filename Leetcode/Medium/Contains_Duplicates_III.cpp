bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int k, int t) {
    std::vector<std::pair<long long int,int> > list;
    int n = nums.size();
    for(int i=0;i<n;i++){
        list.push_back(std::pair<long long int, int>((long long int)nums[i],i));
    }
    std::sort(list.begin(),list.end());
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(list[j].first-list[i].first<=t){
                if(abs(list[j].second-list[i].second)<=k)
                    return true;
            }else{
                break;
            }
        }
    }
    return false;
}