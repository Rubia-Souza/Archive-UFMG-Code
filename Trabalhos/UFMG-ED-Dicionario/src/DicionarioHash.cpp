#include <string>
#include <fstream>

#include "Dicionario.h"
#include "DicionarioHash.h"

#include "Celula.h"
#include "Verbete.h"
#include "QuickSort.h"

DicionarioHash::DicionarioHash() : Dicionario() {
    // TODO: Criar tamanho dinamico da tabela
}
DicionarioHash::~DicionarioHash() {}

void DicionarioHash::inserir(Verbete& verbete) {
    unsigned int indexLista = hash(verbete.getPalavra());

    for(Celula<Verbete*>* iterador = listasVerbetes[indexLista].getInicio()->getProximaCelula(); iterador != listasVerbetes[indexLista].getFim(); iterador = iterador->getProximaCelula()) {
        if(iterador->getValor()->getPalavra() == verbete.getPalavra() && iterador->getValor()->getTipo() == verbete.getTipo()) {
            iterador->getValor()->adicionarSignificado(*verbete.getSignificados());
            return;
        }
    }

    listasVerbetes[indexLista].adicionarFim(&verbete);
    tamanho++;
    return;
}

Verbete* DicionarioHash::pesquisar(const std::string palavra, const TiposVerbete tipo) {
    unsigned int indexLista = hash(palavra);
    for(Celula<Verbete*>* iterador = listasVerbetes[indexLista].getInicio()->getProximaCelula(); iterador != listasVerbetes[indexLista].getFim(); iterador = iterador->getProximaCelula()) {
        if(iterador->getValor()->getPalavra() == palavra && iterador->getValor()->getTipo() == tipo) {
            return iterador->getValor();
        }
    }

    return nullptr;
}

void DicionarioHash::atualizar(Verbete& verbete) {
    unsigned int indexLista = hash(verbete.getPalavra());

    for(Celula<Verbete*>* iterador = listasVerbetes[indexLista].getInicio()->getProximaCelula(); iterador != listasVerbetes[indexLista].getFim(); iterador = iterador->getProximaCelula()) {
        if(iterador->getValor()->getPalavra() == verbete.getPalavra()) {
            Verbete* conteudoAntigo = iterador->getValor();

            iterador->setValor(&verbete);

            delete conteudoAntigo;
            return;
        }
    }

    return;
}

void DicionarioHash::remover(const std::string palavra, const TiposVerbete tipo) {
    unsigned int indexLista = hash(palavra);

    for(Celula<Verbete*>* iterador = listasVerbetes[indexLista].getInicio()->getProximaCelula(); iterador != listasVerbetes[indexLista].getFim(); iterador = iterador->getProximaCelula()) {
        if(iterador->getValor()->getPalavra() == palavra && iterador->getValor()->getTipo() == tipo) {
            listasVerbetes[indexLista].remover(iterador);
            tamanho--;
            return;
        }
    }

    return;
}

void DicionarioHash::imprimir() {
    Verbete** verbetes = new Verbete*[tamanho];

    unsigned int indexVerbete = 0;
    for(unsigned int i = 0; i < QUANTIDADE_LISTAS; i++) {
        if(!listasVerbetes[i].estaVazia()) {
            for(Celula<Verbete*>* iterador = listasVerbetes[i].getInicio()->getProximaCelula(); iterador != listasVerbetes[i].getFim(); iterador = iterador->getProximaCelula()) {
                verbetes[indexVerbete] = iterador->getValor();
                indexVerbete++;
            }
        }
    }

    QuickSort::ordenarCrescente(verbetes, tamanho);
    for(unsigned int i = 0; i < tamanho; i++) {
        verbetes[i]->imprimir();
    }

    delete[] verbetes;
    return;
}

void DicionarioHash::imprimirEmArquivo(std::ofstream* arquivo) {
    Verbete** verbetes = new Verbete*[tamanho];

    unsigned int indexVerbete = 0;
    for(unsigned int i = 0; i < QUANTIDADE_LISTAS; i++) {
        if(!listasVerbetes[i].estaVazia()) {
            for(Celula<Verbete*>* iterador = listasVerbetes[i].getInicio()->getProximaCelula(); iterador != listasVerbetes[i].getFim(); iterador = iterador->getProximaCelula()) {
                verbetes[indexVerbete] = iterador->getValor();
                indexVerbete++;
            }
        }
    }

    QuickSort::ordenarCrescente(verbetes, tamanho);

    for(unsigned int i = 1; i < tamanho; i++) {
        if(verbetes[i]->getPalavra() == verbetes[i-1]->getPalavra() && verbetes[i]->getTipo() < verbetes[i-1]->getTipo()) {
            Verbete* temp = verbetes[i-1];
            verbetes[i-1] = verbetes[i];
            verbetes[i] = temp;
        }
    }

    for(unsigned int i = 0; i < tamanho; i++) {
        verbetes[i]->imprimirEmArquivo(arquivo);
    }

    delete[] verbetes;
    return;
}

void DicionarioHash::limpar() {
    for(unsigned int i = 0; i < QUANTIDADE_LISTAS; i++) {
        listasVerbetes[i].limpar();
    }

    return;
}

bool DicionarioHash::estaVazia() {
    for(unsigned int i = 0; i < QUANTIDADE_LISTAS; i++) {
        if(!listasVerbetes[i].estaVazia()) {
            return false;
        }
    }

    return true;
}

void DicionarioHash::removerVerbetesComMaisDeUmSignificado() {
    Celula<Verbete*>* proximaCelula = nullptr;

    for(unsigned int i = 0; i < QUANTIDADE_LISTAS; i++) {
        if(!listasVerbetes[i].estaVazia()) {
            for(Celula<Verbete*>* iterador = listasVerbetes[i].getInicio()->getProximaCelula(); iterador != listasVerbetes[i].getFim(); iterador = proximaCelula) {
                proximaCelula = iterador->getProximaCelula();

                if(iterador->getValor()->getQuantidadeSignificados() >= 1) {
                    listasVerbetes[i].remover(iterador);
                    tamanho--;
                }
            }
        }
    }

    return;
}

unsigned int DicionarioHash::hash(const std::string palavra) {
    int soma = 0;

    for(unsigned int i = 0; i < palavra.size(); i++) {
        soma = ((int) palavra[i]) * (i + 1);
    }

    return (soma % QUANTIDADE_LISTAS);
}
