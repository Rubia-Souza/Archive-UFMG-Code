#ifndef POKEMON_CAPTURADO_H
#define POKEMON_CAPTURADO_H

#include "../Pokemon/Pokemon.hpp"

class PokemonCapturado : public Pokemon {
    private:
        bool evoluido = false;
        bool dormindo = false;

    public:
        PokemonCapturado(const Pokemon& pokemon);
        ~PokemonCapturado();

        void evoluir(const double taxaPoder);

        void setEvoluido(const bool evoluido);
        bool estaEvoluido() const;

        void setDormindo(const bool dormindo);
        bool estaDormindo() const;
};

#endif
