#include "ArestaExato.hpp"

#include "VerticeExato.hpp"
#include "TipoArestaExata.hpp"

ArestaExato::ArestaExato(VerticeExato* vizinho) {
    this->vizinho = vizinho;
    return;
}

ArestaExato::~ArestaExato() {}

void ArestaExato::setVizinho(VerticeExato* vizinho) {
    this->vizinho = vizinho;
    return;
}

VerticeExato* ArestaExato::getVizinho() {
    return vizinho;
}

void ArestaExato::setCapacidade(const unsigned int capacidade) {
    this->capacidade = capacidade;
    return;
}

unsigned int ArestaExato::getCapacidade() const {
    return capacidade;
}

void ArestaExato::setFluxoAtual(const unsigned int fluxo) {
    this->fluxoAtual = fluxo;
    return;
}

unsigned int ArestaExato::getFluxo() const {
    return fluxoAtual;
}

void ArestaExato::setArestaAssociada(ArestaExato* arestaAssociada) {
    this->arestaAssociada = arestaAssociada;
    return;
}

ArestaExato* ArestaExato::getArestaAssociada() {
    return arestaAssociada;
}

void ArestaExato::setTipo(const TipoArestaExata tipo) {
    this->tipo = tipo;
    return;
}

TipoArestaExata ArestaExato::getTipo() const {
    return tipo;
}

int ArestaExato::getFluxoDisponivel() const {
    return capacidade - fluxoAtual;
}

void ArestaExato::incrementarFluxo(const unsigned int fluxo) {
    if(tipo == TipoArestaExata::Residual) {
        capacidade -= fluxo;
        this->arestaAssociada->fluxoAtual -= fluxo;

        return;
    }
    
    fluxoAtual += fluxo;
    this->arestaAssociada->capacidade += fluxo;

    return;
}