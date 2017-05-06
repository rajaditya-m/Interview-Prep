/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        if(!head)
            return NULL;
        //Now for the split 
        ListNode* fast = head;
        ListNode* mid = head;
        ListNode*midPrev = NULL;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            midPrev = mid;
            mid = mid->next;
        }
        //Now make 3 calls 
        TreeNode* cur = new TreeNode(mid->val);
        if(midPrev)
        {
            midPrev->next = NULL;
            cur->left = sortedListToBST(head);
        }
        if(mid->next)
            cur->right = sortedListToBST(mid->next);
        return cur;
    }
};