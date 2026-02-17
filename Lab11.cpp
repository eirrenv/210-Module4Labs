/*
    Creating a list of players on a basketball team [my favorite is the Toronto Raptors :)]
*/

#include <iostream>
#include <string>
using namespace std;

// array constant for amount of players and games counted
const int PLAYERS = 5, GAMES = 5;

// struct for basketball team
struct Team {
    string playerName;
    int playerNum;
    int * ptsOverGames;
    int ptsAvg;

    ~Team() {
        if (ptsOverGames)
            delete [] ptsOverGames;
        ptsOverGames = nullptr;
    }
};

// protoypes for player input and display
void inputPlayer(Team *);
void displayPlayer(Team *);

int main() {
    // new team roster array for starting 5 on team
    Team *roster = new Team[PLAYERS];

    // player input and printing starting 5
    for (int i = 0; i < PLAYERS; ++i) {
        inputPlayer(&roster[i]);
    }

    for (int i = 0; i < PLAYERS; ++i) {
        displayPlayer(&roster[i]);
    }

    return 0;
}

void inputPlayer(Team * player) {

}