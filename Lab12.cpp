/*
    Reading my spending over a month [obviously with fake numbers ;)]
*/

#include <iostream>
#include <array>
#include <string>
#include <algorithm> // for sort(), find()
#include <numeric> // for accumulate()
#include <fstream>
using namespace std;

// 30 days in a month, the SIZE of the array
const int SIZE = 30;

int main() {
    // initialize array
    array<double, SIZE> balance;

    // open txt file, check for any errors
    ifstream fin;
    fin.open("finances.txt");
    if(fin.good()) {
        // placing values from file into array
        for (int i = 0; i < SIZE; ++i) {
            fin >> balance.at(i);
        }
        fin.close();
    }
    else {
        cout << "File not found.\n";
    }
    // testing array
    for (int i = 0; i < SIZE; ++i) {
        cout << "Balance at " << i << ": " << balance.at(i) << endl;
    }

    return 0;
}