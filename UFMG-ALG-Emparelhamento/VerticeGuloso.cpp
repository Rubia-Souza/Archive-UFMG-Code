#include <vector>
#include <string>

#include "VerticeGuloso.hpp"

VerticeGuloso::VerticeGuloso(const std::string nome) {
    this->nome = nome;
    this->vizinhos = new std::vector<VerticeGuloso*>();

    return;
}

VerticeGuloso::~VerticeGuloso() {
    delete vizinhos;
    return;
}

void VerticeGuloso::setNome(const std::string nome) {
    this->nome = nome;
    return;
}

std::string VerticeGuloso::getNome() const {
    return nome;
}

void VerticeGuloso::adicionarVizinho(VerticeGuloso* vizinho) {
    vizinhos->push_back(vizinho);
    quantidadePossibilidades++;
    
    return;
}

std::vector<VerticeGuloso*>* VerticeGuloso::getVizinhos() {
    return vizinhos;
}

void VerticeGuloso::setQuantidadePossibilidades(const unsigned int novaQuantidade) {
    this->quantidadePossibilidades = novaQuantidade;
    return;
}

unsigned int VerticeGuloso::getQuantidadePossibilidades() const {
    return quantidadePossibilidades;
}