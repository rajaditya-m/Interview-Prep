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
    void recoverTree(TreeNode *root) {
        std::vector<TreeNode*> c(2);
        c[0] = NULL; c[1] = NULL;
        TreeNode* p = NULL;
        inOrderTraversal(root,&p,c);
        int temp = c[0]->val;
        c[0]->val = c[1]->val;
        c[1]->val = temp;
    }
    
    void inOrderTraversal(TreeNode *root,TreeNode** prev, std::vector<TreeNode*> &culprit)
    {
        if(!root)
            return;
        inOrderTraversal(root->left,prev,culprit);
        //Now this root visit 
        if(*prev)
        {
            if((*prev)->val>root->val)
            {
                if(!culprit[0])
                {
                    culprit[0] = *prev;
                }
                culprit[1] = root;
            }
        }
        *prev = root;
        inOrderTraversal(root->right,prev,culprit);
    }
};