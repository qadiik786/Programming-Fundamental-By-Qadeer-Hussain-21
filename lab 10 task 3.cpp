#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // 1. Create and Write three lines
    ofstream fout("notes.txt");
    fout << "Line 1: Introduction to File Handling." << endl;
    fout << "Line 2: Working with fstream in C++." << endl;
    fout << "Line 3: File stream modes." << endl;
    fout.close();
    cout << "Initial 3 lines written to notes.txt\n" << endl;

    // 2. Read and Display content
    ifstream fin("notes.txt");
    string line;
    cout << "--- Reading notes.txt ---" << endl;
    while (getline(fin, line)) {
        cout << line << endl;
    }
    fin.close();

    // 3. Append Name and Roll Number
    ofstream fapp("notes.txt", ios::app);
    fapp << "Name: Qadeer Hussain, Roll No: CSC-521" << endl;
    fapp.close();
    cout << "\nAppended user details successfully." << endl;

    // 4. Display updated content
    cout << "\n--- Updated notes.txt Content ---" << endl;
    ifstream finUpdated("notes.txt");
    while (getline(finUpdated, line)) {
        cout << line << endl;
    }
    finUpdated.close();

    return 0;
}
