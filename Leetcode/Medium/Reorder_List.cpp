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
    void reorderList(ListNode *head) {
        //Base case null do nothing 
        ListNode* prev = NULL;
        ListNode* cur = head;
        while(cur && cur->next)
        {
            prev = cur;
            cur = cur->next;
        }
        // Not single element list 
        if(prev && cur)
        {
            //Not two element list
            if(head->next!=cur)
            {
                prev->next = NULL;
                reorderList(head->next);
                cur->next = head->next;
                head->next = cur;
            }
        }
       
    }
};