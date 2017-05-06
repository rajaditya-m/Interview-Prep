#include "../../includes/tree.h"
#include <iostream>
#include <cstdlib>

/*
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
*/

General::TreeNode<int>* getGrandFather(General::TreeNode<int>* root, int target, 
	General::TreeNode<int>* father,General::TreeNode<int>* grand_father)
{
	if(!root)
		return NULL;

	if(root->value()==target)
		return grand_father;

	General::TreeNode<int>* left_res;
	General::TreeNode<int>* right_res;	
	left_res = getGrandFather(root->getLeftChild(),target,root,father);
	right_res = getGrandFather(root->getRightChild(),target,root,father);

	if(!left_res)
		return right_res;
	else if(!right_res)
		return left_res;
	else return NULL;
}

General::TreeNode<int>* getCousin(General::TreeNode<int>* root,int target)
{
	General::TreeNode<int>* grandpa = getGrandFather(root,target,NULL,NULL);
	std::cout << grandpa->value();
	int grandson1,grandson2,grandson3,grandson4;
	if(grandpa)
	{
		grandson1 = grandpa->getLeftChild()->getLeftChild()->value();
		grandson2 = grandpa->getLeftChild()->getRightChild()->value();
		if(grandson1==target || grandson2==target)
		{
			if(grandpa->getRightChild())
				if(grandpa->getRightChild()->getRightChild())
					return grandpa->getRightChild()->getRightChild();
				else
					return grandpa->getRightChild()->getLeftChild();
			else
				return NULL;
		}
	}
	return NULL;
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
	General::TreeNode<int>* l3_1 = new General::TreeNode<int>(23);
	l1_1->setLeftChild(l2_1);
	l1_1->setRightChild(l2_2);
	l1_2->setLeftChild(l2_3);

	l2_3->setRightChild(l3_1);

	/*
	std::cout << "Preorder Traversal:" ;
	preOrder(root);
	std::cout << "\n";
	std::cout << "Postorder Traversal:" ;
	postOrder(root);
	std::cout << "\n";
	std::cout << "Inorder Traversal:" ;
	inOrder(root);
	std::cout << "\n";
	*/

	General::TreeNode<int>* cuz = getCousin(root,7);
	if(cuz)
		std::cout << cuz->value();

}