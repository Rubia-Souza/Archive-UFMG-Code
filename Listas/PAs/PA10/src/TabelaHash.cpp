#include <string>
#include "TabelaHash.hpp"

TabelaHash::TabelaHash() {
    dado = "";
    vazio = true;
    retirada = false;

    return;
}

TabelaHash::~TabelaHash() {
    dado = "";
    vazio = true;
    retirada = false;

    return;
}

string TabelaHash::getDado() const {
    return dado;
}

void TabelaHash::setDado(const string dado) {
    this->dado = dado;
    return;
}

bool TabelaHash::estaVazio() const {
    return vazio;
}

void TabelaHash::setVazio(const bool vazio) {
    this->vazio = vazio;
    return;
}

bool TabelaHash::foiRetirada() const {
    return retirada;
}

void TabelaHash::setRetirada(const bool retirada) {
    this->retirada = retirada;
    return;
}