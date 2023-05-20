#include "Nodo.h"

#include "Verbete.h"

Nodo::Nodo() {
    esquerdo = nullptr;
    direito = nullptr;

    conteudo = nullptr;
    altura = 0;

    return;
}

Nodo::~Nodo() {
    esquerdo = nullptr;
    direito = nullptr;

    delete conteudo;
    conteudo = nullptr;

    altura = 0;
    return;
}

void Nodo::setNodoEsquerdo(Nodo* esquerdo) {
    this->esquerdo = esquerdo;
    return;    
}

Nodo*& Nodo::getNodoEsquerdo() {
    return esquerdo;
}

void Nodo::setNodoDireito(Nodo* direito) {
    this->direito = direito;
    return;
}

Nodo*& Nodo::getNodoDireito() {
    return direito;
}

void Nodo::setConteudo(Verbete* conteudo) {
    this->conteudo = conteudo;
    return;
}

Verbete* Nodo::getConteudo() {
    return conteudo;
}

void Nodo::setAltura(const int altura) {
    this->altura = altura;
    return;
}

int Nodo::getAltura() const {
    return altura;
}
