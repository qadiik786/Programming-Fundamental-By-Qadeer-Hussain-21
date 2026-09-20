#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inFile("notes.txt");
    ofstream outFile("notes_copy.txt");

    if (!inFile.is_open()) {
        cout << "Error: Could not open source file!" << endl;
        return 1;
    }

    string line;
    int lineCount = 0;

    // Read line-by-line, count lines, and copy to target file
    while (getline(inFile, line)) {
        lineCount++;
        outFile << line << endl;
    }

    inFile.close();
    outFile.close();

    cout << "Total number of lines in notes.txt: " << lineCount << endl;
    cout << "Content successfully copied to notes_copy.txt" << endl;

    return 0;
}
