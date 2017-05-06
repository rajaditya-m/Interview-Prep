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
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head)
            return head;
        ListNode* cur = head;
        ListNode* next = head->next;
        ListNode* prev = NULL;
        while(next)
        {
            if(cur->val!=next->val)
            {
                prev = cur;
                cur = next;
                next = next->next;
                
            }
            else
            {
                ListNode* dummy  = next;
                ListNode* lastNodeToDelete = cur;
                while(dummy && dummy->val==cur->val)
                {
                    dummy = dummy->next;
                    lastNodeToDelete = lastNodeToDelete->next;
                }
                //Delete from cur to lastNodeToDelete
                if(!prev)
                {
                    head = dummy;
                    cur = head;
                    if(cur)
                        next = cur->next;
                    else
                        next = NULL;
                        
                }
                else
                {
                    prev->next = dummy;
                    cur = dummy;
                    if(cur)
                        next = cur->next;
                    else
                        next = NULL;
                }
            }
        }
        return head;
    }
};