#include <iostream>
#include <string>

#include "HeapMinimo.hpp"

#include "Vertice.hpp"

const std::string MENSAGEM_ERRO_ATUALIZAR_HEAP_VAZIO = "[ERROR]: Um elemento tentou ser atualizado com o heap vazio.";
const std::string MENSAGEM_ERRO_TAMANHO_MAXIMO_ATINGIDO = "[ERROR]: O tamanho maximo do heap foi atingido e um elemento foi inserido.";
const std::string MENSAGEM_ERRO_REMOVER_HEAP_VAZIO = "[ERROR]: Um elemento foi removido com o heap vazio.";
const std::string MENSAGEM_ERRO_ATUALIZACAO_INVALIDA = "[ERROR]: Uma distancia tentou ser atualizada para um valor superior.";

HeapMinimo::HeapMinimo(const unsigned int tamanhoMaximo){
    this->tamanhoMaximo = tamanhoMaximo;
    
    distancias = new std::vector<std::pair<Vertice*, unsigned int>>(tamanhoMaximo);
    for(std::pair<Vertice*, unsigned int> distancia : *distancias) {
        distancia.first = nullptr;
        distancia.second = 0;
    }
    
    return;
}

HeapMinimo::~HeapMinimo(){
    delete distancias;
}

void HeapMinimo::adicionar(Vertice* vertice, const unsigned int distancia) {
    if(tamanhoOcupado >= tamanhoMaximo) {
        std::cout << MENSAGEM_ERRO_TAMANHO_MAXIMO_ATINGIDO;
        throw MENSAGEM_ERRO_TAMANHO_MAXIMO_ATINGIDO;
    }

    tamanhoOcupado++;

    int indexInsercao = tamanhoOcupado - 1;
    (*distancias)[indexInsercao] = std::pair<Vertice*, unsigned int>(vertice, distancia);

    int indexAjuste = indexInsercao;
    while(indexAjuste != 0 && (*distancias)[getPai(indexAjuste)].second > (*distancias)[indexAjuste].second) {
        std::pair<Vertice*, unsigned int> temporario = (*distancias)[getPai(indexAjuste)];
        (*distancias)[getPai(indexAjuste)] = (*distancias)[indexAjuste];
        (*distancias)[indexAjuste] = temporario;
        
        indexAjuste = getPai(indexAjuste);
    }
    
    return;
}

void HeapMinimo::atualizar(Vertice* vertice, const unsigned int novaDistancia) {
    if(estaVazio()) {
        std::cout << MENSAGEM_ERRO_ATUALIZAR_HEAP_VAZIO;
        throw MENSAGEM_ERRO_ATUALIZAR_HEAP_VAZIO;
    }

    int indexVerticeAtualizado = 0;
    for(std::pair<Vertice*, unsigned int> distancia : *distancias) {
        if(distancia.first->getId() == vertice->getId()) {
            break;
        }
        indexVerticeAtualizado++;
    }

    if(novaDistancia >= (*distancias)[indexVerticeAtualizado].second) {
        std::cout << MENSAGEM_ERRO_ATUALIZACAO_INVALIDA;
        throw MENSAGEM_ERRO_ATUALIZACAO_INVALIDA;
    }
    
    (*distancias)[indexVerticeAtualizado].second = novaDistancia;
    
    int indexAjuste = indexVerticeAtualizado;
    while(indexAjuste != 0 && (*distancias)[getPai(indexAjuste)].second > (*distancias)[indexAjuste].second) {
        std::pair<Vertice*, unsigned int> temporario = (*distancias)[getPai(indexAjuste)];
        (*distancias)[getPai(indexAjuste)] = (*distancias)[indexAjuste];
        (*distancias)[indexAjuste] = temporario;
        
        indexAjuste = getPai(indexAjuste);
    }
    
    return;
}

Vertice* HeapMinimo::popMenor() {
    if(estaVazio()) {
        std::cout << MENSAGEM_ERRO_REMOVER_HEAP_VAZIO;
        throw MENSAGEM_ERRO_REMOVER_HEAP_VAZIO;
    }
    
    if(tamanhoOcupado == 1) {
        tamanhoOcupado--;
        return (*distancias)[0].first;
    }

    Vertice* menor = (*distancias)[0].first;
    (*distancias)[0] = (*distancias)[tamanhoOcupado - 1];

    tamanhoOcupado--;
    ajustarHeap(0);
    
    return menor;
}

void HeapMinimo::ajustarHeap(const int indexPai) {
    int indexFilhoEsquerdo = getFilhoEsquerdo(indexPai);
    int indexFilhoDireito = getFilhoDireito(indexPai);
    int indexMenor = indexPai;

    if(indexFilhoEsquerdo < tamanhoOcupado && (*distancias)[indexFilhoEsquerdo].second < (*distancias)[indexMenor].second) {
        indexMenor = indexFilhoEsquerdo;
    }

    if(indexFilhoDireito < tamanhoOcupado && (*distancias)[indexFilhoDireito].second < (*distancias)[indexMenor].second) {
        indexMenor = indexFilhoDireito;
    }

    if(indexMenor == indexPai) {
        return;
    }

    std::pair<Vertice*, unsigned int> temporario = (*distancias)[indexPai];
    (*distancias)[indexPai] = (*distancias)[indexMenor];
    (*distancias)[indexMenor] = temporario;
    
    ajustarHeap(indexMenor);

    return;
}

bool HeapMinimo::estaVazio() const {
    return tamanhoOcupado <= 0;
}

int HeapMinimo::getPai(const int index) const {
    return ((index - 1) / 2);
}

int HeapMinimo::getFilhoDireito(const int index) const {
    return ((2 * index) + 2);
}

int HeapMinimo::getFilhoEsquerdo(const int index) const {
    return ((2 * index) + 1);
}

void HeapMinimo::printHeap(){
    int power = 0;
    int value = 1;
    for(int i = 0; i < tamanhoOcupado; i++){
        if(i == value){
            std::cout << std::endl;
            power += 1;
            value += (1 << power);
        }
        std::cout << "(" << (*distancias)[i].first->getId() << ", " << (*distancias)[i].second << ") | ";
    }
    std::cout << std::endl;
}