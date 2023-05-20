#include "./PokemonCapturado.hpp"
#include "../Pokemon/Pokemon.hpp"

PokemonCapturado::PokemonCapturado(const Pokemon& pokemon) : Pokemon(pokemon.getNome(), pokemon.getTipo(), pokemon.getProxEvolucao(), pokemon.getForcaAtaque(), pokemon.getForcaDefesa(), pokemon.getSaude()) {
    setEvoluido(false);
    setDormindo(true);
}

PokemonCapturado::~PokemonCapturado() {}

void PokemonCapturado::evoluir(const double taxaPoder) {
    if(estaEvoluido()) {
        return;
    }
    
    setEvoluido(true);

    setNome(getProxEvolucao());
    setProxEvolucao("");

    double nova_forca = getForcaAtaque() + getForcaAtaque() * taxaPoder;
    double nova_defesa = getForcaDefesa() + getForcaDefesa() * taxaPoder;

    setForcaAtaque(nova_forca);
    setForcaDefesa(nova_defesa);

    return;
}

void PokemonCapturado::setEvoluido(const bool evoluido) {
    this->evoluido = evoluido;
    return;
}

bool PokemonCapturado::estaEvoluido() const {
    return evoluido;
}

void PokemonCapturado::setDormindo(const bool dormindo) {
    this->dormindo = dormindo;
    return;
}

bool PokemonCapturado::estaDormindo() const {
    return dormindo;
}
