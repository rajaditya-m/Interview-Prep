 void invert(std::vector<int>& nums, int start, int end){
    int front = start;
    int back = end;
    while(front<back){
        int tmp = nums[front];
        nums[front] = nums[back];
        nums[back] = tmp;
        front++;
        back--;
    }
}

void rotate(std::vector<int>& nums, int k) {
    int n = nums.size();
    if(k>n)
        k = k%n;
    invert(nums,0,n-1);
    invert(nums,0,k-1);
    invert(nums,k,n-1);
}