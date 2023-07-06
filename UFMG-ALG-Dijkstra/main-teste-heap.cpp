#include <iostream>

#include "Vertice.hpp"
#include "HeapMinimo.hpp"

int testemain(int argc, char const *argv[]) {

    unsigned int opcao = 0;
    unsigned int contadorVertice = 1;
    HeapMinimo heap(1000);

    do {
        std::cout << "[1] Adicionar\n"
                  << "[2] Remover Primeiro\n"
                  << "[3] Atualizar\n"
                  << "[0] Sair\n";

        std::cin >> opcao;

        switch(opcao) {
            case(1): {
                unsigned int distancia = 0;

                std::cout << "\nDigite a distancia: ";
                std::cin >> distancia;

                heap.adicionar(new Vertice(contadorVertice), distancia);

                contadorVertice++;
                break;
            }
            case(2): {
                Vertice* vertice = heap.popMenor();

                std::cout << "\nVertice: " << vertice->getId() << "\n";

                delete vertice;
                break;
            }
            case(3): {
                unsigned int id;
                std::cout << "\nDigite o id vertice: ";
                std::cin >> id;

                unsigned int distancia;
                std::cout << "\nDigite a distancia do vertice: ";
                std::cin >> distancia;

                heap.atualizar(new Vertice(id), distancia);

                break;
            }
        }

        heap.printHeap();
    } while(opcao != 0);

    return 0;
}