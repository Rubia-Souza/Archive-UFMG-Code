#include <iostream>

void fractal(int centroX, int centroY, int tamanhoLado) {
    if(tamanhoLado > 0) {
        fractal(centroX - tamanhoLado, centroY + tamanhoLado, tamanhoLado / 2);
        fractal(centroX + tamanhoLado, centroY + tamanhoLado, tamanhoLado / 2);
        fractal(centroX - tamanhoLado, centroY - tamanhoLado, tamanhoLado / 2);
        fractal(centroX + tamanhoLado, centroY - tamanhoLado, tamanhoLado / 2);
        std::cout << "Centro: [" << centroX << ", " << centroY << "]. Tamanho lado: " << tamanhoLado << "\n";
    }
}

int main() {
    int centroX, centroY, tamanhoInicial;

    std::cout << "Informe o x e o y do centro inicial: ";
    std::cin >> centroX >> centroY;

    std::cout << "Informe o tamanho inicial do lado: ";
    std::cin >> tamanhoInicial;

    fractal(centroX, centroY, tamanhoInicial);
    return 0;
}