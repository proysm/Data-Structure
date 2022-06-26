//--------------------------------------------------------------------
//  2021111954 À¯¼ö¹Î
//  Laboratory 5                                        stackarr.cpp
//
//  SOLUTION: Array implementation of the Stack ADT
//
//--------------------------------------------------------------------
#include "stacklnk.h"
#include <assert.h>
//--------------------------------------------------------------------

template <class DT>
StackNode<DT>::StackNode(const DT& nodeData, StackNode* nextPtr)
    : dataItem(nodeData), next(nextPtr)
{

}


//--------------------------------------------------------------------

template <class DT>
Stack<DT>::Stack(int ignored)
    : top(0)
{

}

//--------------------------------------------------------------------

template <class DT>
Stack<DT>:: ~Stack()
{
    delete top;
}

//--------------------------------------------------------------------

template <class DT>
void Stack<DT>::push(const DT& newDataItem)
{
    top = new StackNode<DT>(newDataItem, top);
    assert(top != 0);
}

//--------------------------------------------------------------------

template <class DT>
DT Stack<DT>::pop()
{
    StackNode<DT>* p;   // Pointer to popped node
    DT temp;            // Temporarily stores popped element

    temp = top->dataItem;
    p = top;
    top = top->next;
    delete p;

    return temp;

}

//--------------------------------------------------------------------

template <class DT>
void Stack<DT>::clear()
{
    StackNode<DT>* p, * next_p;
    p = top;
    while (p != 0)
    {
        next_p = p->next;
        delete p;
        p = next_p;
    }

    top = 0;

}

//--------------------------------------------------------------------

template <class DT>
bool Stack<DT>::isEmpty() const
{
    return (top == 0);
}

//--------------------------------------------------------------------

template <class DT>
bool Stack<DT>::isFull() const
{
    return 0;
}

//--------------------------------------------------------------------

template < class DT >
void Stack<DT>::showStructure() const

// Linked list implementation. Outputs the data items in a stack.
// If the stack is empty, outputs "Empty stack". This operation is
// intended for testing and debugging purposes only.

{
    StackNode<DT>* p;   // Iterates through the stack

    if (top == 0)
        cout << "Empty stack" << endl;
    else
    {
        cout << "top ";
        for (p = top; p != nullptr; p = p->next)
            cout << p->dataItem << " ";
        cout << "bottom" << endl;
    }
}