//--------------------------------------------------------------------
//	컴퓨터공학과 2021111954 유수민 
//
//  Laboratory B, In-lab Exercise 2                     heapsort.cpp
//
//   heapSort() function
//
//--------------------------------------------------------------------
using namespace std;
#include <iostream>
template < class DT >
void moveDown ( DT dataItem [], int root, int size )

// Restores the binary tree that is rooted at root to a heap by moving
// dataItem[root] downward until the tree satisfies the heap property.
// Parameter size is the number of data items in the array.

{

    // 다시 정렬
    int index = root;
    int bottom = size - 1;
    int maxChild; //leftChild와 rightChild 중 더 큰 자식노드
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    while (index <= bottom)
    {
        leftChild = 2 * index + 1;
        rightChild = 2 * index + 2;
        // 자식이 없는 경우 반복문을 빠져나간다.
        if (leftChild > bottom)
            break;
        // 자식이 1개인 경우
        if (leftChild == bottom)
            maxChild = leftChild;
        // 자식이 2개인 경우
        else
        {
            if (dataItem[leftChild].pty() < dataItem[rightChild].pty())
                maxChild = rightChild;
            else maxChild = leftChild;
        }

        if (dataItem[index].pty() < dataItem[maxChild].pty())
        {
            DT tempRoot, tempMax;
            tempRoot.setPty(dataItem[index].pty());
            tempMax.setPty(dataItem[maxChild].pty());
            dataItem[index].setPty(tempMax.pty());
            dataItem[maxChild].setPty(tempRoot.pty());
            index = maxChild;
        }
        else break;
    }
}

//--------------------------------------------------------------------

template < class DT >
void heapSort ( DT dataItems [], int size )

// Heap sort routine. Sorts the data items in the array in ascending
// order based on priority.

{
    DT temp;   // Temporary storage
    int j;     // Loop counter

    // Build successively larger heaps within the array until the
    // entire array is a heap.

    for ( j = (size-1)/2 ; j >= 0 ; j-- )
        moveDown(dataItems,j,size);

    // Swap the root data item from each successively smaller heap with
    // the last unsorted data item in the array. Restore the heap after
    // each exchange.

    for ( j = size-1 ; j > 0 ; j-- )
    {
        temp = dataItems[j];
        dataItems[j] = dataItems[0];
        dataItems[0] = temp;
        moveDown(dataItems,0,j);
    }
}

