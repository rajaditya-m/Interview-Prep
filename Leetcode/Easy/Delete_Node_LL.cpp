/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        //swap the values 
        int tmp = node->next->val;
        node->next->val = node->val;
        node->val = tmp;
        //now delete the next node 
        node->next=node->next->next;
    }
};