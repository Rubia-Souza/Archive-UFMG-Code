#ifndef VERTICE_HPP
#define VERTICE_HPP

#include <vector>

#include "Aresta.hpp"

class Aresta;

class Vertice {
    private:
        int id = 0;
        std::vector<Aresta*>* vizinhos = nullptr;

    public:
        /**
         * @brief Cria um novo objeto do tipo Vértice
         * 
         * @param id É o identificador do vértice
         */
        Vertice(const int id);

        /**
         * @brief Destroi o objeto do tipo Vértice
         * 
         */
        ~Vertice();

        /**
         * @brief Adiciona uma Aresta entre o Vértice atual e o informado com a distância fornecida
         * 
         * @param vertice É o Vértice que se tornará vizinho do atual
         * @param distancia É a distância do Vértice atual para seu novo vizinho
         */
        void adicionarAresta(Vertice* vertice, const unsigned int distancia);

        /**
         * @brief Retorna o identificador do Vértice
         * 
         * @return int É o identificador do Vértice
         */
        int getId() const;

        /**
         * @brief Retorna todas as Arestas incedêntes no Vértice
         * 
         * @return std::vector<Aresta*>* São todas as Aresta incidêntes no Vértice
         */
        std::vector<Aresta*>* getArestaParaVinhos();
};

#endif
