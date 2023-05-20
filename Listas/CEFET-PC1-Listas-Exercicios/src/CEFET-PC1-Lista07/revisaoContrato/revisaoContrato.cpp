#include <iostream>
#include <string>
#include <vector>

using namespace std;

void getUserInput(char *outProblematicNumber, string *outContractNumber);
void splitString(const string target, const char splitPoint, vector<string> *outVector);
string formattNumberInLine(const string line);
string removeLeftZeros(const string line);
string removeCharacter(const string target, const char character);

int main() {
    char problematicNumber;
    string contractNumber = "";

    getUserInput(&problematicNumber, &contractNumber);

    while (problematicNumber != '0' && contractNumber != "0") {
        string result = removeCharacter(contractNumber, problematicNumber);
        result = formattNumberInLine(result);

        cout << result << "\n";        

        getUserInput(&problematicNumber, &contractNumber);
    }

    return 0;
}

void getUserInput(char *outProblematicNumber, string *outContractNumber) {
    string inputLine = "";
    vector<string> splitedLine;

    unsigned int problematicNumber = 0, contractNumber = 0;

    do {
        getline(cin, inputLine);

        splitString(inputLine, ' ', &splitedLine);

        problematicNumber = stoi(splitedLine[0]);
        
        string firstPartOfContractNumber = "";
        firstPartOfContractNumber.push_back(splitedLine[1][0]);
        firstPartOfContractNumber.push_back(splitedLine[1][1]);
        contractNumber = stoi(firstPartOfContractNumber);
    } while (problematicNumber < 0 || problematicNumber > 9 || contractNumber < 0);

    *outProblematicNumber = splitedLine[0][0];
    *outContractNumber = splitedLine[1];

    return;
}

void splitString(const string target, const char splitPoint, vector<string> *outVector) {
    string temp = "";

    for (int i = 0; i < target.length(); i++) {
        char actualCharacter = target[i];

        if (actualCharacter == splitPoint && !temp.empty()) {
            outVector->push_back(temp);
            temp.clear();
        }
        else if (actualCharacter != splitPoint) {
            temp.push_back(actualCharacter);
        }
    }

    if (!temp.empty()) {
        outVector->push_back(temp);
    }

    return;
}

string formattNumberInLine(const string line) {
    string result = removeLeftZeros(line);

    if (line.length() == 0) {
        result = "0";
    }

    return result;
}

string removeLeftZeros(const string line) {
    string result = "";
    bool hasFoundNumberDiferentThanZero = false;

    for (int i = 0; i < line.length(); i++) {
        char actualCharacter = line[i];
        if (actualCharacter != '0' & !hasFoundNumberDiferentThanZero) {
            hasFoundNumberDiferentThanZero = true;
        }
        
        if (hasFoundNumberDiferentThanZero || i == line.length() - 1) {
            result.push_back(actualCharacter);
        }
    }

    return result;
}

string removeCharacter(const string target, const char character) {
    string result = "";

    for (int i = 0; i < target.length(); i++) {
        if (target[i] != character) {
            result.push_back(target[i]);
        }
    }

    return result;
}
