#include <iostream>
#include <string>
#include "basic.h"
#include "game.h"

int main ()
{
    static board b;
    static int turn = 1;
    Player players[8];
    
    Player testi;
    testi.set_color(red);
    testi.set_name("mamad");
    testi.set_number(1);
    testi.set_score(5);
    prtGameBoard(testi);

    cin.get();
    return 0;
}