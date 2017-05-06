class Solution {
public:
   bool isAnagram(std::string s, std::string t) {
	int table[26];
	memset(table,0,sizeof(int)*26);
	bool answer = true;
	for(int i=0;i<s.length();i++){
		table[s[i]-'a']++;
	}
	for(int i=0;i<t.length();i++){
		table[t[i]-'a']--;
	}
	for(int i=0;i<26;i++){
		if(table[i])
			answer = false;
	}
	return answer;
}
};