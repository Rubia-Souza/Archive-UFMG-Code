#include <vector>

#include "Vertice.hpp"

Vertice::Vertice(const int id) {
    this->id = id;
    vizinhos = new std::vector<Aresta*>();

    return;
}

Vertice::~Vertice() {
    for(Aresta* aresta : *vizinhos) {
        delete aresta;
    }
    delete vizinhos;

    return;
}

void Vertice::adicionarAresta(Vertice* vertice, const unsigned int distancia) {
    vizinhos->push_back(new Aresta(vertice, distancia));
    return;
}

int Vertice::getId() const {
    return id;
}

std::vector<Aresta*>* Vertice::getArestaParaVinhos() {
    return vizinhos;
}
