#include <iostream>
#include <iomanip>

using namespace std;

#define INPUT_VECTOR_SIZE 100

void setUpCout() {
    cout << fixed;
    cout << setprecision(4);
}

int main() {
    setUpCout();
    double startValue = 0.0;
    double inputVector[INPUT_VECTOR_SIZE];

    cin >> startValue;
    inputVector[0] = startValue;
    cout << "N[" << 0 << "] = " << inputVector[0] << "\n";

    for (int i = 1, j = 0; i < INPUT_VECTOR_SIZE; i++, j++) {
        inputVector[i] = inputVector[j] / 2.0;
        cout << "N[" << i << "] = " << inputVector[i] << "\n";
    }

    return 0;
}
