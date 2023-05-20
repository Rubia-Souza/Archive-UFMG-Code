#ifndef VERBETE_H
#define VERBETE_H

#include <string>
#include <fstream>

#include "TiposVerbete.h"
#include "Lista.h"

class Verbete {
    private:
        std::string palavra = "";
        TiposVerbete tipoVerbete = TiposVerbete::NOME;
        Lista<std::string>* significados = nullptr;

    public:
        /**
         * @brief Cria um objeto do tipo verbete
         * 
         */
        Verbete();

        /**
         * @brief Cria um objeto do tipo verbete
         * 
         * @param palavra É a palavra que define o verbete
         * @param tipoVerbete É a identificação do tipo do verbete
         * @param significado É o significado associado ao verbete
         */
        Verbete(const std::string& palavra, const char tipoVerbete, const std::string& significado);

        /**
         * @brief Cria um objeto do tipo verbete
         * 
         * @param verbete É o verbete que será utilizado de referência para fazer a copia dos dados
         */
        Verbete(const Verbete& verbete);

        /**
         * @brief Destroi o objeto Verbete
         * 
         */
        virtual ~Verbete();

        /**
         * @brief Imprime as informações do verbete no terminal
         * 
         */
        void imprimir() const;

        /**
         * @brief Imprime as informações do verbete no arquivo informado
         * 
         * @param arquivo É o arquivo que terá as informações do Verbete escrita
         */
        void imprimirEmArquivo(std::ofstream* arquivo) const;

        /**
         * @brief Define o atributo palavra
         * 
         * @param palavra É a palavra que define o Verbete
         */
        void setPalavra(const std::string palavra);

        /**
         * @brief Retorna o atributo palavra
         * 
         * @return std::string É a palavra que define o Verbete
         */
        std::string getPalavra() const;

        /**
         * @brief Define o tipo do Verbete
         * 
         * @details O tipo do verbete pode ser: (v) Verbo, (n) Nome, (a) Adverbio
         * 
         * @param tipo É o tipo do verbete
         */
        void setTipo(const TiposVerbete tipo);

        /**
         * @brief Define o tipo do Verbete
         * 
         * @details O tipo do verbete pode ser: (v) Verbo, (n) Nome, (a) Adverbio
         * 
         * @param tipo É o tipo do verbete
         */
        void setTipo(const char tipo);

        /**
         * @brief Retorna o tipo do verbete
         * 
         * @return TiposVerbete É o tipo do verbete
         */
        TiposVerbete getTipo() const;

        /**
         * @brief Adiciona um significado ao verbete
         * 
         * @param significado É o significado que será adicionado ao verbete
         */
        void adicionarSignificado(const std::string significado);

        /**
         * @brief Adiciona um conjunto de significados ao verbete
         * 
         * @param significados É uma lista de significados que será inserida
         */
        void adicionarSignificado(const Lista<std::string>& significados);

        /**
         * @brief Retorna a lista de significados do verbete
         * 
         * @return Lista<std::string>* É a lista de significados do verbete
         */
        Lista<std::string>* getSignificados() const;

        /**
         * @brief Retorna a quantidade de significados que o verbete possui
         * 
         * @return unsigned int É a quantidade de significados que o verbete possui
         */
        unsigned int getQuantidadeSignificados() const;
};

#endif
