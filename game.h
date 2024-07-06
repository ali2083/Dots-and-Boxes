#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <ostream>
#include <vector>
#include "basic.h"

using namespace std;

void prtGameBoard (Player &player, vector<line> &lines, vector<int> &boxes, board b);
void playGame (vector<Player> &players, board b);
int Score (vector<line> &lines, vector<int> &boxes, int where, board b, int turn);
bool isValidLine (line input);
line inputErrorHandle (board b);

#endif