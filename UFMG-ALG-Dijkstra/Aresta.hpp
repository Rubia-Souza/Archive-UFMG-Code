#ifndef ARESTA_HPP
#define ARESTA_HPP

#include "Vertice.hpp"

class Vertice;

class Aresta {
    private:
        unsigned int distancia = 0;
        Vertice* vizinho = nullptr;

    public:
        /**
         * @brief Cria um novo objeto Aresta
         * 
         * @param vizinho É o vizinho com que o Vértice que contém esta Aresta está associado
         * @param distancia É a distância do Vértice que contém esta Aresta está de seu vizinho
         */
        Aresta(Vertice* vizinho, const unsigned int distancia);

        /**
         * @brief Destroi objeto Aresta
         * 
         */
        ~Aresta();

        /**
         * @brief Retorna a distância entre o Vértice que contem essta Aresta até seu vizinho conectado por ela
         * 
         * @return unsigned int É a distância ao vizinho do Vértice que contém esta aresta
         */
        unsigned int getDistancia() const;

        /**
         * @brief Define a distância do Vértice que contem esta Aresta ao seu vizinho
         * 
         * @param distancia É a nova distância do Vértice que contem esta Aresta ao seu vizinho
         */
        void setDistancia(const unsigned int distancia);

        /**
         * @brief Retorna o vizinho conectado por esta aresta do Vértice que a contem
         * 
         * @return Vertice* É o vizinho conectado por esta aresta do Vértice que a contem
         */
        Vertice* getVizinho() const;

        /**
         * @brief Definie o vizinho que será conectado a esta aresta
         * 
         * @param vertice É o vizinho que será conectado a esta aresta
         */
        void setVizinho(const Vertice* vertice);
};

#endif
