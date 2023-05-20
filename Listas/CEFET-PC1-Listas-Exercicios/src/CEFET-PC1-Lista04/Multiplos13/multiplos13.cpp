#include <iostream>

using namespace std;

int main() {
    int n1 = 0, n2 = 0;

    cin >> n1;
    cin >> n2;

    int maior = 0, menor = 0;
    if (n1 < n2) {
        maior = n2;
        menor = n1;
    }
    else {
        maior = n1;
        menor = n2;
    }

    int sum = 0;
    for (int i = menor; i <= maior; i++) {
        int resto = i % 13;
        if (resto != 0) {
            sum += i;
        }
    }

    cout << sum << "\n";

    return 0;
}
