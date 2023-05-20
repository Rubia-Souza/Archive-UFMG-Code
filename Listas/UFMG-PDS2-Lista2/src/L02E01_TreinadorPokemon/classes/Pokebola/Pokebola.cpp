#include <iostream>
#include <ctime>
#include <cstdlib>

#include "./Pokebola.hpp"
#include "../Pokemon/Pokemon.hpp"
#include "../PokemonCapturado/PokemonCapturado.hpp"

#define MAXIMO_CHANCE_CAPTURA 1
#define MINIMO_CHANCE_CAPTURA 0
#define LIMEAR_CAPTURA 0.5

int Pokebola::count = -1;

Pokebola::Pokebola() {
    Pokebola::incrementCount();
    setId(getQuantidadeTotalPokebolas());
}

Pokebola::~Pokebola() {
    setId(-1);
    delete pokemon;
}

void Pokebola::guardarPokemon() {
    if(contemPokemon()) {
        pokemon->setDormindo(true);
    }

    return;
}

PokemonCapturado* Pokebola::liberarPokemon() {
    if(!contemPokemon()) {
        return nullptr;
    }

    pokemon->setDormindo(false);
    return pokemon;
}

bool Pokebola::contemPokemon() const {
    return (pokemon != nullptr);
}

bool Pokebola::capturar(const Pokemon& pokemon) {
    float num_aleatorio = static_cast<float> (rand()) / static_cast<float> (RAND_MAX);

    bool foi_capturado = num_aleatorio > LIMEAR_CAPTURA;
    if(!foi_capturado) {
        return false;
    }

    setPokemon(pokemon);
    return true;
}

void Pokebola::printInfo() const {
    std::cout << "Pokebola ID: " << getId() << "\n";
    printContent();

    return;
}

void Pokebola::printContent() const {
    if(contemPokemon()) {
        pokemon->info();
    }
    else {
        std::cout << "A pokebola não possui um pokemon\n";
    }

    return;
}

void Pokebola::decrementCount() {
    count -= 1;
    return;
}

void Pokebola::incrementCount() {
    count += 1;
    return;
}

void Pokebola::setId(const int id) {
    this->id = id;
    return;
}

int Pokebola::getId() const {
    return id;
}

void Pokebola::setPokemon(const Pokemon& pokemon) {
    this->pokemon = new PokemonCapturado(pokemon);
    return;
}

unsigned int Pokebola::getQuantidadeTotalPokebolas() {
    return count;
}
