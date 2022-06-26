////--------------------------------------------------------------------
////
////  Laboratory 13                                         show13.cpp
////
////  Adjacency matrix implementations of the showStructure operation
////  for the Weighted Graph ADT
////
////--------------------------------------------------------------------
//
//void WtGraph:: showStructure () const
//
//// Outputs a graph's vertex list and adjacency matrix. This operation
//// is intended for testing/debugging purposes only.
//
//{
//    int wt,         // Edge weight
//        row, col;   // Loop counters
//
//    if ( size == 0 )
//       cout << "Empty graph" << endl;
//    else
//    {
//       cout << endl << "Vertex list : " << endl;
//       for ( row = 0 ; row < size ; row++ )
//           cout << row << '\t' << vertexList[row].label << endl;
//
//       cout << endl << "Edge matrix : " << endl << '\t';
//       for ( col = 0 ; col < size ; col++ )
//           cout << col << '\t';
//       cout << endl;
//       for ( row = 0 ; row < size ; row++ )
//       {
//           cout << row << '\t';
//           for ( col = 0 ; col < size ; col++ )
//           {
//               wt = getEdge(row,col);
//               if ( wt == infiniteEdgeWt )
//                  cout << "- \t";
//               else
//                  cout << wt << '\t';
//           }
//           cout << endl;
//       }
//    }
//}
//
////--------------------------------------------------------------------
//
//void WtGraph:: showStructure () const
//
//// Outputs a graph's vertex list, adjacency matrix, and path matrix.
//// This operation is intended for testing/debugging purposes only.
//
//{
//    int wt,         // Edge weight
//        row, col;   // Loop counters
//
//    if ( size == 0 )
//       cout << "Empty graph" << endl;
//    else
//    {
//       cout << endl << "Vertex list : " << endl;
//       for ( row = 0 ; row < size ; row++ )
//           cout << row << '\t' << vertexList[row].label << endl;
//
//       cout << endl << "Edge matrix : " << endl << '\t';
//       for ( col = 0 ; col < size ; col++ )
//           cout << col << '\t';
//       cout << endl;
//       for ( row = 0 ; row < size ; row++ )
//       {
//           cout << row << '\t';
//           for ( col = 0 ; col < size ; col++ )
//           {
//               wt = getEdge(row,col);
//               if ( wt == infiniteEdgeWt )
//                  cout << "- \t";
//               else
//                  cout << wt << '\t';
//           }
//           cout << endl;
//       }
//
//       cout << endl << "Path matrix : " << endl << '\t';
//       for ( col = 0 ; col < size ; col++ )
//           cout << col << '\t';
//       cout << endl;
//       for ( row = 0 ; row < size ; row++ )
//       {
//           cout << row << '\t';
//           for ( col = 0 ; col < size ; col++ )
//           {
//               wt = getPath(row,col);
//               if ( wt == infiniteEdgeWt )
//                  cout << "- \t";
//               else
//                  cout << wt << '\t';
//           }
//           cout << endl;
//       }
//    }
//}