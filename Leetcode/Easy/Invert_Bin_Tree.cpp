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
    TreeNode* invertTree(TreeNode* root) {
        if(!root){
            return root;
        }
        TreeNode* leftVal = invertTree(root->left);
        TreeNode* rightVal = invertTree(root->right);
        root->right = leftVal;
        root->left = rightVal;
    }
};