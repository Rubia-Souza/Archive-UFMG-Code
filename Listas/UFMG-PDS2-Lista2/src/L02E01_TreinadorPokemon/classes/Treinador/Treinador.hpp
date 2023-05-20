#ifndef TREINADOR_H
#define TREINADOR_H

#include <string>
#include <vector>

#include "../Pokebola/Pokebola.hpp"
#include "../EvolutionBall/EvolutionBall.hpp"
#include "../HealthBall/HealthBall.hpp"

class Treinador {
    private:
        std::string nome = "";
        std::vector<EvolutionBall*> evolution_balls;
        std::vector<HealthBall*> health_balls;

    public:
        Treinador(const std::string nome);
        ~Treinador();

        HealthBall* selecionarHealthBall(const int id) const;
        EvolutionBall* selecionarEvolBall(const int id) const;

        void adicionarPokebola(HealthBall* pokebola);
        void adicionarPokebola(EvolutionBall* pokebola);

        void listarPokemons() const;
        bool possuiPokebolas() const;
        bool possuiPokemons() const;

        void setNome(const std::string nome);
        std::string getNome() const;

    private:
        void printNome() const;
        void printPokemons() const;
        void printHealthBalls() const;
        void printEvolutionBalls() const;
};

#endif
