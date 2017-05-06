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

     TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
         int ix = inorder.size();
         return buildTreeHelper(inorder,postorder,0,ix-1,0,ix-1);
     }
    TreeNode* buildTreeHelper(std::vector<int> &inorder, std::vector<int> &postorder, int is, int ie, int ps, int pe)
    {
       int listSize = ie-is+1;
       TreeNode* root;
       if(listSize<=0)
            return NULL;
        else if(listSize==1)
        {
            root   = new TreeNode(inorder[is]);
        }
        else
        {
            //iterate over the elements to find out the v in the last elem
            int locInorder;
            for(int i=is;i<=ie;i++)
            {
                if(inorder[i]==postorder[pe])
                {
                    locInorder = i;
                    break;
                }
            }
            root = new TreeNode(inorder[locInorder]);
            root->left = buildTreeHelper(inorder,postorder,is,locInorder-1,ps,locInorder-is+ps-1);
            root->right = buildTreeHelper(inorder,postorder,locInorder+1,ie,pe-ie+locInorder,pe-1);
        }
        return root;
    }
};