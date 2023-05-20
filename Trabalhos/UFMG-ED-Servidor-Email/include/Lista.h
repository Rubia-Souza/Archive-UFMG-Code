#ifndef LISTA_H
#define LISTA_H

#include <string>

class Lista {
    protected:
        static const std::string MENSAGEM_ERRO_AO_ADICIONAR_ITEM;
        static const std::string MENSAGEM_ERRO_AO_REMOVER_ITEM;
        static const std::string MENSAGEM_ERRO_AO_BUSCAR_ITEM;
        static const std::string MENSAGEM_ERRO_POSICAO_INVALIDA;

        unsigned int tamanho = 0;

    public:
        /**
         * @brief Destroy o objeto Lista
         * 
         */
        virtual ~Lista() {}

        /**
         * @brief Remove todos os itens da lista
         * 
         */
        void virtual limpar() = 0;

        /**
         * @brief Retorna o tamanho da lista
         * 
         * @return unsigned int é o tamanho da lista
         */
        unsigned int virtual getTamanho() const {
            return tamanho;
        }

        /**
         * @brief Verifica se a lista está vazia
         * 
         * @return true A lista está vazia
         * @return false A lista não está vazia
         */
        bool virtual estaVazia() const {
            return (getTamanho() == 0);
        }
};

#endif
