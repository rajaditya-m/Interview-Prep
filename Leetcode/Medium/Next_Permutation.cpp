class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int n = num.size();
        if(n<2)
            return;
        int k;
        for(k=n-2;k>=0;k--)
        {
            if(num[k]<num[k+1])
                break;
        }
        //This means that no such k exists
        if(k==-1)
        {
            reverse(num.begin(),num.end());
            return;
        }
        //Find the largest l
        int l;
        for(l=n-1;l>k;l--)
        {
            if(num[l]>num[k])
                break;
        }
        //Swap A[l] and a[k]
        int temp = num[l];
        num[l] = num[k];
        num[k] = temp;
        //Now reverse everything from k+1
        reverse(num.begin()+k+1,num.end());
    }
};