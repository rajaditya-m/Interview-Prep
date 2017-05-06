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
    ListNode *reverseKGroup(ListNode *head, int k) {
        int copy = k;
        ListNode* cur = head;
        ListNode* prev = NULL;
        while(cur && copy)
        {
            prev = cur;
            cur=cur->next;
            copy--;
        }
        //Copy contains the position we need to send recursively
        //Too few nodes
        if(copy)
        {
            return head;
        }
        else
        {
            prev->next = NULL;
            ListNode* recur = reverseKGroup(cur,k);
            //Now reverse this list 
            ListNode* p= NULL;
            ListNode* c= head;
            ListNode* n;
            while(c)
            {
                n = c->next;
                c->next = p;
                p = c;
                c = n;
            }
            head->next = recur;
            return p;
        }
    }
};