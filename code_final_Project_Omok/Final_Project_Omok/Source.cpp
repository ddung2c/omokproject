// Doyeon Jung & Tyler Caseria
// CS 171 Final Project
// 13 December 2016

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
const int ROW = 10;
const int COLUMN = 10;
int win = 0;

int board[ROW][COLUMN]; // For saving the values set to the spaces on the board.
#include "player.h" // Player info

Player p0; // Player 1
Player p1; // Player 2

void welcome() { // Displays the title.

	cout << setw(30) << "-------------------------------------------------------------------" << endl;
	cout << setw(30) << "      ---           |-\\       /-|            ---           | / " << endl;
	cout << setw(30) << "    --   --         |  \\     /  |          --   --         |/  " << endl;
	cout << setw(30) << "   --     --        |   \\   /   |         --     --        |\\  " << endl;
	cout << setw(30) << "    --   --         |    \\_/    |          --   --         | \\ " << endl;
	cout << setw(30) << "      ---           |           |            ---           |  \\" << endl;
	cout << setw(30) << "-------------------------------------------------------------------" << endl;
	cout << endl;

}
void Board(const int array[ROW][COLUMN]) { // Input: the board array. Displays the game board.
	system("cls");
	welcome();
	for (int i = 0; i < ROW; i++) { // Displays the board: each time through the loop is one row of the board.
		if (i == 0) {
			for (int m = 0; m < 10; m++) { // displays a border line for the very top of the board ONLY.
				if (m == 0)
					cout << "|";
				cout << "------|";
			}
			cout << endl;
		}
		for (int k = 0; k < 10; k++) { // displays extra space before the board value.
			if (k == 0)
				cout << "|";
			cout << "      |";
		}
		cout << endl;
		for (int j = 0; j < COLUMN; j++) { // Displays one row of the board and extra space below.
			if (j == 0)
				cout << "|";
			//array[i][j] = i + j;
			cout << setw(4);

			if (i == 0 && (array[i][j]>1)) { // Adds an extra 0 before the array value for the first row since they are one digit.
				cout << setw(3);
				cout << "0";
				cout << array[i][j] - 2 << setw(3) << '|';
			}

			else if (array[i][j] == 0 || array[i][j] == 1) { // Displays X or O if the space has already been selected by a player.
				if (array[i][j] == 0) // displays O if player 2 selected the space.
					cout << "O" << setw(3) << '|';
				else // displays X if player 1 selected the space.
					cout << "X" << setw(3) << "|";
			}



			else
				cout << array[i][j] - 2 << setw(3) << "|"; // Displays the array value for that space.
		}
		cout << endl;
		for (int k = 0; k < 10; k++) { // Displays a border line after the row.
			if (k == 0)
				cout << "|";
			cout << "------|";
		}
		cout << endl;
	}
}

void selectname() { // Prompts the user to input names for player 1 and player 2. Names are stored in the object.
	cout << "Enter a name for player1: ";
	cin >> p0.name;
	cout << "Enter a name for player2: ";
	cin >> p1.name;
}

void winning() { // Checks to see if someone has won. If someone has won, that winning values is changed to 1.
	int rowcycle = 0, colcycle = 0;
	for (int count = 0; count < 100; count++) {
		if (board[rowcycle][colcycle] == board[rowcycle + 1][colcycle]     // checks to see if there are 5 in a row vertically
			&& board[rowcycle + 1][colcycle] == board[rowcycle + 2][colcycle]
			&& board[rowcycle + 2][colcycle] == board[rowcycle + 3][colcycle]
			&& board[rowcycle + 3][colcycle] == board[rowcycle + 4][colcycle]) {
			win = 1;
			break;
		}
		else if (board[rowcycle][colcycle] == board[rowcycle][colcycle + 1]   //checks to see if there are 5 in a row horizontally
			&& board[rowcycle][colcycle + 1] == board[rowcycle][colcycle + 2]
			&& board[rowcycle][colcycle + 2] == board[rowcycle][colcycle + 3]
			&& board[rowcycle][colcycle + 3] == board[rowcycle][colcycle + 4]) {
			win = 1;
			break;
		}
		else if (board[rowcycle][colcycle] == board[rowcycle + 1][colcycle + 1]  //checks to see if there are 5 in a row diagonally
			&& board[rowcycle + 1][colcycle + 1] == board[rowcycle + 2][colcycle + 2]
			&& board[rowcycle + 2][colcycle + 2] == board[rowcycle + 3][colcycle + 3]
			&& board[rowcycle + 3][colcycle + 3] == board[rowcycle + 4][colcycle + 4]) {
			win = 1;
			break;
		}
		else if (board[rowcycle][colcycle] == board[rowcycle + 1][colcycle - 1]  //checks to see if there are 5 in a row diagonally
			&& board[rowcycle + 1][colcycle - 1] == board[rowcycle + 2][colcycle - 2]
			&& board[rowcycle + 2][colcycle - 2] == board[rowcycle + 3][colcycle - 3]
			&& board[rowcycle + 3][colcycle - 3] == board[rowcycle + 4][colcycle - 4]) {
			win = 1;
			break;

		}
		else
			colcycle++; // If not, continues the cycle.
		if (colcycle == 10) { // Restarts the cycle at the beginning of the next row.
			rowcycle++;
			colcycle = 0;
		}

	}
}
int main() { // Sets values to every space on the board and then loops the gameplay until someone wins, then displays who won.
	int row;                
	int column;

	int value = 2;
	for (int i = 0; i < 10; i++) { // Assigns a value to each space on the board.
		for (int j = 0; j < 10; j++) {
			board[i][j] = value;
			value++;
		}
	}
	int playercount = 1; // Starts off as player 1's turn.
	do { // Loops the gameplay until someone wins.
		welcome(); 
		if (playercount == 1) // Lets players input names before starting the game and then displays the board.
			selectname();

		Board(board);

		if (playercount % 2 == 1) { // Player 1 goes if the player count is odd.
			cout << "Enter the number of the row you want to choose. (" << p0.name << "): ";
			cin >> row;
			cout << "Enter the number of the column you want to choose. (" << p0.name << "): ";
			cin >> column;
			if (board[row][column] == 0 || board[row][column] == 1) // Reloops if the space has already been assigned to a player.
				continue;
			board[row][column] = 1; // This signifies that player 1 has chosen this space.
		}
		else { // If the player count is even, then player 2 goes.
			cout << "Enter the number of the row you want to choose. (" << p1.name << "): ";
			cin >> row;
			cout << "Enter the number of the column you want to choose. (" << p1.name << "): ";
			cin >> column;
			if (board[row][column] == 1 || board[row][column] == 0) // Reloops if the space has already been assigned to a player.
				continue;
			board[row][column] = 0; // This signifies that player 2 has chosen the space.
		}

		//cout << board[row][column];
		winning();
		playercount++;
	} while (win == 0); // Does this loop as long as someone hasn't won yet. Once someone has one, it moves on to the code below.
	Board(board);
	cout << "YAY ";
	if (2 % playercount==0) // If player 2 made the last move, then they win.
		cout << p1.name << " wins!!!" << endl;
	else // If player 1 made the last move, then they win.
		cout << p0.name << " wins!!!" << endl;

	return 0;
}