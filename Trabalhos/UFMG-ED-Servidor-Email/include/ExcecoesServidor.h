#ifndef EXCECOES_SERVIDOR_H
#define EXCECOES_SERVIDOR_H

#include <string>
#include <stdexcept>

#include "Excecao.h"

namespace ExcecoesServidor {
    class UsuarioJaCadastradoException : public Excecao {
        public:
            /**
             * @brief Cria o objeto de UsuarioJaCadastradoException
             * 
             * @details Representa um erro ao tentar cadastrar um usuário com id já registrada
             * 
             * @param mensagem É a mesagem que a UsuarioJaCadastradoException contem
             */
            UsuarioJaCadastradoException(const std::string mensagem);

            /**
             * @brief Destroi a exceção UsuarioJaCadastradoException
             * 
             */
            virtual ~UsuarioJaCadastradoException();
    };

    class UsuarioNaoEncontradoException : public Excecao {
        public:
            /**
             * @brief Cria o objeto de UsuarioNaoEncontradoException
             * 
             * @details Representa um erro quando um usuário não foi encontrado
             * 
             * @param mensagem É a mesagem que a UsuarioNaoEncontradoException contem
             */
            UsuarioNaoEncontradoException(const std::string mensagem);

            /**
             * @brief Destroi a exceção UsuarioNaoEncontradoException
             * 
             */
            virtual ~UsuarioNaoEncontradoException();
    };
}

#endif
