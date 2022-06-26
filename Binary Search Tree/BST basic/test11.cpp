//--------------------------------------------------------------------
//
//  Laboratory 11                                         test11.cpp
//
//  Test program for the operations in the Binary Search Tree ADT
//
//--------------------------------------------------------------------

#include <iostream>
#include "bstree.cpp"

using namespace std;

//--------------------------------------------------------------------
//
// Declaration for the binary search tree data item class
//

class TestData
{
  public:

    void setKey ( int newKey )
        { keyField = newKey; }   // Set the key

    int key () const
        { return keyField; }     // Returns the key

  private:

    int keyField;                // Key for the data item
};

//--------------------------------------------------------------------

void print_help()
{
    cout << endl << "Commands:" << endl;
    cout << "  P    : Help (displays this message)" << endl;
    cout << "  +key : Insert (or update) data item" << endl;
    cout << "  ?key : Retrieve data item" << endl;
    cout << "  -key : Remove data item" << endl;
    cout << "  K    : Write keys in ascending order" << endl;
    cout << "  C    : Clear the tree" << endl;
    cout << "  E    : Empty tree?" << endl;
    cout << "  F    : Full tree?" << endl;
    cout << "  H    : Height of tree" << endl;
    cout << "  <key : Write keys that are < key" << endl;
    cout << "  Q    : Quit the test program" << endl;
    cout << endl;
}

void main()
{
    BSTree<TestData,int> testTree;   // Test binary search tree
    TestData testData;               // Binary search tree data item
    int inputKey = 0;                    // User input key
    char cmd;                        // Input command

    print_help();

    do
    {
        testTree.showStructure();                     // Output tree

        cout << endl << "Command: ";                  // Read command
        cin >> cmd;
        if ( cmd == '+'  ||  cmd == '?'  ||
             cmd == '-'  ||  cmd == '<'     )
           cin >> inputKey;

        switch ( cmd )
        {
          case 'P' : case 'p' :
               print_help();
               break; 

          case '+' :                                  // insert
               testData.setKey(inputKey);
               cout << "Insert : key = " << testData.key()
                    << endl;
               testTree.insert(testData);
               break;

          case '?' :                                  // retrieve
               if ( testTree.retrieve(inputKey,testData) )
                  cout << "Retrieved : key = "
                       << testData.key() << endl;
               else
                  cout << "Not found" << endl;
               break;

          case '-' :                                  // remove
               if ( testTree.remove(inputKey) )
                  cout << "Removed data item" << endl;
               else
                  cout << "Not found" << endl;
               break;

          case 'K' : case 'k' :                       // writeKeys
               cout << "Keys:" << endl;
               testTree.writeKeys();
               break;

          case 'C' : case 'c' :                       // clear
               cout << "Clear the tree" << endl;
               testTree.clear();
               break;

          case 'E' : case 'e' :                       // empty
               if ( testTree.isEmpty() )
                  cout << "Tree is empty" << endl;
               else
                  cout << "Tree is NOT empty" << endl;
               break;

          case 'F' : case 'f' :                       // full
               if ( testTree.isFull() )
                  cout << "Tree is full" << endl;
               else
                  cout << "Tree is NOT full" << endl;
               break;

          case '<' :                              // In-lab Exercise 3
              cout << "Keys < " << inputKey << " : " << endl;
              testTree.writeLessThan(inputKey);
              cout << endl;
              break;

          case 'Q' : case 'q' :                   // Quit test program
               break;

          default :                               // Invalid command
               cout << "Inactive or invalid command" << endl;
        }
    }
    while ( ( cmd != 'Q' ) && ( cmd != 'q' ) );

}
