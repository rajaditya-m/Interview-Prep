class Solution {
public:
   bool hasNonZeros(std::string version) {
	int n,dot;
	std::string nS;
	do {
		dot = version.find(".");
		if (dot != std::string::npos) {
			nS = version.substr(0, dot);
			version = version.substr(dot + 1);
			n = atoi(nS.c_str());
		}
		else {
			n = atoi(version.c_str());
		}

		if (n != 0) {
			return true;
		}
	} while (dot != std::string::npos);
	
	return false;
}

int compareVersion(std::string version1, std::string version2) {
	int len1 = version1.length();
	int len2 = version2.length();

	bool finished1 = false;
	bool finished2 = false;
	int n1, n2;
	do {
		int dot1 = version1.find(".");
		int dot2 = version2.find(".");
		
		std::string n1S, n2S;
		if (dot1 != std::string::npos) {
			n1S = version1.substr(0, dot1);
			version1 = version1.substr(dot1 + 1);
			n1 = atoi(n1S.c_str());
		}
		else {
			n1 = atoi(version1.c_str());
			finished1 = true;
		}

		if (dot2 != std::string::npos) {
			n2S = version2.substr(0, dot2);
			version2 = version2.substr(dot2 + 1);
			n2 = atoi(n2S.c_str());
		}
		else {
			n2 = atoi(version2.c_str());
			finished2 = true;
		}
		
		if (n1 < n2)
			return -1;
		else if (n1 > n2)
			return 1;
	} while (!finished1 && !finished2);

	if (finished1 && finished2)
		return 0;
	else if (!finished1) {
		return (hasNonZeros(version1) ? 1 : 0);
	}
	else {
		return (hasNonZeros(version2) ? -1 : 0);
	}
}

};