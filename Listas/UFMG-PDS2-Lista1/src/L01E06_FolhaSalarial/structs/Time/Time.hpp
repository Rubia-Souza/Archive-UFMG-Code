#ifndef TIME_H
#define TIME_H

#include <list>
#include <string>

#include "../Jogador/Jogador.hpp"

struct Time {
    std::string nome;
    std::list<Jogador> jogadores;

    Time();
    Time(const std::string nome);

    void adicionar_jogador(const std::string nome, const std::string posicao, const unsigned int salario);
    void remover_jogador(const std::string& nome, const std::string& posicao);
    Jogador get_jogador(const std::string& nome) const;

    void imprimir_lista_jogadores();
    void imprimir_folha_salarial_consolidada() const;

    void set_nome(const std::string nome);
    std::string get_nome() const;

    std::list<Jogador> get_jogadores() const;
};

#endif
