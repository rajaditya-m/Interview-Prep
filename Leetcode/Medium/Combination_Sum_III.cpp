class Solution {
public:
    void insertByInsertionSort(std::vector<int> &arr,int target) {
    int n= arr.size();
    if(n==0){
        arr.push_back(target);
        return;
    }
    else {
        int i;
        for(i=n-1;i>=0;i--){
            if(arr[i]<=target){
                break;
            }
        }
        arr.insert(arr.begin()+i+1,target);
    }
}

std::vector<std::vector<int> > combinationSum3Helper(int k, int n, std::vector<bool> &allowed){
    std::vector<std::vector<int> > res;
    if(k==1){
        if(n>1 && n<10 && allowed[n-1]){
            std::vector<int> innerRes;
            innerRes.push_back(n);
            res.push_back(innerRes);
        }
    }
    else {
        std::vector<bool> allowedCopy(allowed);
        for(int i=0;i<9;i++){
            if(!allowed[i])
                continue;
            //std::vector<bool> allowedCopy(allowed);
            allowedCopy[i] = false;
            std::vector<std::vector<int> > retRes = combinationSum3Helper(k-1,n-(i+1),allowedCopy);
            if(retRes.size()){
                for(int j=0;j<retRes.size();j++){
                    std::vector<int> thisVec = retRes[j];
                    insertByInsertionSort(thisVec,i+1);
                    res.push_back(thisVec);
                }
            }
        }
    }
    return res;
}

std::vector<std::vector<int> > combinationSum3(int k, int n){
    std::vector<bool> initAllowed(9,true);
    return combinationSum3Helper(k,n,initAllowed);
}

};