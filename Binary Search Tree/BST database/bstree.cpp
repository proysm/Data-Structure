#include <iostream>
#include "bstree.h"

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

//--------------------------------------------------------------------

// Insert

template < class DT, class KF >
void BSTree<DT, KF>::insert(const DT& newDataItem)
{
    //재귀 함수 호출
    insertSub(root, newDataItem);
}

template < class DT, class KF >
void BSTree<DT, KF>::insertSub(BSTreeNode<DT, KF>*& p, const DT& newDataItem)
{
    // p에 입력 받은 newDataItem을 바로 넣는다.
    if (p == 0)
    {
        p = new BSTreeNode<DT, KF>(newDataItem, NULL, NULL);
    }
    // newDataItem이 p가 가진 값보다 작다면 
    else if (newDataItem.key() < p->dataItem.key())
    {
        insertSub(p->left, newDataItem);
    }
    //newDataItem이 p가 가진 값보다 크다면
    else
    {
        insertSub(p->right, newDataItem);
    }
}

//--------------------------------------------------------------------

// Retrieve

template < class DT, class KF >
bool BSTree<DT, KF>::retrieve(KF searchKey, DT& searchDataItem) const
{
    // 비어 있는 경우
    if (isEmpty())
    {
        cout << "The tree is Empty." << endl;
        return 0;
    }
    // 비어 있지 않은 경우
    else
    {
        return retrieveSub(root, searchKey, searchDataItem);;
    }
}

template < class DT, class KF >
bool BSTree<DT, KF>::retrieveSub(BSTreeNode<DT, KF>* p, KF searchKey, DT& searchDataItem) const
{
    if (p != NULL)
    {
        // 찾고 있는 값이 p가 가리키는 값보다 큰 경우
        if (p->dataItem.key() < searchKey)
        {
            retrieveSub(p->right, searchKey, searchDataItem);
        }
        // 찾고 있는 값이 p가 가리키는 값보다 작은 경우
        else if (p->dataItem.key() > searchKey)
        {
            retrieveSub(p->left, searchKey, searchDataItem);
        }
        // 찾은 경우
        else if (p->dataItem.key() == searchKey)
        {
            searchDataItem = p->dataItem;
            return 1;
        }
    }
    else
    {
        return 0;
    }
}

//--------------------------------------------------------------------

// Remove

template < class DT, class KF >
bool BSTree<DT, KF>::remove(KF deleteKey)
{
    if (isEmpty())
    {
        cout << "The tree is Empty." << endl;
        return 0;
    }
    else
    {
        return (removeSub(root, deleteKey));
    }
}

template < class DT, class KF >
bool BSTree<DT, KF>::removeSub(BSTreeNode<DT, KF>*& p, KF deleteKey)
{
    // 지우려는 값이 p보다 작은 경우
    if (deleteKey < p->dataItem.key())
    {
        if (p->left != NULL)
            removeSub(p->left, deleteKey);
        else
            return 0;
    }
    // 지우려는 값이 p보다 큰 경우
    else if (deleteKey > p->dataItem.key())
    {
        if (p->right != NULL)
            removeSub(p->right, deleteKey);
        else
            return 0;
    }
    // 지우려는 값을 찾은 경우
    else
    {
        // 지울 값을 담아 놓을 임시 변수
        KF temp = 0;
        BSTreeNode<DT, KF>* tempPtr;

        tempPtr = p;
        if (p->left == NULL)
        {
            p = p->right;
            delete tempPtr;
        }
        else if (p->right == NULL)
        {
            p = p->left;
            delete tempPtr;
        }
        else
        {
            cutRightmost(p->left, tempPtr);
            p->dataItem = tempPtr->dataItem;
            temp = p->dataItem.key();
            removeSub(p->left, temp);
        }
        return 1;
    }
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

//--------------------------------------------------------------------

// Write Keys

template < class DT, class KF >
void BSTree<DT, KF>::writeKeys() const
{
    // 오름 차순 정렬
    if (root == NULL)
    {
        cout << "The tree is Empty." << endl;
    }
    else
    {
        writeKeysSub(root);
        cout << endl;
    }
}

template < class DT, class KF >
void BSTree<DT, KF>::writeKeysSub(BSTreeNode<DT, KF>* p) const
{
    if (p != NULL)
    {
        writeKeysSub(p->left);
        cout << p->dataItem.key() << " ";
        writeKeysSub(p->right);
    }
    else
    {
        return;
    }
}

//--------------------------------------------------------------------

// Clear

template < class DT, class KF >
void BSTree<DT, KF>::clear()
{
    if (isEmpty())
    {
        cout << "The tree is already Empty." << endl;
    }
    else
    {
        clearSub(root);
    }
}

template < class DT, class KF >

void BSTree<DT, KF>::clearSub(BSTreeNode<DT, KF>* p)
{
    if (p != NULL)
    {
        clearSub(p->right);
        clearSub(p->left);
        delete p;
    }
    else
    {
        root = NULL;
        return;
    }
    root = NULL;
}

//--------------------------------------------------------------------

// Empty / Full

template < class DT, class KF >
bool BSTree<DT, KF>::isEmpty() const
{
    return (root == NULL);
}

template < class DT, class KF >
bool BSTree<DT, KF>::isFull() const
{
    return 0;
}

//--------------------------------------------------------------------

// Show Structure

template < class DT, class KF >
void BSTree<DT, KF>::showStructure() const
{
    if (root == 0)
        cout << "Empty tree" << endl;
    else
    {
        cout << endl;
        showSub(root, 1);
        cout << endl;
    }
}

template < class DT, class KF >
void BSTree<DT, KF>::showSub(BSTreeNode<DT, KF>* p, int level) const
{
    int j;   // Loop counter

    if (p != 0)
    {
        showSub(p->right, level + 1);         // Output right subtree
        for (j = 0; j < level; j++)    // Tab over to level
            cout << "\t";
        cout << " " << p->dataItem.key();  // Output key
        if ((p->left != 0) &&           // Output "connector"
            (p->right != 0))
            cout << "<";
        else if (p->right != 0)
            cout << "/";
        else if (p->left != 0)
            cout << "\\";
        cout << endl;
        showSub(p->left, level + 1);          // Output left subtree
    }
}

//--------------------------------------------------------------------

// In-lab 3
template < class DT, class KF >
void BSTree<DT, KF>::writeLessThan(KF searchKey) const
{
    if (isEmpty())
    {
        cout << "The tree is Empty." << endl;
    }
    else
    {
        writeLTSub(root, searchKey);
    }
}

template < class DT, class KF >
void BSTree<DT, KF>::writeLTSub(BSTreeNode <DT, KF>* p, const KF searchKey) const
{

    if (p != NULL)
    {
        writeLTSub(p->left, searchKey);
        if(p->dataItem.key() < searchKey)
            cout << p->dataItem.key() << " ";
        writeLTSub(p->right, searchKey);
    }
    else
    {
        return;
    }

}