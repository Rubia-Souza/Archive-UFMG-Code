#include <iostream>

#include "FaixaOrdenacao.h"
#include "Pilha.h"

#define MAXIMO_OPCOES 6

enum Opcoes {
    Sair = 0,
    Empilhar = 1,
    Desempilhar = 2,
    Limpar = 3,
    EstaVaiza = 4,
    Tamanho = 5,
    Print = 6,
};

void printOpcoes();
unsigned int getOpcao();
void executarTeste(const unsigned int opcao, Pilha& pilha);

int main(int argc, char* argv[]) {
    unsigned int opcao = 0;
    Pilha pilha;

    do {
        printOpcoes();
        opcao = getOpcao();

        executarTeste(opcao, pilha);
    } while(opcao != 0);

    return 0;
}

void printOpcoes() {
    std::cout << "\n[0] Sair\n"
              << "[1] Empilhar\n"
              << "[2] Desempilhar\n"
              << "[3] Limpar\n"
              << "[4] Esta vazia\n"
              << "[5] Tamanho\n"
              << "[6] Printar\n";
    return;
}

unsigned int getOpcao() {
    std::cout << "Digite uma opcao: ";
    unsigned int opcao = 0;
    Pilha pilha;

    do {
        std::cin >> opcao;

        if(opcao > MAXIMO_OPCOES) {
            std::cout << "\nDigite uma opcao valida, entre 0 e " << MAXIMO_OPCOES << ": ";
        }
    } while(opcao > MAXIMO_OPCOES);

    return opcao;
}

void executarTeste(const unsigned int opcao, Pilha& pilha) {
    switch(opcao) {
        case(Opcoes::Empilhar): {
            FaixaOrdencao faixa;

            std::cout << "Inicio: ";
            std::cin >> faixa.inicio;

            std::cout << "Fim: ";
            std::cin >> faixa.fim;

            pilha.empilhar(faixa);
            break;
        }
        case(Opcoes::Desempilhar): {
            FaixaOrdencao* faixaRemovida;

            faixaRemovida = pilha.desempilhar();
            if(faixaRemovida != nullptr) {
                std::cout << "Inicio: " << faixaRemovida->inicio << " Fim: " << faixaRemovida->fim << "\n";
            }

            break;
        }
        case(Opcoes::Limpar): {
            pilha.limpar();
            break;
        }
        case(Opcoes::EstaVaiza): {
            if(pilha.estaVazia()) {
                std::cout << "Esta vazia\n";
            }
            else {
                std::cout << "Nao esta vazia\n";
            }

            break;
        }
        case(Opcoes::Tamanho): {
            std::cout << "Tamanho: " << pilha.getTamanho() << "\n";
            break;
        }
        case(Opcoes::Print): {
            pilha.print();
            break;
        }
    }

    return;
}
