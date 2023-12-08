#include <string>
#include <iostream>

#include "Set.hpp"
#include "TabelaHash.hpp"

Set::Set(const unsigned int tamanho) {
    tamanhoInicial = tamanho;
    tamanhoTabela = 2 * tamanhoInicial;
    tamanhoConjunto = 0;

    tabela = new TabelaHash[tamanhoTabela];
    for(unsigned int i = 0; i < tamanhoTabela; i++) {
        tabela[i].setVazio(true);
        tabela[i].setRetirada(false);
    }

    return;
}

Set::~Set() {
    delete[] tabela;
    return;
}

int Set::calcularHash(const string palavra) {
    int idHash = 0;

    for(char caracter : palavra) {
        idHash = (idHash * 31 + static_cast<int>(caracter)) % tamanhoTabela;
    }

    return idHash;
}

void Set::recriarHash(const unsigned int posicao) {
    int i = 1;
    int novaPosicao = (posicao + i) % tamanhoTabela;

    while(!tabela[novaPosicao].estaVazio() && i <= tamanhoTabela) {
        novaPosicao = (posicao + (i++)) % tamanhoTabela;
    }

    if(i <= tamanhoTabela) {
        tabela[novaPosicao].setDado(tabela[posicao].getDado());
        tabela[novaPosicao].setVazio(false);
        tabela[novaPosicao].setRetirada(false);

        tabela[posicao].setVazio(true);
    }
    else {
        ajustarTamanho(2 * tamanhoTabela);
    }

    return;
}

void Set::ajustarTamanho(const unsigned int novoTamanho) {
    TabelaHash* novaTabela = new TabelaHash[novoTamanho];
    for(unsigned int i = 0; i < novoTamanho; i++) {
        novaTabela[i].setVazio(true);
        novaTabela[i].setRetirada(false);
    }

    for(unsigned int i = 0; i < tamanhoTabela; i++) {
        if(!tabela[i].estaVazio() && !tabela[i].foiRetirada()) {
            int novaPosicao = calcularHash(tabela[i].getDado());
            int j = 1;

            while(!novaTabela[novaPosicao].estaVazio()) {
                novaPosicao = (novaPosicao + j) % novoTamanho;
                j++;
            }

            novaTabela[novaPosicao].setDado(tabela[i].getDado());
            novaTabela[novaPosicao].setVazio(false);
        }
    }

    delete[] tabela;
    
    tabela = novaTabela;
    tamanhoTabela = novoTamanho;

    return;
}

void Set::inserir(const string palavra) {
    int posicaoAlvo = calcularHash(palavra);
    int i = 1;

    while(!tabela[posicaoAlvo].estaVazio() && tabela[posicaoAlvo].getDado() != palavra && i <= tamanhoTabela) {
        posicaoAlvo = (posicaoAlvo + i) % tamanhoTabela;
        i++;
    }

    if(i > tamanhoTabela) {
        ajustarTamanho(2 * tamanhoTabela);
        inserir(palavra);
    }
    else if(tabela[posicaoAlvo].estaVazio() || tabela[posicaoAlvo].foiRetirada()) {
        tabela[posicaoAlvo].setDado(palavra);
        tabela[posicaoAlvo].setVazio(false);
        tabela[posicaoAlvo].setRetirada(false);

        tamanhoConjunto++;
    }

    return;
}

void Set::remover(const string palavra) {
    int posicaoAlvo = calcularHash(palavra);
    int i = 1;

    while(!tabela[posicaoAlvo].estaVazio() && tabela[posicaoAlvo].getDado() != palavra && i <= tamanhoTabela) {
        posicaoAlvo = (posicaoAlvo + i) % tamanhoTabela;
        i++;
    }

    if(!tabela[posicaoAlvo].estaVazio() && tabela[posicaoAlvo].getDado() == palavra) {
        tabela[posicaoAlvo].setVazio(true);
        tabela[posicaoAlvo].setRetirada(true);

        tamanhoConjunto--;
    }

    return;
}

bool Set::pertence(const string palavra) {
    int posicaoAlvo = calcularHash(palavra);
    int i = 1;

    while(!tabela[posicaoAlvo].estaVazio() && tabela[posicaoAlvo].getDado() != palavra && i <= tamanhoTabela) {
        posicaoAlvo = (posicaoAlvo + i) % tamanhoTabela;
        i++;
    }

    return (!tabela[posicaoAlvo].estaVazio() && tabela[posicaoAlvo].getDado() == palavra && !tabela[posicaoAlvo].foiRetirada());
}

Set* Set::intersecao(Set& outroConjunto) {
    Set* conjuntoIntersecao = new Set(tamanhoInicial);

    for(unsigned int i = 0; i < tamanhoTabela; i++) {
        if(!tabela[i].estaVazio() && !tabela[i].foiRetirada() && outroConjunto.pertence(tabela[i].getDado())) {
            conjuntoIntersecao->inserir(tabela[i].getDado());
        }
    }

    return conjuntoIntersecao;
}

Set* Set::uniao(Set& outroConjunto) {
    Set* conjuntoUniao = new Set(tamanhoInicial);

    for(unsigned int i = 0; i < tamanhoTabela; i++) {
        if(!tabela[i].estaVazio() && !tabela[i].foiRetirada()) {
            conjuntoUniao->inserir(tabela[i].getDado());
        }
    }

    for(unsigned int i = 0; i < outroConjunto.getTamanhoTabela(); i++) {
        if(!outroConjunto.estaVazio(i) && !outroConjunto.foiRetirada(i)) {
            conjuntoUniao->inserir(outroConjunto.getDado(i));
        }
    }

    return conjuntoUniao;
}

Set* Set::diferencaSimetrica(Set& outroConjunto) {
    Set* conjuntoDiferencaSimetrica = new Set(tamanhoInicial);

    for(unsigned int i = 0; i < tamanhoTabela; i++) {
        if(!tabela[i].estaVazio() && !tabela[i].foiRetirada() && !outroConjunto.pertence(tabela[i].getDado())) {
            conjuntoDiferencaSimetrica->inserir(tabela[i].getDado());
        }
    }

    for(unsigned int i = 0; i < outroConjunto.getTamanhoTabela(); i++) {
        if(!outroConjunto.estaVazio(i) && !outroConjunto.foiRetirada(i) && !pertence(outroConjunto.getDado(i))) {
            conjuntoDiferencaSimetrica->inserir(outroConjunto.getDado(i));
        }
    }

    return conjuntoDiferencaSimetrica;
}

void Set::print() {
    for(unsigned int i = 0; i < tamanhoTabela; i++) {
        if(!tabela[i].estaVazio() && !tabela[i].foiRetirada()) {
            cout << tabela[i].getDado() << " ";
        }
    }

    cout << endl;
    return;
}

unsigned int Set::getTamanhoTabela() const {
    return tamanhoTabela;
}

unsigned int Set::getTamanho() const {
    return tamanhoConjunto;
}

TabelaHash* Set::getTabela() {
    return tabela;
}

bool Set::estaVazio(const unsigned int posicao) {
    return tabela[posicao].estaVazio();
}

bool Set::foiRetirada(const unsigned int posicao) {
    return tabela[posicao].foiRetirada();
}

string Set::getDado(const unsigned int posicao) {
    return tabela[posicao].getDado();
}
