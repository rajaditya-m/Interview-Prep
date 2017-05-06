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
    ListNode* reverseList(ListNode* head) {
	if (!head)
		return head;
	ListNode* tmp = head->next;
	head->next = NULL;
	if (tmp)
	{
		ListNode* newHead = reverseList(tmp);
		tmp->next = head;
		return newHead;
	}
	return head;
}
};