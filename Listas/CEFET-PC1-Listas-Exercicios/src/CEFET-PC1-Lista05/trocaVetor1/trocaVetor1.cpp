#include <iostream>

using namespace std;

#define INPUT_VECTOR_SIZE 20

int main() {
    int inputVector[INPUT_VECTOR_SIZE];

    for (int i = 0; i < INPUT_VECTOR_SIZE; i++) {
        cin >> inputVector[i];
    }

    for (int start = 0, end = (INPUT_VECTOR_SIZE - 1); start < (INPUT_VECTOR_SIZE / 2); start++, end--) {
        int temp = inputVector[start];
        inputVector[start] = inputVector[end];
        inputVector[end] = temp;
    }

    for (int i = 0; i < INPUT_VECTOR_SIZE; i++) {
        cout << "N[" << i << "] = " << inputVector[i] << "\n";
    }

    return 0;
}
