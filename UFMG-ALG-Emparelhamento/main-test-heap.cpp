#include <iostream>
#include <string>

#include "VerticeGuloso.hpp"
#include "HeapMinimo.hpp"

int main_test_heap(int argc, char const *argv[]) {
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
                std::string nome = "";
                std::cout << "\nDigite o nome: ";
                std::cin >> nome;

                unsigned int possibilidades = 0;
                std::cout << "\nDigite a quantidade de possibilidades: ";
                std::cin >> possibilidades;

                VerticeGuloso* novoVertice = new VerticeGuloso(nome);
                novoVertice->setQuantidadePossibilidades(possibilidades);
                heap.adicionar(novoVertice);

                contadorVertice++;
                break;
            }
            case(2): {
                VerticeGuloso* vertice = heap.popMenor();

                std::cout << "\nVertice: " << vertice->getNome() << "\n";

                delete vertice;
                break;
            }
            case(3): {
                std::string nome = "";
                std::cout << "\nDigite o nome do vertice: ";
                std::cin >> nome;

                unsigned int possibilidades = 0;
                std::cout << "\nDigite a nova quantidade de possibilidades do vertice: ";
                std::cin >> possibilidades;

                VerticeGuloso* verticeAtualizacao = new VerticeGuloso(nome);
                verticeAtualizacao->setQuantidadePossibilidades(possibilidades);
                heap.atualizar(verticeAtualizacao);

                break;
            }
        }

        heap.printHeap();
    } while(opcao != 0);

    return 0;
}