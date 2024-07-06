#include "game.h"

void prtGameBoard(Player &player, vector<line> &lines, vector<int> &boxes, board b)
{

    //index
    board real;
    real.height = b.height + b.height - 1;
    real.width = b.width + b.width - 1;

    //title
    cout << "Player: ";
    changeTerminalColor(player.get_color());
    cout << "[" << player.get_number() << "]-";
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
                    changeTerminalColor(lines[index - 1].color);
                    cout << "---";
                    changeTerminalColor(white);
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
                    
                    //draw points ==> need that
                    if (j % 2 != 0)
                    {
                        int point = (i / 2) * (b.width - 1) + (j / 2); // +1 is box number -1 for vector index
                        if (boxes[point] == 0)
                        {
                            cout << "   ";
                        }
                        else
                        {
                            if (k == 1)
                            {
                                cout << " " << boxes[point] << " ";
                            }
                            else
                            {
                                cout << "   ";
                            }
                        }
                        continue;
                    }
                    
                    //HORIZONTAL lines drawing 
                    else if (lines[index - 1].x == i && lines[index - 1].y == j)
                    {
                        changeTerminalColor(lines[index - 1].color);
                        cout << "|";
                        changeTerminalColor(white);
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

void playGame(vector<Player> &players, board b)
{
    int turn = 0;
    int boardSize = b.width * (b.height - 1) + b.height * (b.width - 1);
    int boardBoxes = (b.height - 1) * (b.width - 1);
    vector<line> lines(boardSize);
    vector<int> boxes(boardBoxes);
    // Initialize boxes vector


    for (int i = 0; i < boardSize; i++)
    {
        prtGameBoard(players[turn], lines, boxes, b);
        cout << "inter line location: ";

        int where = 0;
        line input;
        while (true)
        {
            input = inputErrorHandle(b);
            where = ((input.x * b.width) - ((input.x + 1) / 2)) + (input.y / 2);
            if (lines[where].x == 0 && lines[where].y == 0)
            {
                break;
            }
            else 
            {
                error("This line has already been drawn");
                continue;
            }
            
        }

        input.color = players[turn].get_color();
        lines.insert(lines.begin() + where, input);
        lines.erase(lines.begin() + where + 1);
        system("CLS");

        int box = Score(lines, boxes, where, b, turn);
        //cout << "box:" << box << endl; //for debug comment
        if (box == 1)
        {
            players[turn].set_score(players[turn].get_score() + 1);
        }
        else if (box == 2)
        {
            players[turn].set_score(players[turn].get_score() + 2);
        }
        else
        {
            if (turn >= players.size() - 1) turn = 0;
            else turn++;
        }
    }

    prtGameBoard(players[turn], lines, boxes, b);
    cout << endl;
    getch();

    vector<Player> winners(players.size());
    for (int i = 0; i < players.size(); i++)
    {
        if (winners[0].get_score() < players[i].get_score())
        {
            winners.clear();
            winners.push_back(players[i]);
        }
        else if (winners[0].get_score() == players[i].get_score())
        {
            winners.push_back(players[i]);
        }
    }
    for (int i = 0; i < winners.size(); i++)
    {
        cout << winners[i].get_name() << " Won!" << endl;
        addtoScoreBoard(winners[i]);
    }
    getch();
}

int Score(vector<line> &lines, vector<int> &boxes, int where, board b, int turn)
{
    int x;
    int temp = 0;
    if (lines[where].x % 2 != 0)
    {
        if (isValidLine(lines[where - 1]) && lines[where - 1].x == lines[where].x)
        {
            if (isValidLine(lines[where - b.width]) && isValidLine(lines[where + b.width - 1]))
            {
                x = (lines[where].x / 2) * (b.width - 1) + (lines[where].y / 2);
                boxes[x - 1] = turn + 1;
                temp++;
            }
        }
        if (isValidLine(lines[where + 1]) && lines[where + 1].x == lines[where].x)
        {
            if (isValidLine(lines[where - b.width + 1]) && isValidLine(lines[where + b.width]))
            {
                x = (lines[where].x / 2) * (b.width - 1) + (lines[where].y / 2) + 1;
                boxes[x - 1] = turn + 1;
                temp++;
            }
        }
    }
    else
    {
        if (isValidLine(lines[where - (2 * b.width) + 1]) && lines[where - (2 * b.width) + 1].y == lines[where].y)
        {
            if (isValidLine(lines[where - b.width]) && isValidLine(lines[where - b.width + 1]))
            {
                x = ((lines[where].x / 2) - 1) * (b.width - 1) + ((lines[where].y + 1) / 2);
                boxes[x - 1] = turn + 1;
                temp++;
            }
        }
        if (isValidLine(lines[where + (2 * b.width) - 1]) && lines[where + (2 * b.width) - 1].y == lines[where].y)
        {
            if (isValidLine(lines[where + b.width - 1]) && isValidLine(lines[where + b.width]))
            {
                x = (lines[where].x / 2) * (b.width - 1) + ((lines[where].y + 1) / 2);
                boxes[x - 1] = turn + 1;
                temp++;
            }
        }
    }
    return temp;
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
    input.color = white;
    while (true)
    {
        cin >> input.x >> input.y;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(256, '\n');
            error("Invalid input");
            continue;
        }
        if ((input.x < 0 || input.y < 0) || (input.x > (b.height + b.height - 1) || input.y > (b.width + b.width - 1)))
        {
            error("Invalid input");
            continue;
        }
        if (!isValidLine(input))
        {
            error("Invalid line coordinates");
            continue;
        }
        break;
    }
    return input;
}
