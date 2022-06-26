//--------------------------------------------------------------------
//
//  Laboratory 13                                             heap.h
//
//  Class declaration for the array implementation of the Heap ADT
//
//--------------------------------------------------------------------

using namespace std;

const int defMaxHeapSize = 10;    // Default maximum heap size

template < class DT >
class Heap
{
  public:

    // Constructor
    Heap ( int maxNumber = defMaxHeapSize );

    // Destructor
    ~Heap ();

    // Heap manipulation operations
    void insert(const DT& newDataItem);    // Insert data item
    DT removeMax(); // Remove max pty element
    void clear ();                          // Clear heap

    // Heap status operations
    bool isEmpty () const;                  // Heap is empty
    bool isFull () const;                   // Heap is full

    // Output the heap structure -- used in testing/debugging
    void showStructure () const;

  private:

    // Recursive partner of the showStructure() function
    void showSubtree ( int index, int level ) const;

    // Data members
    int maxSize,   // Maximum number of elements in the heap
        size;      // Actual number of elements in the heap
    DT* dataItems; // Array containing the heap elements
};
