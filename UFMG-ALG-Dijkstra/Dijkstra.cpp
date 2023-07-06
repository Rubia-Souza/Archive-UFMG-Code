#define INFINITO 0x3f3f3f3f

#include <vector>

#include "Dijkstra.hpp"

#include "Graph.hpp"
#include "Vertice.hpp"
#include "Aresta.hpp"
#include "HeapMinimo.hpp"

int Dijkstra::EncontrarMenorCaminho(Graph* grafo, Vertice* verticeInicial, Vertice* verticeFinal) {
    std::vector<Vertice*>* vertices = grafo->getListaVertices();
    std::vector<unsigned int> distanciasOrigem;
    HeapMinimo ordemVizita(vertices->size());

    for(Vertice* vertice : *vertices) {
        distanciasOrigem.push_back(INFINITO);
        ordemVizita.adicionar(vertice, distanciasOrigem[vertice->getId()]);
    }

    distanciasOrigem[verticeInicial->getId()] = 0;
    ordemVizita.atualizar(verticeInicial, distanciasOrigem[verticeInicial->getId()]);

    while(!ordemVizita.estaVazio()) {
        Vertice* verticeAtual = ordemVizita.popMenor();
        if(verticeAtual == verticeFinal) {
            break;
        }

        std::vector<Aresta*>* arestas = verticeAtual->getArestaParaVinhos();
        for(Aresta* arestaVizinho : *arestas) {
            if(!ehPar(arestaVizinho->getDistancia())) {
                continue;
            }

            unsigned int possivelNovaEstimativa = distanciasOrigem[verticeAtual->getId()] + arestaVizinho->getDistancia();
            unsigned int estimativaAtual = distanciasOrigem[arestaVizinho->getVizinho()->getId()];
            if(possivelNovaEstimativa >= estimativaAtual) {
                continue;
            }

            distanciasOrigem[arestaVizinho->getVizinho()->getId()] = possivelNovaEstimativa;
            ordemVizita.atualizar(arestaVizinho->getVizinho(), distanciasOrigem[arestaVizinho->getVizinho()->getId()]);
        }
    }

    unsigned int menorCaminho = distanciasOrigem[verticeFinal->getId()];
    return (menorCaminho == INFINITO ? -1 : menorCaminho);
}

bool Dijkstra::ehPar(const int valor) {
    return (valor % 2) == 0;
}