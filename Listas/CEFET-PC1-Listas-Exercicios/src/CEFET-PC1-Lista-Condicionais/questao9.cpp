#include <iostream>

using namespace std;

int main() {

    int posicaoX = 0, posicaoY = 0;

    cin >> posicaoX >> posicaoY;

    bool isPontoNaOrigem = posicaoX == 0 && posicaoY == 0;

    if (isPontoNaOrigem) {
        cout << "Ponto na origem\n";
        return 0;
    }

    bool isPontoNoEixoY = posicaoX == 0 && posicaoY != 0;
    if (isPontoNoEixoY) {
        cout << "Ponto no eixo Y\n";
        return 0;
    }

    bool isPontoNoEixoX = posicaoX != 0 && posicaoY == 0;
    if (isPontoNoEixoX) {
        cout << "Ponto no eixo X\n";
        return 0;
    }

    if (posicaoX > 0 && posicaoY > 0) {
        cout << "Ponto no quadrante 1\n";
    }
    else if (posicaoX < 0 && posicaoY > 0) {
        cout << "Ponto no quadrante 2\n";
    }
    else if (posicaoX < 0 && posicaoY < 0) {
        cout << "Ponto no quadrante 3\n";
    }
    else {
        cout << "Ponto no quadrante 4\n";
    }

    return 0;
}
