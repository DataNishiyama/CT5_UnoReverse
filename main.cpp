#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

//Reverse String Func
void reverseString(string &str) {
    reverse(str.begin(), str.end());
}

//Read File Func
string readFile(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file: " << filename << endl;
        return "";
    }

    string content;
    string line;
    while (getline(file, line)) {
        content += line + '\n';
    }

    file.close();
    return content;
}

//Write to file Func
void writeFile(const string &filename, const string &content) {
    ofstream file(filename, ios::app);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file: " << filename << endl;
        return;
    }

    file << content;
    file.close();
    cout << "Data appended to file: " << filename << endl;
}

//Reverse and Append Func
void reverseAndAppend(const string &inputFilename, const string &outputFilename) {
    string data;
    cout << "Enter data to append: ";
    cin.ignore();
    getline(cin, data);
    writeFile(inputFilename, data);

    string content = readFile(inputFilename);
    if (content.empty()) {
        cerr << "Error: Unable to read content from file." << endl;
        return;
    }

    reverseString(content);

    ofstream file(outputFilename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file: " << outputFilename << endl;
        return;
    }

    file << content;
    file.close();
    cout << "Reversed content written to file: " << outputFilename << endl;
}

//Main
int main() {
    string inputFilename = "CSC450_CT5_mod5.txt";
    string outputFilename = "CSC450-mod5-reverse.txt";

    int choice;
    do {
        cout << "\nUser Menu:\n"
             << "1. User Enter Text, Reverse and Append Data to CSC450_CT5_mod5.txt\n"
             << "2. Exit Program\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                reverseAndAppend(inputFilename, outputFilename);
                break;
            }
            case 2: {
                cout << "Exiting program.\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    } while (choice != 2);

    return 0;
}
