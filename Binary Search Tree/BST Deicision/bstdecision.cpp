#include "decision.h"
#include <iostream>
#include <string>
using namespace std;

template < class DT, class KF >
BSTreeNode<DT, KF>::BSTreeNode(const DT& nodeDataItem, BSTreeNode* leftPtr, BSTreeNode* rightPtr)
	:dataItem(nodeDataItem), left(leftPtr), right(rightPtr)
{

}

template < class DT, class KF >
BSTree<DT, KF>::BSTree()
	:root(0)
{

}

template < class DT, class KF >
BSTree<DT, KF>::~BSTree()
{
	delete root;
}

template < class DT, class KF >
void BSTree<DT, KF>::cutRightmost(BSTreeNode<DT, KF>*& r, BSTreeNode<DT, KF>*& delPtr)
{
	while (r->right != NULL)
	{
		r = r->right;
	}
	delPtr = r;
}

template < class DT, class KF >
void BSTree<DT, KF>::cutLeftmost(BSTreeNode<DT, KF>*& r, BSTreeNode<DT, KF>*& delPtr)
{
	while (r->left != NULL)
	{
		r = r->left;
	}
	delPtr = r;
}

template < class DT, class KF >
bool BSTree<DT, KF>::isValid()
{
	if (root == NULL) return true;
	return checkValid(root, 0, 0);
}

template < class DT, class KF >
bool BSTree<DT, KF>::checkValid(BSTreeNode<DT, KF>* p, KF temp1, KF temp2)
//왼쪽 서브 트리가 루트보다 작은가, 오른쪽 서브 트리가 루트보다 큰가
{
	BSTreeNode<DT, KF>* tempPtr1, *tempPtr2;
	tempPtr1 = p;
	tempPtr2 = p;

	cutRightmost(p->left, tempPtr1);
	p->dataItem = tempPtr1->dataItem;
	temp1 = p->dataItem.key();

	cutLeftmost(p->right, tempPtr2);
	p->dataItem = tempPtr2->dataItem;
	temp2 = p->dataItem.key();

	if (p->dataItem.key() <= temp2 || p->dataItem.key() >= temp1)
	{
		return 0;
	}
	else if (p->left != NULL)
	{
		checkValid(p->left, temp1, temp2);
	}
	else if (p->right != NULL)
	{
		checkValid(p->right, temp1, temp2);
	}
	return 0;
}

