//--------------------------------------------------------------------
//
//  Laboratory 9, In-lab Exercise 1                        puzzle.cs
//
//  (Shell) Anagram puzzle
//
//--------------------------------------------------------------------

// Simulates a puzzle in which a player attempts to unscramble a
// set of letters to form a word.

#include <iostream>
#include <string>
#include "listdbl.cpp"
#include <vector>
using namespace std;

//--------------------------------------------------------------------
//  컴퓨터공학과 2021111954 유수민 
//
//  Class declaration for the Anagram Puzzle ADT
//
//--------------------------------------------------------------------

class AnagramPuzzle
{
  public:

    AnagramPuzzle(string answ, string init);   // Construct puzzle
    void shiftLeft();                            // Shift letters left
    void swapEnds();                             // Swap end letters
    void display();                              // Display puzzle
    bool isSolved();                             // Puzzle solved

  private:
    // Data members
    //List<char> solution,   // Solution to puzzle
               //puzzle;     // Current puzzle configuration

    vector<char> solution, puzzle;
    int iSize;
};

//--------------------------------------------------------------------

// The main() function provides the user interface to the puzzle.

void main ()
{
    AnagramPuzzle mysteryWord("yes","yse");   // Puzzle
    char move,                                // User input move
         userQuit;                            // User quits puzzle

    // Display the initial puzzle.

    mysteryWord.display();

    // Loop until puzzle solved or user quits

    userQuit = 0;
    while ( !mysteryWord.isSolved() && !userQuit )
    {
        cout << "Enter move ( L/S/Q ): ";   // Get user move
        cin >> move;
        switch ( move )                     // Process move
        {
          case 'L' : case 'l' :  mysteryWord.shiftLeft();  break;
          case 'S' : case 's' :  mysteryWord.swapEnds();   break;
          case 'Q' : case 'q' :  userQuit = 1;             break;
          default:  cout << "Invalid move" << endl;
        }
        mysteryWord.display();              // Display puzzle
    }
    if ( mysteryWord.isSolved() )
       cout << "Congratulations!" << endl;

    system("PAUSE");
}

//--------------------------------------------------------------------
//
//  Implementation of the Anagram Puzzle ADT
//
//--------------------------------------------------------------------

AnagramPuzzle:: AnagramPuzzle(string answ, string init)

// Constructs an anagram puzzle. String answ is the solution to the
// puzzle and string init is the initial scrambled letter sequence.

{
    for (char ch : answ) 
        solution.push_back(ch);

    for (char ch : init)
        puzzle.push_back(ch);

    iSize = solution.size();
}

//--------------------------------------------------------------------

void AnagramPuzzle::shiftLeft()

// Shifts the letters left one position, the leftmost letter is moved
// to the right end of the puzzle.

{
    char temp;
    temp = puzzle[0];
    for (int i = 0; i < iSize; i++)
    { 
        if(i==iSize-1)    
            puzzle[iSize - 1] = temp;
        else 
            puzzle[i] = puzzle[i + 1];   
    
    }

    
}
//--------------------------------------------------------------------

void AnagramPuzzle:: swapEnds()

// Swaps the letters at the left and right ends of the puzzle.

{
    char temp;
    temp = puzzle[iSize-1];
    puzzle[iSize - 1] = puzzle[iSize - 2];
    puzzle[iSize - 2] = temp;
}

//--------------------------------------------------------------------

void AnagramPuzzle:: display()

// Displays an anagram puzzle.

{
    cout << "Solution of the Puzzle: ";
    for (int i = 0; i < iSize; i++) 
        cout << solution[i];
    cout << endl;

    cout << "Current String: ";
    for (int i = 0; i < iSize; i++)
        cout << puzzle[i];
    cout << endl;
}

//--------------------------------------------------------------------

bool AnagramPuzzle:: isSolved ()

// Returns true if a puzzle is solved. Otherwise returns false.

{
    
    for (int i = 0; i < iSize; i++)
        if (solution[i] != puzzle[i]) return 0;

    return 1;
}
