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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode* first = head;
        ListNode* second = head;
        ListNode* prev = NULL;
        while(n)
        {
            first=first->next;
            n--;
        }
        while(first)
        {
            first = first->next;
            prev = second;
            second = second->next;
        }
        if(prev)
            prev->next = second->next;
        else
            {
                head = head->next;
            }    
        return head;
    }
};