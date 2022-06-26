//--------------------------------------------------------------------
//
//  Laboratory 6                                          queueArr.h
//
//  Class declaration for the array implementation of the Queue ADT
//
//--------------------------------------------------------------------

const int defMaxQueueSize = 10;   // Default maximum queue size

template < class DT >
class Queue
{
public:
    // Constructor
    Queue(int maxNumber = defMaxQueueSize);

    // Destructor
    ~Queue();

    // Queue manipulation operations
    void enqueue(const DT& newDataItem);        // Enqueue data item
    DT dequeue();                           // Dequeue data item

    void clear();                            // Clear queue

    // Queue status operations
    bool isEmpty() const;                    // Queue is empty
    bool isFull() const;                     // Queue is full

    // Output the queue structure -- used in testing/debugging
    void showStructure() const;

    void putFront(const DT& newDataItem); //In-lab 2
    DT getRear(); //In-lab 2
    int getLength() const; //In-lab 3

private:

    // Data members
    int maxSize,   // Maximum number of data items in the queue
        front,     // Index of the front data item
        rear;      // Index of the rear data item
    DT* dataItems;   // Array containing the queue data items.
};

