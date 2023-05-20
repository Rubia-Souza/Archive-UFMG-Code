#include <string>
#include <iostream>
#include <fstream>

#include "Verbete.h"

#include "TiposVerbete.h"
#include "Lista.h"
#include "Celula.h"

Verbete::Verbete() {
    significados = new Lista<std::string>();
    return;
}

Verbete::Verbete(const Verbete& verbete) {
    this->palavra = verbete.getPalavra();

    this->tipoVerbete = verbete.getTipo();
    
    this->significados = new Lista<std::string>();
    Lista<std::string>* significadosOriginal = verbete.getSignificados();
    this->adicionarSignificado(*significadosOriginal);

    return;
}


Verbete::Verbete(const std::string& palavra, const char tipoVerbete, const std::string& significado) {
    significados = new Lista<std::string>();

    setPalavra(palavra);
    setTipo(tipoVerbete);
    adicionarSignificado(significado);

    return;
}

Verbete::~Verbete() {
    palavra = "";
    tipoVerbete = TiposVerbete::NOME;

    significados->limpar();
    delete significados;
    significados = nullptr;

    return;
}

void Verbete::imprimir() const {
    std::cout << palavra << " (" << char(tipoVerbete) << ")\n";

    if(!significados->estaVazia()) {
        unsigned int indexSignificado = 1;
        for(Celula<std::string>* iterador = significados->getInicio()->getProximaCelula(); iterador != significados->getFim(); iterador = iterador->getProximaCelula()) {
            std::cout << indexSignificado << ". " << iterador->getValor() << "\n";
            indexSignificado++;
        }
    }

    return;
}

void Verbete::imprimirEmArquivo(std::ofstream* arquivo) const {
    *arquivo << palavra << " (" << char(tipoVerbete) << ")\n";

    if(!significados->estaVazia()) {
        unsigned int indexSignificado = 1;
        for(Celula<std::string>* iterador = significados->getInicio()->getProximaCelula(); iterador != significados->getFim(); iterador = iterador->getProximaCelula()) {
            *arquivo << indexSignificado << ". " << iterador->getValor() << "\n";
            indexSignificado++;
        }
    }

    return;
}   

void Verbete::setPalavra(const std::string palavra) {
    this->palavra = palavra;
    return;
}

std::string Verbete::getPalavra() const {
    return palavra;
}

void Verbete::setTipo(const TiposVerbete tipo) {
    this->tipoVerbete = tipo;
    return;
}

void Verbete::setTipo(const char tipo) {
    this->tipoVerbete = converterCharParaTiposVerbete(tipo);
    return;
}

TiposVerbete Verbete::getTipo() const {
    return tipoVerbete;
}

void Verbete::adicionarSignificado(const std::string significado) {
    if(significado.empty()) {
        return;
    }

    significados->adicionarFim(significado);
    return;
}

void Verbete::adicionarSignificado(const Lista<std::string>& significados) {
    if(significados.estaVazia()) {
        return;
    }

    for(Celula<std::string>* iterador = significados.getInicio()->getProximaCelula(); iterador != significados.getFim(); iterador = iterador->getProximaCelula()) {
        adicionarSignificado(iterador->getValor());
    }

    return;
}

Lista<std::string>* Verbete::getSignificados() const {
    return significados;
}

unsigned int Verbete::getQuantidadeSignificados() const {
    return significados->getTamanho();
}
