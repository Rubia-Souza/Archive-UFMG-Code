#ifndef POKEBOLA_H
#define POKEBOLA_H

#include "../Pokemon/Pokemon.hpp"
#include "../PokemonCapturado/PokemonCapturado.hpp"

class Pokebola {
    private:
        static int count;

    protected:
        int id = 0;
        PokemonCapturado* pokemon = nullptr;

    public:
        Pokebola();
        ~Pokebola();

        void guardarPokemon();
        PokemonCapturado* liberarPokemon();
        bool contemPokemon() const;

        virtual bool capturar(const Pokemon& pokemon);
        virtual void printInfo() const;

    protected:
        virtual void printContent() const;
        static void decrementCount();
        static void incrementCount();

    private:
        void setId(const int id);
        void setPokemon(const Pokemon& pokemon);

    public:
        int getId() const;
        static unsigned int getQuantidadeTotalPokebolas();  
};

#endif
