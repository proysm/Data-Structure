//--------------------------------------------------------------------
//
//  Laboratory b, In-lab Exercise 2                    testbhs.cpp
//
//  Test program for for the heapSort() function
//
//--------------------------------------------------------------------

#include <iostream>
#include "heapsort.cpp"

using namespace std;

//--------------------------------------------------------------------

class TestData
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

const int maxNumDataItems = 10;

void main ()
{
    TestData testList[maxNumDataItems];     // Array
    int size,                               // Number of data items
        inputPty,                           // Input priority
        j;                                  // Loop counter

    // Read in the array.

    cout << endl << "Enter priorities (end with EOF) : ";
    size = 0;
    while ( size < maxNumDataItems  &&  cin >> inputPty )
       testList[size++].setPty(inputPty);

    // Output the unsorted array.

    cout << "Unsorted array :";
    for ( j = 0 ; j < size ; j++ )
        cout << " " << testList[j].pty();
    cout << endl;

    // Sort the array using heap sort.

    heapSort(testList,size);

    // Output the sorted array.

    cout << "Sorted array   :";
    for ( j = 0 ; j < size ; j++ )
        cout << " " << testList[j].pty();
    cout << endl;

    system("pause");
}
