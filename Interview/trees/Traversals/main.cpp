#include "../../includes/tree.h"
#include <iostream>
#include <cstdlib>

void visit(General::TreeNode<int>* node)
{
	std::cout << node->value() << " ";
}

void preOrder(General::TreeNode<int>* root)
{
	if(root)
	{
		visit(root);
		preOrder(root->getLeftChild());
		preOrder(root->getRightChild());
	}
}

void postOrder(General::TreeNode<int>* root)
{
	if(root)
	{
		postOrder(root->getLeftChild());
		postOrder(root->getRightChild());
		visit(root);
	}
}

void inOrder(General::TreeNode<int>* root)
{
	if(root)
	{
		inOrder(root->getLeftChild());
		visit(root);
		inOrder(root->getRightChild());
	}
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

	std::cout << "Preorder Traversal:" ;
	preOrder(root);
	std::cout << "\n";
	std::cout << "Postorder Traversal:" ;
	postOrder(root);
	std::cout << "\n";
	std::cout << "Inorder Traversal:" ;
	inOrder(root);
	std::cout << "\n";

}