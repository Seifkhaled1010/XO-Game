#include <iostream>
using namespace std;


void DrawBoard(char** board)
{
	int height = 4;
	int width = 13;
	int x, y;

	for (int i = 0; i < height; i++)
	{
		x = i - 1;
		y = -1;
		if (i == 0)
		{
			for (int j = 0; j < width; j++)
			{
				cout << "_";
			}
			cout << endl;
		}
		else
		{
			for (int j = 0; j < width; j++)
			{
				if (j % 4 == 0)
				{
					cout << "|";
					y++;
				}
				else
				{
					if (board[x][y] != ' ' && (j == 2 || j == 6 || j == 10))

						cout << board[x][y];

					else

						cout << "_";

				}

			}
			//cout << "|";
			cout << endl;

		}
	}
}


char CheckWinner(char** board)
{
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
			return board[i][0];

	}

	for (int i = 0; i < 3; i++)
	{
		if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
			return board[0][i];
	}

	if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
		return board[0][0];

	if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
		return board[0][2];

	return ' ';

}

void main()
{
	char** board = new char* [3]; //char board[3][3]
	for (int i = 0; i < 3; i++)
	{
		board[i] = new char[3];
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = ' ';
		}
	}

	DrawBoard(board);

	int choice = 0;
	bool isx = true;

	while (choice < 9)
	{
		int x, y;
		cout << "Please enter X and Y for your location: ";
		cin >> x >> y;
		while (board[x][y] != ' ')
		{
			cout << "Location is not empty! Please try to input again: ";
			cin >> x >> y;
		}

		if (isx)
		{
			board[x][y] = 'X';
		}
		else
		{
			board[x][y] = 'O';
		}

		isx = !isx;
		DrawBoard(board);
		char Winner = CheckWinner(board);

		if (Winner == 'X')
		{
			cout << "X won!" << endl;
			return;
		}
		else if (Winner == 'O')
		{
			cout << "O won!" << endl;
			return;
		}

		choice++;

	}

	cout << "Game Over!" << endl;

	for (int i = 0; i < 3; i++)
	{
		delete[] board[i];
	}

	delete[] board;
}
