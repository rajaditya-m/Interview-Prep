/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        //First lets make a side by side copy 
        RandomListNode* cur = head;
        while(cur)
        {
            RandomListNode* newNode = new RandomListNode(cur->label);
            newNode->next = cur->next;
            cur->next = newNode;
            cur=cur->next->next;
        }
        //Now we set the random pointers
        cur = head;
        while(cur)
        {
            if(cur->random)
                cur->next->random = cur->random->next;
            else
                cur->next->random = NULL;    
            cur=cur->next->next;
        }
        //Finally we separate out the two lists
        RandomListNode* newHead = NULL ;
        RandomListNode* prev = NULL;
        cur = head;
        while(cur)
        {
            if(prev)
            {
                prev->next = cur->next;
            }
            else
            {
                newHead = cur->next; 
            }
            prev = cur->next;
            cur->next = cur->next->next;
            cur = cur->next;
        }
        return newHead;
    }
};