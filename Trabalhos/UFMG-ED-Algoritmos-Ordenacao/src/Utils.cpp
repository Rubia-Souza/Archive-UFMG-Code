#include <iostream>
#include <cstdlib>
#include <string>
#include <string.h>
#include <ctime>

#include "Utils.h"

std::string Utils::gerarStringAleatoria(const unsigned int tamanho) {
    const std::string POSSIVEIS_CARACTERES = "0123456789abcdefghijklmnopqrstuvwxyz";
    const unsigned int TAMANHO_POSSIVEIS_CARACTERES = (sizeof(POSSIVEIS_CARACTERES) - 1);
    std::string resultado = "";

    for(unsigned int i = 0; i < tamanho; i++) {
        unsigned int caracterEscolhido = (rand() % TAMANHO_POSSIVEIS_CARACTERES);
        resultado.push_back(POSSIVEIS_CARACTERES[caracterEscolhido]);
    }

    return resultado;
}

int Utils::gerarNumeroInteiroAleatorioEmUmaFaixa(const int valorInicial, const int valorFinal) {
    int faixa = (valorFinal - valorInicial) + 1;
    return (rand() % faixa) + valorInicial;
}

int Utils::gerarNumeroInteiroAleatorio() {
    return rand();
}

float Utils::gerarNumeroFloatAleatorioEmUmaFaixa(const float valorInicial, const float valorFinal) {
    return (static_cast<float>(rand()) / static_cast<float>(RAND_MAX / (valorFinal - valorInicial))) + valorInicial;
}

float Utils::gerarNumeroFloatAleatorio() {
    return (static_cast<float>(rand()) / static_cast<float>(RAND_MAX));
}

Registro* Utils::gerarRegistroAelatorio() {
    Registro* resultado = new Registro();

    resultado->chave = Utils::gerarNumeroInteiroAleatorio();

    /*for(unsigned int i = 0; i < QUANTIDADE_NUMEROS_REGISTRO; i++) {
        resultado->numeros[i] = Utils::gerarNumeroFloatAleatorio();
    }

    for(unsigned int i = 0; i < QUANTIDADE_STRINGS_REGISTRO; i++) {
        strcpy(resultado->textos[i], Utils::gerarStringAleatoria(TAMANHO_PADRAO_STRING_REGISTRO).c_str());
    }*/

    return resultado;
}

void Utils::verificarOrdenacaoCrescente(Registro vetor[], const unsigned int tamanaho) {
    for(unsigned int i = 1; i < tamanaho; i++) {
        if(vetor[i-1] > vetor[i]) {
            std::cout << "\nOrdenacao incorreta";
            return;
        }
    }

    std::cout << "\nOrdenacao correta";
    return;
}

void Utils::verificarOrdenacaoDecrescente(Registro vetor[], const unsigned int tamanaho) {
    for(unsigned int i = 1; i < tamanaho; i++) {
        if(vetor[i-1] < vetor[i]) {
            std::cout << "\nOrdenacao incorreta";
            return;
        }
    }

    std::cout << "\nOrdenacao correta";
    return;
}
