/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        bool hasa = false;
        int counter = 0;
        int answer=0;
        helper(root,k,counter,answer,hasa);
        return answer;
    }
    
    void  helper(TreeNode* root, int k, int &counter, int &answer, bool &hasAnswer)
    {
        if(!root)
            return;
        helper(root->left,k,counter,answer,hasAnswer);
        if(hasAnswer)
            return;
        else if(!hasAnswer && (k==(counter+1)))
        {
            answer = root->val;
            hasAnswer = true;
        }
        counter++;
        if(!hasAnswer)
        {
             helper(root->right,k,counter,answer,hasAnswer);
        }
    }
};