#include <iostream>

#include "Pilha.h"

#include "Celula.h"
#include "FaixaOrdenacao.h"

Pilha::Pilha() {
    base = new Celula();
    topo = new Celula();

    base->proxima = topo;
    topo->anterior = base;

    return;
}

Pilha::~Pilha() {
    limpar();

    delete base;
    delete topo;

    return;
}

void Pilha::empilhar(FaixaOrdencao faixa) {
    Celula* novaCelula = new Celula();
    novaCelula->valor = new FaixaOrdencao(faixa);

    Celula* antigoTopo = topo->anterior;
    antigoTopo->proxima = novaCelula;

    novaCelula->anterior = antigoTopo;
    novaCelula->proxima = topo;

    topo->anterior = novaCelula;

    tamanho++;
    return;
}

FaixaOrdencao* Pilha::desempilhar() {
    if(estaVazia()) {
        return nullptr;
    }

    Celula* celulaRemovida = topo->anterior;

    Celula* novoTopo = celulaRemovida->anterior;
    novoTopo->proxima = topo;
    topo->anterior = novoTopo;

    FaixaOrdencao* valor = celulaRemovida->valor;
    delete celulaRemovida;

    tamanho--;
    return valor;
}

bool Pilha::estaVazia() {
    return (base->proxima == topo);
}

unsigned int Pilha::getTamanho() {
    return tamanho;
}

void Pilha::limpar() {
    if(estaVazia()) {
        return;
    }

    Celula* proxima = nullptr;
    for(Celula* iterador = base->proxima; iterador != topo; iterador = proxima) {
        proxima = iterador->proxima;
        delete iterador;
    }

    topo->anterior = base;
    base->proxima = topo;
    
    tamanho = 0;
    return;
}

void Pilha::print() const {
    for(Celula* iterador = base->proxima; iterador != topo; iterador = iterador->proxima) {
        std::cout << "Inicio: " << iterador->valor->inicio << " Fim: " << iterador->valor->fim << "\n";
    }
    
    return;
}
