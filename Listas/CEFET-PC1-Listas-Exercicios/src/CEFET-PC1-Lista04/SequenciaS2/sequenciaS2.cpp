#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

void setUpCout(const int precision) {
    cout << fixed;
    cout << setprecision(precision);
}

int main() {
    setUpCout(2);
    double s = 0;

    for (int i = 0; i <= 19; i++) {
        if (i == 0) {
            s = 1;
        }
        else {
            // S = 1 + 3/2 + 5/4 + 7/8 + ... + 39/?
            double numerador = 1 + 2.0 * i;
            double divisor = pow(2.0, i);
            double result = numerador / divisor;
            s += result;
        }
    }

    cout << s << "\n";

    return 0;
}
