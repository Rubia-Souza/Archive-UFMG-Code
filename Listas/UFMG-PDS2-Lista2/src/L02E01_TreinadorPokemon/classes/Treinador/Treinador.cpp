#include <iostream>
#include <string>
#include <vector>

#include "./Treinador.hpp"
#include "../EvolutionBall/EvolutionBall.hpp"
#include "../HealthBall/HealthBall.hpp"

Treinador::Treinador(const std::string nome){
    setNome(nome);
    evolution_balls = *(new std::vector<EvolutionBall*>());
    health_balls = *(new std::vector<HealthBall*>());
}

Treinador::~Treinador() {
    for(EvolutionBall* evolution_ball : evolution_balls) {
        delete evolution_ball;
    }

    for(HealthBall* health_ball : health_balls) {
        delete health_ball;
    }
}

HealthBall* Treinador::selecionarHealthBall(const int id) const {
    for(HealthBall* health_ball : health_balls) {
        if(health_ball->getId() == id) {
            return health_ball;
        }
    }

    return nullptr;   
}

EvolutionBall* Treinador::selecionarEvolBall(const int id) const {
    for(EvolutionBall* evolution_ball : evolution_balls) {
        if(evolution_ball->getId() == id) {
            return evolution_ball;
        }
    }

    return nullptr;
}

void Treinador::adicionarPokebola(HealthBall* pokebola) {
    health_balls.push_back(pokebola);
    return;
}

void Treinador::adicionarPokebola(EvolutionBall* pokebola) {
    evolution_balls.push_back(pokebola);
    return;
}

void Treinador::listarPokemons() const {
    printNome();

    if(!possuiPokebolas()) {
        std::cout << "O treinador não possui pokebolas\n";
        return;
    }

    printPokemons();

    return;
}

bool Treinador::possuiPokebolas() const {
    return (health_balls.size() > 0 || evolution_balls.size() > 0);
}

bool Treinador::possuiPokemons() const {
    for(HealthBall* health_ball : health_balls) {
        if(health_ball->contemPokemon()) {
            return true;
        }
    }

    for(EvolutionBall* evolution_ball : evolution_balls) {
        if(evolution_ball->contemPokemon()) {
            return true;
        }
    }

    return false;
}

void Treinador::printNome() const {
    std::cout << "Treinador: " << getNome() << "\n";
    return;
}

void Treinador::printPokemons() const {
    printHealthBalls();
    printEvolutionBalls();

    return;
}

void Treinador::printHealthBalls() const {
    for(HealthBall* health_ball : health_balls) {
        health_ball->printInfo();
    }

    return;
}

void Treinador::printEvolutionBalls() const {
    for(EvolutionBall* evolution_ball : evolution_balls) {
        evolution_ball->printInfo();
    }

    return;
}

void Treinador::setNome(const std::string nome) {
    this->nome = nome;
    return;
}

std::string Treinador::getNome() const {
    return nome;
}
