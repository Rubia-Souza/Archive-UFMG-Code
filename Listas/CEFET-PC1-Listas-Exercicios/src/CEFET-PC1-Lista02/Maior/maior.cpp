#include <iostream>

using namespace std;

int calcularMaiorNumero(int a, int b) {
    return ((a + b + abs(a - b)) / 2);
}

int main() {
    int a = 0, b = 0, c = 0;

    cin >> a;
    cin >> b;
    cin >> c;

    int temp = calcularMaiorNumero(a, b);
    int maior = calcularMaiorNumero(temp, c);

    cout << maior << " eh o maior";
    return 0;
}
