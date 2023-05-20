#ifndef USUARIO_H
#define USUARIO_H

#include <string>

#include "Mensagem.h"
#include "CaixaMensagens.h"
#include "FilaPrioridade.h"

class Usuario {
    private:
        unsigned int id = 0;
        CaixaMensagens caixaMensagens;

    public:
        /**
         * @brief Cria o objeto de Usuário
         * 
         */
        Usuario();

        /**
         * @brief Cria o objeto de Usuário
         * 
         * @param id É o identificador do usuário
         */
        Usuario(const unsigned int id);

        /**
         * @brief Destroi o objeto Usuário
         * 
         */
        virtual ~Usuario();

        /**
         * @brief Armazena uma mensagem em sua Caixa de Mensagens
         * 
         * @param mensagem É a mensagem que será armazenada
         */
        void receberMensagem(const Mensagem mensagem);

        /**
         * @brief Verifica a primeira mensagem da Caixa de Mensagens
         * 
         * @return Mensagem É a mensagem com maior prioridade e mais antiga na Caixa de Mensagens
         */
        Mensagem consultarMensagem();

        /**
         * @brief Retorna todas as Mensagens do Usuário
         * 
         * @return FilaPrioridade<Mensagem> São todas as Mensagens presente na Caixa de Mensagens
         */
        FilaPrioridade<Mensagem> getMensagens();

        /**
         * @brief Define o Id do usuário
         * 
         * @param id É o novo Id do usuário
         */
        void setId(const unsigned int id);

        /**
         * @brief Retornoa o Id do Usuário
         * 
         * @return unsigned int É o Id do usuário
         */
        unsigned int getId() const;

        bool operator==(const Usuario& outroUsuario);
        bool operator!=(const Usuario& outroUsuario);
};

#endif
