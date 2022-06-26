//--------------------------------------------------------------------
//
//  Laboratory B, In-lab Exercise 1                      ptyqueue.h
//
//  Class declaration for the heap implementation of the
//  Priority Queue ADT -- inherits the array implementation of the
//  Heap ADT
//
//--------------------------------------------------------------------

#include "heap.cpp"

const int defMaxQueueSize = 10;   // Default maximum queue size

template < class DT >
class PtyQueue : public Heap<DT>
{
  public:

    // Constructor
    PtyQueue ( int maxNumber = defMaxQueueSize );

    // Queue manipulation operations
    void enqueue ( const DT &newDataItem );   // Enqueue data item
    DT dequeue ();                            // Dequeue data item
};
