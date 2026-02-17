/*
    Creating a list of players on a basketball team (my favorite is the Toronto Raptors :))
*/

#include <iostream>
#include <string>
using namespace std;

// array constant for keeping points over 5 games
const int games = 5;

// struct for basketball team
struct Team {
    string playerName;
    int playerNum;
    int * ptsOverGames;

    ~Team() {
        if (ptsOverGames)
            delete [] ptsOverGames;
        ptsOverGames = nullptr;
    }
};

int main() {

    return 0;
}