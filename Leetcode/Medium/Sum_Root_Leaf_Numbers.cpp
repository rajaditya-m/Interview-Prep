/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include <string>
class Solution {
public:
    int sumNumbers(TreeNode *root, int x=0)
    {
        if(!root)
            return 0;
        int ans = 10*x + root->val;
        if(!root->left && !root->right)
            return ans;
        return (sumNumbers(root->left,ans) + sumNumbers(root->right,ans));
    }
};