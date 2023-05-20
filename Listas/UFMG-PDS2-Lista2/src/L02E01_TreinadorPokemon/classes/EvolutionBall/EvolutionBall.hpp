#ifndef EVOLUTION_BALL_H
#define EVOLUTION_BALL_H

#include "../Pokebola/Pokebola.hpp"

class EvolutionBall : public Pokebola {
    private:
        double taxaPoder = 0.0;
        bool habilidadeUsada = false;

    public:
        EvolutionBall(const double taxaPoder);
        ~EvolutionBall();

        bool evoluirPokemon();
        virtual void printInfo() const override;

        void setTaxaPoder(const double taxaPoder);
        double getTaxaPoder() const;

        void setHabilidadeUsada(const bool habilidadeUsada);
        bool getHabilidadeUsada() const;
};

#endif
