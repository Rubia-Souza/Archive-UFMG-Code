#ifndef BLOCO_MINA_H
#define BLOCO_MINA_H

#include <vector>
#include <string>

#include "../Bloco/Bloco.hpp"
#include "../Coordenada/Coordenada.hpp"

class BlocoMina : public Bloco {
    protected:
        static const std::string SIMBOLO_MINA;

    public:
        BlocoMina();
        BlocoMina(const std::vector<std::vector<Bloco*>>& tabuleiro, const Coordenada coordenada);
        virtual ~BlocoMina();

        virtual bool revelar(std::vector<std::vector<Bloco*>>& tabuleiro) override;
    
    protected:
        virtual std::string renderBloco() const override;
};

#endif
