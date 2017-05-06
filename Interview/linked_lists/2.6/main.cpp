#include "../../includes/linked_list.h"
#include <iostream>
#include <cstdlib>


General::ListNode<int>* floydCycleFinder(General::ListNode<int>* head)
{
	General::ListNode<int>* slow = head;
	General::ListNode<int>* fast = head;
	bool cycleFound = false;
	if(!fast)
		return NULL;
	while(fast->getNext())
	{
		slow =  slow->getNext();
		fast =  fast->getNext()->getNext();
		if(slow==fast)
		{
			cycleFound = true;
			break;
		}
	}
	if(!cycleFound)
		return NULL;
	else
	{
		slow = head;
		while(slow!=fast)
		{
			slow = slow->getNext();
			fast = fast->getNext();
		}
		return slow;
	}
}

int main()
{
	General::ListNode<int> *head1 = new General::ListNode<int>(7);
	General::ListNode<int> *next11 = head1->insertAfter(4);
	General::ListNode<int> *next21 = next11->insertAfter(3);
	General::ListNode<int> *next31 = next21->insertAfter(2);
	General::ListNode<int> *next41 = next31->insertAfter(1);
	General::ListNode<int> *next51 = next41->insertAfter(19);
	next51->setNext(next21);


	General::ListNode<int> *head2 = new General::ListNode<int>(5);
	General::ListNode<int> *next12 = head2->insertAfter(9);
	General::ListNode<int> *next22 = next12->insertAfter(9);

	std::cout<< "List 1 has a cycle:" << floydCycleFinder(head1)->value() << "\n";
	std::cout<< "List 2 has a cycle:" << floydCycleFinder(head2) << "\n";
	return(EXIT_SUCCESS);
}