/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
   std::vector<int> inorderTraversal(TreeNode* root)
{
	std::vector<int> result;
	if(!root) return result;
	std::stack<TreeNode*> addressStack;
	TreeNode* cur = root;
	while(cur || !addressStack.empty())
	{
		if(cur)
		{
			addressStack.push(cur);
			cur=cur->left;
		}
		else if(!addressStack.empty())
		{
			TreeNode* toProcess = addressStack.top();
			addressStack.pop();
			result.push_back(toProcess->val);
			cur = toProcess->right;
		}
	}
	return result;
}
};