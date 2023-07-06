#include <unordered_map>
#include <vector>
#include <queue>

#include "SolucaoExata.hpp"
#include "ArestaExato.hpp"
#include "Constantes.hpp"

/* Solução:
 * 1 Adaptar o grafo para um grafo de fluxo
 *  1.1 Adicionar um vertice fonte a esquerda dos trabalhadores - O(T)
 *  1.2 Adicionar um vertice sumidouro a direita dos empregos - O(E)
 *  1.3 Direcionar as arestas dos trabalhadores para os empregos - O(m)
 *  1.4 Adicionar arestas residuais - O(m)
 *  1.5 Definir que cada aresta padrão tem peso 1 - O(m)
 * 2 Executar algoritmo de fluxo maximo - O(F)
 *  2.1 Encontrar caminho aumentante - O(m)
 * 3 Somar o valor do menor fluxo encontrado a cada caminho aumentante - O(1)
 * 
 * Complexidade: O(T) + O(E) + O(m) + O(m) + O(m) + O(F * m) = O(F * m)
 * 
 * E = Quantidade Empregos
 * T = Quantidade Trabalhadores
 * F = Valor fluxo máximo
 * 
 * n = Quantidade de vértices. n = E + T
 * m = Quantidade de arestas. m = E * T
 */

SolucaoExata::SolucaoExata() {}
SolucaoExata::~SolucaoExata() {}

unsigned int SolucaoExata::EncontrarMaximumMatchingFordFulkerson(GrafoExato* grafo) {
    std::unordered_map<std::string, VerticeExato*>* listaVertices = grafo->getListaCompletaVertices();

    unsigned int passoAtual = 1;
    std::unordered_map<std::string, unsigned int> registroVisitados;
    for(std::unordered_map<std::string, VerticeExato*>::iterator iterator = listaVertices->begin(); iterator != listaVertices->end(); iterator++) {
        registroVisitados[iterator->first] = 0;
    }

    int ultimoFluxoEncontrado = EncontrarMenorFluxoDFS(grafo->getFonte(), INFINITO, grafo->getSumidouro(), registroVisitados, passoAtual);
    unsigned int fluxoMaximo = 0;
    while(ultimoFluxoEncontrado > 0) {
        passoAtual++;
        fluxoMaximo += ultimoFluxoEncontrado;

        ultimoFluxoEncontrado = EncontrarMenorFluxoDFS(grafo->getFonte(), INFINITO, grafo->getSumidouro(), registroVisitados, passoAtual);
    }

    return fluxoMaximo;
}

int SolucaoExata::EncontrarMenorFluxoDFS(VerticeExato* vertice, const int menorFluxoDisponivel, const VerticeExato* sumidouro, std::unordered_map<std::string, unsigned int>& registroVisitados, const unsigned int passoAtual) {
    if(vertice == sumidouro) {
        return menorFluxoDisponivel;
    }

    registroVisitados[vertice->getNome()] = passoAtual;
    std::vector<ArestaExato*>* vizinhos = vertice->getVizinhos();

    for(ArestaExato* aresta : *vizinhos) {
        VerticeExato* vizinho = aresta->getVizinho();

        bool jaFoiVizitado = registroVisitados[vizinho->getNome()] >= passoAtual;
        bool estaNoMaximoDaCapacidade = aresta->getFluxoDisponivel() <= 0;
        if(jaFoiVizitado || estaNoMaximoDaCapacidade) {
            continue;
        }

        int menorValorFluxo = (aresta->getFluxoDisponivel() < menorFluxoDisponivel) ? aresta->getFluxoDisponivel() : menorFluxoDisponivel;
        menorValorFluxo = EncontrarMenorFluxoDFS(vizinho, menorValorFluxo, sumidouro, registroVisitados, passoAtual);

        bool chegouSumidouro = menorValorFluxo > 0;
        if(!chegouSumidouro) {
            continue;
        }

        aresta->incrementarFluxo(menorValorFluxo);
        return menorValorFluxo;
    }

    return 0;
}

unsigned int SolucaoExata::EncontrarMaximumMatchingEdmondsKarp(GrafoExato* grafo) {
    std::unordered_map<std::string, VerticeExato*>* listaVertices = grafo->getListaCompletaVertices();

    unsigned int passoAtual = 1;
    std::unordered_map<std::string, unsigned int> registroVisitados;
    for(std::unordered_map<std::string, VerticeExato*>::iterator iterator = listaVertices->begin(); iterator != listaVertices->end(); iterator++) {
        registroVisitados[iterator->first] = 0;
    }

    int ultimoFluxoEncontrado = 0;
    unsigned int fluxoMaximo = 0;
    do {
        passoAtual++;

        ultimoFluxoEncontrado = EncontrarMenorFluxoBFS(grafo->getFonte(), grafo->getSumidouro(), registroVisitados, passoAtual);
        fluxoMaximo += ultimoFluxoEncontrado;
    } while(ultimoFluxoEncontrado > 0);

    return fluxoMaximo;
}

int SolucaoExata::EncontrarMenorFluxoBFS(VerticeExato* fonte, const VerticeExato* sumidouro, std::unordered_map<std::string, unsigned int>& registroVisitados, const unsigned int passoAtual) {
    std::queue<VerticeExato*> ordemVisita;
    std::unordered_map<std::string, std::pair<std::string, ArestaExato*>> caminho;

    registroVisitados[fonte->getNome()] = passoAtual;
    caminho[fonte->getNome()] = std::pair<std::string, ArestaExato*>("", nullptr);
    ordemVisita.push(fonte);

    while(!ordemVisita.empty()) {
        VerticeExato* verticeAtual = ordemVisita.front();
        ordemVisita.pop();

        if(verticeAtual == sumidouro) {
            break;
        }

        std::vector<ArestaExato*>* vizinhos = verticeAtual->getVizinhos();
        for(ArestaExato* aresta : *vizinhos) {
            VerticeExato* vizinho = aresta->getVizinho();

            bool jaFoiVizitado = registroVisitados[vizinho->getNome()] >= passoAtual;
            bool estaNoMaximoDaCapacidade = aresta->getFluxoDisponivel() <= 0;
            if(jaFoiVizitado || estaNoMaximoDaCapacidade) {
                continue;
            }

            registroVisitados[vizinho->getNome()] = passoAtual;
            caminho[vizinho->getNome()] = std::pair<std::string, ArestaExato*>(verticeAtual->getNome(), aresta);
            ordemVisita.push(vizinho);
        }
    }

    if(caminho.find(sumidouro->getNome()) == caminho.end()) {
        return 0;
    }
    
    int menorValor = INFINITO;
    for(std::pair<std::string, ArestaExato*> par = caminho[sumidouro->getNome()]; par.second != nullptr; par = caminho[par.first]) {
        if(menorValor > par.second->getFluxoDisponivel()) {
            menorValor = par.second->getFluxoDisponivel();
        }
    }

    for(std::pair<std::string, ArestaExato*> par = caminho[sumidouro->getNome()]; par.second != nullptr; par = caminho[par.first]) {
        par.second->incrementarFluxo(menorValor);
    }

    return menorValor;
}