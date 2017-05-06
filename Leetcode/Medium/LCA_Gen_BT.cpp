/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p==root || q== root || root==NULL)
            return root;
        
        TreeNode* leftRes = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightRes = lowestCommonAncestor(root->right,p,q);
        
        if(leftRes && rightRes)
            return root;
        else if(leftRes)
            return leftRes;
        else
            return rightRes;
            
    }
};