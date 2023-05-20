#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

vector<string> splitString(const string input, const char splitCharacter);
vector<string> getStringWithStart(const vector<string> strings, const char initialCharacter);
void printMarker(const vector<string> marks, const string type);
string toLower(const string reference);

int main() {
    stringstream input;
    input.clear();

    string temp = "";
    while(cin >> temp) {
        input << temp << " ";
    }

    string line = input.str();

    vector<string> inputStrings = splitString(line, ' ');
    vector<string> hashtags = getStringWithStart(inputStrings, '#');
    vector<string> ats = getStringWithStart(inputStrings, '@');
    
    printMarker(hashtags, "Hashtags");
    if(ats.size() > 3) {
        cout << "Tweet inválido.\n";
    }
    else {
        printMarker(ats, "Arrobas");
    }

    return 0;
}

vector<string> splitString(const string input, const char splitCharacter) {
    vector<string> splitedString;
    string actualString;

    for(int i = 0; i < input.length(); i++) {
        char actualCharacter = input[i];
        if(actualCharacter != splitCharacter) {
            actualString.push_back(actualCharacter);
        }
        else {
            splitedString.push_back(actualString);
            actualString.clear();
        }
    }

    splitedString.push_back(actualString);
    return splitedString;
}


vector<string> getStringWithStart(const vector<string> strings, const char initialCharacter) {
    vector<string> filteredStrings;

    for(int i = 0; i < strings.size(); i++) {
        string actualString = strings.at(i);
        if(actualString[0] == initialCharacter) {
            filteredStrings.push_back(actualString);
        }
    }

    return filteredStrings;
}

void printMarker(const vector<string> marks, const string type) {
    if(marks.size() == 0) {
        cout << "O tweet não possui " << toLower(type) << ".\n";
        return;
    }
    else {
        cout << type << ": ";
    }

    for(int i = 0; i < marks.size(); i++) {
        cout << marks.at(i);
        if(i != marks.size() - 1) {
            cout << " ";
        }
    }

    cout << "\n";
    return;
}

string toLower(const string reference) {
    string output = "";

    for(int i = 0; i < reference.length(); i++) {
        output.push_back(tolower(reference[i]));
    }

    return output;
}
