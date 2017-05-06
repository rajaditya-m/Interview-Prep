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
  
    void halfWaySplit(ListNode* head, ListNode ** split1)
	{
		*split1 = NULL;
		if(!head)
			return ;
		ListNode* fast = head;
		ListNode* slow = head;
		while(fast->next && fast->next->next)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		*split1 = slow->next;
		slow->next = NULL;
	}

	ListNode* sortedMerge(ListNode* list1, ListNode* list2)
	{
		if(!list1)
			return list2;
		else if(!list2)
			return list1;
		ListNode* res;
		if(list1->val < list2->val)
		{
			res = list1;
			res->next = sortedMerge(list1->next,list2);
		}
		else
		{
			res = list2;
			res->next = sortedMerge(list1,list2->next);
		}
		return res;
	}

	ListNode* sortList(ListNode* list)
	{
		if(!list || !list->next)
			return list;

		ListNode* half;
		halfWaySplit(list,&half);
		ListNode* sortedHalf1 = sortList(list);
		ListNode* sortedHalf2 = sortList(half);
		return sortedMerge(sortedHalf1,sortedHalf2);

	}
};