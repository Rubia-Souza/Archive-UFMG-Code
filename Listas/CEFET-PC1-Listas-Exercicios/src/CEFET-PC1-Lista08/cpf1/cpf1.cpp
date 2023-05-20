#include <iostream>
#include <string>
#include <vector>

using namespace std;

string removeCharacter(const string reference, const char character);
void splitString(const string reference, const char separator, vector<string> *outVector);

class CPF {
    private:
        string numbers = "";
        string validationNumbers = "";
    
    public:
        CPF() {}

        CPF(const string cpf) {
            setCpf(cpf);
        }

        void setCpf(const string cpf) {
            string formattedCpf = removeCharacter(cpf, '.');
            vector<string> splitedCpf;
            splitString(formattedCpf, '-', &splitedCpf);

            if(splitedCpf.size() == 2) {
                numbers = splitedCpf[0];
                validationNumbers = splitedCpf[1];
            }
        }

        string getCpf() {
            return (numbers + validationNumbers);
        }

        void setNumbers(const string numbers) {
            this->numbers = numbers;
        }

        string getNumbers() {
            return numbers;
        }

        void setValidationNumbers(const string validationNumbers) {
            this->validationNumbers = validationNumbers;
        }

        string getValidationNumbers() {
            return validationNumbers;
        }
};

void getCpfInput(vector<string> *outCpfsVector);
bool sumTest(CPF *cpf);
bool firstValidationNumberTest(CPF *cpf);
bool secondValidationNumberTest(CPF *cpf);
int charToInt(const char character);

#define MAX_CPF_AMOUNT 10000

int main() {
    vector<string> cpfs;
    getCpfInput(&cpfs);

    vector<CPF> formattedCpfs;
    for(int i = 0; i < cpfs.size(); i++) {
        CPF *cpf = new CPF(cpfs[i]);
        formattedCpfs.push_back(*cpf);
    }

    for(int i = 0; i < formattedCpfs.size(); i++) {
        CPF *actualCpf = &formattedCpfs[i];
        bool isSumValid = sumTest(actualCpf);
        bool isFirstNumberValid = firstValidationNumberTest(actualCpf);
        bool isSecondNumberValid = secondValidationNumberTest(actualCpf);

        if(isFirstNumberValid && isSecondNumberValid) {
            cout << "CPF valido\n";
        }
        else {
            cout << "CPF invalido\n";
        }
    }

    return 0;
}

void getCpfInput(vector<string> *outCpfsVector) {
    int inputCount = 0;
    string cpf = "";

    while(inputCount < MAX_CPF_AMOUNT && getline(cin, cpf) && cpf != "") {
        outCpfsVector->push_back(cpf);
        inputCount++;
    }

    return;
}

string removeCharacter(const string reference, const char character) {
    string result = "";
    
    for(int i = 0; i < reference.length(); i++) {
        if(reference[i] != character) {
            result.push_back(reference[i]);
        }
    }
    
    return result;
}

void splitString(const string reference, const char separator, vector<string> *outVector) {
    vector<string> splitedString;
    string actualPart = "";

    for(int i = 0; i < reference.length(); i++) {
        if(reference[i] != separator) {
            actualPart.push_back(reference[i]);
        }
        else if(actualPart != "") {
            splitedString.push_back(actualPart);
            actualPart.clear();
        }
    }

    if(actualPart != "") {
        splitedString.push_back(actualPart);
    }

    *outVector = splitedString;
    return;
}

bool sumTest(CPF *cpf) {
    int sum = 0;
    string cpfNumbers = cpf->getCpf();

    for(int i = 0; i < cpfNumbers.length(); i++) {
        int number = charToInt(cpfNumbers[i]);
        sum += number;
    }

    return (sum % 11 == 0);
}

int charToInt(const char character) {
    return (character - '0');
}

bool firstValidationNumberTest(CPF *cpf) {
    const string compleatCpf = cpf->getNumbers();
    const int firstValidationNumber = charToInt(cpf->getValidationNumbers()[0]);
    int sumBasedOnPosition = 0;

    for(int i = 0; i < compleatCpf.length(); i++) {
        int actualNumber = charToInt(compleatCpf[i]);
        sumBasedOnPosition += (actualNumber * (i + 1));
    }

    int generatedValidationNumber = sumBasedOnPosition % 11;
    if(generatedValidationNumber == 10) {
        generatedValidationNumber = 0;
    }

    return (generatedValidationNumber == firstValidationNumber);
}

bool secondValidationNumberTest(CPF *cpf) {
    const string compleatCpf = cpf->getNumbers();
    const int secondValidationNumber = charToInt(cpf->getValidationNumbers()[1]);
    int sumBasedOnPosition = 0, weight = 9;

    for(int i = 0; i < compleatCpf.length(); i++, weight--) {
        int actualNumber = charToInt(compleatCpf[i]);
        sumBasedOnPosition += (actualNumber * weight);
    }

    int generatedValidationNumber = sumBasedOnPosition % 11;
    if(generatedValidationNumber == 10) {
        generatedValidationNumber = 0;
    }

    return (generatedValidationNumber == secondValidationNumber);
}
