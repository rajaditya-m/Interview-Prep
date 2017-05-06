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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = preorder.size();
        return helper(preorder, inorder,0, n-1, 0,n-1);
    }
    
    TreeNode* helper(std::vector<int> &preorder, std::vector<int> &inorder, int ps, int pe, int is, int ie)
    {
        int len = pe-ps+1;
        if(len<=0)
            return NULL;
        int rt = preorder[ps];
        int i;
        for(i=is;i<=ie;i++)
        {
            if(inorder[i]==rt)
                break;
        }
        int lenl = (i-1)-is+1;
        
        TreeNode *root = new TreeNode(rt);
        root->left = helper(preorder, inorder, ps+1, ps+lenl,is,i-1);
        root->right = helper(preorder, inorder, ps+lenl+1,pe,i+1,ie);
        
        return root;
    }
};