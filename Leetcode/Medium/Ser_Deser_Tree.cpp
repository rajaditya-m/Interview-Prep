/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
	void preOrderHelper(TreeNode* root, std::string &s)
	{
		if (root)
		{
			s += std::to_string(root->val);
			s += ",";
			preOrderHelper(root->left, s);
			preOrderHelper(root->right, s);
		}
		else
		{
			s += "#,";
		}
	}

	void makeNice(std::string &s)
	{
		if (s.length() > 0 && s[s.length() - 1] == ',') {
			s = s.substr(0, s.length() - 1);
		}
	}
	
	// Encodes a tree to a single string.
	std::string serialize(TreeNode* root) {
		std::string preOrderStr = "";
		preOrderHelper(root, preOrderStr);
		makeNice(preOrderStr);
		return preOrderStr;
	}

	std::string getNextToken(std::string &s)
	{
		size_t loc = s.find(',');
		std::string token;
		if (loc==std::string::npos)
		{
			token = s;
			s = "";
		}
		else
		{
			token = s.substr(0, loc);
			s = s.substr(loc + 1);
		}
		return token;
	}

	TreeNode* buildTree(std::string &s)
	{
		//Consume a token 
		std::string curTok = getNextToken(s);
		std::string hash = "#";
		if (s.empty())
		{
			if (strcmp(curTok.c_str(), hash.c_str()) == 0)
			{
				return NULL;
			}
			else
			{
				int x = atoi(curTok.c_str());
				TreeNode* t = new TreeNode(x);
				return t;
			}
		}
		else
		{
			if (strcmp(curTok.c_str(), hash.c_str()) == 0)
			{
				return NULL;
			}
			else
			{
				int x = atoi(curTok.c_str());
				TreeNode* t = new TreeNode(x);
				t->left = buildTree(s);
				t->right = buildTree(s);
				return t;
			}
		}
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(std::string data) {
		return buildTree(data);
	}
};
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));