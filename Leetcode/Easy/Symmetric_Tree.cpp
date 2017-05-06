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
    bool isSymmetric(TreeNode *root) {
        if(!root)
            return true;
        return isMirror(root->left,root->right);
    }
    
    bool isMirror(TreeNode* root1, TreeNode* root2)
    {
        if(root1==NULL || root2==NULL)
            return (root1==NULL && root2==NULL) ;
        if(root1->val == root2->val )
            return (isMirror(root1->left,root2->right) && isMirror(root1->right,root2->left));
        return false;
    }
    
};