#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

#include "DicionarioArvoreAVL.h"

#include "Nodo.h"

#include "Dicionario.h"
#include "Verbete.h"

DicionarioArvoreAVL::DicionarioArvoreAVL() : Dicionario() {
    raiz = nullptr;
    return;
}

DicionarioArvoreAVL::~DicionarioArvoreAVL() {
    limpar();
    return;
}

void DicionarioArvoreAVL::inserir(Verbete& verbete)  {
    raiz = inserirRecursivamente(raiz, verbete);
    return;
}

Nodo* DicionarioArvoreAVL::inserirRecursivamente(Nodo* nodo, Verbete& verbete) {
    if(raiz == nullptr) {
        nodo = new Nodo();

        nodo->setConteudo(&verbete);
        nodo->setAltura(1);
        quantidadeElementos++;

        return nodo;
    }
    else if(nodo == nullptr) {
        nodo = new Nodo();
        
        nodo->setConteudo(&verbete);
        nodo->setAltura(1);
        quantidadeElementos++;

        return nodo;
    }
    else if(nodo->getConteudo()->getPalavra() == verbete.getPalavra() && nodo->getConteudo()->getTipo() == verbete.getTipo()) {
        nodo->getConteudo()->adicionarSignificado(*verbete.getSignificados());
        return nodo;
    }

    if(verbete.getPalavra() < nodo->getConteudo()->getPalavra()) {
        nodo->setNodoEsquerdo(inserirRecursivamente(nodo->getNodoEsquerdo(), verbete));
    }
    else if(verbete.getPalavra() >= nodo->getConteudo()->getPalavra()) {
        nodo->setNodoDireito(inserirRecursivamente(nodo->getNodoDireito(), verbete));
    }

    atualizarAlturaNodo(nodo);
    const int fatorBalanceamento = calcularFatorBalanceamento(nodo);

    if(fatorBalanceamento >= 2 && verbete.getPalavra() < nodo->getNodoEsquerdo()->getConteudo()->getPalavra()) {
        return rotacionarParaDireita(nodo);
    }
    else if(fatorBalanceamento <= -2 && verbete.getPalavra() >= nodo->getNodoDireito()->getConteudo()->getPalavra()) {
        return rotacionarParaEsquerda(nodo);
    }
    else if(fatorBalanceamento >= 2 && verbete.getPalavra() >= nodo->getNodoEsquerdo()->getConteudo()->getPalavra()) {
        nodo->setNodoEsquerdo(rotacionarParaEsquerda(nodo->getNodoEsquerdo()));
        return rotacionarParaDireita(nodo);
    }
    else if(fatorBalanceamento <= -2 && verbete.getPalavra() < nodo->getNodoDireito()->getConteudo()->getPalavra()) {
        nodo->setNodoDireito(rotacionarParaDireita(nodo->getNodoDireito()));
        return rotacionarParaEsquerda(nodo);
    }

    return nodo;
}

Verbete* DicionarioArvoreAVL::pesquisar(const std::string palavra, const TiposVerbete tipo)  {
    return pesquisarRecursivamente(raiz, palavra, tipo);
}

Verbete* DicionarioArvoreAVL::pesquisarRecursivamente(Nodo*& nodo, const std::string palavra, const TiposVerbete tipo) {
    if(nodo == nullptr) {
        return nullptr;
    }
    else if(nodo->getConteudo()->getPalavra() == palavra && nodo->getConteudo()->getTipo() == tipo) {
        return nodo->getConteudo();
    }

    if(palavra < nodo->getConteudo()->getPalavra()) {
        return pesquisarRecursivamente(nodo->getNodoEsquerdo(), palavra, tipo);
    }
    else if(palavra > nodo->getConteudo()->getPalavra()) {
        return pesquisarRecursivamente(nodo->getNodoDireito(), palavra, tipo);
    }
    else if(palavra == nodo->getConteudo()->getPalavra() && nodo->getConteudo()->getTipo() != tipo) {
        Verbete* verbeteBuscado = pesquisarRecursivamente(nodo->getNodoDireito(), palavra, tipo);
        if(verbeteBuscado != nullptr) {
            return verbeteBuscado;
        }

        verbeteBuscado = pesquisarRecursivamente(nodo->getNodoEsquerdo(), palavra, tipo);
        if(verbeteBuscado != nullptr) {
            return verbeteBuscado;
        }
    }

    return nullptr;
}

void DicionarioArvoreAVL::atualizar(Verbete& verbete)  {
    atualizarRecursivamente(raiz, verbete);
    return;
}

void DicionarioArvoreAVL::atualizarRecursivamente(Nodo*& nodo, Verbete& verbete) {
    if(nodo == nullptr) {
        return;
    }
    else if(nodo->getConteudo()->getPalavra() == verbete.getPalavra() && nodo->getConteudo()->getTipo() == verbete.getTipo()) {
        Verbete* conteudoAntigo = nodo->getConteudo();

        nodo->setConteudo(&verbete);

        delete conteudoAntigo;
        return;
    }

    if(verbete.getPalavra() < nodo->getConteudo()->getPalavra()) {
        atualizarRecursivamente(nodo->getNodoEsquerdo(), verbete);
    }
    else if(verbete.getPalavra() >= nodo->getConteudo()->getPalavra()) {
        atualizarRecursivamente(nodo->getNodoDireito(), verbete);
    }

    return;
}

void DicionarioArvoreAVL::remover(const std::string palavra, const TiposVerbete tipo)  {
    raiz = removerRecursivamente(raiz, palavra, tipo);
    return;
}

Nodo* DicionarioArvoreAVL::removerRecursivamente(Nodo* nodo, const std::string palavra, const TiposVerbete tipo) {
    if(nodo == nullptr) {
        return nodo;
    }

    if(palavra < nodo->getConteudo()->getPalavra()) {
        nodo->setNodoEsquerdo(removerRecursivamente(nodo->getNodoEsquerdo(), palavra, tipo));
    }
    else if(palavra > nodo->getConteudo()->getPalavra()) {
        nodo->setNodoDireito(removerRecursivamente(nodo->getNodoDireito(), palavra, tipo));
    }
    else if(palavra == nodo->getConteudo()->getPalavra() && tipo != nodo->getConteudo()->getTipo()) {
        nodo->setNodoDireito(removerRecursivamente(nodo->getNodoDireito(), palavra, tipo));
        nodo->setNodoEsquerdo(removerRecursivamente(nodo->getNodoEsquerdo(), palavra, tipo));
    }
    
    if(palavra == nodo->getConteudo()->getPalavra() && tipo == nodo->getConteudo()->getTipo()) { // Nodo que será excluido foi encontrado
        if(nodo->getNodoEsquerdo() == nullptr) { // Remove como se tivesse um filho (ou nenhum) na direita
            Nodo* filho = nodo->getNodoDireito();
            delete nodo;
            quantidadeElementos--;
            return filho;
        }
        else if(nodo->getNodoDireito() == nullptr) { // Remove como se tivesse um filho na esquerda
            Nodo* filho = nodo->getNodoEsquerdo();
            delete nodo;
            quantidadeElementos--;
            return filho;
        }
        else { // Remove nodo com dois filhos
            Nodo* filho = encontrarMenorValorSubArvoreDireita(nodo->getNodoDireito());

            // Troca o menor valor da subarvore da direita com o nodo autal ("remoção")
            Verbete* copiaConteudo = new Verbete(*filho->getConteudo());
            nodo->setConteudo(copiaConteudo);

            // Remove o nodo que teve o conteudo substituido com o atual da subarvore da direita
            nodo->setNodoDireito(removerRecursivamente(nodo->getNodoDireito(), nodo->getConteudo()->getPalavra(), nodo->getConteudo()->getTipo()));
            quantidadeElementos--;
        }
    }

    if(nodo == nullptr) {
        return nodo;
    }

    atualizarAlturaNodo(nodo);
    const int fatorBalanceamento = calcularFatorBalanceamento(nodo);
    const int fatorBalanceamentoSubArvoreEsquerda = calcularFatorBalanceamento(nodo->getNodoEsquerdo());
    const int fatorBalanceamentoSubArvoreDireita = calcularFatorBalanceamento(nodo->getNodoDireito());

    if(fatorBalanceamento >= 2 && fatorBalanceamentoSubArvoreEsquerda >= 0) {
        return rotacionarParaDireita(nodo);
    }
    else if(fatorBalanceamento >= 2 && fatorBalanceamentoSubArvoreEsquerda <= -1) {
        nodo->setNodoEsquerdo(rotacionarParaEsquerda(nodo->getNodoEsquerdo()));
        return rotacionarParaDireita(nodo);
    }
    else if(fatorBalanceamento <= -2 && fatorBalanceamentoSubArvoreDireita <= 0) {
        return rotacionarParaEsquerda(nodo);
    }
    else if(fatorBalanceamento <= -2 && fatorBalanceamentoSubArvoreDireita >= 1) {
        nodo->setNodoDireito(rotacionarParaDireita(nodo->getNodoDireito()));
        return rotacionarParaEsquerda(nodo);
    }

    return nodo;
}

Nodo* DicionarioArvoreAVL::encontrarMenorValorSubArvoreDireita(Nodo* subarvore) {
    Nodo* alvo = subarvore;

    while(alvo->getNodoEsquerdo() != nullptr) {
        alvo = alvo->getNodoEsquerdo();
    }

    return alvo;
}

void DicionarioArvoreAVL::imprimir()  {
    imprimirRecursivamente(raiz);
    return;
}

void DicionarioArvoreAVL::imprimirRecursivamente(Nodo*& nodo) {
    if(nodo != nullptr) {
        imprimirRecursivamente(nodo->getNodoEsquerdo());
        nodo->getConteudo()->imprimir();
        imprimirRecursivamente(nodo->getNodoDireito());
    }

    return;
}

void DicionarioArvoreAVL::imprimirEmArquivo(std::ofstream* arquivo) {
    imprimirEmArquivoRecursivo(raiz, arquivo);
    return;
}

void DicionarioArvoreAVL::imprimirEmArquivoRecursivo(Nodo*& nodo, std::ofstream* arquivo) {
    if(nodo != nullptr) {
        imprimirEmArquivoRecursivo(nodo->getNodoEsquerdo(), arquivo);
        nodo->getConteudo()->imprimirEmArquivo(arquivo);
        imprimirEmArquivoRecursivo(nodo->getNodoDireito(), arquivo);
    }

    return;
}

void DicionarioArvoreAVL::imprimirArvoreHorizontal() {
    imprimirArvoreHorizontal(raiz, ESPACAMENTO_PADRAO);
    return;
}

void DicionarioArvoreAVL::imprimirArvoreHorizontal(Nodo*& nodo, unsigned int espacamento) {
    if(nodo == nullptr) {
      return;
    }
    
    espacamento += ESPACAMENTO_PADRAO;
    imprimirArvoreHorizontal(nodo->getNodoDireito(), espacamento);

    std::cout << "\n";
    for(unsigned int i = ESPACAMENTO_PADRAO; i < espacamento; i++) {
      std::cout << " ";
    }
    std::cout << nodo->getConteudo()->getPalavra() << "\n";

    imprimirArvoreHorizontal(nodo->getNodoEsquerdo(), espacamento);
    return;
}

void DicionarioArvoreAVL::limpar() {
    limparRecursivamente(raiz);
    raiz = nullptr;

    return;
}

void DicionarioArvoreAVL::limparRecursivamente(Nodo*& nodo) {
    if(nodo != nullptr) {
        limparRecursivamente(nodo->getNodoEsquerdo());
        limparRecursivamente(nodo->getNodoDireito());
        delete nodo;
    }

    return;
}

bool DicionarioArvoreAVL::estaVazia() {
    return (raiz == nullptr);
}

void DicionarioArvoreAVL::removerVerbetesComMaisDeUmSignificado() {
    Verbete* verbetesComMaisDeUmSignificado = new Verbete[quantidadeElementos];
    unsigned int quantidadePalavrasComMaisDeUmSignificado = 0;

    buscarVerbetesComMaisDeUmSignificadoRecursivo(verbetesComMaisDeUmSignificado, raiz, quantidadePalavrasComMaisDeUmSignificado);

    for(unsigned int i = 0; i < quantidadePalavrasComMaisDeUmSignificado; i++) {
        remover(verbetesComMaisDeUmSignificado[i].getPalavra(), verbetesComMaisDeUmSignificado[i].getTipo());
    }

    delete[] verbetesComMaisDeUmSignificado;
    return;
}

void DicionarioArvoreAVL::buscarVerbetesComMaisDeUmSignificadoRecursivo(Verbete verebetes[], Nodo* nodo, unsigned int& index) {
    if(nodo == nullptr) {
        return;
    }
    else if(nodo->getConteudo()->getQuantidadeSignificados() >= 1) {
        verebetes[index].setPalavra(nodo->getConteudo()->getPalavra());
        verebetes[index].setTipo(nodo->getConteudo()->getTipo());
        index++;
    }

    if(nodo->getNodoEsquerdo() != nullptr) {
        buscarVerbetesComMaisDeUmSignificadoRecursivo(verebetes, nodo->getNodoEsquerdo(), index);
    }
    
    if(nodo->getNodoDireito() != nullptr) {
        buscarVerbetesComMaisDeUmSignificadoRecursivo(verebetes, nodo->getNodoDireito(), index);
    }

    return;
}

void DicionarioArvoreAVL::atualizarAlturaNodo(Nodo*& nodo) {
    int alturaSubArvoreEsquerda = ((nodo->getNodoEsquerdo() == nullptr) ? 0 : nodo->getNodoEsquerdo()->getAltura());
    int alturaSubArvoreDireita = ((nodo->getNodoDireito() == nullptr) ? 0 : nodo->getNodoDireito()->getAltura());

    nodo->setAltura(std::max(alturaSubArvoreEsquerda, alturaSubArvoreDireita) + 1);

    return;
}

int DicionarioArvoreAVL::calcularFatorBalanceamento(Nodo*& nodo) {
    if(nodo == nullptr) {
        return 0;
    }

    int alturaDireita = ((nodo->getNodoDireito() == nullptr) ? 0 : nodo->getNodoDireito()->getAltura());
    int alturaEsquerda = ((nodo->getNodoEsquerdo() == nullptr) ? 0 : nodo->getNodoEsquerdo()->getAltura());

    int fatorBalanceamento = alturaEsquerda - alturaDireita;
    return fatorBalanceamento;
}

Nodo* DicionarioArvoreAVL::rotacionarParaEsquerda(Nodo* nodo) {
    Nodo* acima = nodo;
    Nodo* abaixo = acima->getNodoDireito();
    Nodo* esquerdoAbaixo = abaixo->getNodoEsquerdo();

    acima->setNodoDireito(esquerdoAbaixo);
    abaixo->setNodoEsquerdo(acima);

    atualizarAlturaNodo(acima);
    atualizarAlturaNodo(abaixo);

    return abaixo;
}

Nodo* DicionarioArvoreAVL::rotacionarParaDireita(Nodo* nodo) {
    Nodo* acima = nodo;
    Nodo* abaixo = acima->getNodoEsquerdo();
    Nodo* direitoAbaixo = abaixo->getNodoDireito();

    acima->setNodoEsquerdo(direitoAbaixo);
    abaixo->setNodoDireito(acima);

    atualizarAlturaNodo(acima);
    atualizarAlturaNodo(abaixo);

    return abaixo;
}
