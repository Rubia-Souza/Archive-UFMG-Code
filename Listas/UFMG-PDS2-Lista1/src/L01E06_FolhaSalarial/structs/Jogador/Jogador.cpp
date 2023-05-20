#include <iostream>
#include <string>

#include "./Jogador.hpp"

Jogador::Jogador() {
    set_nome("");
    set_posicao("");
    set_salario(0);
}

Jogador::Jogador(const std::string nome) {
    set_nome(nome);
    set_posicao("");
    set_salario(0);
}

Jogador::Jogador(const std::string nome, const std::string posicao, const unsigned int salario) {
    set_nome(nome);
    set_posicao(posicao);
    set_salario(salario);
}

bool Jogador::operator <(const Jogador & outro_jogador) {
    return outro_jogador.get_salario() < get_salario();
}

void Jogador::imprimir_dados() const {
    std::cout << get_nome() << "\t" << get_posicao() << "\t" << get_salario() << "\n";
    return;
}

void Jogador::set_nome(const std::string nome) {
    this->nome = nome;
    return;
}

std::string Jogador::get_nome() const {
    return nome;
}

void Jogador::set_posicao(const std::string posicao) {
    this->posicao = posicao;
    return;
}

std::string Jogador::get_posicao() const {
    return posicao;
}

void Jogador::set_salario(const unsigned int salario){
    this->salario = salario;
    return;
}

unsigned int Jogador::get_salario() const {
    return salario;
}
