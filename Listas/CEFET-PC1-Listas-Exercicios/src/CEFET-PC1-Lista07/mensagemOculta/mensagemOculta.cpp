#include <iostream>
#include <ctype.h>
#include <string>

using namespace std;

string getFirstLetters(const string line);

int main() {
    unsigned int testAmount = 0;

    do {
        cin >> testAmount;
        cin.ignore();
    } while(testAmount < 1);

    for (int i = 0; i < testAmount; i++) {
        string lineToTest = "";
        getline(cin, lineToTest);

        string codedMassage = getFirstLetters(lineToTest);
        cout << codedMassage << "\n";
    }

    return 0;
}

string getFirstLetters(const string line) {
    string result = "";
    bool foundFirstCharacter = false;

    for (int i = 0; i < line.length(); i++) {
        if (isalpha(line[i]) && !foundFirstCharacter) {
            result.push_back(line[i]);
            foundFirstCharacter = true;
        }
        else if(line[i] == ' ') {
            foundFirstCharacter = false;
        }
    }

    return result;
}