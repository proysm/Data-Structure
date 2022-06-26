//--------------------------------------------------------------------
//
//  Laboratory 10                                         test10.cpp
//
//  Test program for a set of recursive linked list functions
//
//--------------------------------------------------------------------

// Reads a list of characters and calls the specified recursive
// routine.

#include <iostream>
#include "listrec.cpp"

void main()
{
    List<char> testList;   // Test list
    char testData;         // List data element

    cout << endl << "Enter a list of characters : ";
    cin.get(testData);
    while ( testData != '\n' )
    {
        testList.insert(testData);
        cin.get(testData);

    }
    testList.showStructure();

    // Call a recursive routine by uncommenting the call you wish to
    // execute.
    testList.write();
    testList.insertEnd('!');

    // 각각의 in-lab 확인할 때 상대 주석 처리 필요.
    //in-lab 1
    //testList.stackWriteMirror();
    //testList.iterReverse();
    //testList.deleteEnd();
    //cout << "length = " << testList.getLength() << endl;
    //testList.showStructure();

    //in-lab 3
    testList.writeMirror();
    testList.iterReverse();
    testList.deleteEnd();
    testList.iterReverse();
    cout << "length = " << testList.getLength() << endl;
    testList.stackWriteMirror();
    testList.cRemove();
    testList.showStructure();
 
    system("pause");
}
