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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        std::vector<std::vector<int> > allRes = allPathSums(root);
        std::vector<std::vector<int> > finRes;
        for(int k=0;k<allRes.size();k++)
        {
            std::vector<int> v = allRes[k];
            int sumX = 0;
            for(int j=0;j<v.size();j++)
                sumX += v[j];
            if(sumX==sum)
                finRes.push_back(v);
        }
        return finRes;
    }
    
    std::vector<std::vector<int> > allPathSums(TreeNode* root)
    {
        std::vector<std::vector<int> > result;
        if(!root)
            return result;
        if(!root->left && !root->right)
        {
            std::vector<int> solo;
            solo.push_back(root->val);
            result.push_back(solo);
        }
        else
        {
            std::vector<std::vector<int> > leftRes = allPathSums(root->left);
            std::vector<std::vector<int> > rightRes = allPathSums(root->right);
            for(int k=0;k<leftRes.size();k++)
            {
                std::vector<int> v = leftRes[k];
                v.insert(v.begin(),root->val);
                result.push_back(v);
            }
            for(int k=0;k<rightRes.size();k++)
            {
                std::vector<int> v = rightRes[k];
                v.insert(v.begin(),root->val);
                result.push_back(v);
            }
        }
        return result;
    }
};