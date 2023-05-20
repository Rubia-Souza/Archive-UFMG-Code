#include <iostream>
#include <iomanip>

using namespace std;

void setUpCout(const int precision) {
    cout << fixed;
    cout << setprecision(precision);
}

int main() {
    setUpCout(2);
    double s = 0;

    for (int i = 1; i <= 100; i++) {
        if (i == 1) {
            s = 1;
        }
        else {
            double reuslt = 1.0/i;
            s += reuslt;
        }
    }

    cout << s << "\n";

    return 0;
}
