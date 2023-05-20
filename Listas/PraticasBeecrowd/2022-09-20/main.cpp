#include <iostream>

unsigned int suicidar(unsigned int numeroPessoas, unsigned int contadorPessoaViva) {
    if(numeroPessoas == 1) {
        return 0;
    }
    
    return ((suicidar(numeroPessoas - 1, contadorPessoaViva) + contadorPessoaViva) % numeroPessoas);
}

int main() {
    unsigned int casosTeste = 0;
    unsigned int numeroPessoas = 0;
    unsigned int contadorPessoaViva = 0;

    std::cin >> casosTeste;

    for(unsigned int i = 0; i < casosTeste; i++) {
        std::cin >> numeroPessoas;
        std::cin >> contadorPessoaViva;

        std::cout << "Case " << i + 1 << ": " << suicidar(numeroPessoas, contadorPessoaViva) + 1 << "\n";
    }

    return 0;
}
