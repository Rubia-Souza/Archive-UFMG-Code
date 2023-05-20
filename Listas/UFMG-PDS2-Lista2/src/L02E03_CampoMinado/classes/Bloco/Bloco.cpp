#include <vector>
#include <string>

#include "./Bloco.hpp"
#include "../BlocoMina/BlocoMina.hpp"
#include "../Coordenada/Coordenada.hpp"

const std::string Bloco::SIMBOLO_NAO_REVELADO = "#";

Bloco::Bloco() {
    Coordenada* coordenada = new Coordenada();
    setCoordenada(*coordenada);
    delete coordenada;

    setRevelado(false);
    setValor(0);
}

Bloco::Bloco(const Coordenada coordenada) {
    setCoordenada(coordenada);
    setRevelado(false);
    setValor(0);
}

Bloco::~Bloco() {
    setRevelado(false);
    setValor(0);
}

bool Bloco::revelar(std::vector<std::vector<Bloco*>>& tabuleiro) {
    if(ehRevelado()) {
        return true;
    }

    setRevelado(true);

    std::vector<Bloco*> blocos_adjacentes = getBlocosAdjacentes(tabuleiro);    
    for(Bloco* bloco : blocos_adjacentes) {
        if(!contemBomba()) {
            bloco->revelar(tabuleiro);
        }
    }
    
    return true;
}

std::vector<Bloco*> Bloco::getBlocosAdjacentes(const std::vector<std::vector<Bloco*>>& tabuleiro) const {
    std::vector<Coordenada>* coordenadas_adjacentes = new std::vector<Coordenada>();
    getCoordenada().getCoordenadasAdjacentes(*coordenadas_adjacentes, tabuleiro.size(), tabuleiro[0].size());

    std::vector<Bloco*> blocos_adjacentes;
    for(Coordenada coordenada : *coordenadas_adjacentes) {
        blocos_adjacentes.push_back(tabuleiro[coordenada.getRow()][coordenada.getColumn()]);
    }

    delete coordenadas_adjacentes;;
    return blocos_adjacentes;
}

std::string Bloco::getSimbolo() const {
    if(!ehRevelado()) {
        return SIMBOLO_NAO_REVELADO;
    }

    return renderBloco();
}

std::string Bloco::renderBloco() const {
    return std::to_string(getValor());
}

void Bloco::setCoordenada(const Coordenada coordenada) {
    this->coordenada = coordenada;
    return;
}

Coordenada Bloco::getCoordenada() const {
    return coordenada;
}

void Bloco::setRevelado(const bool revelado) {
    this->revelado = revelado;
    return;
}

bool Bloco::ehRevelado() const {
    return revelado;
}

void Bloco::setValor(const int valor) {
    this->valor = valor;
    return;
}

int Bloco::getValor() const {
    return valor;
}

bool Bloco::contemBomba() const {
    return getValor() == INDICADOR_BOMBA;
}
