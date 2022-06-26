//유수민 2021111954 컴퓨터공학과

#include "queueLnk10.h"
#include <iostream>

using namespace std;

template <class DT>
QueueNode<DT>::QueueNode(const DT& nodeData, QueueNode* nextPtr)
    :dataItem(nodeData), next(nextPtr)
{}

template <class DT>
Queue<DT>::Queue(int ignored)
    : front(0), rear(0)
{}

template<class DT>
Queue<DT>::~Queue()
{
    delete front;
    delete rear;
}

template<class DT>
void Queue<DT>::enqueue(const DT& newDataItem)
{
    if (isEmpty())
    {
        rear = new QueueNode<DT>(newDataItem, NULL);
        front = rear;
    }
    else
    {
        QueueNode<DT>* nodeData = new QueueNode<DT>(newDataItem, NULL);
        rear->next = nodeData;
        rear = nodeData;
    }
}

template<class DT>
DT Queue<DT>::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is Empty, you can't Dequeue!" << endl;
    }
    else
    {
        DT nodeData;
        QueueNode<DT>* p;
        nodeData = front->dataItem;
        p = front;
        cout << "dequeue value" << front->dataItem << endl;
        front = front->next;
        delete p;
        return nodeData;
    }

}

template <class DT>
void Queue<DT>::clear()
{
    while (front != NULL)
    {
        QueueNode<DT>* p;
        p = front;
        front = front->next;
        delete p;
    }
}

template<class DT>
bool Queue<DT>::isEmpty() const
{
    return (front == NULL);
}

template<class DT>
bool Queue<DT>::isFull() const
{
    return false;
}

template<class DT>
void Queue<DT>::showStructure() const
{
    QueueNode<DT>* p;   // Iterates through the queue

    if (front == nullptr)
        cout << "Empty queue" << endl;
    else
    {
        cout << "front ";
        for (p = front; p != nullptr; p = p->next)
            cout << p->dataItem << " ";
        cout << "rear" << endl;
    }
}