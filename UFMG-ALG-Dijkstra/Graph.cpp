#include <vector>
#include <memory>

#include "Graph.hpp"
#include "Vertice.hpp"

Graph::Graph(const unsigned int quantidadeVertices) {
    quantidadeBasicaCidades = quantidadeVertices;
    quantidadeDerivadaCidades = 2 * quantidadeVertices;

    vertices = new std::vector<Vertice*>();
    for(unsigned int i = 0; i < quantidadeDerivadaCidades; i++) {
        vertices->push_back(new Vertice(i));
    }

    return;
}

Graph::~Graph() {
    for(Vertice* vertice : *vertices) {
        delete vertice;
    }
    delete vertices;

    return;
}

void Graph::adicionarAresta(const unsigned int idVertice1, const unsigned int idVertice2, const unsigned int distancia) {
    Vertice* vertice1Par = (*vertices)[idVertice1];
    Vertice* vertice1Impar = (*vertices)[idVertice1 + quantidadeBasicaCidades];

    Vertice* vertice2Par = (*vertices)[idVertice2];
    Vertice* vertice2Impar = (*vertices)[idVertice2 + quantidadeBasicaCidades];

    vertice1Par->adicionarAresta(vertice2Impar, distancia);
    vertice2Impar->adicionarAresta(vertice1Par, distancia);

    vertice1Impar->adicionarAresta(vertice2Par, distancia);
    vertice2Par->adicionarAresta(vertice1Impar, distancia);

    return;
}

std::vector<Vertice*>* Graph::getListaVertices() const {
    return vertices;
}
