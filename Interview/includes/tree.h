#ifndef __GENERAL_TREES_H_
#define __GENERAL_TREES_H_

#include <iostream>
#include <cstdlib>

namespace General 
{
	template <class T>
	class TreeNode
	{
	public:

		TreeNode(const T &val)
		{
			data = val;
			leftChild = rightChild = NULL;
		}

		~TreeNode() {}

		TreeNode* getLeftChild() const { return leftChild;}

		TreeNode* getRightChild() const {return rightChild;}

		const T& value() const {return data;}

		void setLeftChild(TreeNode* lc) { leftChild = lc;}

		void setRightChild(TreeNode* rc) { rightChild = rc;}

		void setValue(const T &value) {data = value;}

	public:
		TreeNode* leftChild;
		TreeNode* rightChild;
		T data;
	};
}

#endif