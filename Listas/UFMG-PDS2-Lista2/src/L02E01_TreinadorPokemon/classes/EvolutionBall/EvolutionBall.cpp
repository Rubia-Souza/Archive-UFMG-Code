#include <iostream>

#include "./EvolutionBall.hpp"

EvolutionBall::EvolutionBall(const double taxaPoder) {
    setTaxaPoder(taxaPoder);
}

EvolutionBall::~EvolutionBall() {}

bool EvolutionBall::evoluirPokemon() {
    if(!contemPokemon() || getHabilidadeUsada()) {
        return false;
    }

    pokemon->evoluir(getTaxaPoder());
    setHabilidadeUsada(true);
    return true;
}

void EvolutionBall::printInfo() const {
    std::cout << "EvolutionBall ID: " << getId() << "\n";
    printContent();

    return;
}

void EvolutionBall::setTaxaPoder(const double taxaPoder) {
    this->taxaPoder = taxaPoder;
    return;
}

double EvolutionBall::getTaxaPoder() const {
    return taxaPoder;
}

void EvolutionBall::setHabilidadeUsada(const bool habilidadeUsada) {
    this->habilidadeUsada = habilidadeUsada;
    return;
}

bool EvolutionBall::getHabilidadeUsada() const {
    return habilidadeUsada;
}
