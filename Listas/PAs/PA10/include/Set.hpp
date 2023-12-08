#ifndef SET_HPP
#define SET_HPP

#include <string>
#include "TabelaHash.hpp"

class Set {
    private:
        unsigned int tamanhoInicial = 0;
        unsigned int tamanhoTabela = 0;
        unsigned int tamanhoConjunto = 0;
        TabelaHash* tabela = nullptr;

    public:
        Set(const unsigned int tamanho);
        virtual ~Set();

        void inserir(const std::string dado);
        void remover(const std::string dado);
        bool pertence(const std::string dado);
        
        Set* intersecao(Set& outroSet);
        Set* uniao(Set& outroSet);
        Set* diferencaSimetrica(Set& outroSet);

        unsigned int getTamanho() const;
        unsigned int getTamanhoTabela() const;
        TabelaHash* getTabela();

        bool estaVazio(const unsigned int posicao);
        bool foiRetirada(const unsigned int posicao);
        std::string getDado(const unsigned int posicao);

        void print();

    private:
        int calcularHash(const std::string dado);
        void recriarHash(const unsigned int posicao);
        void ajustarTamanho(const unsigned int novoTamanho);
};

#endif