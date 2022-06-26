//--------------------------------------------------------------------
//  컴퓨터공학과 2021111954 유수민
//  Laboratory 13                                         test13.cpp
//
//  Test program for the operations in the Weighted Graph ADT
//
//--------------------------------------------------------------------

#include "wtgraph.h"

using namespace std;

void print_help()
{
    cout << endl << "Commands:" << endl;
    cout << "  H       : Help (displays this message)" << endl;
    cout << "  +v      : Insert (or update) vertex v" << endl;
    cout << "  =v w wt : Insert an edge with weight wt between "
         << "vertices v and w" << endl;
    cout << "  ?v      : Retrieve vertex" << endl;
    cout << "  #v w    : Display the weight of the edge between "
         << "vertices v and w" << endl;
    cout << "  -v      : Remove vertex v" << endl;
    cout << "  !v w    : Remove the edge between vertices v and w"
         << endl;
    cout << "  C       : Clear the graph" << endl;
    cout << "  E       : Empty graph?" << endl;
    cout << "  F       : Full graph?" << endl;
    cout << "  Q       : Quit the test program" << endl;
    cout << endl;

}

void main()
{
    WtGraph testGraph(8);         // Test graph
    Vertex testVertex;            // Vertex
    char v1[vertexLabelLength],
         v2[vertexLabelLength],   // Vertex labels
         cmd;                     // Input command
    int wt;                       // Edge weight

    print_help();

    do
    {

//PM    testGraph.computePaths();                 // In-lab Exercise 1

//D                                               // In-lab Exercise 3
//D     if ( testGraph.areAllEven() )
//D        cout << endl << "All vertices have even degree" << endl;
//D     else
//D        cout << endl << "NOT all vertices have even degree" << endl;

        testGraph.showStructure();                   // Output graph

        cout << endl << "Command: ";                 // Read command
        cin >> cmd;
        if ( cmd == '+'  ||  cmd == '?'  ||  cmd == '-' )
           cin >> v1;
        else if ( cmd == '#'  ||  cmd == '!' )
           cin >> v1 >> v2;
        else if ( cmd == '=' )
           cin >> v1 >> v2 >> wt;

        switch ( cmd )
        {
          case 'H' : case 'h' :
               print_help();
               break;

          case '+' :                                 // insertVertex
               cout << "Insert vertex : " << v1 << endl;
               strcpy(testVertex.label,v1);
               testGraph.insertVertex(testVertex);
               break;

          case '=' :                                 // insertEdge
               cout << "Insert edge : " << v1 << " " << v2 << " "
                    << wt << endl;
               testGraph.insertEdge(v1,v2,wt);
               break;

          case '?' :                                 // retrieveVertex
               if ( testGraph.retrieveVertex(v1,testVertex) )
                  cout << "Vertex " << v1 << " exists" << endl;
               else
                  cout << "Vertex NOT found" << endl;
               break;

		  case '#':                                 // edgeWeight
			  if (testGraph.getEdgeWeight(v1, v2, wt))
				  cout << "Weight = " << wt << endl;
			  else
				  cout << "No edge between these vertices" << endl;
			  break;

          case '-' :                                 // removeVertex
               cout << "Remove vertex " << v1 << endl;
               testGraph.removeVertex(v1);
               break;

          case '!' :                                 // removeEdge
               cout << "Remove the edge between vertices "
                    << v1 << " and " << v2 << endl;
               testGraph.removeEdge(v1,v2);
               break;

          case 'C' : case 'c' :                      // clear
               cout << "Clear the graph" << endl;
               testGraph.clear();
               break;

          case 'E' : case 'e' :                      // isEmpty
               if ( testGraph.isEmpty() )
                  cout << "Graph is empty" << endl;
               else
                  cout << "Graph is NOT empty" << endl;
               break;

          case 'F' : case 'f' :                      // isFull
               if ( testGraph.isFull() )
                  cout << "Graph is full" << endl;
               else
                  cout << "Graph is NOT full" << endl;
               break;

          case 'Q' : case 'q' :                   // Quit test program
               break;

          default :                               // Invalid command
               cout << "Invalid command" << endl;
        }
    }
    while ( cmd != 'Q'  &&  cmd != 'q' );
}
