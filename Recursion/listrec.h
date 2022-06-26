//--------------------------------------------------------------------
//
//  Laboratory 11                                          listrec.h
//
//  Class declarations for a partial linked list implementation of
//  the List ADT with additional recursive linked list functions
//
//--------------------------------------------------------------------

template < class DT >         // Forward declaration of the List class
class List;

template < class DT >
class ListNode                // Facilitator class for the List class
{
  private:

    // Constructor
    ListNode ( const DT &initData, ListNode *nextPtr );

    // Data members
    DT dataItem;        // List data item
    ListNode *next;    // Pointer to the next list node

  friend class List<DT>;
};

//--------------------------------------------------------------------

template < class DT >
class List
{
  public:

    // Constructor
    List ( int ignored = 0 );

    // Destructor
    ~List ();

    // List manipulation functions
    void insert ( const DT &newData );         // Insert after cursor
    void clear ();                             // Clear list

    // Output the list structure -- used in testing/debugging
    void showStructure () const;

    // Prelab functions
    void write () const;                       // Output list data items
    void insertEnd ( const DT &newData );      // Insert at end
    void writeMirror () const;                 // Mirror view of list
    void reverse ();                           // Reverse list
    void deleteEnd ();                         // Delete from end
    int getLength () const;                    // Length of list

    // In-lab functions
    void iterReverse ();                       // In-lab Exercise 1
    void stackWriteMirror () const;            // In-lab Exercise 1
    void cRemove();                            // In-lab Exercise 3

  private:

    // Recursive partners of the Prelab functions
    void writeSub ( ListNode<DT> *p ) const;
    void insertEndSub ( ListNode<DT> *&p, const DT &newElement );
    void writeMirrorSub ( ListNode<DT> *p ) const;
    void reverseSub ( ListNode<DT> *p, ListNode<DT> *nextP );
    void deleteEndSub ( ListNode<DT> *&p );
    int getLengthSub ( ListNode<DT> *p ) const;

    // Recursive partners of the In-lab functions
    void cRemoveSub(ListNode<DT> *&p);

  private:

    // Data members
    ListNode<DT> *head,     // Pointer to the beginning of the list
                 *cursor;   // Cursor pointer
};
