#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

void setUpCout() {
    cout << fixed;
    cout << setprecision(4);
}

int main() {
    setUpCout();

    const double pi = 3.14159;
    double raio = 0;

    cin >> raio;

    double area = pow(raio, 2) * pi;

    cout << "A=" << area << "\n";
    return 0;
}
