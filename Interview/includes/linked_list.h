#ifndef __GENERAL_LINKEDLIST_H_
#define __GENERAL_LINKEDLIST_H_

#include <iostream>
#include <cstdlib>

namespace General 
{
	template <class T> 
	class ListNode
	{
	public:
		
		ListNode(const T &value)
		{
			next = NULL;
			data = value;
		}

		~ListNode() {}

		ListNode* getNext() const { return next;}

		const T& value() const { return data;}

		void setNext(ListNode *elem) { next = elem;}

		void setValue(const T &value) { data = value;}

		ListNode* insertAfter(const T &value) 
		{
			ListNode* newNode = new ListNode<T>(value);
			newNode->setNext(next);
			next = newNode;
			return newNode;
		}

		void printList()
		{
			ListNode* pntr = next;
			std::cout << data << " ";
			while(pntr)
			{
				std::cout << pntr->value() << " ";
				pntr=pntr->getNext();
			}
			std::cout << "\n";
		}

	public:
		ListNode* next;
		T data;

	};
}

#endif