#include <iostream>
#include <string>
#include <vector>
#include "basic.h"
#include "game.h"

int main ()
{
    static board b;
    static int turn = 1;
    Player players[8];

    int boardSize = b.height * (b.width - 1) + b.width * (b.height - 1);
    vector<line> lines(boardSize); //Sort by rows!

    Player testi;
    testi.set_color(red);
    testi.set_name("mamad");
    testi.set_number(1);
    testi.set_score(5);

    board real;
    real.height = b.height + b.height - 1;
    real.width = b.width + b.width - 1;
    

    line s;
    s.x = 2;
    s.y = 5;

    lines.insert(lines.begin() + 17,s);
    prtGameBoard(testi, lines, real);

    for (int i = 0; i < lines.size(); i++) 
        cout << lines[i].x << " ";
    cin.get();
    return 0;
}