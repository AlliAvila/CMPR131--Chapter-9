#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;

class nQueens
{
private:
    char** board;
    int dimension;

    // Recursive helper function
    // Precondition: 
    // The board has been initialized and may already have queens placed in previous rows (0 to row - 1).
    // 'row' represents the current row index (0-based) where a queen needs to be placed.
    // Postcondition:
    // Returns true if a valid configuration is found (all queens placed), false otherwise.
    bool solveNQueensRecursive(int row)
    {
        // Base case: all queens have been placed
        if (row == dimension)
            return true;

        // Try to place a queen in each column of the current row
        for (int col = 0; col < dimension; col++)
        {
            if (canPlaceQueen(row, col))
            {
                placeQueen(row, col);

                // Recurse to place a queen in the next row
                if (solveNQueensRecursive(row + 1))
                {
                    return true;
                }

                // Backtrack: remove queen if placing here didn't lead to a solution
                removeQueen(row, col);
            }
        }

        // No valid column found in this row → backtrack
        return false;
    }

public:
    // Constructor
    // Precondition: n > 0
    // Postcondition: Allocates a dimension x dimension board and initializes all cells to '_'
    nQueens(int n)
    {
        dimension = n;

        // allocate rows
        board = new char* [dimension];

        // allocate columns
        for (int i = 0; i < dimension; i++)
        {
            board[i] = new char[dimension];
            for (int j = 0; j < dimension; j++)
            {
                board[i][j] = '_';
            }
        }
    }

    // Destructor
    // Precondition: Object must be valid
    // Postcondition: Deallocates dynamically allocated 2D board
    ~nQueens()
    {
        for (int i = 0; i < dimension; i++)
        {
            delete[] board[i];
        }

        delete[] board;
    }

    // Display the current board
    // Precondition: Board must be initialized
    // Postcondition: Prints the board in a formatted grid to the console
    void displayBoard()
    {
        cout << "\n\t" << char(201) << string((dimension * 2) - 1, char(205)) << char(187);

        for (int i = 0; i < dimension; i++)
        {
            cout << "\n\t" << char(186);
            for (int j = 0; j < dimension; j++)
            {
                if (j == (dimension - 1))
                {
                    cout << board[i][j];
                }
                else
                {
                    cout << board[i][j] << char(179);
                }
            }

            cout << char(186);
        }

        cout << "\n\t" << char(200) << string((dimension * 2) - 1, char(205)) << char(188) << "\n";
    }

    // Place a queen at (row, col)
    // Precondition: row and col must be within bounds (0 to dimension-1)
    // Postcondition: The board at (row, col) is updated with 'Q'
    void placeQueen(int row, int col)
    {
        board[row][col] = 'Q';
    }

    // Remove a queen from (row, col)
    // Precondition: row and col must be within bounds (0 to dimension-1)
    // Postcondition: The board at (row, col) is updated with '_'
    void removeQueen(int row, int col)
    {
        board[row][col] = '_';
    }

    // Check if a queen can be placed at (row, col)
    // Precondition: row and col must be within bounds (0 to dimension-1)
    // Postcondition: Returns true if placing a queen does not conflict with existing queens
    bool canPlaceQueen(int row, int col)
    {
        // check column
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < dimension; j++)
            {
                if (board[i][j] == 'Q' && (j == col || abs(i - row) == abs(j - col)))
                {
                    return false;
                }
            }
        }

        return true;
    }

    // Recursion-based solver
    // startCol = column where the first queen (row 1) is placed
    // Precondition: startCol must be between 1 and dimension
    // Postcondition: Solves the n-Queens problem with the first queen fixed in row 1, startCol.
    // Displays the solution if found, otherwise prints a no-solution message
    bool solveNQueens(int startCol)
    {
        // place first queen in row 0 at the specified column
        placeQueen(0, startCol - 1);

        // start recursion from the next row
        if (solveNQueensRecursive(1))
        {
            cout << "\n\tSolution found:";
            displayBoard();
            return true;
        }
        else
        {
            cout << "\n\tNo solution exists with the first queen fixed at column " << startCol << ".\n\n";
            return false;
        }
    }

    // Getter for dimension
    // Precondition: Object must be properly constructed
    // Postcondition: Returns the dimension of the board
    int getDimension() const
    {
        return dimension;
    }
};
