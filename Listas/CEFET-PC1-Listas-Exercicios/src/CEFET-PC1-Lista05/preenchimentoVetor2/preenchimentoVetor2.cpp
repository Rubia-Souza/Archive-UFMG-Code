#include <iostream>

using namespace std;

#define INPUT_VECTOR_SIZE 1000

int main() {
    int inputVector[INPUT_VECTOR_SIZE];
    int maxValue = 0;

    while (maxValue < 2 || maxValue > 50) {
        cin >> maxValue;
    }
    
    for (int i = 0; i < INPUT_VECTOR_SIZE; i) {
        for (int j = 0; j < maxValue && i < INPUT_VECTOR_SIZE; j++) {
            inputVector[i] = j;
            cout << "N[" << i << "] = " << inputVector[i] << "\n";
            i++;
        }
    }

    return 0;
}
