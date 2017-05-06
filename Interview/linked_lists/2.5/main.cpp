#include "../../includes/linked_list.h"
#include <iostream>
#include <cstdlib>

General::ListNode<int>* addInReverse(General::ListNode<int>* n1, General::ListNode<int>* n2 ,int carry)
{
	General::ListNode<int>* res;
	General::ListNode<int>* restRes = NULL;
	int val_ret;
	if(!n1 && !n2)
	{
		if(carry!=0)
		{
			val_ret = carry;
		}
		else
		{
			return NULL;
		}
	}
	else if(!n1)
	{
		val_ret = n2->value() + carry;
	}
	else if(!n2)
	{
		val_ret = n1->value() + carry;
	}
	else
	{
		int int_val = n1->value() + n2->value() + carry;
		val_ret = int_val%10;
		int carry_next = int_val/10;
		restRes = addInReverse(n1->getNext(),n2->getNext(),carry_next);
	}
	res = new General::ListNode<int>(val_ret);
	res->setNext(restRes);
	return res;
}

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

void padIfNeeded(General::ListNode<int>** n1,General::ListNode<int>** n2)
{
	int l1 = listLen(*n1);
	int l2 = listLen(*n2);
	if(l1==l2)
		return;
	else
	{
		if(l1<l2)
		{
			int t= l1;
			l1 = l2;
			l2 = t;

			General::ListNode<int>* temp = *n1;
			*n1 = *n2;
			*n2 = temp;			
		}
		int diff = l1 - l2;
		while(diff--)
		{
			General::ListNode<int> *temp = new General::ListNode<int>(0);
			temp->setNext(*n2);
			*n2 = temp;
		}
	}
}


General::ListNode<int>* add(General::ListNode<int>* n1,General::ListNode<int>* n2, int *carry_out)
{
	General::ListNode<int>* res;
	General::ListNode<int>* restRes = NULL;
	int val_ret;
	if(!n1 && !n2)
	{
		*carry_out = 0;
		return NULL;
	}
	else 
	{
		int carry;
		General::ListNode<int> *resBefore = add(n1->getNext(),n2->getNext(),&carry);
		int newVal = n1->value() + n2->value() + carry;
		int val_ret = newVal%10;
		*carry_out = newVal/10;
		General::ListNode<int>* newHead = new General::ListNode<int>(val_ret);
		newHead->setNext(resBefore);
		return newHead;
	}
}


int main()
{
	General::ListNode<int> *head1 = new General::ListNode<int>(7);
	General::ListNode<int> *next11 = head1->insertAfter(1);
	General::ListNode<int> *next21 = next11->insertAfter(6);

	General::ListNode<int> *head2 = new General::ListNode<int>(5);
	General::ListNode<int> *next12 = head2->insertAfter(9);
	General::ListNode<int> *next22 = next12->insertAfter(9);

	head1->printList();
	head2->printList();
	std::cout<< "**After padding**\n";
	padIfNeeded(&head1,&head2);
	head1->printList();
	head2->printList();
	std::cout<< "- - -\n";
	int c_o;
	General::ListNode<int>* result = add(head1,head2,&c_o);
	if(c_o!=0)
	{
		General::ListNode<int>* msbdigit = new General::ListNode<int>(c_o);
		msbdigit->setNext(result);
		result = msbdigit;
	}
	result->printList();
	return(EXIT_SUCCESS);
}