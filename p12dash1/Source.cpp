#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

void pressEnterToContinue();

int main() {
    string file_path;
    cout << "input file: ";
    getline(cin, file_path);

    ifstream file(file_path);
    if (!file) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    string word;
    int word_count = 0, char_count = 0;

    while (file >> word) {
        word_count++;
        for (char c : word) {
            if (!isspace(c)) {
                char_count++;
            }
        }
    }


    file.close();

    cout << "Words:      " << word_count << endl;
    cout << "Characters: " << char_count << endl;

    pressEnterToContinue();
}

void pressEnterToContinue() {
    cout << "\nPress enter to continue... \n";
    cin.clear();
    while (cin.get() != '\n') continue;
}
