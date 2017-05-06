class Solution {
public:
    bool isBalanced(TreeNode *root) 
    {
        if(!root)
            return true;
        int heightL = height(root->left);
        int heightR = height(root->right);
        if(abs(heightL-heightR)>1)
            return false;
        else
            return (isBalanced(root->left) && isBalanced(root->right));
    }
    
    int height(TreeNode* root)
    {
        if(!root)
        return 0;
        if(!root->left && !root->right)
            return 1;
        return std::max(height(root->left),height(root->right))+1;
    }
};