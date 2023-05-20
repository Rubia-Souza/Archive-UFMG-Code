#ifndef QUICK_SORT_ITERATIVO_H
#define QUICK_SORT_ITERATIVO_H

#include "Registro.h"
#include "DadosDesempenho.h"

class QuickSortIterativo {
    private:
        QuickSortIterativo();

    public:
        virtual ~QuickSortIterativo();

        /**
         * @brief Realiaza a ordenação em ordem crescente por meio do algoritmo Quick Sort Iterativo
         * 
         * @param vetor É o vetor que será ordenado
         * @param tamanho É o tamanho do vetor que será ordenado
         * @param dadosDesempenho É o objeto que irá armazenar os dados de desempenho da execução do algoritmo
         */
        static void ordenarCrescente(Registro vetor[], const unsigned int tamanho, DadosDesempenho& dadosDesempenho);

        /**
         * @brief Realiaza a ordenação em ordem decrescente por meio do algoritmo Quick Sort Iterativo
         * 
         * @param vetor É o vetor que será ordenado
         * @param tamanho É o tamanho do vetor que será ordenado
         * @param dadosDesempenho É o objeto que irá armazenar os dados de desempenho da execução do algoritmo
         */
        static void ordenarDecrescente(Registro vetor[], const unsigned int tamanho, DadosDesempenho& dadosDesempenho);
    
    private:
        /**
         * @brief Realiza as separações das faixas de ordenação do quick sort
         * 
         * @param vetor É o vetor que será ordenado
         * @param base É o ponto inicial do vetor atual
         * @param topo É o ponto final do vetor atual
         * @param dadosDesempenho É o objeto que irá armazenar os dados de desempenho da execução do algoritmo
         */
        static void quickSortCrescente(Registro vetor[], int base, int topo, DadosDesempenho& dadosDesempenho);

        /**
         * @brief Realiza a partição da faixa atual do vetor com base no pivo em ordem crescente
         * 
         * @param vetor É o vetor que será ordenado
         * @param base É o ponto inicial do vetor atual
         * @param topo É o ponto final do vetor atual 
         * @param dadosDesempenho É o objeto que irá armazenar os dados de desempenho da execução do algoritmo 
         */
        static int particionarCrescente(Registro vetor[], int base, int topo, DadosDesempenho& dadosDesempenho);

        /**
         * @brief Realiza as separações das faixas de ordenação do quick sort
         * 
         * @param vetor É o vetor que será ordenado
         * @param base É o ponto inicial do vetor atual
         * @param topo É o ponto final do vetor atual
         * @param dadosDesempenho É o objeto que irá armazenar os dados de desempenho da execução do algoritmo
         */
        static void quickSortDecrescente(Registro vetor[], int base, int topo, DadosDesempenho& dadosDesempenho);
        
        /**
         * @brief Realiza a partição da faixa atual do vetor com base no pivo em ordem decrescente
         * 
         * @param vetor É o vetor que será ordenado
         * @param base É o ponto inicial do vetor atual
         * @param topo É o ponto final do vetor atual 
         * @param dadosDesempenho É o objeto que irá armazenar os dados de desempenho da execução do algoritmo 
         */
        static int particionarDecrescente(Registro vetor[], int base, int topo, DadosDesempenho& dadosDesempenho);
};

#endif
