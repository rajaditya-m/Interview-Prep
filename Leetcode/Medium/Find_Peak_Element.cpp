class Solution {
public:
    int findPeakElement(const std::vector<int> &num) {
	int n = num.size();
	std::vector<int> checker(n, 0);
	bool peakFound = false;
	int peakIdx = -1;
	do {
		int randIdx = rand() % n;
		if (checker[randIdx] == 1)
			continue;
		bool leftCheck = true, rightCheck = true;
		if (randIdx - 1 >= 0) {
			if (num[randIdx] > num[randIdx - 1])
				leftCheck = true;
			else
				leftCheck = false;
		}
		if (randIdx + 1 < n) {
			if (num[randIdx] > num[randIdx + 1])
				rightCheck = true;
			else
				rightCheck = false;
		}
		if (leftCheck&&rightCheck) {
			peakFound = true;
			peakIdx = randIdx;
		}
		else {
			checker[randIdx] = 1;
		}
	} while (!peakFound);
	return peakIdx;
}
};