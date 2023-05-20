#ifndef CAIXA_MENSAGENS_H
#define CAIXA_MENSAGENS_H

#include <string>

#include "FilaPrioridade.h"
#include "Mensagem.h"

class CaixaMensagens {
    private:
        static const std::string MENSAGEM_ERRO_CONSULTAR_MENSAGEM_CAIXA_ENTRADA_VAZIA;
        FilaPrioridade<Mensagem>* mensagens = nullptr;

    public:
        /**
         * @brief Cria o objeto de CaixaMensagens
         * 
         */
        CaixaMensagens();

        /**
         * @brief Destroi a CaixaMensagens
         * 
         */
        virtual ~CaixaMensagens();

        /**
         * @brief Armazena uma mensagem na Caixa de Mensagens
         * 
         * @param mensagem É a mensagem que será armazenada
         */
        void guardarMensagem(const Mensagem mensagem);

        /**
         * @brief Remove e retorna a mensagem mais antiga e com maior prioridade na Caixa de Mensagens
         * 
         * @return Mensagem É a mensagem com maior prioridade e mais antiga
         */
        Mensagem consultarMensagem();

        /**
         * @brief Retorna todas as mensagens da Caixa de Entrada
         * 
         * @return FilaPrioridade<Mensagem>* São todoas a mensagens Armazenadas na Caixa de Entrada
         */
        FilaPrioridade<Mensagem>* getMensagens() const;

        /**
         * @brief Retorna a Quantidade Mensagens na Caixa de Entrada
         * 
         * @return unsigned int É a Quantidade de Mensagens na Caixa de Entrada
         */
        unsigned int getQuantidadeMensagens() const;
};

#endif
