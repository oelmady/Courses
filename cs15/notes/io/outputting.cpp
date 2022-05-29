/*
outputting.cpp
purpose: output names to a .txt file
author: Omar Elmady
May 28, 2022
 */

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream output;
    string name;
    output.open("output.txt");

    if (not output.is_open()) {
        cerr << "failed to open!" << endl;
        exit (EXIT_FAILURE);
    }

    cout << "Tell me your name." << endl;
    cin >> name;

    output << "Behind every great idea is a greater vision.\n";
    output << name;

    output.close();
    return 0;
}
