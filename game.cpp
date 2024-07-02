#include "game.h"

void prtGameBoard(Player &player, vector<line> &lines, board b)
{
    //index
    board real;
    real.height = b.height + b.height - 1;
    real.width = b.width + b.width - 1;

    //title
    cout << "Player: ";
    changeTerminalColor(player.get_color());
    cout << player.get_name() << endl;
    changeTerminalColor(white);
    cout << "SCORE: " << player.get_score();

    //game board
    for (int i = -1; i < real.height; i++)
    {
        if (i % 2 == 0)
        {
            cout << i << " ";
            for (int j = 0; j < real.width; j++)
            {   
                // lines number difination
                int index = ((i * b.width) - ((i + 1) / 2)) + (j + 1) / 2;

                //draw points
                if (j % 2 == 0)
                {
                    cout << "o";
                    continue;
                }

                //vertical lines drawing 
                if (lines[index - 1].x == i && lines[index - 1].y == j)
                {
                    cout << "---";
                }
                else
                {
                    cout << "   ";
                    //cout << " " << index << "  ";
                }
            }
            cout << endl;
        }
        else
        {
            for (int k = 0; k < 3; k++)
            {
                if (k == 1 && 0 < i) cout << i << " ";
                else cout << "  ";
                for (int j = 0; j <= real.width; j++)
                {   
                    // board titles
                    if (i == -1)
                    {
                        if (k != 2) break;
                        cout << j << " ";
                        continue;
                    }

                    // lines number difination
                    int index = ((i * b.width) - ((i + 1) / 2)) + (j / 2) + 1;
                    

                    //draw points
                    if (j % 2 != 0)
                    {
                        cout << "   ";
                        continue;
                    }

                    //vertical lines drawing 
                    if (lines[index - 1].x == i && lines[index - 1].y == j)
                    {
                        cout << "|";
                    }
                    else
                    {
                        cout << " ";
                        //cout << " " << index << "  "; for debug
                    }
                }
                cout << endl;
            }
        }
    }
    
    
}