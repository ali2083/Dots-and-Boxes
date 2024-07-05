#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <ostream>
#include <vector>
#include "basic.h"

using namespace std;

void prtGameBoard (Player &player, vector<line> &lines, vector<int> &boxes, board b);
void playGame (Player players[], int count, board b);
int Score (vector<line> &lines, int where, board b);
bool isValidLine (line input);
line inputErrorHandle (board b);

#endif