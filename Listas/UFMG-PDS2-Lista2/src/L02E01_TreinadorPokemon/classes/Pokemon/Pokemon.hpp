#ifndef POKEMON_H
#define POKEMON_H

#include <string>

class Pokemon {
    protected:
        std::string nome = "";
        std::string tipo = "";
        double forcaAtaque = 0.0;
        double forcaDefesa = 0.0;
        std::string proxEvolucao = "";
        double saude = 0.0;

    public:
        Pokemon(const std::string nome, const std::string tipo, const std::string proxEvolucao, const double forcaAtaque, const double forcaDefesa, const double saude);
        ~Pokemon();

        void maxSaude();
        void info() const;

        void setNome(const std::string nome);
        std::string getNome() const;

        void setTipo(const std::string tipo);
        std::string getTipo() const;

        void setForcaAtaque(const double forcaAtaque);
        double getForcaAtaque() const;

        void setForcaDefesa(const double forcaDefesa);
        double getForcaDefesa() const;

        void setProxEvolucao(const std::string proxEvolucao);
        std::string getProxEvolucao() const;

        void setSaude(const double saude);
        double getSaude() const;
};

#endif
