#include <iostream>
#include <ctype.h>
#include <string>
#include <iterator>
#include <vector>
#include <map>

using namespace std;

void findMostFrequentLetters(const string line, vector<char> *outFrequentLtters);
void fillMap(map<char, int> *outMap);
void checkLettersFrequencys(const string refString, map<char, int> *outMap);
void printMap(const map<char, int> outMap);
string setLowerCase(const string reference);
void getMostFrequentLettersIndex(const map<char, int> letters, vector<char> *mostFrequentLetters);
string vectorToString(const vector<char> target);

int main() {
    unsigned int testAmount = 0;

    do {
        cin >> testAmount;
        cin.ignore();
    } while(testAmount < 1);

    for (int i = 0; i < testAmount; i++) {
        string lineTest = "";
        getline(cin, lineTest);

        vector<char> frequentLetters;
        findMostFrequentLetters(lineTest, &frequentLetters);

        string ordenatedLetters = vectorToString(frequentLetters);
        cout << ordenatedLetters << "\n";
    }

    return 0;
}

void findMostFrequentLetters(const string line, vector<char> *outFrequentLtters) {
    string lineTest = setLowerCase(line);

    map<char, int> letterFrequency;
    fillMap(&letterFrequency);
    checkLettersFrequencys(lineTest, &letterFrequency);

    printMap(letterFrequency);
    getMostFrequentLettersIndex(letterFrequency, outFrequentLtters);
}

void fillMap(map<char, int> *outMap) {
    char actualLetter = 'a';
    for (int i = 0; i < 26; i++) {
        outMap->insert(pair<char, int>(actualLetter, 0));
        actualLetter += 1;
    }

    return;
}

void checkLettersFrequencys(const string refString, map<char, int> *outMap) {
    for (int i = 0; i < refString.length(); i++) {
        char actualCharacter = refString[i];
        if (isalpha(actualCharacter)) {
            map<char, int>::iterator element = outMap->find(actualCharacter);
            element->second += 1;
        }
    }

    return;
}

void printMap(const map<char, int> outMap) {
    map<char, int>::const_iterator element;
    for (element = outMap.begin(); element != outMap.end(); element++) {
        cout << "Letra: " << element->first << " valor: " << element->second << "\n";
    }

    return;
}

string setLowerCase(const string reference) {
    string result = reference;
    for (int i = 0; i < result.length(); i++) {
        result[i] = tolower(result[i]);
    }

    return result;
}

void getMostFrequentLettersIndex(const map<char, int> letters, vector<char> *mostFrequentLetters) {
    int highestValue = 0;
    map<char, int>::const_iterator element;

    for (element = letters.begin(); element != letters.end(); element++) {
        int actualLetterFrequency = element->second;
        if (actualLetterFrequency > highestValue) {
            mostFrequentLetters->clear();
            mostFrequentLetters->push_back(element->first);
            highestValue = actualLetterFrequency;
        }
        else if (actualLetterFrequency == highestValue) {
            mostFrequentLetters->push_back(element->first);
        }
    }

    return;
}

string vectorToString(const vector<char> target) {
    string result = "";
    for (int i = 0; i < target.size(); i++) {
        result.push_back(target[i]);
    }

    return result;
}
