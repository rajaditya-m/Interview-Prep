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
ListNode* mergeKLists(std::vector<ListNode*> &list)
{
	ListNode* head = NULL;
	ListNode* prev = NULL;
	std::priority_queue<std::pair<int,ListNode*>,std::vector<std::pair<int,ListNode*> >,std::greater<std::pair<int,ListNode*> > > pq;
	int k = list.size();
	for(int i=0;i<k;i++)
	{
		if(list[i])
		{
			pq.push(std::pair<int,ListNode*>(list[i]->val,list[i]));
		}
	}
	while(!pq.empty())
	{
		std::pair<int,ListNode*> r  = pq.top();
		pq.pop();
		ListNode* nxt;
		ListNode* cur = r.second;
		if(!prev)
		{
			head = cur;
			prev = cur;
		}
		else
		{
			prev->next = cur;
			prev = cur;
		}
		nxt = cur->next;
		cur->next = NULL;
		if(nxt)
		{
			pq.push(std::pair<int,ListNode*>(nxt->val,nxt));
		}
	}
	return head;
}
};