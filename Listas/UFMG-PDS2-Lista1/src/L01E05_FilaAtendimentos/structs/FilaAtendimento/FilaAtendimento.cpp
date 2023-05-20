#include <iostream>
#include <string>

#include "./FilaAtendimento.hpp"
#include "../Cliente/Cliente.hpp"

#define VALOR_SENHA_INICIAL 0

Celula::Celula() {
    set_proxima(nullptr);
    set_anterior(nullptr);
    set_valor(*(new Cliente()));
}

Celula::Celula(Cliente valor) {
    set_proxima(nullptr);
    set_anterior(nullptr);
    set_valor(valor);
}

Celula::Celula(Celula* proxima, Celula* anterior) {
    set_proxima(proxima);
    set_anterior(anterior);
    set_valor(*(new Cliente()));
}

Celula::Celula(Celula* proxima, Celula* anterior, Cliente valor) {
    set_proxima(proxima);
    set_anterior(anterior);
    set_valor(valor);
}

void Celula::set_proxima(Celula* proxima) {
    this->proxima = proxima;
    return;
}

Celula* Celula::get_proxima() const {
    return proxima;
}

void Celula::set_anterior(Celula* anterior) {
    this->anterior = anterior;
    return;
}

Celula* Celula::get_anterior() const {
    return anterior;
}

void Celula::set_valor(Cliente valor) {
    this->valor = valor;
    return;
}

Cliente Celula::get_valor() const {
    return valor;
}

ListaDuplamenteEncadeada::ListaDuplamenteEncadeada() {
    inicio = new Celula();
    fim = new Celula();

    inicio->set_proxima(fim);
    fim->set_anterior(inicio);
    tamanho = 0;
}

bool ListaDuplamenteEncadeada::esta_vazia() const {
    return (inicio->proxima == fim && fim->anterior == inicio);
}

void ListaDuplamenteEncadeada::adicionar_ao_fim(const Cliente valor) {
    Celula* novaCelula = new Celula(valor);

    Celula* penultimaCelula = fim->get_anterior();
    penultimaCelula->set_proxima(novaCelula);

    novaCelula->set_anterior(penultimaCelula);
    novaCelula->set_proxima(fim);

    fim->set_anterior(novaCelula);
    tamanho++;

    return;
}

void ListaDuplamenteEncadeada::adicionar_ao_comeco(const Cliente valor) {
    Celula* novaCelula = new Celula(valor);

    Celula* segundaCelula = inicio->get_proxima();
    segundaCelula->set_anterior(novaCelula);

    novaCelula->set_proxima(segundaCelula);
    novaCelula->set_anterior(inicio);

    inicio->set_proxima(novaCelula);
    tamanho++;

    return;
}

void ListaDuplamenteEncadeada::adicionar_antes(const Cliente valor, const int senhaReferencia) {
    Celula* posterior = nullptr;
    for(posterior = inicio->get_proxima(); posterior != fim; posterior = posterior->get_proxima()) {
        if(posterior->get_valor().get_senha() == senhaReferencia) {
            break;
        }
    }

    Celula* anterior = posterior->get_anterior();
    Celula* novaCelula = new Celula(valor);

    anterior->set_proxima(novaCelula);
    posterior->set_anterior(novaCelula);

    novaCelula->set_anterior(anterior);
    novaCelula->set_proxima(posterior);

    tamanho++;
    return;
}

void ListaDuplamenteEncadeada::adicionar_depois(const Cliente valor, const int senhaReferencia) {
    Celula* anterior = nullptr;
    for(anterior = inicio->get_proxima(); anterior != fim; anterior = anterior->get_proxima()) {
        if(anterior->get_valor().get_senha() == senhaReferencia) {
            break;
        }
    }

    Celula* posterior = anterior->get_proxima();
    Celula* novaCelula = new Celula(valor);

    anterior->set_proxima(novaCelula);
    posterior->set_anterior(novaCelula);

    novaCelula->set_anterior(anterior);
    novaCelula->set_proxima(posterior);

    tamanho++;
    return;
}

void ListaDuplamenteEncadeada::remover(const Cliente valor) {
    Celula* alvo = nullptr;
    for(alvo = inicio->get_proxima(); alvo != fim; alvo = alvo->get_proxima()) {
        if(alvo->get_valor().get_senha() == valor.get_senha()) {
            break;
        }
    }

    if(alvo == fim) {
        return;
    }

    Celula* anterior = alvo->get_anterior();
    Celula* posterior = alvo->get_proxima();

    anterior->set_proxima(posterior);
    posterior->set_anterior(anterior);

    delete alvo;
    return;
}

Cliente* ListaDuplamenteEncadeada::pop_first() {
    if(esta_vazia()) {
        return nullptr;
    }

    Celula* celulaRemovida = inicio->get_proxima();
    Celula* novoValorInicial = celulaRemovida->get_proxima();

    inicio->set_proxima(novoValorInicial);
    novoValorInicial->set_anterior(inicio);

    tamanho--;
    return &(celulaRemovida->valor);
}

Cliente* ListaDuplamenteEncadeada::pop_last() {
    if(esta_vazia()) {
        return nullptr;
    }

    Celula* celulaRemovida = fim->get_anterior();
    Celula* novoValorFinal = celulaRemovida->get_anterior();

    fim->set_anterior(novoValorFinal);
    novoValorFinal->set_proxima(fim);

    tamanho--;
    return &(celulaRemovida->valor);
}

void ListaDuplamenteEncadeada::limpar() {
    Celula* proximaReferencia = nullptr;
    
    for(Celula* iterador = inicio->get_proxima(); iterador != fim; iterador = proximaReferencia) {
        proximaReferencia = iterador->get_proxima();
        delete iterador;
    }

    inicio->set_proxima(fim);
    fim->set_anterior(inicio);
    tamanho = 0;

    return;
}

Cliente ListaDuplamenteEncadeada::get_elemento_em(const unsigned int posicao) const {
    if(posicao >= get_tamanho()) {
        return *(new Cliente());
    }

    Celula* alvo = inicio->get_proxima();
    for(unsigned int i = 0; i < posicao; i++) {
        alvo = alvo->get_proxima();
    }

    return alvo->get_valor();
}

unsigned int ListaDuplamenteEncadeada::get_tamanho() const {
    return tamanho;
}

FilaAtendimento::FilaAtendimento() {
    ultima_senha_gerada = VALOR_SENHA_INICIAL;
    index_ultimo_prioritario = -1;
    clientes = new ListaDuplamenteEncadeada();
}

void FilaAtendimento::adicionar_cliente(const std::string nome, const unsigned int idade) {
    Cliente* cliente = new Cliente(nome, idade, this->get_nova_senha());

    if(!cliente->eh_prioritario()) {
        clientes->adicionar_ao_fim(*cliente);
        return;
    }
    
    if(index_ultimo_prioritario == -1) {
        clientes->adicionar_ao_comeco(*cliente);
    }
    else {
        Cliente ultimo_prioritario = clientes->get_elemento_em(index_ultimo_prioritario);
        clientes->adicionar_depois(*cliente, ultimo_prioritario.get_senha());
    }
    index_ultimo_prioritario++;

    return;
}

Cliente* FilaAtendimento::chamar_cliente() {
    if(clientes->esta_vazia()) {
        std::cout << "Fila vazia!\n";
        return nullptr;
    }

    Cliente* primeiroFila = clientes->pop_first();
    if(primeiroFila->eh_prioritario()) {
        index_ultimo_prioritario--;
    }

    return primeiroFila;
}

void FilaAtendimento::estimativa_tempo_espera(const int senha) const {
    unsigned int tempoEspera = 0;
    Cliente clienteAtual;

    for(unsigned int i = 0; i < clientes->get_tamanho(); i++) {
        clienteAtual = clientes->get_elemento_em(i);
        if(clienteAtual.get_senha() != senha) {
            tempoEspera += clienteAtual.tempo_estimado_atendimento();
        }
        else {
            break;
        }
    }

    std::cout << "Tempo estimado para atender " << clienteAtual.get_nome() << " eh " << tempoEspera << " minutos.\n";
    return;
}

void FilaAtendimento::imprimir_fila() const {
    for(unsigned int i = 0; i < clientes->get_tamanho(); i++) {
        Cliente clienteAtual = clientes->get_elemento_em(i);
        clienteAtual.imprimir_dados(); 
    }
}

bool FilaAtendimento::esta_vazia() const {
    return clientes->esta_vazia();
}

int FilaAtendimento::get_nova_senha() {
    this->ultima_senha_gerada += 1;
    return ultima_senha_gerada;
}
