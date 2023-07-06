#ifndef GRAFO_GULOSO_HPP
#define GRAFO_GULOSO_HPP

#include <unordered_map>
#include <string>

#include "VerticeGuloso.hpp"

class GrafoGuloso {
    private:
        std::unordered_map<std::string, VerticeGuloso*>* trabalhadores = nullptr;
        std::unordered_map<std::string, VerticeGuloso*>* empregos = nullptr;
        std::unordered_map<std::string, VerticeGuloso*>* listaCompletaVertices = nullptr;

    public:
        /**
         * @brief Cria um grafo para ser utilizado pela solução gulosa
         * 
         */
        GrafoGuloso();

        /**
         * @brief Destroi a instância do GrafoGuloso
         * 
         */
        virtual ~GrafoGuloso();

        /**
         * @brief Adiciona um novo vértice ao conjunto daqueles que representam trabalhadores
         * 
         * @param nome É o nome do trabalhador que identificará o vértice
         */
        void adicionarTrabalhador(const std::string nome);

        /**
         * @brief Adiciona um novo vértice ao conjunto daqueles que representam empregos
         * 
         * @param nome É o nome do emprego que identificará o vértice
         */
        void adicionarEmprego(const std::string nome);

        /**
         * @brief Adiciona uma aresta do trabalhador para o emprego especificado e vice-versa
         * 
         * @param nomeEmprego É o nome do emprego que será ligado ao trabalhador
         * @param nomeTrabalhador É o nome do trabalhador que será ligado ao emprego
         */
        void adicionarQualificacao(const std::string nomeEmprego, const std::string nomeTrabalhador);

        /**
         * @brief Retorna a lista de todos os vértice de trabalhadores
         * 
         * @return std::unordered_map<std::string, VerticeGuloso*>* É a lista de todos os vértice de trabalhadores
         */
        std::unordered_map<std::string, VerticeGuloso*>* getListaTrabalhadores();

        /**
         * @brief Retorna a lista de todos os vértice de empregos
         * 
         * @return std::unordered_map<std::string, VerticeGuloso*>* É a lista de todos os vértice de empregos
         */
        std::unordered_map<std::string, VerticeGuloso*>* getListaEmpregos();

        /**
         * @brief Retorna a lista de todos os vértices do grafo
         * 
         * @return std::unordered_map<std::string, VerticeGuloso*>* É a lista de todos os vértice do grafo
         */
        std::unordered_map<std::string, VerticeGuloso*>* getListaVertices();
};

#endif