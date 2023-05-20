#include <iostream>
#include <vector>

using namespace std;

#define MAX_SIZE 100
#define MIN_SIZE 1

bool ehPrimo(const int numero);

int main() {
    int numeroCasos = 0;

    do {
        cin >> numeroCasos;
    } while(numeroCasos < MIN_SIZE || numeroCasos > MAX_SIZE);

    vector<int> testes(numeroCasos);

    for (int i = 0; i < numeroCasos; i++) {
        cin >> testes[i];
    }

    for (int i = 0; i < numeroCasos; i++) {
        if (ehPrimo(testes[i])) {
            cout << testes[i] << " eh primo\n";
        }
        else {
            cout << testes[i] << " nao eh primo\n";
        }
    }

    return 0;
}

bool ehPrimo(const int numero) {
    for (int i = 2; i < numero; i++) {
        if (numero % i == 0) {
            return false;
        }
    }

    return true;
}
