#ifndef BASIC_H
#define BASIC_H

#include <iostream>
#include <string>
#include <windows.h>


using namespace std;

enum Color
{
    blue = 1,
    green = 2,
    cyan = 3,
    red = 4,
    puple = 5,
    yellow = 6,
    white = 7,
    gray = 8,
    light_blue = 9,
    light_green = 10,
    light_cyan = 11,
    light_red = 12,
    light_puple = 13,
    light_yellow = 14,
    light_white = 15
};

struct board
{
    int width = 4;
    int height = 5;
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

void changeTerminalColor(Color color);
void menu ();
void error (string err_text);
bool checkInputs();
void setBoardSize (int width, int height);
// board getBoardSize (); maybe not useful
void playerDefine ();
void scoreBoard ();

#endif