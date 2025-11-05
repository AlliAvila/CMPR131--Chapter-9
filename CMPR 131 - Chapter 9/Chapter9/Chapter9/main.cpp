// Names: Allison Avila, Hayden Martinez, David Derramadero
// Date : Started 11/5/2025
// Chapter 9 - Assignments 
#include <iostream>
#include "input.h"
#include <ctime>
#include <random>

using namespace std;
void option1();
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
	cout << "\n\n\t1> Pattern of astricks and blanks";



}
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
void guessNumber(int low, int high, int count)
{
	if (low == high)
	{
		cout << "\n\tYour number must be " << low << "!";
		cout << "\n\tNumber of guesses: " << count;
		return;
	}

	int guess = (low + high) / 2;
	if (toupper(inputChar("\n\tIs your number " + to_string(guess) + "? (Y-yes or N-no): ", static_cast<string>("yn"))) == 'Y')
	{
		cout << "\n\tNumber of guesses: " << count;
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
void option3()
{
	system("cls");
	short numberOfRings = inputInteger("\n\tEnter the number of rings (1..64): ", 1, 64);


}
void option4()
{
	system("cls");
	short boardDimension = inputInteger("\n\tEnter the board dimension dxd: ", true);

	short firstColumnPosition = inputInteger("\n\tEnter the colume position(1.." + to_string(boardDimension) + ") of the first Queen on row 1:", 1, boardDimension);

}