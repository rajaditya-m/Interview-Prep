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
ListNode* partition(ListNode* head, int x)
{
	ListNode* smallerListHead = NULL;
	ListNode* smallerListTail = NULL;
	ListNode* largerListHead = NULL;
	ListNode* largerListTail = NULL;
	while(head)
	{
		ListNode* cur = head;
		head = head->next;
		if(cur->val>=x)
		{
			if(!largerListHead)
			{
				largerListHead = largerListTail = cur;
				cur->next = NULL;
			}
			else
			{
				largerListTail->next = cur;
				cur->next = NULL;
				largerListTail = cur;
			}
		}
		else
		{
			if(!smallerListHead)
			{
				smallerListHead = smallerListTail = cur;
				cur->next = NULL;
			}
			else
			{
				smallerListTail->next = cur;
				cur->next = NULL;
				smallerListTail = cur;
			}
		}
	}
	if(smallerListHead)
	{
		smallerListTail->next = largerListHead;
		return smallerListHead;
	}
	else
	{
		return largerListHead;
	}
}
};