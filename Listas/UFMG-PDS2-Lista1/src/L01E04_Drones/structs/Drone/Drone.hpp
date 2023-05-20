#ifndef DRONE_H
#define DRONE_H

#include <string>

#include "../Ponto2D/Ponto2D.hpp"

struct Drone {
    int id;
    double energia;
    double raio_comunicacao;
    Ponto2D posicao_atual;
    std::string* mensagens;
    unsigned int index_salvar_mensagem;

    Drone();
    Drone(const int id, const Ponto2D posicao_atual, const double raio_comunicacao);

    void mover(const double velocidade, const double orientacao_velocidade, const double tempo);
    double calcular_distancia(const Drone* drone) const;
    bool esta_no_alcance(const Drone* drone) const;

    void broadcast_mensagem(Drone** drones, const unsigned int qtd_drones);
    void salvar_mensagem(const std::string mensagem);
    void deletar_mensagen(const std::string& mensagem);
    void limpar_mensagens();

    void imprimir_mensagens_recebidas() const;
    void imprimir_status() const;

    void set_id(const int id);
    int get_id() const;

    void set_energia(const double energia);
    double get_energia() const;

    void set_raio_comunicacao(const double raio_comunicacao);
    double get_raio_comunicacao() const;

    void set_posicao_atual(const Ponto2D posicao_atual);
    Ponto2D get_posicao_atual() const;

    std::string* get_mensagens() const;
};

#endif