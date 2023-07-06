#include <vector>
#include <string>

#include "VerticeExato.hpp"

#include "ArestaExato.hpp"
#include "TipoArestaExata.hpp"

VerticeExato::VerticeExato(const std::string nome) {
    this->nome = nome;
    this->vizinhos = new std::vector<ArestaExato*>();

    return;
}

VerticeExato::~VerticeExato() {
    for(ArestaExato* aresta : *vizinhos) {
        delete aresta;
    }
    delete vizinhos;
    
    return;
}

void VerticeExato::setNome(const std::string nome) {
    this->nome = nome;
    return;
}

std::string VerticeExato::getNome() const {
    return nome;
}

void VerticeExato::adicionarVizinho(ArestaExato* arestaParaVizinho) {
    vizinhos->push_back(arestaParaVizinho);
    return;
}

std::vector<ArestaExato*>* VerticeExato::getVizinhos() {
    return vizinhos;
}