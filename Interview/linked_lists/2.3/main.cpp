#include "../../includes/linked_list.h"
#include <iostream>
#include <cstdlib>

void deleteMiddle(General::ListNode<char>* node)
{

	char nextNodeData = node->getNext()->value();
	node->setValue(nextNodeData);
	node->setNext(node->getNext()->getNext());
	delete node->getNext();
}

int main()
{
	General::ListNode<char>* head = new General::ListNode<char>('a');
	General::ListNode<char>* nos2 = head->insertAfter('b');
	General::ListNode<char>* nos3 = nos2->insertAfter('c');
	General::ListNode<char>* nos4 = nos3->insertAfter('d');
	General::ListNode<char>* nos5 = nos4->insertAfter('e');
	head->printList();
	std::cout << "Middle element is deleted.\n";
	deleteMiddle(nos3);
	head->printList();
}
