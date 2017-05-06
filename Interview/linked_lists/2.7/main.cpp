#include "../../includes/linked_list.h"
#include <iostream>
#include <cstdlib>

int listLen(General::ListNode<int>* head)
{
	int len =0;
	while(head)
	{
		head=head->getNext();
		len++;
	}
	return len;
}

bool isPalindrome(General::ListNode<int>* head,int len,General::ListNode<int> **imgNode)
{
	if(len==1)
	{
		*imgNode = head->getNext(); 
		return true;
	}
	else if(len==0)
	{
		*imgNode = head->getNext()->getNext();
		return (head->value()==head->getNext()->value());
	}
	else
	{
		General::ListNode<int>* mirrorNode;
		bool otherRes = isPalindrome(head->getNext(),len-2,&mirrorNode);
		bool thisRes = (head->value()==mirrorNode->value());
		*imgNode = mirrorNode->getNext();
		return (otherRes && thisRes);
	}
}

int main()
{
	General::ListNode<int> *head1 = new General::ListNode<int>(7);
	General::ListNode<int> *next11 = head1->insertAfter(1);
	General::ListNode<int> *next21 = next11->insertAfter(6);
	General::ListNode<int> *next31 = next21->insertAfter(1);
	General::ListNode<int> *next41 = next31->insertAfter(7);

	General::ListNode<int> *head2 = new General::ListNode<int>(5);
	General::ListNode<int> *next12 = head2->insertAfter(9);
	General::ListNode<int> *next22 = next12->insertAfter(9);

	head1->printList();
	head2->printList();

	int len1=listLen(head1);
	int len2=listLen(head2);
	General::ListNode<int>* placeholder;

	std::cout<< "List 1 is Palindrome:" << isPalindrome(head1,len1,&placeholder) << "\n";
	std::cout<< "List 2 is Palindrome:" << isPalindrome(head2,len2,&placeholder) << "\n";
	return(EXIT_SUCCESS);
}