//--------------------------------------------------------------------
//
//  Laboratory 13                                             heap.cpp
//
//  Actual implementation of class in the Heap ADT
//--------------------------------------------------------------------

#include "heap.h"
#include <iostream>
using namespace std;
//--------------------------------------------------------------------


template<class DT>
Heap<DT>::Heap(int maxNumber)
    :maxSize(maxNumber), size(0)
{
    dataItems = new DT[maxSize];
}

template < class DT >
Heap<DT>::~Heap()
{
    delete dataItems;
}

//--------------------------------------------------------------------

template < class DT >
void Heap<DT>::insert(const DT& newDataItem)
{
    if (isFull())
    {
        cout << "Heap is Full" << endl;
    }
    else if (isEmpty())
    {
        dataItems[size] = newDataItem;
        size++;
    }
    else
    {
        dataItems[size] = newDataItem;
        DT temp;
        int parentIndex = (size - 1) / 2;
        int sizeIndex = size;

        while (dataItems[parentIndex].pty() < dataItems[sizeIndex].pty())
        {
            temp = dataItems[parentIndex];
            dataItems[sizeIndex] = temp;
            dataItems[parentIndex] = newDataItem;
            sizeIndex = parentIndex;
            parentIndex = (sizeIndex - 1) / 2;
        } 

        size++;
    }
    
}

template < class DT >
DT Heap<DT>::removeMax()
{
    DT temp;
    if (isEmpty())
    {
        cout << "Heap is Empty." << endl;
        temp.setPty(NULL);
    }
    else
    {
        // 삭제
        temp = dataItems[0];
        dataItems[0].setPty(NULL);
        dataItems[0].setPty(dataItems[size - 1].pty());
        dataItems[size - 1].setPty(NULL);
        size--; 

        // 다시 정렬
        int root = 0;
        int bottom = size - 1;
        int maxChild; //leftChild와 rightChild 중 더 큰 자식노드
        int leftChild = 2 * root + 1;
        int rightChild = 2 * root + 2;

        while (root <= bottom)
        {
            leftChild = 2 * root + 1;
            rightChild = 2 * root + 2;
            // 자식이 없는 경우 반복문을 빠져나간다.
            if (dataItems[leftChild].pty() == NULL) break;
            // 자식이 1개인 경우
            if (leftChild == bottom)
                maxChild = leftChild;
            // 자식이 2개인 경우
            else
            {
                if (dataItems[leftChild].pty() < dataItems[rightChild].pty())
                    maxChild = rightChild;
                else maxChild = leftChild;
            }

            DT tempRoot, tempMax;
            tempRoot.setPty(dataItems[root].pty());
            tempMax.setPty(dataItems[maxChild].pty());
            dataItems[root].setPty(tempMax.pty());
            dataItems[maxChild].setPty(tempRoot.pty());

            root = maxChild;
        }
        
    }
    return temp;
}

template < class DT >
void Heap<DT>::clear()
{
    if (isEmpty())
    {
        cout << "Heap is already Empty" << endl;
    }
    else
    {
        while (size != 0)
        {
            dataItems[size].setPty(NULL);
            size--;
        }
    }
}

//--------------------------------------------------------------------

template < class DT >
bool Heap<DT>::isEmpty() const
{
    if (size == 0) return 1;
    else return 0;
}

template < class DT >
bool Heap<DT>::isFull() const
{
    if (size == maxSize) return 1;
    else return 0;
}

//--------------------------------------------------------------------

template < class DT >
void Heap<DT>:: showStructure () const

// Outputs the priorities of the data in a heap in both array
// and tree form. If the heap is empty, outputs "Empty heap". This
// operation is intended for testing/debugging purposes only.

{
    int j;   // Loop counter

    cout << endl;
    if ( size == 0 )
       cout << "Empty heap" << endl;
    else
    {
       cout << "size = " << size << endl;       // Output array form
       for ( j = 0 ; j < maxSize ; j++ )
           cout << j << "\t";
       cout << endl;
       for ( j = 0 ; j < size ; j++ )
           cout << dataItems[j].pty() << "\t";
       cout << endl << endl;
       showSubtree(0,0);                        // Output tree form
    }
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void Heap<DT>:: showSubtree ( int index, int level ) const

// Recursive partner of the showStructure() function. Outputs the
// subtree (subheap) whose root is stored in dataItems[index]. Argument
// level is the level of this dataItems within the tree.

{
     int j;   // Loop counter

     if ( index < size )
     {
        showSubtree(2*index+2,level+1);        // Output right subtree
        for ( j = 0 ; j < level ; j++ )        // Tab over to level
            cout << "\t";
        cout << " " << dataItems[index].pty();   // Output dataItems's pty
        if ( 2*index+2 < size )                // Output "connector"
           cout << "<";
        else if ( 2*index+1 < size )
           cout << "\\";
        cout << endl;
        showSubtree(2*index+1,level+1);        // Output left subtree
    }
}