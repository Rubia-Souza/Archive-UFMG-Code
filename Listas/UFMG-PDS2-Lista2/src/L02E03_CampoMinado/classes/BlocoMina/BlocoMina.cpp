#include <vector>
#include <string>

#include "./BlocoMina.hpp"
#include "../BlocoContador/BlocoContador.hpp"
#include "../Coordenada/Coordenada.hpp"

const std::string BlocoMina::SIMBOLO_MINA = "*";

BlocoMina::BlocoMina() {}

BlocoMina::BlocoMina(const std::vector<std::vector<Bloco*>>& tabuleiro, const Coordenada coordenada) : Bloco(coordenada) {
    setValor(INDICADOR_BOMBA);
    std::vector<Bloco*> blocos_adjacentes = getBlocosAdjacentes(tabuleiro);

    for(Bloco* bloco : blocos_adjacentes) {
        if(!bloco->contemBomba()) {
            if(bloco->getValor() == 0) {
                Coordenada coordenada_bloco_alvo = bloco->getCoordenada();
                delete bloco;

                bloco = new BlocoContador(coordenada_bloco_alvo);
            }

            BlocoContador* bloco_contador = dynamic_cast<BlocoContador*>(bloco);
            bloco_contador->incrementarValor();
        }
    }
}

BlocoMina::~BlocoMina() {}

bool BlocoMina::revelar(std::vector<std::vector<Bloco*>>& tabuleiro) {
    setRevelado(true);

    for(unsigned int i = 0; i < tabuleiro.size(); i++) {
        for(unsigned int j = 0; j < tabuleiro[i].size(); j++) {
            Bloco* blocoAtual = tabuleiro[i][j];

            if(blocoAtual == this || blocoAtual->ehRevelado()) {
                continue;
            }

            blocoAtual->revelar(tabuleiro);
        }
    }

    return false;
}

std::string BlocoMina::renderBloco() const {
    return SIMBOLO_MINA;
}
