#ifndef PILHA_H
#define PILHA_H

#include "Celula.h"
#include "FaixaOrdenacao.h"

class Pilha {
    private:
        Celula* topo = nullptr;
        Celula* base = nullptr;
        unsigned int tamanho = 0;

    public:
        /**
         * @brief Cria um objeto Pilha
         * 
         */
        Pilha();

        /**
         * @brief Destroi o objeto pilha
         * 
         */
        virtual ~Pilha();

        /**
         * @brief Adiciona uma faixa de ordenação ao topo da pilha
         * 
         * @param faixa É o objeto que será empilhado
         */
        void empilhar(FaixaOrdencao faixa);

        /**
         * @brief Remove o objeto do topo da pilha
         * 
         * @return FaixaOrdencao* É o objeto removido da pilha
         */
        FaixaOrdencao* desempilhar();

        /**
         * @brief Verifica se a pilha está vazia
         * 
         * @return true Informa que a pilha está vazia
         * @return false Informa que a pilha não está vazia
         */
        bool estaVazia();

        /**
         * @brief Retorna o tamanho da pilha
         * 
         * @return unsigned int É o tamanho da pilha
         */
        unsigned int getTamanho();

        /**
         * @brief Desempilha todos elementos da pilha
         * 
         */
        void limpar();

        /**
         * @brief Printa todos elementos da pilha no terminal
         * 
         */
        void print() const;
};

#endif
