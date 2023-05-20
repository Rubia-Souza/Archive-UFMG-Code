#ifndef HEALTH_BALL_H
#define HEALTH_BALL_H

#include <ctime>

#include "../Pokebola/Pokebola.hpp"

class HealthBall : public Pokebola {
    private:
        time_t ultimoUso = 0.0;
        double intervalo = 0;

    public:
        HealthBall(const double intervalo);
        ~HealthBall();
        
        bool recuperarPokemon();
        virtual void printInfo() const override;

    private:
        void setUltimoUso(const time_t ultimoUso);
        void setIntervalo(const double intervalo);

    public:
        time_t getUltimoUso() const;
        double getIntervalo() const;
};

#endif
