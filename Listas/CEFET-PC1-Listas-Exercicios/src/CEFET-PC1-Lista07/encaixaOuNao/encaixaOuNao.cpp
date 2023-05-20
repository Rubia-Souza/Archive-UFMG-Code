#include <iostream>
#include <string>

using namespace std;

bool doesStringMatchEnd(const string refString, const string endCheckString);
bool doesStringFit(const string string1, const string string2);

int main() {
    unsigned int testAmount = 0;

    do {
        cin >> testAmount;
    } while (testAmount < 1);

    for (int i = 0; i < testAmount; i++) {
        string firstNumber = "", secondNumber = "";
        cin >> firstNumber >> secondNumber;

        bool doesMatch = doesStringMatchEnd(firstNumber, secondNumber);
        if (doesMatch) {
            cout << "encaixa\n";
        }
        else {
            cout << "nao encaixa\n";
        }
    }
    
    return 0;
}

bool doesStringMatchEnd(const string refString, const string endCheckString) {
    if (!doesStringFit(refString, endCheckString)) {
        return false;
    }

    for (int refIndex = refString.length() - 1, endCheckIndex = endCheckString.length() - 1; 
            endCheckIndex >= 0; endCheckIndex--, refIndex--)
    {
        if (refString[refIndex] != endCheckString[endCheckIndex]) {
            return false;
        }
    }

    return true;
}

bool doesStringFit(const string string1, const string string2) {
    return string1.length() >= string2.length();
}
