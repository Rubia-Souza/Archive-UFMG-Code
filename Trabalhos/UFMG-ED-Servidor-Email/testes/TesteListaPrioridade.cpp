#include <iostream>
#include <limits>
#include <string>

#include "FilaPrioridade.h"
#include "CelulaPrioridade.h"
#include "Mensagem.h"

void printMenuLista();
unsigned int getOpcao();
void executarOpacoa(const unsigned int opcao, FilaPrioridade<Mensagem>* lista);
Mensagem* getMensagem();
unsigned int getIndex();
void printLista(const FilaPrioridade<Mensagem>& lista);

int main() {
    FilaPrioridade<Mensagem>* teste = new FilaPrioridade<Mensagem>();
    unsigned int opcao = 0;
    
    do {
        printMenuLista();
        opcao = getOpcao();

        executarOpacoa(opcao, teste);
    } while(opcao);

    delete teste;
    return 0;
}

void printMenuLista() {
    std::cout << "\n--------------------\n";

    std::cout << "\n[1] Adicionar";
    std::cout << "\n[2] Buscar elemento";
    std::cout << "\n[3] Verificar se esta vazia";
    std::cout << "\n[4] Limpar";
    std::cout << "\n[5] Exibir lista";
    std::cout << "\n[0] Sair";

    return;
}

unsigned int getOpcao() {
    unsigned int opcao = 0;

    std::cout << "\nDigite uma das opcoes: ";
    std::cin >> opcao;

    return opcao;
}

void executarOpacoa(const unsigned int opcao, FilaPrioridade<Mensagem>* lista) {
    switch (opcao) {
        case(1): {
            Mensagem* mensagem = getMensagem();

            lista->adicionar(mensagem, mensagem->getPrioridade());
            break;
        }
        case(2): {
            printLista(*lista);
            unsigned int index = getIndex();

            Mensagem* mensagem = lista->get(index);

            std::cout << "\n[" << mensagem->getPrioridade() << "]" << " Mensagem: " << mensagem->getTexto() << "\n";
            break;
        }
        case(3): {
            if(lista->estaVazia()) {
                std::cout << "\nLista esta vazia";
            }
            else {
                std::cout << "\nLista nao esta vazia";
            }

            break;
        }
        case(4): {
            lista->limpar();
            break;
        }
        case(5): {
            printLista(*lista);
            break;
        }
    }

    printLista(*lista);
    return;
}

Mensagem* getMensagem() {
    std::string texto = "";
    unsigned int prioridade = 0;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\nDigite o texto que deseja salvar: ";
    std::getline(std::cin, texto);
    
    std::cout << "\nDigite a prioridade da mensagem: ";
    std::cin >> prioridade;

    return new Mensagem(texto, prioridade);
}

unsigned int getIndex() {
    unsigned int index = 0;

    std::cout << "\nO index que deseja: ";
    std::cin >> index;

    return index;
}

void printLista(const FilaPrioridade<Mensagem>& lista) {
    if(lista.estaVazia()) {
        std::cout << "\nLista vazia!";
        return;
    }

    for(CelulaPrioridade<Mensagem>* iterador = lista.getInicio()->getProximaCelula(); iterador != lista.getFim(); iterador = iterador->getProximaCelula()) {
        std::cout << "\n[" << iterador->getValor()->getPrioridade() << "]" << " Mensagem: " << iterador->getValor()->getTexto();
    }

    return;
}
