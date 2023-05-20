#include <iostream>
#include <string>

using namespace std;

#define INPUT_VECTOR_SIZE 5

bool isPair(const int number);
void printVector(const int vector[], const int size, const bool isPair);

int main() {
    const int INTERATIONS = 15;
    int pairVector[INPUT_VECTOR_SIZE], oddVector[INPUT_VECTOR_SIZE];
    int pairIndex = 0, oddIndex = 0;

    for (int i = 0; i < INTERATIONS; i++) {
        int input = 0;
        cin >> input;

        if (isPair(input)) {
            pairVector[pairIndex] = input;
            pairIndex++;
        }
        else {
            oddVector[oddIndex] = input;
            oddIndex++;
        }

        if (pairIndex == INPUT_VECTOR_SIZE) {
            printVector(pairVector, pairIndex, true);
            pairIndex = 0;
        }

        if (oddIndex == INPUT_VECTOR_SIZE) {
            printVector(oddVector, oddIndex, false);
            oddIndex = 0;
        }
    }

    printVector(oddVector, oddIndex, false);
    printVector(pairVector, pairIndex, true);

    return 0;
}

bool isPair(const int number) {
    return (number % 2 == 0);
}

void printVector(const int vector[], const int size, const bool isPair) {
    string type;
    if (isPair) {
        type = "par";
    }
    else {
        type = "impar";
    }

    for (int i = 0; i < size; i++) {
        cout << type << "[" << i << "] = " << vector[i] << "\n";
    }

    return;
}
