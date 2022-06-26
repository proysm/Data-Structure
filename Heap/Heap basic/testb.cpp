//--------------------------------------------------------------------
//
//  Laboratory B                                         testb.cpp
//
//  Test program for the operations in the Heap ADT
//
//--------------------------------------------------------------------

#include <iostream>
#include "heap.cpp"

using namespace std;

//--------------------------------------------------------------------
//
// Declaration for the heap data item class
//

class TestDataItem
{
  public:

    void setPty ( int newPty )
        { priority = newPty; }   // Set the priority

    int pty () const
        { return priority; }     // Returns the priority

  private:

    int priority;                // Priority for the data item
};

//--------------------------------------------------------------------

void print_help()
{
    cout << endl << "Commands:" << endl;
    cout << "  H    : Help (displays this message)" << endl;
    cout << "  +pty : Insert data item" << endl;
    cout << "  -    : Remove highest priority data item" << endl;
    cout << "  C    : Clear the heap" << endl;
    cout << "  E    : Empty heap?" << endl;
    cout << "  F    : Full heap?" << endl;
    cout << "  Q    : Quit the test program" << endl;
    cout << endl;
}

void main()
{
    Heap<TestDataItem> testHeap(8);  // Test heap
    TestDataItem testDataItem;       // Heap data item
    int inputPty;                    // User input priority
    char cmd;                        // Input command

    print_help();

    do
    {
        testHeap.showStructure();                     // Output heap

        cout << endl << "Command: ";                  // Read command
        cin >> cmd;
        if ( cmd == '+' )
           cin >> inputPty;

        switch ( cmd )
        {
          case 'H' : case 'h' :
               print_help();
               break;

          case '+' :                                  // insert
               testDataItem.setPty(inputPty);
               cout << "Insert : pty = " << testDataItem.pty()
                    << endl;
               testHeap.insert(testDataItem);
               break;

          case '-' :                                  // removeMax
               testDataItem = testHeap.removeMax();
               cout << "Removed data item : "
                    << " pty = " << testDataItem.pty() << endl;
               break;

          case 'C' : case 'c' :                       // clear
               cout << "Clear the heap" << endl;
               testHeap.clear();
               break;

          case 'E' : case 'e' :                       // isEmpty
               if ( testHeap.isEmpty() )
                  cout << "Heap is empty" << endl;
               else
                  cout << "Heap is NOT empty" << endl;
               break;

          case 'F' : case 'f' :                       // isFull
               if ( testHeap.isFull() )
                  cout << "Heap is full" << endl;
               else
                  cout << "Heap is NOT full" << endl;
               break;

          case 'Q' : case 'q' :                   // Quit test program
               break;

          default :                               // Invalid command
               cout << "Inactive or invalid command" << endl;
        }
    }
    while ( ( cmd != 'Q' ) && ( cmd != 'q' ) );
}
