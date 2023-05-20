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
