#include "game.h"

void prtGameBoard(Player &player, vector<line> &lines, board real)
{
    //title
    cout << "Player: ";
    changeTerminalColor(player.get_color());
    cout << player.get_name() << endl;
    changeTerminalColor(white);
    cout << "SCORE: " << player.get_score() << endl << endl;

    //game board
    for (int i = 0; i < real.height; i++)
    {
        for (int j = 0; j < real.width; j++)
        {
            cout << "o";
            if (lines[i + j].x == i && lines[i + j].y == j)
            {
                cout << "---";
            }
            else
            {
                cout << "   ";
            }
        }
        cout << endl;
    }
    
    
}