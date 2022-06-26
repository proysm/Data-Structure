//--------------------------------------------------------------------
//
//  Laboratory 6                                          queuelnk.h
//
//  Class declarations for the linked list implementation of the
//  Queue ADT
//
//--------------------------------------------------------------------

template < class DT >        // Forward declaration of the Queue class 
class Queue;

template < class DT >
class QueueNode              // Facilitator class for the Queue class
{
private:

    // Constructor
    QueueNode(const DT& nodeData, QueueNode* nextPtr);

    // Data members
    DT dataItem;         // Queue data item
    QueueNode* next;     // Pointer to the next data item

    friend class Queue<DT>;
};

//--------------------------------------------------------------------

template < class DT >
class Queue
{
public:

    // Constructor
    Queue(int ignored = 0);

    // Destructor
    ~Queue();

    // Queue manipulation operations
    void enqueue(const DT& newDataItem);        // Enqueue data item
    DT dequeue();                             // Dequeue data item

    void clear();                            // Clear queue

    // Queue status operations
    bool isEmpty() const;                    // Queue is empty
    bool isFull() const;                     // Queue is full

    // Output the queue structure -- used in testing/debugging
    void showStructure() const;

private:

    // Data members
    QueueNode<DT>* front,   // Pointer to the front node
        * rear;    // Pointer to the rear node
};

