#include <iostream>
#include <ctime>

#include "./HealthBall.hpp"

time_t getDataHoraAtual();

HealthBall::HealthBall(const double intervalo) {
    setIntervalo(intervalo);
    setUltimoUso(0.0);
}

HealthBall::~HealthBall() {}

bool HealthBall::recuperarPokemon() {
    if(!contemPokemon()) {
        return false;
    }

    time_t data_hora_atual = getDataHoraAtual();
    double tempo_passado = abs(difftime(data_hora_atual, getUltimoUso()));
    if(tempo_passado <= getIntervalo()) {
        return false;
    }

    pokemon->maxSaude();
    setUltimoUso(data_hora_atual);
    return true;
}

time_t getDataHoraAtual() {
    time_t data_hora_atual = 0.0;
    time(&data_hora_atual);
    return data_hora_atual;
}

void HealthBall::printInfo() const {
    std::cout << "HealthBall ID: " << getId() << "\n";
    printContent();

    return;
}

void HealthBall::setUltimoUso(const time_t ultimoUso) {
    this->ultimoUso = ultimoUso;
    return;
}

time_t HealthBall::getUltimoUso() const {
    return ultimoUso;
}

void HealthBall::setIntervalo(const double intervalo) {
    this->intervalo = intervalo;
    return;
}

double HealthBall::getIntervalo() const {
    return intervalo;
}
