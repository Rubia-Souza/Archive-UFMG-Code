#ifndef TABELA_HASH_HPP
#define TABELA_HASH_HPP

#include <string>

class TabelaHash {
    private:
        std::string dado = "";
        bool vazio = true;
        bool retirada = false;

    public:
        TabelaHash();
        virtual ~TabelaHash();

        std::string getDado() const;
        void setDado(const std::string dado);

        bool estaVazio() const;
        void setVazio(const bool vazio);

        bool foiRetirada() const;
        void setRetirada(const bool retirada);
};

#endif