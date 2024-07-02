#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <ostream>
#include <vector>
#include "basic.h"

using namespace std;

void prtGameBoard (Player &player, vector<line> &lines, vector<int> points, board b);
void playGame (Player players[], int count, board b);
bool isLineValid (line);

#endif