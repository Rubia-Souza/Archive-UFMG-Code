#ifndef DICIONARIO_H
#define DICIONARIO_H

#include <string>
#include <fstream>

#include "Verbete.h"
#include "TiposVerbete.h"

class Dicionario {
    public:
        /**
         * @brief Cria objeto Dicionário
         * 
         */
        Dicionario();

        /**
         * @brief Destroi objeto Dicionário
         * 
         */
        virtual ~Dicionario();

        /**
         * @brief Insere um verbete no dicionário
         * 
         * @param verbete É o verbete que será inserido
         */
        virtual void inserir(Verbete& verbete) = 0;

        /**
         * @brief Busca um verbete com base em uma palavra
         * 
         * @param palavra É a palavra do verbete que será buscado
         * @param tipo É o tipo do verbete
         * @return Verbete* É o verbete da palavra, se existir. Caso contrário, retorna nullptr
         */
        virtual Verbete* pesquisar(const std::string palavra, const TiposVerbete tipo) = 0;

        /**
         * @brief Sobre-escreve as informações de um verbete
         * 
         * @details Caso o verbete não seja encontrado, nada é feito.
         * 
         * @param verbete É as novas informações que serão sobre-escritas no verbete
         */
        virtual void atualizar(Verbete& verbete) = 0;

        /**
         * @brief Remove o verbete com a palavra informada caso encontrado
         * 
         * @param palavra É a palavra do verbete que será buscado e removido
         * @param tipo É o tipo do verbete
         */
        virtual void remover(const std::string palavra, const TiposVerbete tipo) = 0;

        /**
         * @brief Imprime o dicionário no terminal
         * 
         */
        virtual void imprimir() = 0;

        /**
         * @brief Imprime as informações do dicionário no arquivo informado
         * 
         * @param arquivo É o arquivo que terá as informações do Dicionario escrita
         */
        virtual void imprimirEmArquivo(std::ofstream* arquivo) = 0;

        /**
         * @brief Remove todos elementos do dicionário
         * 
         */
        virtual void limpar() = 0;

        /**
         * @brief Verifica se o dicionário está vazio
         * 
         * @return true Se o dicionário estiver vazio
         * @return false Se o dicionário não estiver vazio
         */
        virtual bool estaVazia() = 0;

        /**
         * @brief Remove todos os verbetes com mais de um significado no dicionário
         * 
         */
        virtual void removerVerbetesComMaisDeUmSignificado() = 0;
};

#endif
