//--------------------------------------------------------------------
//
//  Laboratory 5                                        stackarr.cpp
//
//  SOLUTION: Array implementation of the Stack ADT
//
//--------------------------------------------------------------------
#include "stackarr.h"

//--------------------------------------------------------------------

template <class DT>
Stack<DT>::Stack(int maxNumber)
    : top(maxNumber), maxSize(maxNumber)
{
    dataItems = new DT[maxSize];
}

//--------------------------------------------------------------------

template <class DT>
Stack<DT>:: ~Stack()
{
    delete[] dataItems;

}

//--------------------------------------------------------------------

template <class DT>
void Stack<DT>::push(const DT& newDataItem)
{
    if (isFull())
    {
        cout << "Stack is full" << endl;
    }
    else
    {
        top--;
        dataItems[top] = newDataItem;


    }
}

//--------------------------------------------------------------------

template <class DT>
DT Stack<DT>::pop()
{
    if (isEmpty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {

        dataItems[top] = NULL;
        top++;
        return dataItems[top];
    }

}

//--------------------------------------------------------------------

template <class DT>
void Stack<DT>::clear()
{
    for (int i = 0; i < maxSize; i++)
    {
        dataItems[i] = NULL;
        top = maxSize;
    }

}

//--------------------------------------------------------------------

template <class DT>
bool Stack<DT>::isEmpty() const
{
    if (top == maxSize) return true;
    else false;
}

//--------------------------------------------------------------------

template <class DT>
bool Stack<DT>::isFull() const
{
    return(top == NULL);
}

//--------------------------------------------------------------------

template < class DT >
void Stack<DT>::showStructure() const

// "Downward" array implementation. Outputs the data items in a 
// stack. If the stack is empty, outputs "Empty stack". This operation
// is intended for testing and debugging purposes only.

{
    int j;   // Loop counter

    if (top == maxSize)
        cout << "Empty stack" << endl;
    else
    {
        cout << "top = " << top << endl;
        for (j = 0; j < maxSize; j++)
            cout << j << "\t";
        cout << endl;
        for (j = 0; j < maxSize; j++)
            if (j < top)
                cout << " \t";
            else
                cout << dataItems[j] << "\t";
        cout << endl;
    }
}
