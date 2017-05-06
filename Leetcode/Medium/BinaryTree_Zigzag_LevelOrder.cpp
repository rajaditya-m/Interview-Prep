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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        std::vector<std::vector<int> > result;
        std::vector<int> indLevel;
        if(!root)
        {
           // result.push_back(indLevel);
            return result;
        }
        std::queue<TreeNode*> q;
        int nodesInCurLevel = 1;
        int nodesInNextLevel = 0;
        bool flip = false;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* cur = q.front();
            nodesInCurLevel--;
            q.pop();
            indLevel.push_back(cur->val);
            if(cur->left)
            {
                q.push(cur->left);
                nodesInNextLevel++;
            }
            if(cur->right)
            {
                q.push(cur->right);
                nodesInNextLevel++;
            }
            if(!nodesInCurLevel)
            {
                std::vector<int> newV;
                if(flip)
                {
                    for(int i=indLevel.size()-1;i>=0;i--)
                    {
                        newV.push_back(indLevel[i]);
                    }
                }
                else
                    newV = indLevel;
                    
                result.push_back(newV);
                indLevel.clear();
                flip = !flip;
                nodesInCurLevel = nodesInNextLevel;
                nodesInNextLevel=0;
            }
        }
        return result;
    }

};