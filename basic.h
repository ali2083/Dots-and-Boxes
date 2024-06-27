using namespace std;

class player
{
private:
    int score;
    int number;
    char color;
    string name;

public:
    player(/* args */);
    void set_score (int my_score) {score = my_score};
    int get_score () {return score};
    
    void set_number (int num) {number = num};
    int get_number () {return number};
    
    void set_color (int colour) {color = colour};
    char get_color () {return color};
    
    void set_name (int username) {name = username};
    string get_name () {return name};
};

player::player(/* args */)
{
    score = 0;
    number = 0;
    color = 0;
    name = "";
}




void menu ();
void error (string err_text);
void setBoardSiza (int width, int height);
void playerDefine ();