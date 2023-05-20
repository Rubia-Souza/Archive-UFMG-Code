#include <iostream>
#include <limits>
#include <string>

#include "ListaEncadeada.h"
#include "Celula.h"
#include "Mensagem.h"

void printMenuLista();
unsigned int getOpcao();
void executarOpacoa(const unsigned int opcao, ListaEncadeada<Mensagem>* lista);
Mensagem* getMensagem();
unsigned int getIndex();
void printLista(const ListaEncadeada<Mensagem>& lista);

int main() {
    ListaEncadeada<Mensagem>* teste = new ListaEncadeada<Mensagem>();
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

    std::cout << "\n[1] Adicionar no inicio";
    std::cout << "\n[2] Adicionar na posição";
    std::cout << "\n[3] Adicionar no final";
    std::cout << "\n[4] Remover do comeco";
    std::cout << "\n[5] Remover de uma posicao";
    std::cout << "\n[6] Remover do fim";
    std::cout << "\n[7] Buscar elemento";
    std::cout << "\n[8] Verificar se esta vazia";
    std::cout << "\n[9] Limpar";
    std::cout << "\n[10] Exibir lista";
    std::cout << "\n[0] Sair";

    return;
}

unsigned int getOpcao() {
    unsigned int opcao = 0;

    std::cout << "\nDigite uma das opcoes: ";
    std::cin >> opcao;

    return opcao;
}

void executarOpacoa(const unsigned int opcao, ListaEncadeada<Mensagem>* lista) {
    switch (opcao) {
        case(1): {
            Mensagem* mensagem = getMensagem();

            lista->adicionarComeco(mensagem);
            break;
        }
        case(2): {
            Mensagem* mensagem = getMensagem();
            unsigned int posicao = getIndex();

            lista->adicionarNaPosicao(mensagem, posicao);
            break;
        }
        case(3): {
            Mensagem* mensagem = getMensagem();

            lista->adicionarFim(mensagem);
            break;
        }
        case(4): {
            lista->removerComeco();
            break;
        }
        case(5): {
            printLista(*lista);
            unsigned int index = getIndex();

            lista->remover(index);

            break;
        }
        case(6): {
            lista->removerFim();
            break;
        }
        case(7): {
            printLista(*lista);
            unsigned int index = getIndex();

            Mensagem* mensagem = lista->get(index);

            std::cout << "\n[" << mensagem->getPrioridade() << "]" << " Mensagem: " << mensagem->getTexto() << "\n";
            break;
        }
        case(8): {
            if(lista->estaVazia()) {
                std::cout << "\nLista esta vazia";
            }
            else {
                std::cout << "\nLista nao esta vazia";
            }

            break;
        }
        case(9): {
            lista->limpar();
            break;
        }
        case(10): {
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

void printLista(const ListaEncadeada<Mensagem>& lista) {
    if(lista.estaVazia()) {
        std::cout << "\nLista vazia!";
        return;
    }

    for(Celula<Mensagem>* iterador = lista.getInicio()->getProximaCelula(); iterador != lista.getFim(); iterador = iterador->getProximaCelula()) {
        std::cout << "\n[" << iterador->getValor()->getPrioridade() << "]" << " Mensagem: " << iterador->getValor()->getTexto();
    }

    return;
}
