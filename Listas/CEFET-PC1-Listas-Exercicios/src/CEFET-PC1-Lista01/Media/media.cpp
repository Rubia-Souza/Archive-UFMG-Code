#include <iostream>
#include <iomanip>

using namespace std;

void setUpCout() {
    cout << fixed;
    cout << setprecision(5);
}

int main() {
    setUpCout();

    double a = 0, b = 0;
    const double pesoA = 3.5, pesoB = 7.5;

    do {
        cin >> a;
    } while(a > 10 || a < 0);

    do {
        cin >> b;
    } while(b > 10 || b < 0);

    double media = (a * pesoA + b * pesoB) / (pesoA + pesoB);
    cout << "MEDIA = " << media << "\n";
    return 0;
}
