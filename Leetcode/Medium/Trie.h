#include <string>
#include <unordered_set>
#include <vector>

class TrieNode {
public:
	// Initialize your data structure here.
	TrieNode() {
		links_.resize(26,NULL);
	}
	std::vector<TrieNode*> links_;
	};

class Trie {
public:
	Trie() {
		root = new TrieNode();
		}

	// Inserts a word into the trie.
	void insert(std::string word) {
		int n = word.size();
		if(!n)
			return;
		TrieNode* cur = root;
		for(int i=0;i<n;i++) {
			char x = word[i];
			TrieNode* xNode = cur->links_[x-'a'];
			if(!xNode) {
				xNode = new TrieNode();
				cur->links_[x-'a'] = xNode;
			}
			cur = xNode;
		}
		wordSet_.insert(word);
	}

	// Returns if the word is in the trie.
	bool search(std::string word) {
		auto it = wordSet_.find(word);
		if(it!=wordSet_.end())
			return true;
		else
			return false;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(std::string prefix) {
		int n = prefix.size();
		TrieNode* cur = root;
		for(int i=0;i<n;i++){
			char x = prefix[i];
			TrieNode* xNode = cur->links_[x-'a'];
			if(!xNode)
				return false;
			cur=xNode;
		}
		return true;
	}

private:
	TrieNode* root;
	std::unordered_set<std::string> wordSet_;
};