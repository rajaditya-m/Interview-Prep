int majorityElement_Slow(std::vector<int> &vec) {
	int n = vec.size();
	int threshold = n / 2;
	std::sort(vec.begin(), vec.end());
	return (vec[threshold]);
}

int majorityElement(std::vector<int> &vec) {
	int n = vec.size();
	int threshold = n / 2;

	int majorityElem = 0;
	int counter = 1;
	int loopCounter = 1;
	for (auto it = vec.begin() + 1; it != vec.end(); it++) {
		if (*it == vec[majorityElem])
			counter++;
		else
			counter--;
		if (counter == 0) {
			majorityElem = loopCounter;
			counter = 1;
		}
		loopCounter++;
	}

	return vec[majorityElem];

}