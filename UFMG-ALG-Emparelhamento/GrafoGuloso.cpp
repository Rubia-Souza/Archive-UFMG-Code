#include <string>
#include <unordered_map>

#include "GrafoGuloso.hpp"
#include "VerticeGuloso.hpp"

GrafoGuloso::GrafoGuloso() {
    this->empregos = new std::unordered_map<std::string, VerticeGuloso*>();
    this->trabalhadores = new std::unordered_map<std::string, VerticeGuloso*>();
    this->listaCompletaVertices = new std::unordered_map<std::string, VerticeGuloso*>();

    return;
}

GrafoGuloso::~GrafoGuloso() {
    for(std::unordered_map<std::string, VerticeGuloso*>::iterator iterator = empregos->begin(); iterator != empregos->end(); iterator++) {
        delete iterator->second;
    }
    delete empregos;

    for(std::unordered_map<std::string, VerticeGuloso*>::iterator iterator = trabalhadores->begin(); iterator != trabalhadores->end(); iterator++) {
        delete iterator->second;
    }
    delete trabalhadores;

    delete listaCompletaVertices;

    return;
}

void GrafoGuloso::adicionarTrabalhador(const std::string nome) {
    if(trabalhadores->find(nome) != trabalhadores->end()) {
        return;
    }

    VerticeGuloso* novoVertice = new VerticeGuloso(nome);
    (*trabalhadores)[nome] = novoVertice;
    (*listaCompletaVertices)[nome] = novoVertice;

    return;
}

void GrafoGuloso::adicionarEmprego(const std::string nome) {
    if(empregos->find(nome) != empregos->end()) {
        return;
    }

    VerticeGuloso* novoVertice = new VerticeGuloso(nome);
    (*empregos)[nome] = novoVertice;
    (*listaCompletaVertices)[nome] = novoVertice;

    return;
}

void GrafoGuloso::adicionarQualificacao(const std::string nomeEmprego, const std::string nomeTrabalhador) {
    VerticeGuloso* emprego = (*empregos)[nomeEmprego];
    VerticeGuloso* trabalhador = (*trabalhadores)[nomeTrabalhador];

    emprego->adicionarVizinho(trabalhador);
    trabalhador->adicionarVizinho(emprego);

    return;
}

std::unordered_map<std::string, VerticeGuloso*>* GrafoGuloso::getListaTrabalhadores() {
    return trabalhadores;
}

std::unordered_map<std::string, VerticeGuloso*>* GrafoGuloso::getListaEmpregos() {
    return empregos;
}

std::unordered_map<std::string, VerticeGuloso*>* GrafoGuloso::getListaVertices() {
    return listaCompletaVertices;
}