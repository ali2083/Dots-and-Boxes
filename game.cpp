#include "game.h"

void prtGameBoard(Player &player, vector<line> &lines, board b)
{
}

void addLine()
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
        else // i % 2 == 0 => false
        {
            for (int k = 0; k < 3; k++)
            {
                if (k == 1 && 0 < i) cout << i << " ";
                else cout << "  ";

                for (int j = 0; j < real.width; j++)
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
                    

                    //draw points ==> faild 
                    /*
                    if (j % 2 != 0)
                    {
                        int point = points[(i - 1) * (b.width - 1) + (j / 2)];
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
                    */
                   if (j % 2 != 0)
                    {
                        cout << "  ";
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
    cout << "Press any key to start..." << endl;
    cin.get();

    int turn = 0;
    int boardSize = b.width * (b.height - 1) + b.height * (b.width - 1);
    int boardBoxes = (b.height - 1) * (b.width - 1);
    vector<line> lines(boardSize); 
    vector<int> points(boardBoxes);

    for (int i = 0; i < boardSize; i++)
    {
        prtGameBoard(players[turn], lines, b);
        cout << "inter line location: ";
        line input = inputErrorHandle(b);

        //don't forget check the inputs in next commit
        int where = ((input.x * b.width) - ((input.x + 1) / 2)) + (input.y / 2);
        lines.insert(lines.begin() + where, input);
        lines.erase(lines.begin() + where + 1);
        system("CLS");


        if (isScore(lines, where, b))
        {
            players[turn].set_score(players[turn].get_score() + 1);
        }
        else
        {
            if (turn >= count - 1) turn = 1;
            else turn++;
        }
    }
}

bool isScore(vector<line> &lines, int where, board b)
{
    if (lines[where].x % 2 != 0)
    {
        if (isValidLine(lines[where - 1]) && lines[where - 1].x == lines[where].x)
        {
            if (isValidLine(lines[where - b.width]) && isValidLine(lines[where + b.height - 1]))
            {
                return true;
            }
        }
        if (isValidLine(lines[where + 1]) && lines[where + 1].x == lines[where].x)
        {
            if (isValidLine(lines[where - b.width + 1]) && isValidLine(lines[where - b.height]))
            {
                return true;
            }
        }
    }
    else
    {
        if (isValidLine(lines[where - (2 * b.width) + 1]) && lines[where - (2 * b.width) + 1].y == lines[where].y)
        {
            if (isValidLine(lines[where - b.width]) && isValidLine(lines[where - b.height + 1]))
            {
                return true;
            }
        }
        if (isValidLine(lines[where + (2 * b.width) - 1]) && lines[where + (2 * b.width) - 1].y == lines[where].y)
        {
            if (isValidLine(lines[where + b.width - 1]) && isValidLine(lines[where + b.height]))
            {
                return true;
            }
        }
    }
    return false;
}

bool isValidLine(line input)
{
    if (input.x == 0 && input.y == 0) return false;
    else if (input.x % 2 == 0 && input.y % 2 == 0) return false;
    else if (input.x % 2 != 0 && input.y % 2 != 0) return false;
    else return true;
}

line inputErrorHandle(board b)
{
    line input;
    while (true)
    {
        try
        {
           cin >> input.x >> input.y;
        }
        catch(const std::error_code& e)
        {
            error("Input error");
            continue;
        }
        if ((input.x < 0 || input.y < 0) || (input.x > (b.width + b.width - 1) || input.y > (b.height + b.height - 1)))
        {
            error("Invalid input");
            continue;
        }
        if ((input.x % 2 == 0 && input.y % 2 == 0) || (input.x % 2 != 0 && input.y % 2 != 0))
        {
            error("Invalid line coordinates");
            continue;
        }
        break;
    }
    return input;
}
