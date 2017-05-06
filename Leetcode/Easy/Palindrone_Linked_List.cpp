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
    bool isPalindrome(ListNode* head) {
	//Find out the middle of the list 
	ListNode *fast = head, *slow = head;
	ListNode *prev = NULL;
	bool answer = true;
	while(fast!= NULL && fast->next!= NULL) {
		fast = fast->next->next;
		prev = slow;
		slow = slow->next;
	}
	bool oddLengthList = false;
	if(fast) {
		oddLengthList = true;
	}
	ListNode* newHead;
	if(oddLengthList) {
		newHead = slow->next;
		if(prev)
			prev->next = NULL;
		if(slow)
			slow->next = NULL;
	}
	else {
		newHead = slow;
		if(prev)
			prev->next = NULL;
	}
	//Now reverse newHead in place
	ListNode *prv = NULL, *cur = newHead, *nxt = NULL;
	if(cur) {
		nxt = cur->next;
	}
	while(cur) {
		cur->next = prv;
		prv = cur;
		cur = nxt;
		if(nxt) 
			nxt = nxt->next;
	}
	ListNode* reversedHead = prv;
	ListNode* unreversedHead = head;
	//Now compare the reverse head 
	while(reversedHead) {
		if(reversedHead->val != unreversedHead->val)
		{
			answer = false;
			break;
		}
		else {
			reversedHead = reversedHead->next;
			unreversedHead = unreversedHead->next;
		}
	}
	//Now we know the answer time to restore the linked list
	cur = prv;
	prv = NULL;
	nxt = NULL;
	if(cur) {
		nxt = cur->next;
	}
	while(cur) {
		cur->next = prv;
		prv = cur;
		cur = nxt;
		if(nxt) 
			nxt = nxt->next;
	}
	if(oddLengthList) {
		if(prev)
			prev->next = slow;
		if(slow)
			slow->next = prv;
	}
	else {
		if(prev)
			prev->next = prv;
	}
	return answer;
}
};