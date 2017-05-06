class Solution {
public:
    std::string convertToTitle(int n) {
	std::string res = "";
	while (n > 0){
		int dig = (n-1) % 26;
		char x = dig + 'A';
		res.push_back(x);
		n = (n-1) / 26;
	}
	std::reverse(res.begin(), res.end());
	return res;
}
};