class Solution {
public:
int trailingZeroes(int n) {
	long long int num5 = 0;
	long long int div5 = 5;
	int val;
	do {
		val = n / div5;
		num5 += val;
		div5 *= 5;
	} while (val);
	return num5;
}
};