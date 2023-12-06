#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int random(int min, int max)
{
    srand(static_cast<unsigned int>(time(0)));
    return min + rand() % (max - min + 1);
}

int dice()
{
    return random(1, 6);
}

int main()
{
    int ladder[] = {5, 20, 30, 45, 60, 85};
    int snake[] = {15, 25, 37, 52, 68, 98};
    int maxPlayer = 2;
    int player = 0;
    bool gameOver = false;
    int current[maxPlayer] = {0};
    int board = 100;

    while (!gameOver)
    {
        system("cls");
        cout << "Snake and Ladder Game" << endl;
        cout << "Current Player: " << player + 1 << endl;
        cout << "===========================" << endl;
        for (int i = 0; i < maxPlayer; i++)
        {
            cout << "Player " << player + i << " is at position " << current[i] << endl;
        }
        cout << "===========================" << endl;
        cout << "Player " << player + 1 << " rolled a dice " << dice() << endl;
        current[player] += dice();
        if (current[player] >= board)
        {
            cout << "Player " << player + 1 << " wins!" << endl;
            gameOver = true;
        }

        for (int i = 0; i < sizeof(ladder) / sizeof(int); i++)
        {
            if (current[player] == ladder[i])
            {
                cout << "Player " << player + 1 << " climbed a ladder " << dice() << endl;
                current[player] += dice();
            }
        }

        for (int i = 0; i < sizeof(snake) / sizeof(int); i++)
        {
            if (current[player] == snake[i])
            {
                cout << "Player " << player + 1 << " bitten by a snake " << dice() << endl;
                current[player] -= dice();
                current[player] -= dice();
            }
        }
        player = (player + 1) % maxPlayer;
        system("Pause");
    }
    return 0;
}