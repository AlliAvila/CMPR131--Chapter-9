// Names: Allison Avila, Hayden Martinez, David Derramadero
// Date : Started 11/5/2025
// Chapter 9 - Assignments 
#include <iostream>
#include <ctime>
#include <random>
#include "input.h"
#include "TowerOfHanoi.h"
#include "nQueens.h"

using namespace std;
void option1();
void pattern(int level, int spaces);
void printSpaces(int n);
void printStars(int n);
void option2();
void guessNumber(int low,int high,int count);
void option3();
void option4();

int main()
{
	srand(time(0));
	do
	{
		system("cls");
		cout << "\n\t\t CMPR131 Chapter 9: Recursive Applications";
		cout << "\n\t\t" << string(70, char(205));
		cout << "\n\t\t1> Pattern of astricks and blanks";
		cout << "\n\t\t2> Guess a number";
		cout << "\n\t\t3> Solve Tower of Hanoi";		
		cout << "\n\t\t4> Solve n-Queens";
		cout << "\n\t\t" << string(70, char(196));
		cout << "\n\t\t0> Exit";
		cout << "\n\t\t" << string(70, char(205)) << '\n';
		switch (inputInteger("\t\t Option: ", 0, 4))
		{
		case 0: exit(1);
		case 1: option1(); break;
		case 2: option2(); break;
		case 3: option3(); break;
		case 4: option4(); break;
		default: cout << "\n\tERROR: invalid option.\n";
		}
		cout << '\n';
		system("pause");
	} while (true);
	return 0;
}
void option1()
{
	system("cls");
	cout << "\n\n\t1> Pattern of astricks and blanks\n";

	pattern(0, 0);
	
	cout << "\n";
}


// Pre-Condition: Gets called from pattern and n is the number of spaces
// Post-Condtion: prints the number of spaces
void printSpaces(int n)
{
	if (n == 0) return;
	cout << " ";
	printSpaces(n - 1);
}
// Pre-Condition: Gets called from pattern and n is the number of starts
// Post-Condtion: prints the number of stars
void printStars(int n)
{
	if (n == 0) return;
	cout << "*";
	if (n > 1) cout << " ";
	printStars(n - 1);
}
// Pre-Condition: Gets called from main
// Post-Condtion: Prints a pattern of * recursively separated by spaces
void pattern(int level, int spaces)
{
	if (level > 1) return; // Base case: stop after level 3

	// Line 1: 1 star
	printSpaces(spaces);
	printStars(1);
	cout << "\n";

	// Line 2: 2 stars
	printSpaces(spaces);
	printStars(2);
	cout << "\n";

	// Line 3: 1 star, spacesed more
	printSpaces(spaces + 2);
	printStars(1);
	cout << "\n";

	// Line 4: 4 stars
	printSpaces(spaces);
	printStars(4);
	cout << "\n";

	// Line 5: 1 star, spacesed more
	printSpaces(spaces + 4);
	printStars(1);
	cout << "\n";

	// Line 6: 2 stars
	printSpaces(spaces + 4);
	printStars(2);
	cout << "\n";

	// Line 7: 1 star, spacesed more
	printSpaces(spaces + 6);
	printStars(1);
	cout << "\n";

	// Line 8: 8 stars
	if (level == 1)
		return;

	printSpaces(spaces);
	printStars(8);
	cout << "\n";
	pattern(level + 1, spaces + 8);
}

// Pre-Condition: Gets called from main
// Post-Condtion: calls guessNumber function and displays the number the user was guessing of
void option2()
{
	system("cls");
	int ogMaxNumber = rand() % 1000 + 1;
	cout << "\n\t2> Guess your number between 1 to " << ogMaxNumber << "\n\t";
	system("pause");
	int guessCounter = 1;
	int min = 1;
	int max = ogMaxNumber;
	
	guessNumber(min, max, guessCounter);

}
// Pre-Condition: Gets called from option two with high being the first max number to guess from
// Post-Condtion: calls recursivly until the number is found
void guessNumber(int low, int high, int count)
{
	if (low == high)
	{
		cout << "\n\tYour number must be " << low << "!";
		cout << "\n\tNumber of guesses: " << count;
		return;
	}
	
	int guess = (low + high) / 2;

	if (guess <= 1)
	{
		cout << "\n\tYour number must be " << low << "!";
		cout << "\n\tNumber of guesses: " << count;
		return;
	}
	if (toupper(inputChar("\n\tIs your number " + to_string(guess) + "? (Y-yes or N-no): ", static_cast<string>("yn"))) == 'Y')
	{
		cout << "\n\tNumber of guesses: " << count << " Yay!";
		return;
	}
	if (toupper(inputChar("\tIs your number larger than " + to_string(guess) + "? (Y-yes or N-no): ", static_cast<string>("yn"))) == 'Y')
	{
		low = guess + 1;
	}
	else
	{
		high = guess - 1;
	}
	count++;

	guessNumber(low, high, count);
}


// Tower of Hanoi (recursive)
// Precondition: Utilizes the TowerOfHanoi class to play the game.
// Postcondition: Manages user input for the amount of rings to be used in order to play the Tower of Hanoi game. Plays until the user decides to stop (N).
void option3()
{
	do
	{
		system("cls");
		cout << "Tower of Hanoi (Recursive)";
		cout << "\n" << string(70, char(196));
		short rings = inputInteger("\n\n\tEnter the number of rings (1..64): ", 1, 64);

		TowerOfHanoi tower(rings);

		tower.start();

	} while (toupper(inputChar("\n\tPlay again? (Y-yes or N-no): ", static_cast<string>("yn"))) != 'N');
}
/// Pre-Condition: 
/// Called from main if the user chose option 4
/// Post-Condition:
/// Displays a solution to the n-Queens game if possible based on the user's input
void option4()
{
	system("cls");
	cout << "\n\t3> n-Queens Problem ";
	cout << "\n\t" << string(65, char(196));

	int boardDimension = inputInteger("\n\tEnter the board dimension dxd: ",true);

	nQueens game(boardDimension);

	int firstColumnPosition = inputInteger("\n\tEnter the colume position(1.." + to_string(boardDimension) + ") of the first Queen on row 1:", 1, boardDimension);

	bool solved = game.solveNQueens(firstColumnPosition);
}
