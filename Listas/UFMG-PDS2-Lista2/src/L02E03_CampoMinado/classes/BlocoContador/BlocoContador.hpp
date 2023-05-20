#ifndef BLOCO_CONTADOR_H
#define BLOCO_CONTADOR_H

#include <vector>

#include "../Bloco/Bloco.hpp"
#include "../Coordenada/Coordenada.hpp"

class BlocoContador : public Bloco {
    public:
        BlocoContador();
        BlocoContador(const Coordenada coordenada);
        BlocoContador(const Bloco bloco);
        virtual ~BlocoContador();

        virtual bool revelar(std::vector<std::vector<Bloco*>>& tabuleiro) override;
        void incrementarValor();
};

#endif
