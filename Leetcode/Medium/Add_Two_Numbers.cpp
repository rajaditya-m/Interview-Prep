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
ListNode *tailRec(ListNode* l1,ListNode *l2,int carry)
{
	if(!l1 && !l2)
	{	if(!carry)
			return NULL;
		else
		{
			ListNode* new_head = new ListNode(carry);
			return new_head;
		}

	}
	else if(!l1)
	{
		int dig = (l2->val+carry)%10;
		int car = (l2->val+carry)/10;
		if(car)
		{
			ListNode* new_head = new ListNode(dig);
			ListNode* new_tail = tailRec(NULL,l2->next,car);
			new_head->next = new_tail;
			return new_head;
		}
		else
		{
			ListNode* new_head = new ListNode(dig);
			new_head->next = l2->next;
			return new_head;
		}
	}
	else if(!l2)
	{
		int dig = (l1->val+carry)%10;
		int car = (l1->val+carry)/10;
		if(car)
		{
			ListNode* new_head = new ListNode(dig);
			ListNode* new_tail = tailRec(l1->next,NULL,car);
			new_head->next = new_tail;
			return new_head;
		}
		else
		{
			ListNode* new_head = new ListNode(dig);
			new_head->next = l1->next;
			return new_head;
		}
	}
	else
	{
		int d1 = l1->val;
		int d2 = l2->val;
		int dig = (d1+d2+carry)%10;
		int car = (d1+d2+carry)/10;
		ListNode* rem_result = tailRec(l1->next,l2->next,car);
		ListNode* new_head = new ListNode(dig);
		new_head->next = rem_result;
		return new_head;
	} 
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
	return tailRec(l1,l2,0);
}
};