#ifndef SOLUCAO_GULOSA_HPP
#define SOLUCAO_GULOSA_HPP

#include "GrafoGuloso.hpp"

class SolucaoGulosa {
    private:
        SolucaoGulosa();

    public:
        virtual ~SolucaoGulosa();

        /**
         * @brief Encontra a maior quantidade aproximada de pares que podem ser formados entre trabalhadores e empregos
         * 
         * @details Este método utiliza uma métrica para agrupar primeiro os empregos e trabalhadores que possuem menos possibildades, reduzindo a chance de que hajam escolhas erradas. 
         * Para isso, ele utiliza um Heap Binário Mínimo a fim de manter a ordem dos empregos que possuem menos trabalhadores candidatos. 
         * Para cada emprego, ele seleciona o trabalhador disponível que pode atuar em menos empregos. 
         * 
         * @details Comlexidade: O((m + n) * log(n)), sendo "m" a quantidade de arestas e "n" a quantidade de vértices
         * 
         * @details Este algoritmo é apenas uma aproximação e não garante resultados exatos para todos os casos
         * 
         * @details A precisão deste algortimo foi maior em comparação com o método EncontrarMaximumMatchingSemPrioridade(). O seu resultado para os 13 testes disponíveis foi de 100%
         * 
         * @param grafo É o grafo que será aplicado o algoritmo para encontrar os pares
         * @return unsigned int É a maior quantidade de pares estimada pelo algoritmo
         */
        static unsigned int EncontrarMaximumMatchingComPrioridade(GrafoGuloso* grafo);

        /**
         * @brief Encontra a maior quantidade aproximada de pares que podem ser formados entre trabalhadores e empregos
         * 
         * @details Para cada emprego, este método agrupa o primeiro trabalhador disponível ligado a ele que encontrar sem dar prioridade a nenhum vértice.
         * 
         * @details Comlexidade: O(m + n), sendo "m" a quantidade de arestas e "n" a quantidade de vértices
         * 
         * @details Este algoritmo é apenas uma aproximação e não garante resultados exatos para todos os casos
         * 
         * @details A precisão deste algortimo foi menor em comparação com o método EncontrarMaximumMatchingComPrioridade(). O seu resultado para os 13 testes disponíveis foi de 93.5885%
         * 
         * @param grafo É o grafo que será aplicado o algoritmo para encontrar os pares
         * @return unsigned int É a maior quantidade de pares estimada pelo algoritmo
         */
        static unsigned int EncontrarMaximumMatchingSemPrioridade(GrafoGuloso* grafo);
};

#endif