#ifndef ARESTA_EXATO_HPP
#define ARESTA_EXATO_HPP

#include "VerticeExato.hpp"
#include "TipoArestaExata.hpp"

class VerticeExato;

class ArestaExato {
    private:
        unsigned int capacidade = 0;
        unsigned int fluxoAtual = 0;
        
        VerticeExato* vizinho = nullptr;
        ArestaExato* arestaAssociada = nullptr;

        TipoArestaExata tipo = TipoArestaExata::Padrao;

    public:
        /**
         * @brief Cria uma instância de uma aresta do grafo exato
         * 
         * @details Esta aresta só deve ser utilizada para o grafo da solução exata
         * 
         * @param vizinho É o vizinho do vértice que contém esta aresta
         */
        ArestaExato(VerticeExato* vizinho);

        /**
         * @brief Destroi a instancia da aresta
         * 
         */
        virtual ~ArestaExato();

        /**
         * @brief Definie o vizinho que será conectado a esta aresta
         * 
         * @param vertice É o vizinho que será conectado a esta aresta
         */
        void setVizinho(VerticeExato* vizinho);

        /**
         * @brief Retorna o vizinho conectado por esta aresta do Vértice que a contem
         * 
         * @return Vertice* É o vizinho conectado por esta aresta do Vértice que a contem
         */
        VerticeExato* getVizinho();

        /**
         * @brief Define o valor da cpacidade da aresta. Ou seja, o máximo de fluxo que pode
         * passar por ela
         * 
         * @param capacidade É o novo valor da capacidade para a aresta
         */
        void setCapacidade(const unsigned int capacidade);

        /**
         * @brief Retorna a capacidade atual da aresta
         * 
         * @return unsigned int É o valor da capacidade da aresta
         */
        unsigned int getCapacidade() const;

        /**
         * @brief Define a quantidade de fluxo que irá passar pela aresta
         * 
         * @details O fluxo definido por este método não irá afetar a aresta associada
         * 
         * @param fluxo É o fluxo que irá passar pela aresta
         */
        void setFluxoAtual(const unsigned int fluxo);

        /**
         * @brief Retorna a quantidade atual de fluxo que está passando pelo aresta
         * 
         * @return unsigned int É a quantidade atual de fluxo que está passando pelo aresta
         */
        unsigned int getFluxo() const;

        /**
         * @brief Define qual a aresta associada a atual
         * 
         * @details Uma aresta padrão estará associada a uma aresta residual, de modo que 
         * o fluxo que passa pela primeira é igual a capacidade da segunda
         * 
         * @details Uma aresta residual estará associada a uma aresta padrão, de modo que 
         * a capacidade da primeira é igual ao fluxo que passa pela segunda
         * 
         * @param arestaAssociada É a aresta que será associada a atual
         */
        void setArestaAssociada(ArestaExato* arestaAssociada);

        /**
         * @brief Retorna a aresta associada a atual
         * 
         * @return ArestaExato* É a aresta associada a atual
         */
        ArestaExato* getArestaAssociada();

        /**
         * @brief Define o tipo da aresta
         * 
         * @details A aresta pode ser uma aresta residual ou padrão
         * 
         * @param tipo É o tipo da aresta
         */
        void setTipo(const TipoArestaExata tipo);

        /**
         * @brief Retorna o tipo da aresta
         * 
         * @details A aresta pode ser uma aresta residual ou padrão
         * 
         * @return TipoArestaExata É o tipo da aresta
         */
        TipoArestaExata getTipo() const;

        /**
         * @brief Retorna a quantidade de fluxo que pode passar por esta aresta
         * 
         * @details A quantidade de fluxo disponível que pode ser passado pela aresta é dado pela
         * capacidade menos a quantidade de fluxo atual que passa por ela
         * 
         * @return int É a quantidade de fluxo disponível que pode ser passado pela aresta
         */
        int getFluxoDisponivel() const;

        /**
         * @brief Atualiza o valor da aresta e da sua respectiva aresta associada ao novo
         * valor de fluxo que foi adicionado a ela
         * 
         * @details Caso seja uma aresta padrão, o fluxo atual dela é incrementado e a
         * capacidade da sua aresta residual (assocaida) é incrementada
         * 
         * @details Caso seja uma aresta residual, a capacidade dela é decrementada e o
         * fluxo atual que passa pela aresta padrão associada a ela é decrementado
         * 
         * @param fluxo É a quantidade de fluxo que será adicionado a aresta
         */
        void incrementarFluxo(const unsigned int fluxo);
};

#endif