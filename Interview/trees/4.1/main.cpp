#include "../../includes/tree.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>


int checkHeightBalanced(General::TreeNode<int>* node)
{
	if(!node)
		return 0;

	int leftHeight = checkHeightBalanced(node->getLeftChild());
	if(leftHeight==-1)
		return -1;

	int rightHeight = checkHeightBalanced(node->getRightChild());
	if(rightHeight==-1)
		return -1;

	int heightDiff = fabs(leftHeight-rightHeight);
	if(heightDiff>1)
		return -1;
	else
		return std::max(leftHeight,rightHeight)+1;
}


int main()
{
	General::TreeNode<int>* root = new General::TreeNode<int>(12);
	General::TreeNode<int>* l1_1 = new General::TreeNode<int>(15);
	General::TreeNode<int>* l1_2 = new General::TreeNode<int>(-10);
	root->setLeftChild(l1_1);
	root->setRightChild(l1_2);
	General::TreeNode<int>* l2_1 = new General::TreeNode<int>(7);
	General::TreeNode<int>* l2_2 = new General::TreeNode<int>(22);
	General::TreeNode<int>* l2_3 = new General::TreeNode<int>(13);
	l1_1->setLeftChild(l2_1);
	l1_1->setRightChild(l2_2);
	l1_2->setLeftChild(l2_3);

	std::cout << "Is the tree height balanced?:" << checkHeightBalanced(root) <<"\n";

}