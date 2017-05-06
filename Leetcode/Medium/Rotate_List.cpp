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
    ListNode *rotateRight(ListNode *head, int k) {
        if(k==0)
            return head;
        ListNode* prev = NULL;
        ListNode* cur = head;
        while(cur && cur->next)
        {
            prev = cur;
            cur = cur->next;
        }
        if(prev)
        {
            prev->next = NULL;
            if(cur)
            {
                cur->next = head;
                return rotateRight(cur,k-1);
            }
            else
            {
                return prev;
            }
        }
        return cur;
    }
};