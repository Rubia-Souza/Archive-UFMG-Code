#include <iostream>

using namespace std;

int main() {
    float x = 0, y = 0;

    cin >> x >> y;

    bool isPointInOrigin = x == 0 && y == 0;
    if (isPointInOrigin) {
        cout << "Origem\n";
        return 0;
    }

    bool isPointInXLine = y == 0 && x != 0;
    if (isPointInXLine) {
        cout << "Eixo X\n";
        return 0;
    }

    bool isPointInYLine = x == 0 && y != 0;
    if (isPointInYLine) {
        cout << "Eixo Y\n";
        return 0;   
    }

    bool isXPositve = x > 0;
    bool isYPositve = y > 0;

    if (isXPositve && isYPositve) {
        cout << "Q1\n";
    }
    else if (!isXPositve && isYPositve) {
        cout << "Q2\n";
    }
    else if (!isXPositve && !isYPositve) {
        cout << "Q3\n";
    }
    else if (isXPositve && !isYPositve) {
        cout << "Q4\n";
    }

    return 0;
}
