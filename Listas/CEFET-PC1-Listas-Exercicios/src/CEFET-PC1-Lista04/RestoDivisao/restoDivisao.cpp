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

    for (int i = (menor + 1); i < maior; i++) {
        int resto = i % 5;
        if (resto == 2 || resto == 3) {
            cout << i << "\n";
        }
    }

    return 0;
}
