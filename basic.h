#ifndef BASIC_H
#define BASIC_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <conio.h>
#include <windows.h>

const int MIN_BOARD_SIZE = 4;
const int MAX_BOARD_SIZE = 40;
const int MAX_PLAYERS = 8;
const int NUM_COLORS = 15;

using namespace std;

enum Color
{
    blue = 1,
    green = 2,
    cyan = 3,
    red = 4,
    purple = 5,
    yellow = 6,
    white = 7,
    gray = 8,
    light_blue = 9,
    light_green = 10,
    light_cyan = 11,
    light_red = 12,
    light_purple = 13,
    light_yellow = 14,
    light_white = 15
};

struct board
{
    int width = 4;
    int height = 4;
};

struct line
{
    int x = 0;
    int y = 0;
    Color color;
};

class Player
{
private:
    int score;
    int number;
    Color color;
    string name;

public:
    Player(/* args */);
    void set_score (int my_score) {score = my_score;}
    int get_score () {return score;}
    
    void set_number (int num) {number = num;}
    int get_number () {return number;}
    
    void set_color (Color colour) {color = colour;}
    Color get_color () {return color;}
    
    void set_name (string username) {name = username;}
    string get_name () {return name;}
};

struct game
{
    board b;
    vector<Player> players;
};

void changeTerminalColor(Color color);
void changeTerminalColor(int color);
void menu ();
void error (string err_text);
//bool checkInputs();
//void setBoardSize (int width, int height);
board changeBoardSize (); //maybe not useful
void playerDefine (game &my_game);
void scoreBoard ();
void addtoScoreBoard (Player player);

#endif