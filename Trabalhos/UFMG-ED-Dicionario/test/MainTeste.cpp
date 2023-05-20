#include <iostream>

#include "Verbete.h"
#include "TiposVerbete.h"

#include "DicionarioArvoreAVL.h"
#include "DicionarioHash.h"

enum Opcoes {
    SAIR = 0,
    INSERIR = 1,
    REMOVER = 2,
    PESQUISAR = 3,
    ATUALIZAR = 4,
    IMPRIMIR = 5,
    LIMPAR = 6,
};

void printMenu();
unsigned int getTipoDicionario();
unsigned int getOpcao();
void executar(const unsigned int opcao, Dicionario* dicionario);
Verbete* getVerbete();

int main() {
    unsigned int tipoDicionario = getTipoDicionario();
    Dicionario* dicionario;

    if(tipoDicionario == 1) {
        dicionario = new DicionarioArvoreAVL();
    }
    else if(tipoDicionario == 2) {
        dicionario = new DicionarioHash();
    }

    unsigned int opcao = 0;
    do {
        printMenu();
        opcao = getOpcao();

        executar(opcao, dicionario);
    } while(opcao != 0);

    delete dicionario;
    return 0;
}

void printMenu() {
    std::cout << "\n----- Opcoes -----\n";

    std::cout  << "[1] Inserir\n"
               << "[2] Remover\n"
               << "[3] Pesquisar\n"
               << "[4] Atualizar\n"
               << "[5] Imprimir\n"
               << "[6] Limpar\n"
               << "[0] Sair\n";
    
    return;
}

unsigned int getOpcao() {
    unsigned int opcao = 0;

    std::cout << "\nEscolha uma das opcoes: ";

    do {
        std::cin >> opcao;

        if(opcao > Opcoes::LIMPAR) {
            std::cout << "\nDigite um valor valido, entre (" << Opcoes::SAIR << " e " << Opcoes::LIMPAR << "): ";
        }
    } while(opcao > Opcoes::LIMPAR);    

    return opcao;
}

unsigned int getTipoDicionario() {
    unsigned int tipoDicionario = 0;

    std::cout << "\n[1] Arvore AVL"
              << "\n[2] Hash";

    std::cout << "\nEscolha um tipo de dicionario: ";
    do {
        std::cin >> tipoDicionario;

        if(tipoDicionario < 1 || tipoDicionario > 2) {
            std::cout << "\nDigite um valor valido, entre (1 e 2): ";
        }
    } while(tipoDicionario > 2);    

    return tipoDicionario;
}

void executar(const unsigned int opcao, Dicionario* dicionario) {
    switch(opcao) {
        case(Opcoes::INSERIR): {
            Verbete* verbete = getVerbete();

            dicionario->inserir(*verbete);
            break;
        }
        case(Opcoes::REMOVER): {
            std::string palavra = "";
            std::cout << "\nDigite a palavra que deseja deletar: ";
            std::cin >> palavra;

            char tipo;
            std::cout << "\nDigite o tipo do verebte que deseja deletar: ";
            std::cin >> tipo;

            dicionario->remover(palavra, converterCharParaTiposVerbete(tipo));
            break;
        }
        case(Opcoes::PESQUISAR): {
            std::string palavra = "";
            std::cout << "\nDigite a palavra que deseja buscar: ";
            std::cin >> palavra;

            char tipo;
            std::cout << "\nDigite o tipo do verebte que deseja deletar: ";
            std::cin >> tipo;
            
            Verbete* verbeteBuscado = dicionario->pesquisar(palavra, converterCharParaTiposVerbete(tipo));

            if(verbeteBuscado != nullptr) {
                std::cout << "\nVerbete: " << verbeteBuscado->getPalavra() << " encontrado!\n";
                verbeteBuscado->imprimir();
            }
            else {
                std::cout << "\nVerbete não encontrado";
            }

            break;
        }
        case(Opcoes::ATUALIZAR): {
            Verbete* verbete = getVerbete();

            dicionario->atualizar(*verbete);
            break;
        }
        case(Opcoes::IMPRIMIR): {
            if(dicionario->estaVazia()) {
                std::cout << "\nDicionario esta vazio";
            }
            else {
                dicionario->imprimir();
            }

            break;
        }
        case(Opcoes::LIMPAR): {
            dicionario->limpar();
            break;
        }
    }

    return;
}

Verbete* getVerbete() {
    Verbete* verbete = new Verbete;
    
    std::string palavra = "";
    std::cout << "\nDigite a palavra: ";
    std::cin >> palavra;

    verbete->setPalavra(palavra);

    std::cout << "\nDigite o tipo da palavra: ";
    char tipo = 0;
    do {
        std::cin >> tipo;

        if(tipo != TiposVerbete::NOME && tipo != TiposVerbete::VERBO && tipo != TiposVerbete::ADJETIVO) {
            std::cout << "Digite um tipo da palavra valido (" << char(TiposVerbete::ADJETIVO) << ", " << char(TiposVerbete::NOME) << ", " << char(TiposVerbete::VERBO) << "): ";
        }
    } while(tipo != TiposVerbete::NOME && tipo != TiposVerbete::VERBO && tipo != TiposVerbete::ADJETIVO);

    switch(tipo) {
        case(TiposVerbete::ADJETIVO): {
            verbete->setTipo(TiposVerbete::ADJETIVO);
            break;
        }
        case(TiposVerbete::NOME): {
            verbete->setTipo(TiposVerbete::NOME);
            break;
        }
        case(TiposVerbete::VERBO): {
            verbete->setTipo(TiposVerbete::VERBO);
            break;
        }
    }

    std::string significado = "";

    std::cout << "\nDigite um significado ou vazio para parar: ";

    std::getchar();
    std::getline(std::cin, significado);

    verbete->adicionarSignificado(significado);

    return verbete;
}
