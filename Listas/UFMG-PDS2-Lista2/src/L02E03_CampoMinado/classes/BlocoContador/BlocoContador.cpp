#include <vector>

#include "./BlocoContador.hpp"
#include "../Coordenada/Coordenada.hpp"

BlocoContador::BlocoContador() {}

BlocoContador::BlocoContador(const Coordenada coordenada) : Bloco(coordenada) {}

BlocoContador::BlocoContador(const Bloco bloco) : Bloco(bloco.getCoordenada()) {}

BlocoContador::~BlocoContador() {}

bool BlocoContador::revelar(std::vector<std::vector<Bloco*>>& tabuleiro) {
    setRevelado(true);
    return true;
}

void BlocoContador::incrementarValor() {
    setValor(getValor() + 1);
    return;
}
