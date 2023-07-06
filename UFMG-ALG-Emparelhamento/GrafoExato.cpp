#include <unordered_map>
#include <string>

#include "GrafoExato.hpp"

#include "VerticeExato.hpp"
#include "ArestaExato.hpp"
#include "Constantes.hpp"

const std::string GrafoExato::NOME_FONTE = "interno_vertice_fonte";
const std::string GrafoExato::NOME_SUMIDOURO = "interno_vertice_sumidouro";

GrafoExato::GrafoExato() {
    this->fonte = new VerticeExato(NOME_FONTE);
    this->sumidouro = new VerticeExato(NOME_SUMIDOURO);

    this->listaEmpregos = new std::unordered_map<std::string, VerticeExato*>();
    this->listaTrabalhadores = new std::unordered_map<std::string, VerticeExato*>();
    this->listaCompletaVertices = new std::unordered_map<std::string, VerticeExato*>();

    return;
}

GrafoExato::~GrafoExato() {
    delete fonte;
    delete sumidouro;

    for(std::unordered_map<std::string, VerticeExato*>::iterator iterator = listaCompletaVertices->begin(); iterator != listaCompletaVertices->end(); iterator++) {
        delete iterator->second;
    }
    delete listaCompletaVertices;

    delete listaEmpregos;
    delete listaTrabalhadores;

    return;
}

void GrafoExato::adicionarTrabalhador(const std::string nome) {
    if(listaTrabalhadores->find(nome) != listaTrabalhadores->end()) {
        return;
    }

    VerticeExato* novoVertice = new VerticeExato(nome);
    (*listaTrabalhadores)[nome] = novoVertice;
    (*listaCompletaVertices)[nome] = novoVertice;

    ArestaExato* arestaDaFonte = new ArestaExato(novoVertice);
    arestaDaFonte->setCapacidade(1);

    ArestaExato* arestaResidualParaFonte = new ArestaExato(fonte);
    arestaResidualParaFonte->setCapacidade(0);
    arestaResidualParaFonte->setTipo(TipoArestaExata::Residual);

    arestaDaFonte->setArestaAssociada(arestaResidualParaFonte);
    arestaResidualParaFonte->setArestaAssociada(arestaDaFonte);

    fonte->adicionarVizinho(arestaDaFonte);
    novoVertice->adicionarVizinho(arestaResidualParaFonte);

    return;
}

void GrafoExato::adicionarEmprego(const std::string nome) {
    if(listaEmpregos->find(nome) != listaEmpregos->end()) {
        return;
    }

    VerticeExato* novoVertice = new VerticeExato(nome);
    (*listaEmpregos)[nome] = novoVertice;
    (*listaCompletaVertices)[nome] = novoVertice;

    ArestaExato* arestaParaSumidouro = new ArestaExato(sumidouro);
    arestaParaSumidouro->setCapacidade(1);

    ArestaExato* arestaResidualDoSumidouro = new ArestaExato(novoVertice);
    arestaResidualDoSumidouro->setCapacidade(0);
    arestaResidualDoSumidouro->setTipo(TipoArestaExata::Residual);

    arestaParaSumidouro->setArestaAssociada(arestaResidualDoSumidouro);
    arestaResidualDoSumidouro->setArestaAssociada(arestaParaSumidouro);

    novoVertice->adicionarVizinho(arestaParaSumidouro);
    sumidouro->adicionarVizinho(arestaResidualDoSumidouro);

    return;
}

void GrafoExato::adicionarQualificacao(const std::string nomeEmprego, const std::string nomeTrabalhador) {
    VerticeExato* emprego = (*listaEmpregos)[nomeEmprego];
    VerticeExato* trabalhador = (*listaTrabalhadores)[nomeTrabalhador];

    ArestaExato* arestaPadrao = new ArestaExato(emprego);
    arestaPadrao->setCapacidade(1);

    ArestaExato* arestaResidual = new ArestaExato(trabalhador);
    arestaResidual->setCapacidade(0);
    arestaResidual->setTipo(TipoArestaExata::Residual);

    arestaPadrao->setArestaAssociada(arestaResidual);
    arestaResidual->setArestaAssociada(arestaPadrao);

    trabalhador->adicionarVizinho(arestaPadrao);
    emprego->adicionarVizinho(arestaResidual);

    return;
}

VerticeExato* GrafoExato::getFonte() {
    return fonte;
}

VerticeExato* GrafoExato::getSumidouro() {
    return sumidouro;
}

std::unordered_map<std::string, VerticeExato*>* GrafoExato::getListaEmpregos() {
    return listaEmpregos;
}

std::unordered_map<std::string, VerticeExato*>* GrafoExato::getListaTrabalhadores() {
    return listaTrabalhadores;
}

std::unordered_map<std::string, VerticeExato*>* GrafoExato::getListaCompletaVertices() {
    return listaCompletaVertices;
}