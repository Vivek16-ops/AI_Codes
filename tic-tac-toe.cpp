#include <iostream>
#include <stdlib.h>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char turn = 'x';
bool draw = false;
int choice;
int row, column;

void display_board()
{
    // Rendering Game Board Layout
    cout << "Player 1 - [x]   Player 2 - [o]" << endl
         << endl;

    cout << "     |       |       |" << endl;
    cout << "------------------------" << endl;
    cout << board[0][0] << "    |   " << board[0][1] << "   |    " << board[0][2] << "  |" << endl;
    cout << "------------------------" << endl;
    cout << board[1][0] << "    |   " << board[1][1] << "   |    " << board[1][2] << "  |" << endl;
    cout << "------------------------" << endl;
    cout << board[2][0] << "    |   " << board[2][1] << "   |   " << board[2][2] << "   |" << endl;
    cout << endl
         << endl;
}

void playerturn()
{
    if (turn == 'x')
    {
        cout << "Player 1 turn: " << endl;
    }
    else if (turn == 'o')
    {
        cout << "Player 2 turn: " << endl;
    }

    cin >> choice;

    // Using Switch Case to select particular row and column
    switch (choice)
    {
    case 1:
        row = 0;
        column = 0;
        break;

    case 2:
        row = 0;
        column = 1;
        break;

    case 3:
        row = 0;
        column = 2;
        break;

    case 4:
        row = 1;
        column = 0;
        break;

    case 5:
        row = 1;
        column = 1;
        break;

    case 6:
        row = 1;
        column = 2;
        break;

    case 7:
        row = 2;
        column = 0;
        break;

    case 8:
        row = 2;
        column = 1;
        break;

    case 9:
        row = 2;
        column = 2;
        break;

    default:
        cout << "Invalid Position Enter your choice again: " << endl;
        break;
    }

    if (turn == 'x' && board[row][column] != 'x' && board[row][column] != 'o')
    {
        board[row][column] = 'x';
        turn = 'o';
    }
    else if (turn == 'o' && board[row][column] != 'x' && board[row][column] != 'o')
    {
        board[row][column] = 'o';
        turn = 'x';
    }
    else
    {
        cout << "Spot Already filled" << endl;
        playerturn();
    }
    display_board();
}

bool gameover()
{
    // Checking Simple row and column
    for (int i = 0; i < 3; i++)
    {
        if ((board[i][0] == board[i][1] && board[i][0] == board[i][2]) || (board[0][i] == board[1][i] && board[0][i] == board[2][i]))
        {
            return false;
        }
    }

    // checking diagonal
    if ((board[0][0] == board[1][1] && board[0][0] == board[2][2]) || (board[0][2] == board[1][1] && board[0][2] == board[2][0]))
    {
        return false;
    }

    // checking if game is in continue mode or not
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'x' && board[i][j] != 'o')
            {
                return true;
            }
        }
    }

    draw = true;
    return false;
}
int main()
{
    cout << "T-i-c T-a-c T-o-e" << endl;
    cout << "Player 2 game" << endl;
    while (gameover())
    {
        display_board();
        playerturn();
        gameover();
    }

    if (turn == 'x' && draw == false)
    {
        cout << "Congrates Player 2 win" << endl;
    }
    else if (turn == 'o' && draw == false)
    {
        cout << "Congrates Player 1 win" << endl;
    }
    else
    {
        cout << "Game Draw Would you like to play again" << endl;
    }
    return 0;
}