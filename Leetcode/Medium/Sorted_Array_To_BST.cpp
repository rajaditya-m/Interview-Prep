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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        int numElems = num.size();
        TreeNode* sNode;
        if(numElems==0)
        {
            sNode = NULL;
        }
        else if(numElems == 1)
        {
            sNode = new TreeNode(num[0]);
        }
        else
        {
            //Split into two parts
            int leftEndIdx = (numElems/2);
            int rightEndIdx = (numElems/2)+1;
            std::vector<int> left(num.begin(),num.begin()+leftEndIdx);
            std::vector<int> right(num.begin()+rightEndIdx,num.end());
            sNode = new TreeNode(num[numElems/2]);
            sNode->left = sortedArrayToBST(left);
            sNode->right = sortedArrayToBST(right);
        }
        return sNode;
    }
};