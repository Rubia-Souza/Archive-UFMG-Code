#ifndef VERTICE_EXATO_HPP
#define VERTICE_EXATO_HPP

#include <vector>
#include <string>

#include "ArestaExato.hpp"

class ArestaExato;

class VerticeExato {
    private:
        std::string nome = "";
        std::vector<ArestaExato*>* vizinhos = nullptr;

    public:
        /**
         * @brief Cria um novo vértice com um determinado nome
         * 
         * @details Este vértice só pode ser usado para a solução e para o grafo exato
         * 
         * @param nome É o nome que será utilizado par identificar o vértice
         */
        VerticeExato(const std::string nome);

        /**
         * @brief Destroi a instância do vértice atual
         * 
         */
        virtual ~VerticeExato();

        /**
         * @brief Define o nome que irá identificar o vértice
         * 
         * @param nome É o nome que identificará o vértice
         */
        void setNome(const std::string nome);

        /**
         * @brief Retorna o nome do vértice
         * 
         * @return std::string É o nome do vértice
         */
        std::string getNome() const;

        /**
         * @brief Adiciona um vizinho ao vértice
         * 
         * @param vizinho É o novo vizinho para o vértice
         */
        void adicionarVizinho(ArestaExato* arestaParaVizinho);

        /**
         * @brief Retoran a lista de vizinhos do vértice
         * 
         * @return std::vector<VerticeGuloso*>* É a lista de vizinhos do vértice
         */
        std::vector<ArestaExato*>* getVizinhos();
};

#endif