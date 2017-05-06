#include "../../includes/tree.h"
#include <iostream>
#include <cstdlib>

void visit(General::TreeNode<int>* node)
{
	std::cout << node->value() << " ";
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

General::TreeNode<int>* makeBalancedBST(int arr[],int start, int end)
{
	if(start>end)
		return NULL;
	int mid = (start+end)/2;
	General::TreeNode<int>* root = new General::TreeNode<int>(arr[mid]);
	General::TreeNode<int>* leftSubTree = makeBalancedBST(arr,start,mid-1);
	General::TreeNode<int>* rightSubTree = makeBalancedBST(arr,mid+1,end);
	root->setLeftChild(leftSubTree);
	root->setRightChild(rightSubTree);
	return root;
}


int main()
{
	int arr[] = {1,2,3,4,5,5,6,8};
	int len = 8;
	General::TreeNode<int>* resTree = makeBalancedBST(arr,0,7);

	std::cout << "Given tree is:" ;
	inOrder(resTree);
	std::cout << "\n";

}