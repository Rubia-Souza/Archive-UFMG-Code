#include <iostream>
#include <string>

using namespace std;

string getFirstLetters(const string line);
int countAlitarations(const string line);

int main() {
    string lineToTest = "";

    while (getline(cin, lineToTest)) {
        int amountAlitararions = countAlitarations(lineToTest);
        cout << amountAlitararions << "\n";
    }

    return 0;
}

string getFirstLetters(const string line) {
    string result = "";
    bool foundFirstCharacter = false;

    for (int i = 0; i < line.length(); i++) {
        if (isalpha(line[i]) && !foundFirstCharacter) {
            result.push_back(tolower(line[i]));
            foundFirstCharacter = true;
        }
        else if(line[i] == ' ') {
            foundFirstCharacter = false;
        }
    }

    return result;
}

int countAlitarations(const string line) {
    string firstLetters = getFirstLetters(line);
    int count = 0;
    char lastLetter = ' ';
    bool hasAlreadyIncremented = false;

    for (int i = 0; i < firstLetters.length(); i++) {
        char actualCharacter = firstLetters[i];
        if (lastLetter != actualCharacter) {
            hasAlreadyIncremented = false;
        }
        else if (lastLetter == actualCharacter && !hasAlreadyIncremented) {
            hasAlreadyIncremented = true;
            count++;
        }
        lastLetter = actualCharacter;
    }

    return count;
}
