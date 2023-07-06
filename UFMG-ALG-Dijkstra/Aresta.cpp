#include "Aresta.hpp"
#include "Vertice.hpp"

Aresta::Aresta(Vertice* vizinho, const unsigned int distancia) {
    this->vizinho = vizinho;
    this->distancia = distancia;

    return;
}

Aresta::~Aresta() {}

unsigned int Aresta::getDistancia() const {
    return distancia;
}

void Aresta::setDistancia(const unsigned int distancia) {
    this->distancia = distancia;
    return;
}

Vertice* Aresta::getVizinho() const {
    return vizinho;
}

void Aresta::setVizinho(const Vertice* vertice) {
    this->vizinho = vizinho;
    return;
}
