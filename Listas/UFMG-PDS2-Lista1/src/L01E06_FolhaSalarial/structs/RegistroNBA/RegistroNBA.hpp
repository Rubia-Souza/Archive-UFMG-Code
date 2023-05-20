#ifndef REGISTRO_NBA_H
#define REGISTRO_NBA_H

#include <map>
#include <string>

#include "../Time/Time.hpp"

struct RegistroNBA {
    std::map<std::string, Time, std::less<std::string>> times;

    RegistroNBA();

    void adicionar_time(const std::string nome);
    void adicionar_jogador(const std::string nome_time, const std::string nome_jogador, const std::string posicao, const unsigned int salario);

    void imprimir_lista_jogadores_time(const std::string nome_time);
    void imprimir_folha_consolidada_time(const std::string nome_time);
    void imprimir_folha_salarial_geral() const;
};

#endif
