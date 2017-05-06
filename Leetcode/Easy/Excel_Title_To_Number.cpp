class Solution {
public:
    int titleToNumber(std::string s) {
	int n = s.length();
	int powIdx = 0;
	int res = 0;
	for (int i = n - 1; i >= 0; i--) {
		int idx = (s[i] - 'A')+1;
		res += idx*pow(26, powIdx);
		powIdx++; 
	}
	return res;
}
};