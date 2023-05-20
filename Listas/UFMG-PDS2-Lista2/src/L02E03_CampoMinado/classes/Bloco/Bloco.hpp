#ifndef BLOCO_H
#define BLOCO_H

#include <vector>
#include <string>

#include "../Coordenada/Coordenada.hpp"

#define INDICADOR_BOMBA -1

class Bloco {
    protected:
        static const std::string SIMBOLO_NAO_REVELADO;
        Coordenada coordenada;
        bool revelado = false;
        int valor = 0;

    public:
        Bloco();
        Bloco(const Coordenada coordenada);
        virtual ~Bloco();

        virtual bool revelar(std::vector<std::vector<Bloco*>>& tabuleiro);
        std::string getSimbolo() const;

        void setCoordenada(const Coordenada coordenada);
        Coordenada getCoordenada() const;

        void setRevelado(const bool revelado);
        bool ehRevelado() const;

        void setValor(const int valor);
        int getValor() const;

        bool contemBomba() const;
    
    protected:
        virtual std::string renderBloco() const;
        virtual std::vector<Bloco*> getBlocosAdjacentes(const std::vector<std::vector<Bloco*>>& tabuleiro) const;
};

#endif
