#ifndef VERTICE_GULOSO_HPP
#define VERTICE_GULOSO_HPP

#include <vector>
#include <string>

class VerticeGuloso {
    private:
        std::string nome = "";
        std::vector<VerticeGuloso*>* vizinhos = nullptr;

        unsigned int quantidadePossibilidades = 0;

    public:
        /**
         * @brief Cria uma instância de um vértice guloso
         * 
         * @details Este vértice só pode ser usado para o Grafo e para a Solução Gulosa
         * 
         * @param nome É o nome que identifica o vértice
         */
        VerticeGuloso(const std::string nome);

        /**
         * @brief Destroi a instância do vértice
         * 
         */
        virtual ~VerticeGuloso();

        /**
         * @brief Define o nome do vértice
         * 
         * @param nome É o novo nome do vértice
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
         * @param vizinho É o novo vizinho do vértice
         */
        void adicionarVizinho(VerticeGuloso* vizinho);

        /**
         * @brief Retorana a lista de vizinhos do vértice
         * 
         * @return std::vector<VerticeGuloso*>* É a lista de vizinhos do vértice
         */
        std::vector<VerticeGuloso*>* getVizinhos();

        /**
         * @brief Define a quantidade de vértices disponíveis que podem ser agrupados com o vértice atual
         * 
         * @param novaQuantidade É a nova quantidade de vértices que podem ser agrupados com o vértice atual
         */
        void setQuantidadePossibilidades(const unsigned int novaQuantidade);

        /**
         * @brief Retorna a quantidade de vértices disponíveis que podem ser agrupados com o vértice atual
         * 
         * @return unsigned int É a quantidade de vértices disponíveis que podem ser agrupados com o vértice atual
         */
        unsigned int getQuantidadePossibilidades() const;
};

#endif