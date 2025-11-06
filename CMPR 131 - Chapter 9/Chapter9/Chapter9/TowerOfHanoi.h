#pragma once

#include <iomanip>
#include <string>
#include <vector>
#include <stack>

using namespace std;
class TowerOfHanoi
{
private:
	vector<stack<short>> rods;
	short rings;
	int moves;
public:
	// Precondition: Utilizes the number of rings to initialize the game. rings(ring) initializes the number of rings.
	// Postcondition: Initializes the rods and places all rings on the first rod in descending order.
	TowerOfHanoi(int ring) : rings(ring)
	{
		moves = 0;

		rods.resize(3); // Create 3 rods

		// Initialize the first rod with rings in descending order
		for (int i = rings; i > 0; --i)
		{
			rods[0].push(i);
		}
	}

	// Precondition: Receives the number of rings to move and the source, destination, and auxiliary rods.
	// Postcondition: Recursively moves the rings from the source rod to the destination rod using the auxiliary rod.
	void move(int& count, short numberOfRings, char from, char to, char aux)
	{

		if (numberOfRings == 0)
			return;

		move(count, numberOfRings - 1, from, aux, to);
		count++;
		cout << "\n\tMove #" << count << ": disk " << numberOfRings << " from peg-" << from << " to peg-" << to << "...\n";

		int indexFrom = from - 'A';
		int indexTo = to - 'A';
		int ring = rods[indexFrom].top();
		rods[indexFrom].pop();
		rods[indexTo].push(ring);

		displayTowers();

		moves++;


		move(count, numberOfRings - 1, aux, to, from);
	}

	// Precondition: Receives the index of the ring and the height of the tower
	// Postcondition: Returns a visual of a single rod with its rings
	void oneRod(int index, int height)
	{

		// If no ring, display empty rod
		if (index == 0)
		{
			cout << string(height, ' ') << string(1, char(186)) << string(height + 1, ' ');
			return;
		}

		if (height < 10)
		{
			cout << string(height - index, ' ') << string(index, char(220)) << index << string(index, char(220)) << string((height - index) + 1, ' ');
		}
		else
		{
			cout << string(height, ' ') << index << string(height + 1, ' ');

			if (index >= 10)
			{
				cout << "\b"; // Backspace to adjust for two-digit numbers
			}
		}

	}

	// Precondition: Utilizes oneRod to display each rod and its rings. 
	// Postcondition: Displays the current visual state of all 3 towers.
	void displayTowers()
	{
		int ringSize = rings;

		// Create a 2D vector to hold the rings on each rod(peg) for display purposes
		vector<vector<int>> pegs(3, vector<int>(rings, 0));


		cout << "\n\t " << string(rings - 1, ' ') << string(1, char(186)) << string(rings * 2 + 1, ' ') << string(1, char(186)) << string(rings * 2 + 1, ' ') << string(1, char(186));

		// Transfer the contents of the rods to a 2D vector for easier display
		for (int i = 0; i < 3; ++i)
		{
			stack<short> temp = rods[i];
			int index = temp.size() - 1;
			while (!temp.empty() && index >= 0)
			{
				pegs[i][index--] = temp.top();
				temp.pop();
			}
		}

		for (int stack = rings - 1; stack >= 0; --stack) // For each level of the rods
		{
			for (int rod = 0; rod < 3; ++rod)
			{
				if (rod == 0)
				{
					cout << "\n\t";
				}

				oneRod(pegs[rod][stack], rings);
			}
		}


		cout << "\n\t" << string(ringSize, char(205)) << string(1, char(202)) << string(ringSize, char(205)) << " " << string(ringSize, char(205)) << string(1, char(202)) << string(ringSize, char(205)) << " "
			<< string(ringSize, char(205)) << string(1, char(202)) << string(ringSize, char(205)) << " ";
		cout << "\n\t" << string(ringSize, ' ') << "A" << string(ringSize * 2 + 1, ' ') << "B" << string(ringSize * 2 + 1, ' ') << "C";
	}

// Precondition: Utilizes methods for move() and displayTowers()
// Postcondition: Displays the game and manages user input. Displays the number of moves the computer took to solve the game.
	void start()
	{
		system("cls");
		int count = 0;
		cout << "Tower of Hanoi (Recursive)";
		cout << "\n" << string(70, char(196)) << "\n";

		displayTowers();
		move(count, rings, 'A', 'C', 'B');	

		cout << "\n\n\tThe computer has solved the game in " << count << " moves.";
	}


};
