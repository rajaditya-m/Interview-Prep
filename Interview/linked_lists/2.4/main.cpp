#include "../../includes/linked_list.h"
#include <iostream>
#include <cstdlib>

void partitionList(General::ListNode<int>** head, int pivot)
{
	General::ListNode<int> *lqThanPivot= NULL;
	General::ListNode<int> *geqThanPivot = NULL;
	General::ListNode<int> *cur = *head;
	General::ListNode<int> *nextToCur;
	while(cur)
	{
		nextToCur = cur->getNext();
		if(cur->value()<pivot)
		{
			cur->setNext(lqThanPivot);
			lqThanPivot = cur;
		}
		else
		{
			cur->setNext(geqThanPivot);
			geqThanPivot = cur;
		}
		cur = nextToCur;
	}
	cur = lqThanPivot;
	while(cur->getNext())
	{
		cur = cur->getNext();
	}
	cur->setNext(geqThanPivot);
	*head = lqThanPivot;
}


int main()
{
	General::ListNode<int> *head = new General::ListNode<int>(6);
	General::ListNode<int> *next1 = head->insertAfter(5);
	General::ListNode<int> *next2 = next1->insertAfter(3);
	General::ListNode<int> *next3 = next2->insertAfter(1);
	General::ListNode<int> *next4 = next3->insertAfter(8);
	General::ListNode<int> *next5 = next4->insertAfter(7);
	General::ListNode<int> *next6 = next5->insertAfter(2);
	General::ListNode<int> *next7 = next6->insertAfter(4);
	head->printList();
	std::cout << "Pivoting around the element 4, we get:\n";
	partitionList(&head,4);
	head->printList();
	return(EXIT_SUCCESS);
}