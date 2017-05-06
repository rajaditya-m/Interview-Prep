#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <utility>
#include "../../includes/tree.h"

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

General::TreeNode<int>* listToTree(std::vector<std::pair<int,int> > edgeList)
{
	std::vector<std::pair<int,int> >::iterator it;
	std::map<int,General::TreeNode<int>*> lookup;
	General::TreeNode<int> *root;
	root = NULL;
	int parent,child;
	for(it=edgeList.begin();it!=edgeList.end();++it)
	{
		parent = it->first;
		child = it->second;
		General::TreeNode<int> *pPntr;
		General::TreeNode<int> *cPntr;
		std::map<int,General::TreeNode<int>* >::iterator it1;
		it1 = lookup.find(parent);
		if(it1!=lookup.end())
			pPntr = it1->second;
		else
			pPntr = NULL;
		it1 = lookup.find(child);
		if(it1!=lookup.end())
			cPntr = it1->second;
		else
			cPntr = NULL;
		if(!pPntr)
		{
			General::TreeNode<int> *tempPtr = new General::TreeNode<int>(parent);
			std::pair<int,General::TreeNode<int>* > tempPair(parent,tempPtr);
			lookup.insert(tempPair);
			pPntr = tempPtr;
		}
		if(!cPntr)
		{
			General::TreeNode<int> *tempPtr = new General::TreeNode<int>(child);
			std::pair<int,General::TreeNode<int>* > tempPair(child,tempPtr);
			lookup.insert(tempPair);
			cPntr = tempPtr;
		}
		if(!pPntr->getLeftChild())
		{
			pPntr->setLeftChild(cPntr);
		}
		else
		{
			pPntr->setRightChild(cPntr);
		}
		if(!root || root->value()== child)
			root = pPntr; 
	}
	return root;
}


int main()
{
	std::vector<std::pair<int,int> > sample;
	std::pair<int,int> edge1(12,13);
	std::pair<int,int> edge2(12,15);
	std::pair<int,int> edge3(16,12);
	std::pair<int,int> edge4(16,14);
	sample.push_back(edge1);
	sample.push_back(edge2);
	sample.push_back(edge3);
	sample.push_back(edge4);
	General::TreeNode<int> *res = listToTree(sample);
	inOrder(res);
	return (EXIT_SUCCESS);
}