#include <string>

#include "Mensagem.h"

Mensagem::Mensagem() {}

Mensagem::Mensagem(const std::string texto, const unsigned int prioridade) {
    setTexto(texto);
    setPrioridade(prioridade);

    return;
}

Mensagem::~Mensagem() {}

void Mensagem::setTexto(const std::string texto) {
    this->texto = texto;
    return;
}

std::string Mensagem::getTexto() const {
    return texto;
}

void Mensagem::setPrioridade(const unsigned int prioridade) {
    this->prioridade = prioridade;
    return;
}

unsigned int Mensagem::getPrioridade() const {
    return prioridade;
}
