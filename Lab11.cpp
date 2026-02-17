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
void displayPlayer(Team *);

int main() {
    // new team roster array for starting 5 on team
    Team *roster = new Team[PLAYERS];

    // name for team
    string teamName;
    cout << "Please provide the team name: ";
    getline(cin, teamName);
    cout << endl;

    // player input and printing starting 5
    for (int i = 0; i < PLAYERS; ++i) {
        inputPlayer(&roster[i]);
    }

    cout << "Players on Team: " << teamName << endl;
    for (int i = 0; i < PLAYERS; ++i) {
        displayPlayer(&roster[i]);
    }

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
    // player position is position on court, can be PG, SG, SF, PF, or C
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

// display player name, number, court position, score per game, PPG average over the 5 games
void displayPlayer(Team * player) {
    cout << "Name: " << player->playerName << endl;
    cout << "Number: " << player->playerNum << endl;
    cout << "Position: " << player->playerPos << endl;
    for (int i = 0; i < GAMES; ++i) {
        cout << "Game #" << i + 1 << ": " << player->ptsOverGames[i] << endl;
    }
    cout << "PPG Average: " << player->ptsAvg << " Points Per Game";
    cout << endl << endl;
}