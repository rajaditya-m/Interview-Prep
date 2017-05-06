class Solution {
public:
std::vector<int> grayCode(int n) {
	std::vector<int> result;
	std::unordered_set<int> processed;
	std::stack<int> cur;
	cur.push(0);
	processed.insert(0);
	while (!cur.empty()) {
		int curElem = cur.top();
		cur.pop();
		int i, j;
		for (i = 0; i < n; i++) {
			int mask = 1 << i;
			int tmp = curElem | mask;
			auto it = processed.find(tmp);
			if (it == processed.end()) {
				processed.insert(tmp);
				cur.push(tmp);
				break;
			}
			int mask2 = ~(1 << i);
			tmp = curElem & mask2;
			it = processed.find(tmp);
			if (it == processed.end()) {
				processed.insert(tmp);
				cur.push(tmp);
				break;
			}
		}
		result.push_back(curElem);
	}
	return result;
}
};