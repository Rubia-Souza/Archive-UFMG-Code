#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void getNumbers(map<int, int> *outMap);
void printMap(const map<int, int> map);

int main() {
    map<int, int> numbersFrequency;
    getNumbers(&numbersFrequency);

    printMap(numbersFrequency);

    return 0;
}

void getNumbers(map<int, int> *outMap) {
    unsigned int amountInputs = 0;
    do {
        cin >> amountInputs;
        cin.ignore();
    } while(amountInputs < 1);

    for(int i = 0; i < amountInputs; i++) {
        string inputLine = "";
        getline(cin, inputLine);
        
        int inputNumber = stoi(inputLine);
        map<int, int>::iterator element = outMap->find(inputNumber);
        if(element != outMap->end()) {
            element->second += 1;
        }
        else if(inputNumber >= 1 && inputNumber <= 2000) {
            outMap->insert(pair<int, int>(inputNumber, 1));        
        }
    }

    return;
}

void printMap(const map<int, int> map) {
    for(const auto &element : map) {
        cout << element.first << " aparece " << element.second << " vez(es)\n";
    }

    return;
}
