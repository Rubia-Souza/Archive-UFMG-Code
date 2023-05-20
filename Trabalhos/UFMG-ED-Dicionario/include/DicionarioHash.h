#ifndef DICIONARIO_HASH_H
#define DICIONARIO_HASH_H

#include <string>
#include <fstream>

#include "Dicionario.h"
#include "Lista.h"

#include "Verbete.h"

class DicionarioHash : public Dicionario {
    private:
        // TODO: Identificar tamanho padrão ideal para dicionario
        static const unsigned int QUANTIDADE_LISTAS = 10;
        Lista<Verbete*> listasVerbetes[QUANTIDADE_LISTAS];
        unsigned int tamanho = 0;

    public:
        /**
         * @brief Cria objeto DicionarioHash
         * 
         */
        DicionarioHash();

        /**
         * @brief Destroi objeto DicionarioHash
         * 
         */
        virtual ~DicionarioHash();

        /**
         * @brief Insere um verbete no dicionário
         * 
         * @param verbete É o verbete que será inserido
         */
        virtual void inserir(Verbete& verbete) override;

        /**
         * @brief Busca um verbete com base em uma palavra
         * 
         * @param palavra É a palavra do verbete que será buscado
         * @param tipo É o tipo do verbete
         * @return Verbete* É o verbete da palavra, se existir. Caso contrário, é nullptr
         */
        virtual Verbete* pesquisar(const std::string palavra, const TiposVerbete tipo) override;

        /**
         * @brief Sobre-escreve as informações de um verbete
         * 
         * @details Caso o verbete não seja encontrado, nada é feito.
         * 
         * @param verbete É as novas informações que será sobre-escrita no verbete
         */
        virtual void atualizar(Verbete& verbete) override;

        /**
         * @brief Remove o verbete com a palavra informada caso encontrado
         * 
         * @param palavra É a palavra do verbete que será buscado e removido
         * @param tipo É o tipo do verbete
         */
        virtual void remover(const std::string palavra, const TiposVerbete tipo) override;

        /**
         * @brief Imprime o dicionário no terminal
         * 
         */
        virtual void imprimir() override;

        /**
         * @brief Imprime as informações do dicionário no arquivo informado
         * 
         * @param arquivo É o arquivo que terá as informações do Dicionario escrita
         */        
        virtual void imprimirEmArquivo(std::ofstream* arquivo) override;

        /**
         * @brief Remove todos elementos do dicionário
         * 
         */
        virtual void limpar() override;

        /**
         * @brief Verifica se o dicionário está vazio
         * 
         * @return true Se o dicionário estiver vazio
         * @return false Se o dicionário não estiver vazio
         */
        virtual bool estaVazia() override;

        /**
         * @brief Remove todos os verbetes com mais de um significado no dicionário
         * 
         */
        virtual void removerVerbetesComMaisDeUmSignificado() override;
    
    private:
        /**
         * @brief Realiza o mapeamento da palavra com o index da tabela
         * 
         * @param palavra É a palavra utilizada para realizar o mapeamento
         * @return unsigned int É o index correspondente a palavra informada
         */
        unsigned int hash(const std::string palavra);
};

#endif
