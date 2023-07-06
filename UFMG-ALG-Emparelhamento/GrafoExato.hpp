#ifndef GRAFO_EXATO_HPP
#define GRAFO_EXATO_HPP

#include <unordered_map>
#include <string>

#include "VerticeExato.hpp"

class GrafoExato {
    private:
        static const std::string NOME_FONTE;
        static const std::string NOME_SUMIDOURO;
        
        VerticeExato* fonte = nullptr;
        VerticeExato* sumidouro = nullptr;
        
        std::unordered_map<std::string, VerticeExato*>* listaEmpregos = nullptr;
        std::unordered_map<std::string, VerticeExato*>* listaTrabalhadores = nullptr;
        std::unordered_map<std::string, VerticeExato*>* listaCompletaVertices = nullptr;

    public:
        /**
         * @brief Cria um grafo para ser utilizado pela solução exata
         * 
         * @details Este grafo será adaptado com a criação de dois novos vértices, a fonte e o sumidouro.
         * Todos os trabalhadores estarão ligados a fonte e todos os empregos estarão ligados ao sumidouro.
         * 
         */
        GrafoExato();

        /**
         * @brief Destroi a instância do GrafoExato
         * 
         */
        virtual ~GrafoExato();

        /**
         * @brief Adiciona um novo vértice ao conjunto daqueles que representam trabalhadores e o liga a fonte
         * com uma aresta de capacidade 1
         * 
         * @details A aresta terá o sentido da fonte para o trabalhador. Além disso, é criada uma aresta residual
         * com capacidade 0 no sentido oposto
         * 
         * @param nome É o nome do trabalhador que identificará o vértice
         */
        void adicionarTrabalhador(const std::string nome);

        /**
         * @brief Adiciona um novo vértice ao conjunto daqueles que representam empregos e o liga ao sumidouro
         * com uma aresta de capacidade 1
         * 
         * @details A aresta terá o sentido do emprego para o sumidouro. Além disso, é criada uma aresta residual
         * com capacidade 0 no sentido oposto
         * 
         * @param nome É o nome do emprego que identificará o vértice
         */
        void adicionarEmprego(const std::string nome);

        /**
         * @brief Adiciona uma aresta do trabalhador para o emprego especificado com capacidade 1
         * 
         * @details Além disso, é criada uma aresta residual com capacidade 0 no sentido oposto
         * 
         * @param nomeEmprego É o nome do emprego que será ligado ao trabalhador por uma aresta residual
         * @param nomeTrabalhador É o nome do trabalhador que será ligado ao emprego por uma aresta padrão
         */
        void adicionarQualificacao(const std::string nomeEmprego, const std::string nomeTrabalhador);

        /**
         * @brief Retorna o vértice da fonte do grafo
         * 
         * @return VerticeExato* É o vértice que é a fonte do fluxo
         */
        VerticeExato* getFonte();

        /**
         * @brief Retorna o vértice do sumidouro do grafo
         * 
         * @return VerticeExato* É o vértice que é o sumidouro (fim) do fluxo
         */
        VerticeExato* getSumidouro();

        /**
         * @brief Retorna a lista de todos os vértice de trabalhadores
         * 
         * @return std::unordered_map<std::string, VerticeGuloso*>* É a lista de todos os vértice de trabalhadores
         */
        std::unordered_map<std::string, VerticeExato*>* getListaEmpregos();

        /**
         * @brief Retorna a lista de todos os vértice de empregos
         * 
         * @return std::unordered_map<std::string, VerticeGuloso*>* É a lista de todos os vértice de empregos
         */
        std::unordered_map<std::string, VerticeExato*>* getListaTrabalhadores();

        /**
         * @brief Retorna a lista de todos os vértices do grafo
         * 
         * @return std::unordered_map<std::string, VerticeGuloso*>* É a lista de todos os vértice do grafo
         */
        std::unordered_map<std::string, VerticeExato*>* getListaCompletaVertices();
};

#endif