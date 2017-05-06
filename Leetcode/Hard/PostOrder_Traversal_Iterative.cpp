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
    std::vector<int> postorderTraversal(TreeNode *root) 
{
	std::vector<int> result;
	if(!root) return result;
	std::stack<TreeNode*> addressStack;
	std::stack<TreeNode*> revPrinterStack;
	addressStack.push(root);
	while(!addressStack.empty())
	{
		TreeNode* cur = addressStack.top();
		addressStack.pop();
		revPrinterStack.push(cur);
		if(cur->left)
			addressStack.push(cur->left);
		if(cur->right)
			addressStack.push(cur->right);
	}
	while(!revPrinterStack.empty())
	{
		TreeNode* visit = revPrinterStack.top();
		revPrinterStack.pop();
		result.push_back(visit->val);
	}
	return result;
}
};