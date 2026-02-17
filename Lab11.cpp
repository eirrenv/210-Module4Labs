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
    string playerPos;
    int * ptsOverGames;
    double ptsAvg;

    ~Team() {
        if (ptsOverGames)
            delete [] ptsOverGames;
        ptsOverGames = nullptr;
    }
};

// protoypes for player input and display
void inputPlayer(Team *);
// void displayPlayer(Team *);

int main() {
    // new team roster array for starting 5 on team
    Team *roster = new Team[PLAYERS];

    // player input and printing starting 5
    for (int i = 0; i < PLAYERS; ++i) {
        inputPlayer(&roster[i]);
    }

    // for (int i = 0; i < PLAYERS; ++i) {
    //    displayPlayer(&roster[i]);
    // }

    return 0;
}


// function to input data for players, inputting name, number, position, PPG, and calculating PPG average over 5 game stretch
void inputPlayer(Team * player) {
    static int numPlayer = 1;
    cout << "Input data for player #" << numPlayer << ":\n";
    cout << "Player name: ";
    getline(cin, player->playerName);
    cout << "Player number: ";
    cin >> player->playerNum;
    cin.ignore();
    cout << "Player position: ";
    getline(cin, player->playerPos);

    player->ptsAvg = 0.0;
    player->ptsOverGames = new int[GAMES];
    cout << "Player points over games:" << endl;
    for (int i = 0; i < GAMES; ++i) {
        cout << "Game #" << i + 1 << ": ";
        cin >> player->ptsOverGames[i];
        player->ptsAvg += player->ptsOverGames[i];
    }
    player->ptsAvg = player->ptsAvg / 5.0;
    cin.ignore();
    cout << endl << endl;
    numPlayer++;
}