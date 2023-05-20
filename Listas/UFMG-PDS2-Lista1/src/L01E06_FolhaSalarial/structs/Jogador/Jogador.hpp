#ifndef JOGADOR_H
#define JOGADOR_H

#include <string>

struct Jogador {
    std::string nome;
    std::string posicao;
    unsigned int salario;

    Jogador();
    Jogador(const std::string nome);
    Jogador(const std::string nome, const std::string posicao, const unsigned int salario);

    bool operator <(const Jogador & outro_jogador);

    void imprimir_dados() const;

    void set_nome(const std::string nome);
    std::string get_nome() const;

    void set_posicao(const std::string posicao);
    std::string get_posicao() const;

    void set_salario(const unsigned int salario);
    unsigned int get_salario() const;
};

#endif
