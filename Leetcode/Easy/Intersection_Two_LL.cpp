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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* endA = headA;
        while(endA && endA->next)
        {
            endA = endA->next;
        }
        //Now connect this to thenext of B 
        if(endA)
            endA->next = headB;
        
        //Now we have a cyclic linked list 
        ListNode* hare = headA;
        ListNode* tortoise = headA;
        while(hare && hare->next)
        {
            hare = hare->next->next;
            tortoise = tortoise->next;
            if(hare==tortoise)
            {
                break;
            }
        }
        //No cycle no intersection
        if(!hare || !hare->next)
        {
            if(endA)
                endA->next = NULL;
            return NULL;
        }
        //Now we advance the hair and tortoise at the same speed
        hare = headA;
        while(hare && hare!=tortoise)
        {
            hare=hare->next;
            tortoise = tortoise->next;
        }
        //The intersection point is hare
        //Detach the LL though
        if(endA)
            endA->next = NULL;
        return hare;
        
    }
};