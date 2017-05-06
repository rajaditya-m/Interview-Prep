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
    int helper(int &rootsum, TreeNode* root)
    {
        if(!root)
        {
            rootsum = -9999;
            return -9999;
        }
        
        int leftRs,rightRs;
        int leftK = helper(leftRs,root->left);
        int rightK = helper(rightRs,root->right);
        
        rootsum = std::max(std::max(leftRs,rightRs)+root->val,root->val);
        
        return std::max(std::max(leftK,std::max(rightK,leftRs+rightRs+root->val)),rootsum);
    }
    int maxPathSum(TreeNode *root) {
        if(!root)
            return 0;
        int r;
        return helper(r,root);
        
    }
};