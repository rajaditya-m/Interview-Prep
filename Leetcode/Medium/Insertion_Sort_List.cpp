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
    ListNode *insertionSortList(ListNode* head)
	{
		if(!head)
			return head;
		ListNode* endOfSortedList = head;
		ListNode* curKey = head->next;
		while(curKey)
		{
			ListNode* prev = NULL;
			ListNode* cur = head;
			while(cur!=curKey)
			{
				if(cur->val>curKey->val)
                    break;
                prev = cur;
                cur = cur->next;
			}
			if(cur==curKey)
			{
				endOfSortedList = curKey;
			}
			else
			{
				if(!prev)
				{
					endOfSortedList->next = curKey->next;
					curKey->next = head;
					head = curKey;
				}
				else
				{
					endOfSortedList->next = curKey->next;
					prev->next = curKey;
					curKey->next = cur;
				}
			}
		
			curKey =  endOfSortedList->next;
		}
		return head;
	}
};