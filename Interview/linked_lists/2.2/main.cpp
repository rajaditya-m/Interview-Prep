#include "../../includes/linked_list.h"
#include <iostream>
#include <cstdlib>

General::ListNode<char>* getKthToLastElem(General::ListNode<char>* head, int k)
{
	General::ListNode<char>* headstartPntr = head;
	while(k--)
	{
		headstartPntr = headstartPntr->getNext();
	}
	General::ListNode<char>* retVal = head;
	while(headstartPntr)
	{
		headstartPntr = headstartPntr->getNext();
		retVal = retVal->getNext();
	}
	return retVal;
}

int main()
{
	General::ListNode<char>* head = new General::ListNode<char>('a');
	General::ListNode<char>* nos2 = head->insertAfter('b');
	General::ListNode<char>* nos3 = nos2->insertAfter('c');
	General::ListNode<char>* nos4 = nos3->insertAfter('d');
	General::ListNode<char>* nos5 = nos4->insertAfter('e');
	head->printList();
	std::cout << "2nd element from last is:" << getKthToLastElem(head,2)->value() << "\n";
}
