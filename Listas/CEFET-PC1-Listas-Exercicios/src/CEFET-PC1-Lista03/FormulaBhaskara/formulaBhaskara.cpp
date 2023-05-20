#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

void setUpCout() {
    cout << fixed;
    cout << setprecision(5);
}

double * calculateBhaskara(double delta, double a, double b) {
    static double roots[2];
    double sqrtDelta = sqrt(delta);

    roots[0] = (-b + sqrtDelta) / (2 * a);
    roots[1] = (-b - sqrtDelta) / (2 * a);

    return roots;
}

double calculateDeltaValue(double a, double b, double c) {
    return pow(b, 2) - (4 * a * c);
}

int main() {
    setUpCout();

    double a = 0, b = 0, c = 0;

    cin >> a >> b >> c;

    bool isAInvalid = a == 0;
    if (isAInvalid) {
         cout << "Impossivel calcular\n";
         return 0;
    }

    double delta = calculateDeltaValue(a, b, c);
    
    bool isDeltaNegative = delta < 0;
    if (isDeltaNegative) {
        cout << "Impossivel calcular\n";
        return 0;
    }

    double *roots = calculateBhaskara(delta, a, b);
    cout << "R1 = " << roots[0] << "\n";
    cout << "R2 = " << roots[1] << "\n";

    return 0;
}
