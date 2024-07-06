#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include "basic.h"
#include "game.h"



int main ()
{
    //Initialize
    game my_game;

    //code
    char input;
    bool nmenu = true;
    my_game.players.resize(2);

    my_game.players[0].set_name("ali");
    my_game.players[0].set_number(1);
    my_game.players[0].set_color(red);

    my_game.players[1].set_name("mamad");
    my_game.players[1].set_number(2);
    my_game.players[1].set_color(blue);

    playGame(my_game.players, my_game.b);
    while (true)
    {   
        if (nmenu)
        {
            system("CLS");
            menu();
            nmenu = false;
        }
        input = getch();
        if (!(input == '1' || input == '2' || input == '3' || input == '4' || input == '0'))
        {
            error("Incorrect input \nPlease enter a valid number between 1 and 4");
            continue;
        }

        switch (input)
        {
        case '1':
            if (my_game.players.size() >= 2)
            {
                playGame(my_game.players, my_game.b);
                nmenu = true;
            }
            else
            {
                error("Requires at least two players");
                continue;
            }
            break;
        case '2':
            my_game.b = changeBoardSize();
            cout << "The dimensions of the board were changed to " << my_game.b.width << " and " << my_game.b.height <<endl;
            cout << "press any key to continue!";
            getch();
            nmenu = true;
            break;
        case '3':
            playerDefine(my_game);
            system("CLS");
            for (int i = 0; i < my_game.players.size(); i++)
            {
                cout << "[" << my_game.players[i].get_number() << "]" <<"-Player: ";
                changeTerminalColor(my_game.players[i].get_color());
                cout << my_game.players[i].get_name() << endl;
                changeTerminalColor(white);
            }
            cout << "press any key to continue!";
            getch();
            system("CLS");
            playGame(my_game.players, my_game.b);
            nmenu = true;
            break;
        case '4':
            scoreBoard();
            getch();
            nmenu = true;
            break;
        case '0':
            return 0;
            break;
        }
    }
    
    cin.get();
    return 0;
}