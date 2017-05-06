#include "../../includes/linked_list.h"
#include <iostream>
#include <cstdlib>

General::ListNode<int>* reverseList(General::ListNode<int>* head, General::ListNode<int>* prev)
{
	if(!(head->getNext()))
	{
		head->setNext(prev);
		return head;
	}
	else
	{
		General::ListNode<int>* retVal = reverseList(head->getNext(),head);
		head->setNext(prev);
		return retVal;
	}
}

General::ListNode<int>* reverseListIt(General::ListNode<int>* head)
{
	if(!head)
		return head;
	General::ListNode<int>* prev = NULL;
	General::ListNode<int>* cur = head;
	General::ListNode<int>* next = head->getNext();
	while(cur)
	{
		cur->setNext(prev);
		prev = cur;
		cur = next;
		if(next)
			next = next->getNext();
	}
	return prev;
}

int main()
{
	General::ListNode<int> *head = new General::ListNode<int>(5);
	General::ListNode<int> *next1 = head->insertAfter(7);
	General::ListNode<int> *next2 = next1->insertAfter(12);
	General::ListNode<int> *next3 = next2->insertAfter(14);
	General::ListNode<int> *next4 = next3->insertAfter(21);
	head->printList();
	//General::ListNode<int> *rev = reverseList(head,NULL);
	General::ListNode<int> *rev = reverseListIt(head);
	rev->printList();
	return(EXIT_SUCCESS);
}