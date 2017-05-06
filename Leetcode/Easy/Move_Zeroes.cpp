class Solution {
public:
    void moveZeroes(std::vector<int> &num) {
	int n = num.size();
	int i = -1;
	for(int j=0;j<n;++j){
		if(num[j]!=0) {
			i++;
			int tmp = num[i];
			num[i] = num[j];
			num[j]= tmp;
		}
	}
}
};