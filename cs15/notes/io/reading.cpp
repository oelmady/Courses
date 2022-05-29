// Purpose: given an input file, reads file
// author: Omar Elmady
// date: May 28, 2022

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[]) {
    ifstream file_stream;
    if (argc != 2) {
        cerr << "Incorrect number of arguments. Rerun using ./test {filename}.";
        exit(EXIT_FAILURE);
    }


    string filename = argv[1];
    file_stream.open(filename);

    if (not file_stream.is_open()){
        cerr << "Failed to open " << filename << endl;
        exit(EXIT_FAILURE);
    }

    string word;
    //  1) read from file
    //  2) check validity of reading
    //  3) use the data
/*
    while (file_stream >> word) {
        // this conditional statement assigns the whitespace-separated word input to file_stream to the "word" variable
        // when the terminal string character is found, the condition fails
        cout << word << endl;
    }
*/
    while (getline(file_stream, word)) {
        cout << word << endl;
    }

    file_stream.close();
    return 0;
}
