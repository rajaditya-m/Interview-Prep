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
   ListNode* removeElements(ListNode* head, int val) {
	if (!head)
		return head;
	if (val == head->val)
		return removeElements(head->next,val);
	else
	{
		ListNode* removed = removeElements(head->next,val);
		head->next = removed;
		return head;
	}
}
};