#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct Range {
    int minValue = 0;
    int maxValue = 0;
};

void getInputs(vector<Range> *ranges);
void getRange(const string line, int *minValue, int *maxValue);
void splitString(const string reference, const char separator, vector<string> *splitedString);
int countValidNumbers(const Range range);
bool hasRepetition(const string number);
int charToInt(const char character);

int main() {
    vector<Range> testCases;
    getInputs(&testCases);

    for(int i = 0; i < testCases.size(); i++) {
        int amountValidNumbers = countValidNumbers(testCases[i]);
        cout << amountValidNumbers << "\n";
    }
    
    return 0;
}

void getInputs(vector<Range> *ranges) {
    string line = "";
    vector<Range> inputs;

    while(getline(cin, line) && line != "") {
        int minValue = 0, maxValue = 0;
        getRange(line, &minValue, &maxValue);

        if(minValue != -1 && maxValue != -1) {
            Range inputRange;
            inputRange.minValue = minValue;
            inputRange.maxValue = maxValue;

            inputs.push_back(inputRange);
        }
    }
    
    *ranges = inputs;
    return;
}

void getRange(const string line, int *minValue, int *maxValue) {
    vector<string> splitedLine;
    splitString(line, ' ', &splitedLine);

    int minInput = stoi(splitedLine[0]);
    int maxInput = stoi(splitedLine[1]);

    if(maxInput < minInput) {
        minInput = -1;
        maxInput = -1;
    }

    if(minInput < 1 || minInput > 5000) {
        minInput = -1;
    }
    
    if(maxInput < 1 || maxInput > 5000) {
        maxInput = -1;
    }

    *minValue = minInput;
    *maxValue = maxInput;
    return;
}

void splitString(const string reference, const char separator, vector<string> *splitedString) {
    vector<string> temp;
    string actualPart = "";

    for(int i = 0; i < reference.length(); i++) {
        if(reference[i] != separator) {
            actualPart.push_back(reference[i]);
        }
        else if(actualPart != "") {
            temp.push_back(actualPart);
            actualPart.clear();
        }
    }

    if(actualPart != "") {
        temp.push_back(actualPart);
    }

    *splitedString = temp;
    return;
}

int countValidNumbers(const Range range) {
    vector<int> validNumbers;

    for(int i = range.minValue; i <= range.maxValue; i++) {
        if(!hasRepetition(to_string(i))) {
            validNumbers.push_back(i);
        }
    }

    return validNumbers.size();
}

bool hasRepetition(const string number) {
    map<int, int> numberFrequencys;

    for(int i = 0; i < number.length(); i++) {
        int actualDigit = charToInt(number[i]);

        map<int, int>::iterator element = numberFrequencys.find(actualDigit);
        if(element != numberFrequencys.end()) {
            return true;
        }
        else {
            numberFrequencys.insert(pair<int, int>(actualDigit, 1));
        }
    }

    return false;
}

int charToInt(const char character) {
    return (character - '0');
}
