#include <map>
#include <string>
#include <algorithm>

#include "./RegistroNBA.hpp"
#include "../Time/Time.hpp"
#include "../Jogador/Jogador.hpp"

RegistroNBA::RegistroNBA() {}

void RegistroNBA::adicionar_time(const std::string nome) {
    Time* novo_time = new Time(nome);
    times.insert(std::pair<std::string, Time>(nome, *novo_time));

    return;
}

void RegistroNBA::adicionar_jogador(const std::string nome_time, const std::string nome_jogador, const std::string posicao, const unsigned int salario) {
    bool possui_time = times.count(nome_time);
    if(!possui_time) {
        adicionar_time(nome_time);
    }

    times[nome_time].adicionar_jogador(nome_jogador, posicao, salario);
    return;
}

void RegistroNBA::imprimir_lista_jogadores_time(const std::string nome_time) {
    times[nome_time].imprimir_lista_jogadores();
    return;
}

void RegistroNBA::imprimir_folha_consolidada_time(const std::string nome_time) {
    times[nome_time].imprimir_folha_salarial_consolidada();
    return;
}

void RegistroNBA::imprimir_folha_salarial_geral() const {
    for(std::map<std::string, Time>::const_iterator iterador = times.begin(); iterador != times.end(); iterador++) {
        iterador->second.imprimir_folha_salarial_consolidada();
    }

    return;
}
