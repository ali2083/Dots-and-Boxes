#include "basic.h"

Player::Player()
{
    score = 0;
    number = 0;
    color = white;
    name = "";
}

void changeTerminalColor(Color color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void menu()
{
  cout << "Play\n";
  cout << "Board Size\n";
  cout << "players\n";
  cout << "Ranking\n";
  cout << "Exit\n";
}

void error (string err_text)
{
    cout << err_text << endl;
}

void setBoardSize(int width, int height)
{
}

void getBoardSize()
{
}

void playerDefine()
{
}

void scoreBoard()
{
}
