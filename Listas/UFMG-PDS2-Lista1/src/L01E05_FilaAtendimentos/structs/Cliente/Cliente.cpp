#include <iostream>
#include <string>

#include "./Cliente.hpp"

#define IDADE_PRIORITARIA 60

#define TEMPO_ATENDIMENTO_PRIORITARIO 12
#define TEMPO_ATENDIMENTO_NORMAL 8

Cliente::Cliente() {
    set_nome("");
    set_idade(0);
    set_senha(0);
}

Cliente::Cliente(const std::string nome, const unsigned int idade, const int senha) {
    set_nome(nome);
    set_idade(idade);
    set_senha(senha);
}

bool Cliente::eh_prioritario() const {
    return (idade >= IDADE_PRIORITARIA);
}

unsigned int Cliente::tempo_estimado_atendimento() const {
    if(eh_prioritario()) {
        return TEMPO_ATENDIMENTO_PRIORITARIO;
    }

    return TEMPO_ATENDIMENTO_NORMAL;
}

void Cliente::imprimir_dados() const {
    std::cout << get_senha() << "\t"
              << get_nome() << "\t"
              << get_idade() << "\n";

    return;
}

void Cliente::set_nome(const std::string nome) {
    this->nome = nome;
    return;
}

std::string Cliente::get_nome() const {
    return nome;
}

void Cliente::set_idade(const unsigned int idade) {
    this->idade = idade;
    return;
}

unsigned int Cliente::get_idade() const {
    return idade;
}

void Cliente::set_senha(const int senha) {
    this->senha = senha;
    return;
}

int Cliente::get_senha() const {
    return senha;
}
