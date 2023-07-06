#ifndef SOLUCAO_EFICIENTE_HPP
#define SOLUCAO_EFICIENTE_HPP

#include "GrafoExato.hpp"
#include "VerticeExato.hpp"

class SolucaoExata {
    private:
        SolucaoExata();

    public:
        virtual ~SolucaoExata();

        /**
         * @brief Encontra a maior quantidade de pares que podem ser formados entre empregos e trabalhadores
         * 
         * @details Este método encontra a solução por meio do algoritmo de flxuo de Ford Fulkerson com uma DFS
         * 
         * @details O resultado obtido por este algoritmo é um resultado exato para o problema
         * 
         * @details Complexidade: O(m * f), sendo "m" a quantidade de arestas e "f" o valor do fluxo máximo.
         * A complexidade, muitas vezes, será melhor que no pior caso, pois, como as arestas possuem peso
         * unitário, não ocorrerá o caso em que o mesmo caminho aumentante será repetido diversas vezes até
         * ser preenchido completamente. Assim, cada ajuste no fluxo passará por um novo caminho aumentante
         * 
         * @param grafo É o grafo exato adaptado em que será aplicada a solução
         * @return unsigned int É a maior quantidade possível de pares que podem ser formados
         */
        static unsigned int EncontrarMaximumMatchingFordFulkerson(GrafoExato* grafo);

        /**
         * @brief Encontra a maior quantidade de pares que podem ser formados entre empregos e trabalhadores
         * 
         * @details Este método encontra a solução por meio do algoritmo de flxuo de Edemonds Karp, que utiliza uma BFS
         * 
         * @details O resultado obtido por este algoritmo é um resultado exato para o problema
         * 
         * @details Complexidade: O(n * m^2), sendo "n" a quantidade de vértices e "m" a quantidade de arestas.
         * O benefício deste algoritmo é que ele é independente do fluxo máximo. No entanto, como as arestas possuem
         * capacidade 1, é nótavel uma diferença de desempenho em relação ao Ford Fulkerson.
         * 
         * @param grafo É o grafo exato adaptado em que será aplicada a solução
         * @return unsigned int É a maior quantidade possível de pares que podem ser formados
         */
        static unsigned int EncontrarMaximumMatchingEdmondsKarp(GrafoExato* grafo);
    
    private:
        /**
         * @brief Executa uma DFS para encontrar um caminho aumentante e incrementar o fluxo das suas arestas
         * 
         * @param vertice É o vértice atual do fluxo, iniciando na fonte
         * @param menorFluxoDisponivel É a menor distância encontrada até então
         * @param sumidouro É o vértice final do fluxo
         * @param registroVisitados É o registro de marcação de vértices como já visitados para auxliar a DFS
         * @param passoAtual É o indicador do vértice que já foi vizitado ou não. Aqueles que já foram visitados, 
         * possuem o mesmo valor do passo atual no registroVisitados em sua respectiva posição
         * @return int É o valor do menor fluxo disponível encontrado durante o caminho aumentante
         */
        static int EncontrarMenorFluxoDFS(VerticeExato* vertice, const int menorFluxoDisponivel, const VerticeExato* sumidouro, std::unordered_map<std::string, unsigned int>& registroVisitados, const unsigned int passoAtual);

        /**
         * @brief Executa uma BFS para encontrar um caminho aumentante e incrementar o fluxo das suas arestas
         * 
         * @param fonte É o vértice inicial do fluxo
         * @param sumidouro É o vértice final do fluxo
         * @param registroVisitados É o registro de marcação de vértices como já visitados para auxliar a BFS
         * @param passoAtual É o indicador do vértice que já foi vizitado ou não. Aqueles que já foram visitados, 
         * possuem o mesmo valor do passo atual no registroVisitados em sua respectiva posição
         * @return int É o valor do menor fluxo disponível encontrado durante o caminho aumentante
         */
        static int EncontrarMenorFluxoBFS(VerticeExato* fonte, const VerticeExato* sumidouro, std::unordered_map<std::string, unsigned int>& registroVisitados, const unsigned int passoAtual);
};

#endif