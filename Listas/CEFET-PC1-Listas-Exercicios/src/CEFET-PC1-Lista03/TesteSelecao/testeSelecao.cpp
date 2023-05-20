#include <iostream>

using namespace std;

int main() {
    int a = 0, b = 0, c = 0, d = 0;

    cin >> a >> b >> c >> d;

    bool isBGreaterThanC = b > c;
    bool isDGreaterThanA = d > a;

    bool isCDGreaterThanAB = (c + d) > (a + b);

    bool isCPositive = c > 0;
    bool isDPositive = d > 0;

    bool isAPair = a % 2 == 0;

    if (isBGreaterThanC && isDGreaterThanA 
        && isCDGreaterThanAB && isCPositive 
        && isDPositive && isAPair) {

            cout << "Valores aceitos\n";
    }
    else {
        cout << "Valores nao aceitos\n";
    }

    return 0;
}
