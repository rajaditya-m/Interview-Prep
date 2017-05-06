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
 bool isValidBSTHelper(TreeNode* root, TreeNode** prev)
    {
        if(!root)
            return true;
        
        if(!isValidBSTHelper(root->left,prev))
            return false;
        
        if((*prev) && (*prev)->val >= root->val)
            return false;

		*prev = root;
		//TreeNode* np = root;
        
        return isValidBSTHelper(root->right,prev);
    }

	bool isValidBST(TreeNode* root)
    {
		TreeNode* prev = NULL;
        return isValidBSTHelper(root,&prev);
    }
};