#include <iostream>
#include <math.h>

using namespace std;

int calcularMaiorNumero(int a, int b) {
    return ((a + b + abs(a - b)) / 2);
}

int calcularMaiorEntreNumeros(int* numeros, int index) {
    if (index > 0) {
        int maior = calcularMaiorEntreNumeros(numeros, (index - 1));
        return calcularMaiorNumero(numeros[index], maior);
    }
    else {
        return numeros[index];
    }
}

int main() {
    const int ARRAY_LENGHT = 3;
    int numeros[ARRAY_LENGHT] = {};

    for (int i = 0; i < 3; i++) {
        cin >> numeros[i];
    }

    int maior = calcularMaiorEntreNumeros(numeros, (ARRAY_LENGHT - 1));

    cout << maior << " eh o maior\n";
    return 0;
}
