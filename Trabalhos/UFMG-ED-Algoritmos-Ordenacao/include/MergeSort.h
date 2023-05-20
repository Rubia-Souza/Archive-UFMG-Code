#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "Registro.h"
#include "DadosDesempenho.h"

class MergeSort {
    private:
        MergeSort();

    public:
        virtual ~MergeSort();

        /**
         * @brief Realiaza a ordenação em ordem crescente por meio do algoritmo Merge Sort
         * 
         * @param vetor É o vetor que será ordenado
         * @param tamanho É o tamanho do vetor que será ordenado
         * @param dadosDesempenho É o objeto que irá armazenar os dados de desempenho da execução do algoritmo
         */
        static void ordenarCrescente(Registro vetor[], const unsigned int tamanho, DadosDesempenho& dadosDesemepnho);

        /**
         * @brief Realiaza a ordenação em ordem decrescente por meio do algoritmo Merge Sort
         * 
         * @param vetor É o vetor que será ordenado
         * @param tamanho É o tamanho do vetor que será ordenado
         * @param dadosDesempenho É o objeto que irá armazenar os dados de desempenho da execução do algoritmo
         */
        static void ordenarDecrescente(Registro vetor[], const unsigned int tamanho, DadosDesempenho& dadosDesemepnho);
    
    private:
        /**
         * @brief Realiza a separação do vetor ao meio e depois o unifica de forma ordenada
         * 
         * @param vetor É o vetor que será dividido
         * @param posicaoInicial É o ponto inicial do vetor atual
         * @param posicaoFinal É o ponto fnial do vetor atual
         * @param dadosDesemepnho É o objeto que irá armazenar os dados de desempenho da execução do algoritmo
         */
        static void mergeSortCrescente(Registro vetor[], const unsigned int posicaoInicial, const unsigned int posicaoFinal, DadosDesempenho& dadosDesemepnho);

        /**
         * @brief Realiza o merge dos subvetores criados em ordem crescente
         * 
         * @param vetor É o vetor que será ordenado
         * @param indexEsquerdo É o ponto inicial do vetor atual
         * @param indexMeio É o ponto do meio do vetor atual
         * @param indexDireito É o ponto final do vetor atual
         * @param dadosDesemepnho É o objeto que irá armazenar os dados de desempenho da execução do algoritmo
         */
        static void mergeCrescente(Registro vetor[], const int indexEsquerdo, const int indexMeio, const int indexDireito, DadosDesempenho& dadosDesemepnho);

        /**
         * @brief Realiza a separação do vetor ao meio e depois o unifica de forma ordenada
         * 
         * @param vetor É o vetor que será dividido
         * @param posicaoInicial É o ponto inicial do vetor atual
         * @param posicaoFinal É o ponto fnial do vetor atual
         * @param dadosDesemepnho É o objeto que irá armazenar os dados de desempenho da execução do algoritmo
         */
        static void mergeSortDecrescente(Registro vetor[], const unsigned int posicaoInicial, const unsigned int posicaoFinal, DadosDesempenho& dadosDesemepnho);

        /**
         * @brief Realiza o merge dos subvetores criados em ordem decrescente
         * 
         * @param vetor É o vetor que será ordenado
         * @param indexEsquerdo É o ponto inicial do vetor atual
         * @param indexMeio É o ponto do meio do vetor atual
         * @param indexDireito É o ponto final do vetor atual
         * @param dadosDesemepnho É o objeto que irá armazenar os dados de desempenho da execução do algoritmo
         */
        static void mergeDecrescente(Registro vetor[], const int indexEsquerdo, const int indexMeio, const int indexDireito, DadosDesempenho& dadosDesemepnho);
};

#endif
