#ifndef EXCECOES_MAIN_H
#define EXCECOES_MAIN_H

#include <string>
#include <stdexcept>

#include "Excecao.h"

namespace ExcecoesMain {
    class AquivoEntradaNaoInformadoException : public Excecao {
        public:
            /**
             * @brief Cria o objeto de AquivoEntradaNaoInformadoException
             * 
             * @details Representa um erro ao informar um aruivo de entrada inválido
             * 
             * @param mensagem É a mesagem que a AquivoEntradaNaoInformadoException contem
             */
            AquivoEntradaNaoInformadoException(const std::string mensagem);

            /**
             * @brief Destroi a exceção AquivoEntradaNaoInformadoException
             * 
             */
            virtual ~AquivoEntradaNaoInformadoException();
    };

    class ErroAoAbrirAquivoEntradaException : public Excecao {
        public:
            /**
             * @brief Cria o objeto de ErroAoAbrirAquivoEntradaException
             * 
             * @details Representa um erro ao abrir o arquivo de entrada informado
             * 
             * @param mensagem É a mesagem que a ErroAoAbrirAquivoEntradaException contem
             */
            ErroAoAbrirAquivoEntradaException(const std::string mensagem);

            /**
             * @brief Destroi a exceção ErroAoAbrirAquivoEntradaException
             * 
             */
            virtual ~ErroAoAbrirAquivoEntradaException();
    };
}

#endif
