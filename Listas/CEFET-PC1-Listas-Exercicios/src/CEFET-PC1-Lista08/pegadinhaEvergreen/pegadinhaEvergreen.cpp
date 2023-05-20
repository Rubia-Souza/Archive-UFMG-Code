#include <iostream>
#include <math.h>
#include <string>

using namespace std;

string fixName(const string firstPart, const string secondPart);

int main() {
    int testAmount = 0;

    do {
        cin >> testAmount;
        cin.ignore();
    } while(testAmount > 2000);

    for(int i = 0; i < testAmount; i++) {
        string firstPart = "", secondPart = "";
        getline(cin, firstPart);
        getline(cin, secondPart);

        string fixedName = fixName(firstPart, secondPart);
        cout << fixedName << "\n";
    }

    return 0;
}

string fixName(const string firstPart, const string secondPart) {
    int lastIndex = ceil(((firstPart.length() + secondPart.length()) / 2.0));
    const bool doesPartsHasSameSize = firstPart.length() == secondPart.length();
    int firstPartIndex = 0, secondPartIndex = 0;
    string fixedName = "";

    for(int i = 0; i < lastIndex; i++) {
        if(i % 2 == 0) {
            fixedName.push_back(firstPart[firstPartIndex]);
            fixedName.push_back(firstPart[firstPartIndex + 1]);
            firstPartIndex += 2;
        }
        else {
            fixedName.push_back(secondPart[secondPartIndex]);
            if(!doesPartsHasSameSize && i == lastIndex - 1) {
                break;
            }
            fixedName.push_back(secondPart[secondPartIndex + 1]);
            secondPartIndex += 2;
        }
    }

    return fixedName;
}
