#include "game.h"

void prtGameBoard(Player player)
{
    //title
    cout << "Player: ";
    changeTerminalColor(player.get_color());
    cout << player.get_name() << endl;
    changeTerminalColor(white);
    cout << "SCORE: " << player.get_score();

    //game board
    
}