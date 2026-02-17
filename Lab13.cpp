/*
    Reading my spending over a month [obviously with fake numbers ;)]
*/

#include <iostream>
#include <array>
#include <string>
#include <algorithm> // for sort(), find()
#include <numeric> // for accumulate()
#include <iomanip> // for nice looking numbers :)
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

    // sorting array from highest to lowest
    sort(balance.rbegin(), balance.rend());
    cout << "Sorted Balance: ";
    for (double val : balance) 
        cout << "$" << val << " "; 
    cout << endl; 

    cout << endl;

    // sorted lowest to highest
    sort(balance.begin(), balance.end());
        cout << "Sorted Balance: ";
        for (double val : balance) 
            cout << "$" << val << " "; 
        cout << endl; 

    cout << endl;

    // using iterator to find value in array
    double target = 653.64;
    array<double, SIZE> :: iterator it;
    it = find(balance.begin(), balance.end(), target);
    if (it != balance.end()) {
        cout << target << " Found in position " << it - balance.begin() << endl;
    }
    else {
        cout << target << " was not found in balance." << endl;
    }

    cout << endl; 

    // find max and min
    cout << "Maximum balance over the month: $" << *max_element(balance.begin(), balance.end()) << endl;
    cout << "Minimum balance over the month: $" << *min_element(balance.begin(), balance.end()) << endl;

    cout << endl;
    
    // sorted balance, without duplicate values
    array<double, SIZE> sortedBalance;
    sortedBalance.fill(0.0);
    sortedBalance.at(0) = balance.at(0);
    int j = 0;
    for (int i = 0; i < SIZE; ++i) {
        while(balance.at(i) == sortedBalance.at(j)) {
            ++i;
        }
        ++j;
        sortedBalance.at(j) = balance.at(i);
    }
    
    // sortedBalance array sorted from lowest to highest
    cout << "Sorted balance array from lowest to highest value:" << endl;
    for (int i = 0; sortedBalance.at(i) != 0.0; ++i) {
        cout << "$" << sortedBalance.at(i) << " ";
    }
    cout << endl;

    cout << endl;

    double averageBalance;
    // average balance over a month
    cout << "Average account balance over a month:" << endl;
    averageBalance = accumulate(sortedBalance.begin(), sortedBalance.end(), 0.0) / 7.0;
    cout << "$" << fixed << setprecision(2) << averageBalance << endl; 

    return 0;
}