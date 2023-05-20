#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <string>

#include "ListaEncadeada.h"
#include "Usuario.h"
#include "Mensagem.h"

class Servidor {
    private:
        static const std::string MENSAGEM_ERRO_CADASTRO_USUARIO;
        static const std::string MENSAGEM_ERRO_REMOVER_USUARIO;
        static const std::string MENSAGEM_ERRO_ENTREGAR_MENSAGEM;
        static const std::string MENSAGEM_ERRO_CONSULTAR_MENSAGEM_USUARIO_NAO_ENCONTRADO;
        
        ListaEncadeada<Usuario>* usuarios = nullptr;

    public:
        /**
         * @brief Cria o objeto de Servidor
         * 
         */
        Servidor();

        /**
         * @brief Destroi o objeto Servidor
         * 
         */
        virtual ~Servidor();

        /**
         * @brief Cadastra um novo usuário no servidor
         * 
         * @param id É o id do usuário que será cadastrado
         */
        void cadastrarNovoUsuario(const unsigned int id);

        /**
         * @brief Remove um usuário do servidor
         * 
         * @param id É o id do usuário que será removido
         */
        void removerUsuario(const unsigned int id);

        /**
         * @brief Envia uma mensagem para um determinado usuário
         * 
         * @param id É o id do usuário que receberá a mensagem
         * @param mensagem É a mensagem que será enviada para o usuário
         */
        void entregarMensagem(const unsigned int id, const Mensagem mensagem);

        /**
         * @brief Retorna a primeira mensagem da Caixa de Mensagens de um determinado usuário
         * 
         * @param id É o usuário que irá verificar a sua Caixa de Mensagens
         * @return Mensagem É a mensagem mais antiga e com maior prioridade presente na Caixa de Mensagens
         */
        Mensagem consultarEmail(const unsigned int id);
};

#endif
