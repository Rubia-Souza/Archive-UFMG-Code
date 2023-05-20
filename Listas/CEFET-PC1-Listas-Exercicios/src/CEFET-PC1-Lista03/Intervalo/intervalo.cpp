#include <iostream>

using namespace std;

int main() {
    float testNumber = 0;

    cin >> testNumber;
    
    if (testNumber >= 0 && testNumber <= 25) {
        cout << "Intervalo [0,25]\n";
    }
    else if (testNumber > 25 && testNumber <= 50) {
        cout << "Intervalo (25,50]\n";
    }
    else if (testNumber > 50 && testNumber <= 75) {
        cout << "Intervalo (50,75]\n";
    }
    else if (testNumber > 75 && testNumber <= 100) {
        cout << "Intervalo (75,100]\n";
    }
    else {
        cout << "Fora de intervalo\n";
    }

    return 0;
}
