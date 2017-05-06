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
std::vector<int> preorderTraversal(TreeNode* root)
{
	std::vector<int> result;
	if(!root) return result;
	std::stack<TreeNode*> addressStack;
	addressStack.push(root);
	while(!addressStack.empty())
	{
		TreeNode* toProcess = addressStack.top();
		addressStack.pop();
		result.push_back(toProcess->val);
		if(toProcess->right)
			addressStack.push(toProcess->right);
		if(toProcess->left)
			addressStack.push(toProcess->left);
	}
	return result;
}
};