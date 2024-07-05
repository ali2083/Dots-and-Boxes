#include <iostream>
#include <string>
#include <vector>
#include "basic.h"
#include "game.h"

int main ()
{
    //Initialize
    Player players[8];
    int count = 8;
    static board b;
    players[1].set_color(red);
    players[1].set_name("---amghezi");

    //code
    menu();
    char input;
    while (true)
    {
        cin.get(input);
        if (input == '1' || input == '2' || input == '3' || input == '4') break;
        else error("Incorrect input \nPlease enter a valid number between 1 and 4");
    }
    switch (input)
    {
    case '1':
        playGame(players, count, b);
        break;
    case '2':
        
        break;
    case '3':
        
        break;
    case '4':
        
        break;
    }
    return 0;
}