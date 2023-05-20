#include <iostream>

using namespace std;

#define NUMBERS_SIZE 100

int main() {
    int numbers[NUMBERS_SIZE];

    for (int i = 0; i < NUMBERS_SIZE; i++) {
        cin >> numbers[i];
    }

    int position = 0, highestNumber = 0;
    for (int i = 0; i < NUMBERS_SIZE; i++) {
        if (highestNumber < numbers[i]) {
            highestNumber = numbers[i];
            position = i + 1;
        }
    }

    cout << highestNumber << "\n";
    cout << position << "\n";

    return 0;
}
