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
    void flatten(TreeNode *root) {
        if(!root)
            return ;
        //Single element list 
        if(!root->left && !root->right)
            return ;
        flatten(root->right);
        flatten(root->left);
        TreeNode* cur = root->left;
        if(cur)
        {
            while(cur && cur->right)
            {
                cur = cur->right;
            }
            cur->right = root->right;
            root->right = root->left;
        }
        root->left = NULL;
    }
};