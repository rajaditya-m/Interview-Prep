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
    vector<vector<int> > levelOrderBottom(TreeNode *root)
    {
        std::vector<std::vector<int> > result;
        if(!root)
        {
           // result.push_back(indLevel);
            return result;
        }
        std::queue<TreeNode*> q;
        q.push(root);
        int numEntryInCurLevel = 1;
        return levelOrderRec(q,numEntryInCurLevel);
    }
    
    
    vector<vector<int> > levelOrderRec(std::queue<TreeNode*> q,int nNodes) 
    {
        int numChild = 0;
        std::vector<int> thisLevel;
        std::vector<std::vector<int> > result;
        while(nNodes)
        {
            TreeNode* cur = q.front();
            q.pop();
            thisLevel.push_back(cur->val);
            nNodes--;
            if(cur->left)
            {
                q.push(cur->left);
                numChild++;
            }
            if(cur->right)
            {
                q.push(cur->right);
                numChild++;
            }
        }
        if(numChild)
        {
            result = levelOrderRec(q,numChild);
            result.push_back(thisLevel);
        }
        else
        {
            result.push_back(thisLevel);
        }
        return result;
    }
};