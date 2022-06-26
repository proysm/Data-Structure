// 유수민 2021111954 컴퓨터공학과

#include "queuearr16.h"
#include <assert.h>
#include <iostream>

using namespace std;

template < class DT >
Queue<DT>::Queue(int maxNumber)
    : front(-1), rear(-1), maxSize(maxNumber)
{
    dataItems = new DT[maxSize];
    for (int i = 0; i < maxSize; i++)
    {
        dataItems[i] = NULL;
    }
}

template < class DT >
Queue<DT>::~Queue()
{
    delete[] dataItems;
}

template < class DT >
void Queue<DT>::enqueue(const DT& newDataItem)
{
    if (isFull())
    {
        cout << "Queue is Full, you can't Enqueue!" << endl;
    }
    else
    {
        if (rear + 1 < maxSize)
        {
            dataItems[rear + 1] = newDataItem;
            rear++;
        }
        else
        {
            dataItems[0] = newDataItem;
            rear = 0;
        }
        if (front == -1) front = 0;
    }
}

template < class DT >
DT Queue<DT>::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is Empty, you can't Dequeue!" << endl;
    }
    else
    {
        dataItems[front] = NULL;
        if (front + 1 < maxSize) front++;
        else front = -1;
    }
    return front;
}

template < class DT >
void Queue<DT>::clear()
{
    for (int i = 0; i < maxSize; i++)
    {
        dataItems[i] = NULL;
    }
    front = -1;
    rear = -1;
}

template < class DT >
bool Queue<DT>::isEmpty() const
{

    for (int i = 0; i < maxSize; i++)
    {
        if (dataItems[i] != NULL) return false;
    }
    return true;
}

template < class DT >
bool Queue<DT>::isFull() const
{
    return ((rear + 2) % maxSize == ((front + 1) % maxSize));
}

template < class DT >
void Queue<DT>::showStructure() const
{
    int j;   // Loop counter

    if (front == -1)
        cout << "Empty queue" << endl;
    else
    {
        cout << "front = " << front << "  rear = " << rear << endl;
        for (j = 0; j < maxSize; j++)
            cout << j << "\t";
        cout << endl;
        if (rear >= front)
        {
            for (j = 0; j < maxSize; j++)
            {
                if ((j >= front) && (j <= rear))
                    cout << dataItems[j] << "\t";
                else
                    cout << " \t";
            }
        }
        else
        {
            for (j = 0; j < maxSize; j++)
            {
                if ((j >= front) || (j <= rear))
                    cout << dataItems[j] << "\t";
                else
                    cout << " \t";
            }
        }
        cout << endl;
    }

}

// In-lab operations
template < class DT >
void Queue<DT>::putFront(const DT& newDataItem)  // >
{
    DT temp;
    if (front == -1) front = maxSize; rear = maxSize;
    if (isFull()) cout << "Queue is Full, you can't Enqueue!" << endl;
    else
    {
        if (dataItems[front-1] == NULL) 
        {
            dataItems[front-1] = newDataItem;
            front--;
            rear--;
        }
        else
        {
            cout << "Data is already in Queue[front]" << endl;
        }
    }
}

template < class DT >
DT Queue<DT>::getRear()  // =
{
    DT elem;
    elem = dataItems[rear];
    dataItems[rear] = NULL;

    if (rear == 0) rear = 0;
    else rear--;

    return elem;
}

template < class DT >
int Queue<DT>::getLength() const // #
{
    int ilength = 0;
    for (int i = 0; i < maxSize; i++)
    {
        if (dataItems[i] != NULL) ilength++;
    }
    return ilength;
}