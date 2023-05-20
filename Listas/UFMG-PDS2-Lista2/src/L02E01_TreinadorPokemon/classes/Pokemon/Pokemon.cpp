#include <iostream>
#include <string>

#include "./Pokemon.hpp"

#define SAUDE_MAXIMA_PADRAO 100

Pokemon::Pokemon(const std::string nome, const std::string tipo, const std::string proxEvolucao, const double forcaAtaque, const double forcaDefesa, const double saude) {
    setNome(nome);
    setTipo(tipo);
    setProxEvolucao(proxEvolucao);
    setForcaAtaque(forcaAtaque);
    setForcaDefesa(forcaDefesa);
    setSaude(saude);
}

Pokemon::~Pokemon() {}

void Pokemon::maxSaude() {
    setSaude(SAUDE_MAXIMA_PADRAO);
    return;
}

void Pokemon::info() const {
    std::cout << "Pokemon: " << getNome() << ", " 
              << getTipo() << ", " 
              << getForcaAtaque() << ", " 
              << getForcaDefesa() << ", " 
              << getSaude() << "\n";
    
    return;
}

void Pokemon::setNome(const std::string nome) {
    this->nome = nome;
    return;
}

std::string Pokemon::getNome() const {
    return nome;
}

void Pokemon::setTipo(const std::string tipo) {
    this->tipo = tipo;
    return;
}

std::string Pokemon::getTipo() const {
    return tipo;
}

void Pokemon::setForcaAtaque(const double forcaAtaque) {
    this->forcaAtaque = forcaAtaque;
    return;
}

double Pokemon::getForcaAtaque() const {
    return forcaAtaque;
}

void Pokemon::setForcaDefesa(const double forcaDefesa) {
    this->forcaDefesa = forcaDefesa;
    return;
}

double Pokemon::getForcaDefesa() const {
    return forcaDefesa;
}

void Pokemon::setProxEvolucao(const std::string proxEvolucao) {
    this->proxEvolucao = proxEvolucao;
    return;
}

std::string Pokemon::getProxEvolucao() const {
    return proxEvolucao;
}

void Pokemon::setSaude(const double saude) {
    this->saude = saude;
    return;
}

double Pokemon::getSaude() const {
    return saude;
}
