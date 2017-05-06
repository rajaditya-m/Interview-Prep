class Solution {
public:
    int findLeft(std::vector<int> &nums, int target){
    int n = nums.size();
    int start = 0;
    int end = n-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(nums[mid]==target){
            if(mid-1>=0){
                if(nums[mid-1]<target)
                    return mid;
                else {
                    end = mid-1;
                }
            }
            else {
                return mid;
            }
        } else if(nums[mid]>target){
            end = mid-1;
        }
        else {
            start = mid+1;
        }

    }
    return -1;
}

int findRight(std::vector<int> &nums, int target){
    int n = nums.size();
    int start = 0;
    int end = n-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(nums[mid]==target){
            if(mid+1<n){
                if(nums[mid+1]>target)
                    return mid;
                else {
                    start = mid+1;
                }
            }
            else {
                return mid;
            }
        } else if(nums[mid]>target){
            end = mid-1;
        }
        else {
            start = mid+1;
        }

    }
    return -1;
}

std::vector<int> searchRange(std::vector<int> &nums, int target){
    std::vector<int> res;
    res.push_back(findLeft(nums,target));
    res.push_back(findRight(nums,target));
    return res;
}
};