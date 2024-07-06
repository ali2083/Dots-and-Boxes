#include "basic.h"

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

void changeTerminalColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void menu()
{
  cout << "[1] - Play\n";
  cout << "[2] - Board Size\n";
  cout << "[3] - Players\n";
  cout << "[4] - Ranking\n";
  cout << "[0] - Exit\n";
}

void error (string err_text)
{
    cout << endl;
    changeTerminalColor(red);
    cout << "Error: ";
    changeTerminalColor(yellow);
    cout << err_text << endl;
    changeTerminalColor(white);
}

board changeBoardSize()
{
    int width, height;
    board x;

    cout << "Enter board width (between " << MIN_BOARD_SIZE << " and " << MAX_BOARD_SIZE << "): ";
    cin >> width;

    while (width < MIN_BOARD_SIZE || width > MAX_BOARD_SIZE) {
        if (width == 0) return x;
        error("Invalid width! Please enter a value between " + to_string(MIN_BOARD_SIZE) + " and " + to_string(MAX_BOARD_SIZE) + ".");
        cout << "Enter board width (between " << MIN_BOARD_SIZE << " and " << MAX_BOARD_SIZE << "): ";
        cin >> width;
    }

    cout << "Enter board height (between " << MIN_BOARD_SIZE << " and " << MAX_BOARD_SIZE << "): ";
    cin >> height;

    while (height < MIN_BOARD_SIZE || height > MAX_BOARD_SIZE) {
        if (height == 0) return x;
        error("Invalid height! Please enter a value between " + to_string(MIN_BOARD_SIZE) + " and " + to_string(MAX_BOARD_SIZE) + ".");
        cout << "Enter board height (between " << MIN_BOARD_SIZE << " and " << MAX_BOARD_SIZE << "): ";
        cin >> height;
    }

    // Set the board size
    x.height = height;
    x.width = width;
    return x;
}

void playerDefine(game &my_game) // cins do not have error handle
{    
    int numPlayers;

    cout << "Enter the number of players (between 2 and " << MAX_PLAYERS << "): ";
    cin >> numPlayers;

    while (numPlayers < 2 || numPlayers > MAX_PLAYERS) {
        cin.clear();
        cin.ignore(256, '\n');
        error("Invalid number of players! Please enter a value between 2 and " + to_string(MAX_PLAYERS) + ".");
        cout << "Enter the number of players (between 2 and " << MAX_PLAYERS << "): ";
        cin >> numPlayers;
    }

    my_game.players.resize(numPlayers);

    for (int i = 0; i < numPlayers; i++) {
        Player player;
        player.set_number(i + 1);
        cout << "Enter player " << i + 1 << "'s name: ";
        string name;
        cin >> name;
        player.set_name(name);

        cout << "Choose player " << i + 1 << "'s color: " << endl;
        
        for (int j = 0; j < NUM_COLORS; j++) {
            changeTerminalColor(j);
            cout << "[" << j + 1 << "] ";
        }
        changeTerminalColor(white);
        cout << endl;

        int colorChoice;
        cin >> colorChoice;

        while (colorChoice < 1 || colorChoice > NUM_COLORS) {
            error("Invalid color choice! Please enter a value between 1 and " + to_string(NUM_COLORS) + ".");
            cout << "Choose player " << i + 1 << "'s color: " << endl;
            for (int j = 0; j < NUM_COLORS; j++) {
                changeTerminalColor(j);
                cout << "[" << j + 1 << "] ";
            }
            cin >> colorChoice;
        }
        player.set_color(Color(colorChoice - 1));
        my_game.players[i] = player;
        system("CLS");
    }
    
}

void scoreBoard()
{
    system("CLS");
    ifstream file("scores.txt");
    if (!file.fail())
    {
        cout << "\n\nSCOREBOARD\n\n";

        cout << "------------------\n";
        cout << "| Player | Score |\n";
        cout << "------------------\n";

        string my_line;
        while (getline(file, my_line)) {
            cout << my_line << endl;
        }
    }
    else
    {
        error ("Scores file not found!");
        return;
    }
    file.close();
    cout << "--------------------\n\n";
}

void addtoScoreBoard(Player player)
{
    ofstream file("scores.txt", ios::app);
    if (!file.fail())
    {
        string score = to_string(player.get_score());
        file << player.get_name() << " " << score << "\n";
    }
    else
    {
        error ("making file failed");
        return;
    }
    file.close();
}
