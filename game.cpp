#include "game.h"

void prtGameBoard(Player &player, vector<line> &lines, vector<int> points, board b)
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
                        int point = points[(i - 1) * (b.width - 1) + (j / 2) + 1];
                        if (point == 0)
                        {
                            cout << "   ";
                        }
                        else
                        {
                            cout << " " << point << " ";
                        }
                        continue;
                    }

                    //HORIZONTAL lines drawing 
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

void playGame(Player players[], int count, board b)
{
    cout << "Press any key to start...";
    cin.get();

    int turn = 1;
    int boardSize = b.width * (b.height - 1) + b.height * (b.width - 1);
    int boardBoxes = (b.height - 1) * (b.width - 1);
    vector<line> lines(boardSize); 
    vector<int> points(boardBoxes);
    for (int i = 0; i < boardSize; i++)
    {
        prtGameBoard(players[turn], lines, points, b);
        cout << "inter line location: ";
        line input;
        cin >> input.x >> input.y;

        //don't forget check the inputs in next commit
        int where = ((input.x * b.width) - ((input.x + 1) / 2)) + (input.y / 2);
        lines.insert(lines.begin() + where, input);
        prtGameBoard(players[turn], lines, points, b);


        if (turn >= count - 1) turn = 1;
        else turn++;
    }
}
