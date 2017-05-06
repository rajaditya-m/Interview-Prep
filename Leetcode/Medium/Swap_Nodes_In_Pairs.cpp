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
    ListNode *swapPairs(ListNode *head) {
        //Base case
        if(!head || !(head->next))
            return head;
        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* residual = swapPairs(head->next->next);
        first->next = residual;
        second->next = first;
        return second;
    }
};
