#ifndef FILA_ATENDIMENTO_H
#define FILA_ATENDIMENTO_H

#include <string>

#include "./Cliente/Cliente.hpp"

struct Celula {
    Celula* proxima;
    Celula* anterior;
    Cliente valor;

    Celula();
    Celula(Cliente valor);
    Celula(Celula* proxima, Celula* anterior);
    Celula(Celula* proxima, Celula* anterior, Cliente valor);

    void set_proxima(Celula* proxima);
    Celula* get_proxima() const;
    void set_anterior(Celula* anterior);
    Celula* get_anterior() const;
    void set_valor(Cliente valor);
    Cliente get_valor() const;
};

struct ListaDuplamenteEncadeada {
    Celula* inicio;
    Celula* fim;

    unsigned int tamanho;

    ListaDuplamenteEncadeada();
    
    void adicionar_ao_fim(const Cliente valor);
    void adicionar_ao_comeco(const Cliente valor);
    void adicionar_antes(const Cliente valor, const int senhaReferencia);
    void adicionar_depois(const Cliente valor, const int senhaReferencia);

    void remover(const Cliente valor);
    Cliente* pop_first();
    Cliente* pop_last();
    void limpar();

    Cliente get_elemento_em(const unsigned int posicao) const;
    bool esta_vazia() const;

    unsigned int get_tamanho() const;
};

struct FilaAtendimento {
    int ultima_senha_gerada;
    int index_ultimo_prioritario;
    ListaDuplamenteEncadeada* clientes;

    FilaAtendimento();

    void adicionar_cliente(const std::string nome, const unsigned int idade);
    Cliente* chamar_cliente();
    void estimativa_tempo_espera(const int senha) const;
    void imprimir_fila() const;

    bool esta_vazia() const;

    int get_nova_senha();
};

#endif
