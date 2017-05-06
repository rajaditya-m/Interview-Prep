#include "../../includes/linked_list.h"
#include <iostream>
#include <cstdlib>
#include <map>

void removeDuplicates(General::ListNode<int>* head)
{
	std::map<int,int> lookup;
	General::ListNode<int>* cur=head;
	General::ListNode<int>* prev = NULL;
	General::ListNode<int>* holder;
	while(cur)
	{
		int curVal = cur->value();
		int lookupVal = lookup[curVal];
		if(lookupVal>0)
		{
			holder = cur;
			prev->setNext(cur->getNext());
			cur = cur->getNext();
			delete holder;
		}
		else
		{
			prev = cur;
			cur = cur->getNext();
			lookup[curVal]=lookupVal+1;
		}
	} 
}

int main()
{
	General::ListNode<int> *head1 = new General::ListNode<int>(7);
	General::ListNode<int> *next11 = head1->insertAfter(4);
	General::ListNode<int> *next21 = next11->insertAfter(3);
	General::ListNode<int> *next31 = next21->insertAfter(2);
	General::ListNode<int> *next41 = next31->insertAfter(2);
	General::ListNode<int> *next51 = next41->insertAfter(7);
	
	head1->printList();
	std::cout << "After Duplicate Removal:\n";
	removeDuplicates(head1);
	head1->printList();
	return(EXIT_SUCCESS);
}