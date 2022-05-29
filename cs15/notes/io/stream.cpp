/*
reading to and from files
by omar elmady
may 28 2022
 */

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// FUNCTION DECLARATIONS
void writeLineToFile(string line, ofstream& output);
void findEvens(string line, ofstream& output);

int main(int argc, char const *argv[]) {
    ifstream file_stream;
    if (argc != 2) {
        cerr << "Incorrect number of arguments. Rerun using ./test {filename}.";
        exit(EXIT_FAILURE);
    }

    // create an input file stream to read the command file
    string command_file = argv[1];
    ifstream input;
    input.open(command_file);
    if (not input.is_open()) {
        cerr << "Error opening file " << command_file << endl;
        exit(EXIT_FAILURE);
    }

    // create two outputs with hardcoded file names
    ofstream int_output, char_output;
    char_output.open("char-output");
    int_output.open("int-output");
    if (not int_output.is_open()){
        cerr << "Error opening int-output file." << endl;
        exit(EXIT_FAILURE);
    }
    if (not char_output.is_open()){
        cerr << "Error opening an output file." << endl;
        exit(EXIT_FAILURE);
    }

    string line;
    while (getline(input, line)) {
        if (line[0] <= '9' && line[0] >= '0') {
            findEvens(line, int_output);
        }
        else {
            writeLineToFile(line, char_output);
        }
    }

    char_output.close();
    int_output.close();
    input.close();

    return 0;
}

// FUNCTION DEFINITIONS

// given a string and a reference to an output file
// write the entire string to that output file
// effects: none
// return: void
void writeLineToFile(string line, ofstream& output) {
    output << line << endl;
    // sends line to the ofstream output
}

/*
given a string and a reference to an output file,
parse the string to find all even numbers
effect: undefined behavior if "chars" are present in the string line
return: void
 */
void findEvens(string line, ofstream& output) {
    istringstream sequence(line);
    int temp;
    // read sequence integers by iteratively placing them in the temp variable until reaching the terminal character of the line
    while (sequence >> temp) {
        if (temp % 2 == 0) {
            output << temp << endl;
        }
        // does nothing with odd integers
    }
}
