#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>

#include "Vertice.hpp"

class Graph {
    private:
        unsigned int quantidadeBasicaCidades = 0;
        unsigned int quantidadeDerivadaCidades = 0;
        std::vector<Vertice*>* vertices = nullptr;

    public:
        /**
         * @brief Cria um novo objeto de Grafo
         * 
         * @param quantidadeVertices É a quantidade de Vértices alocados no Grafo
         */
        Graph(const unsigned int quantidadeVertices);

        /**
         * @brief Destroi o objeto Grafo
         * 
         */
        ~Graph();

        /**
         * @brief Adiciona uma aresta com duplo sentido do Vértice 1 para o Vértice 2
         * 
         * @details O Vertice1Par é ligado ao Vertice2Impar. Já o Vertice1Impar é ligado ao Vertice2Par. São criadas Arestas de ida e volta
         * 
         * @param idVertice1 É o id do Vértice 1 par
         * @param idVertice2 É o id do Vértice 2 par
         * @param distancia É a distância que haverá entre o Vértice 1 e o Vértice 2
         */
        void adicionarAresta(const unsigned int idVertice1, const unsigned int idVertice2, const unsigned int distancia);

        /**
         * @brief Retorna a Lista de Vértices presentes no Grafo
         * 
         * @return std::vector<Vertice*>* É a Lista de Vértice que o Grafo contem
         */
        std::vector<Vertice*>* getListaVertices() const;
};

#endif
