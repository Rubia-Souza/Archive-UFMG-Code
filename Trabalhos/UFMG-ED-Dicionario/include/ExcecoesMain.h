#ifndef EXCECOES_MAIN_H
#define EXCECOES_MAIN_H

#include <string>
#include <stdexcept>

#include "Excecao.h"

namespace ExcecoesMain {
    class ArquivoEntradaNaoFornecidoException : public Excecao {
        public:
            /**
             * @brief Cria o objeto de ArquivoEntradaNaoFornecidoException
             * 
             * @details Representa um erro ao não informar um arquivo de entrada
             * 
             * @param mensagem É a mesagem que a ArquivoEntradaNaoFornecidoException contem
             */
            ArquivoEntradaNaoFornecidoException(const std::string mensagem);

            /**
             * @brief Destroi a exceção ArquivoEntradaNaoFornecidoException
             * 
             */
            virtual ~ArquivoEntradaNaoFornecidoException();
    };

    class ArquivoEntradaNaoAbertoException : public Excecao {
        public:
            /**
             * @brief Cria o objeto de ArquivoEntradaNaoAbertoException
             * 
             * @details Representa um erro ao não conseguir abrir um arquivo de entrada
             * 
             * @param mensagem É a mesagem que a ArquivoEntradaNaoAbertoException contem
             */
            ArquivoEntradaNaoAbertoException(const std::string mensagem);

            /**
             * @brief Destroi a exceção ArquivoEntradaNaoFornecidoException
             * 
             */
            virtual ~ArquivoEntradaNaoAbertoException();
    };

    class ArquivoSaidaNaoFornecidoException : public Excecao {
        public:
            /**
             * @brief Cria o objeto de ArquivoSaidaNaoFornecidoException
             * 
             * @details Representa um erro ao não informar o arquivo de saida
             * 
             * @param mensagem É a mesagem que a ArquivoSaidaNaoFornecidoException contem
             */
            ArquivoSaidaNaoFornecidoException(const std::string mensagem);

            /**
             * @brief Destroi a exceção ArquivoSaidaNaoFornecidoException
             * 
             */
            virtual ~ArquivoSaidaNaoFornecidoException();
    };

    class ArquivoSaidaNaoAbertoException : public Excecao {
        public:
            /**
             * @brief Cria o objeto de ArquivoSaidaNaoAbertoException
             * 
             * @details Representa um erro ao não conseguir abrir um arquivo de entrada
             * 
             * @param mensagem É a mesagem que a ArquivoSaidaNaoAbertoException contem
             */
            ArquivoSaidaNaoAbertoException(const std::string mensagem);

            /**
             * @brief Destroi a exceção ArquivoEntradaNaoFornecidoException
             * 
             */
            virtual ~ArquivoSaidaNaoAbertoException();
    };

    class ArgumentoInvalidoException : public Excecao {
        public:
            /**
             * @brief Cria o objeto de ArgumentoInvalidoExcecao
             * 
             * @details Representa um erro ao informar um argumento inválido
             * 
             * @param mensagem É a mesagem que a ArgumentoInvalidoExcecao contem
             */
            ArgumentoInvalidoException(const std::string mensagem);

            /**
             * @brief Destroi a exceção ArgumentoInvalidoException
             * 
             */
            virtual ~ArgumentoInvalidoException();
    };

    class TipoDicionarioNaoInformadoException : public Excecao {
        public:
            /**
             * @brief Cria o objeto de TipoDicionarioNaoInformadoException
             * 
             * @details Representa um erro ao informar um argumento inválido
             * 
             * @param mensagem É a mesagem que a TipoDicionarioNaoInformadoException contem
             */
            TipoDicionarioNaoInformadoException(const std::string mensagem);

            /**
             * @brief Destroi a exceção TipoDicionarioNaoInformadoException
             * 
             */
            virtual ~TipoDicionarioNaoInformadoException();
    };

    class ErroAoEncerrarMemLogException : public Excecao {
        public:
            /**
             * @brief Cria o objeto de ErroAoEncerrarMemLogException
             * 
             * @details Representa um erro ao Encerrar o MemLog
             * 
             * @param mensagem É a mesagem que a ErroAoEncerrarMemLogException contem
             */
            ErroAoEncerrarMemLogException(const std::string mensagem);

            /**
             * @brief Destroi a exceção ErroAoEncerrarMemLogException
             * 
             */
            virtual ~ErroAoEncerrarMemLogException();
    };
}

#endif