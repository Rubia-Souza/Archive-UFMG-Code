#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include "Graph.hpp"
#include "Vertice.hpp"

class Dijkstra {
    public:
        /**
         * @brief Encontra o menor caminho entre um Vértice Inicial e um Vértice Final se exisitir
         * 
         * @param grafo É o grafo no qual o menor caminho será verificado
         * @param verticeInicial É o vertice em que irá iniciar a busca pelo menor caminho
         * @param verticeFinal É o vertice que indica a posição final do menor caminho
         * @return int É a distância do menor caminho do Vértice Inicial ao Vértice Final se existir. Caso contrário, retornará -1
         */
        static int EncontrarMenorCaminho(Graph* grafo, Vertice* verticeInicial, Vertice* verticeFinal);
    private:
        /**
         * @brief Verifica se um número é par
         * 
         * @param valor É o número que irá ser verificada a paridade
         * @return true Se o número for par
         * @return false Se o número for impar
         */
        static bool ehPar(const int valor);
};

#endif