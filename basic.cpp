#include "basic.h"
#include"cmath"
Player::Player()
{
    score = 0;
    number = 0;
    color = white;
    name = "";
}

void changeTerminalColor(Color color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void menu()
{
  cout << "[1]-Play\n";
  cout << "[2]Board Size\n";
  cout << "[3]players\n";
  cout << "[4]Ranking\n";
  cout << "[5]Exit\n";
}

void error (string err_text)
{
    cout << err_text << endl;
}

void setBoardSize(int width, int height)
 {  int MIN_BOARD_SIZE ;
    int MAX_BOARD_SIZE;
    if (width < MIN_BOARD_SIZE || width > MAX_BOARD_SIZE || height < MIN_BOARD_SIZE || height > MAX_BOARD_SIZE) {
        error("Board size must be between " << MIN_BOARD_SIZE << " and " << MAX_BOARD_SIZE << "!");
        return;
    }
    game.width = width;
    game.height = height;

    // Resize the board
    game.board.resize(game.height, vector<char>(game.width, ' '));

    // Display message about changing board size
    cout << "Board size successfully changed to " << game.width << "x" << game.height << "." << endl;
}


void getBoardSize()
{
    int width, height;
    int MIN_BOARD_SIZE ;
    int MAX_BOARD_SIZE;
    cout << "Enter board width (between " << MIN_BOARD_SIZE << " and " << MAX_BOARD_SIZE << "): ";
    cin >> width;

    while (width < MIN_BOARD_SIZE || width > MAX_BOARD_SIZE) {
        error("Invalid width! Please enter a value between " << MIN_BOARD_SIZE << " and " << MAX_BOARD_SIZE << ".");
        cout << "Enter board width (between " << MIN_BOARD_SIZE << " and " << MAX_BOARD_SIZE << "): ";
        cin >> width;
    }

    cout << "Enter board height (between " << MIN_BOARD_SIZE << " and " << MAX_BOARD_SIZE << "): ";
    cin >> height;

    while (height < MIN_BOARD_SIZE || height > MAX_BOARD_SIZE) {
        error("Invalid height! Please enter a value between " << MIN_BOARD_SIZE << " and " << MAX_BOARD_SIZE << ".");
        cout << "Enter board height (between " << MIN_BOARD_SIZE << " and " << MAX_BOARD_SIZE << "): ";
        cin >> height;
    }

    // Set the board size
    setBoardSize(width, height);
}



void playerDefine()
{    int numPlayers;

    cout << "Enter the number of players (between 2 and " << MAX_PLAYERS << "): ";
    cin >> numPlayers;

    while (numPlayers < 2 || numPlayers > MAX_PLAYERS) {
        error("Invalid number of players! Please enter a value between 2 and " << MAX_PLAYERS << ".");
        cout << "Enter the number of players (between 2 and " << MAX_PLAYERS << "): ";
        cin >> numPlayers;
    }

    game.players.resize(numPlayers);

    for (int i = 0; i < numPlayers; i++) {
        cout << "Enter player " << i + 1 << "'s name: ";
        cin >> game.players[i].name;

        cout << "Choose player " << i + 1 << "'s color: " << endl;
        for (int j = 0; j < NUMCOLORS; j++) {
            cout << "[" << j + 1 << "] " << SetColorSpace(Color(j)) << " (" << (Color(j)) << ")" << endl;
        }

        int colorChoice;
        cin >> colorChoice;

        while (colorChoice < 1 || colorChoice > NUMCOLORS) {
            error("Invalid color choice! Please enter a value between 1 and " << NUMCOLORS << ".");
            cout << "Choose player " << i + 1 << "'s color: " << endl;
            for (int j = 0; j < NUMCOLORS; j++) {
                cout << "[" << j + 1 << "] " << SetColorSpace(Color(j)) << " (" << (Color(j)) << ")" << endl;
            }
            cin >> colorChoice;
        }

        game.players[i].color = Color(colorChoice - 1);
    }
}



void scoreBoard()
{
    cout << "\n\nSCOREBOARD\n\n";

    cout << "--------------------\n";
    cout << "| Player | Score | Color |\n";
    cout << "--------------------\n";

    for (int i = 0; i < game.players.size(); i++) {
        cout << "| ";
        cout << std::left << getw(8) << game.players[i].name << " | ";
        cout << std::right << getw(5) << game.scores[i] << " | ";
        changeTerminalColor(game.players[i].color);
        cout << std::left << getw(6) << SetColorSpace(game.players[i].color) << " (" << (game.players[i].color) << ")" << " |";
        changeTerminalColor(white);
        cout << endl;
    }

    cout << "--------------------\n\n";
}


