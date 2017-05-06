class Solution {
public:
   int uniqueNumericalHash(std::string s){
	int res=0;
	int counter = 0;
	for(int i=9;i>=0;i--){
		char x = s[i];
		if(x=='A'){
			counter+=2;
		}
		else if(x=='T'){
			counter++;
			int mask = 1<<counter;
			res |= mask;
			counter++;
		}
		else if(x=='G'){
			int mask = 1<<counter;
			res |= mask;
			counter+=2;
		}
		else if(x=='C'){
			int mask = 1<<counter;
			res |= mask;
			counter++;
			mask = 1<<counter;
			res |= mask;
			counter++;
		}
	}
	return res;
}

std::vector<std::string> findRepeatedDnaSequences(std::string s) {
	int l = s.size();
	std::unordered_set<int> table;
	std::set<std::string> setler;
	for(int i=0;i<=l-10;i++){
		std::string subs = s.substr(i,10);
		int x = uniqueNumericalHash(subs);
		auto it = table.find(x);
		if(it!=table.end()){
			setler.insert(subs);
		}
		else {
			table.insert(x);
		}
	}
	std::vector<std::string> optvec;
	optvec.resize(setler.size());
	std::copy(setler.begin(),setler.end(),optvec.begin());
	return optvec;
}
};