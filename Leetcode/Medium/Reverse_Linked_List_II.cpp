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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode* prevM;
        ListNode* nodeM;
        ListNode* nodeN;
        ListNode* cur = head;
        ListNode* prev = NULL;
        int counter = 1;
        while(cur)
        {
            if(counter==m)
            {
                nodeM = cur;
                prevM = prev;
            }
            if(counter==n)
            {
                nodeN = cur;
                break;
            }
            prev = cur;
            cur = cur->next;
            counter++;
        }
        while(nodeM!=nodeN)
        {
            if(prevM)
            {
                prevM->next = nodeM->next;
                nodeM->next = nodeN->next;
                nodeN->next = nodeM;
                nodeM = prevM->next;
            }
            else
            {
                head = nodeM->next;
                nodeM->next = nodeN->next;
                nodeN->next = nodeM;
                nodeM = head;
            }
        }
        return head;
    }
};