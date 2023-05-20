#include <iostream>
#include <list>
#include <string>
#include <algorithm>

#include "./Time.hpp"
#include "../Jogador/Jogador.hpp"

Time::Time() {
    set_nome("");
    jogadores = *(new std::list<Jogador>());
}

Time::Time(const std::string nome) {
    set_nome(nome);
    jogadores = *(new std::list<Jogador>());
}

void Time::adicionar_jogador(const std::string nome, const std::string posicao, const unsigned int salario) {
    Jogador* jogador = new Jogador(nome, posicao, salario);
    jogadores.push_back(*jogador);

    return;
}

void Time::remover_jogador(const std::string& nome, const std::string& posicao) {
    for(std::list<Jogador>::iterator iterador = jogadores.begin(); iterador != jogadores.end(); iterador++) {
        if(iterador->get_nome() == nome && iterador->get_posicao() == posicao) {
            jogadores.erase(iterador);
        }
    }

    return;
}

Jogador Time::get_jogador(const std::string& nome) const {
    for(Jogador jogador : jogadores) {
        if(jogador.get_nome() == nome) {
            return jogador;
        }
    }

    return *(new Jogador());
}

void Time::imprimir_lista_jogadores() {
    std::cout << get_nome() << "\n";
    jogadores.sort([](const Jogador& jogador1, const Jogador& jogador2) {
        return jogador2.get_salario() < jogador1.get_salario();
    });

    for(Jogador jogador : jogadores) {
        jogador.imprimir_dados();
    }

    return;
}

void Time::imprimir_folha_salarial_consolidada() const {
    unsigned int salario_total = 0;

    for(Jogador jogador : jogadores) {
        salario_total += jogador.get_salario();
    }

    std::cout << get_nome() << "\t" << salario_total << "\n";
    return;
}

void Time::set_nome(const std::string nome) {
    this->nome = nome;
    return;
}

std::string Time::get_nome() const {
    return nome;
}

std::list<Jogador> Time::get_jogadores() const {
    return jogadores;
}