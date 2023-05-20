#include <iostream>
#include <string>
#include <math.h>
#include <sstream>

#include "Drone.hpp"
#include "../Ponto2D/Ponto2D.hpp"

#define QUANTIDADE_PADRAO_ENERGIA_INICIAL 100
#define TAMANHO_MAXIMO_BUFFER_MENSAGENS 5

std::string criar_mensagem(const Drone& drone);

Drone::Drone() {
    set_id(-1);
    set_energia(0);
    set_raio_comunicacao(0.0);
    set_posicao_atual(*(new Ponto2D()));
    this->mensagens = new std::string[TAMANHO_MAXIMO_BUFFER_MENSAGENS];
    this->limpar_mensagens();
    index_salvar_mensagem = 0;
}

Drone::Drone(const int id, const Ponto2D posicao_atual, const double raio_comunicacao) {
    set_id(id);
    set_energia(QUANTIDADE_PADRAO_ENERGIA_INICIAL);
    set_posicao_atual(posicao_atual);
    set_raio_comunicacao(raio_comunicacao);
    this->mensagens = new std::string[TAMANHO_MAXIMO_BUFFER_MENSAGENS];
    this->limpar_mensagens();
    index_salvar_mensagem = 0;
}

void Drone::mover(const double velocidade, const double orientacao_velocidade, const double tempo) {
    if(get_energia() <= 0) {
        return;
    }

    const double distanciaPercorrida = velocidade * tempo;
    set_energia(get_energia() - distanciaPercorrida);

    const double x_final = distanciaPercorrida * cos(orientacao_velocidade) + get_posicao_atual().get_x();
    this->posicao_atual.set_x(x_final);
    
    const double y_final = distanciaPercorrida * sin(orientacao_velocidade) + get_posicao_atual().get_y();
    this->posicao_atual.set_y(y_final);

    if(get_energia() <= 50) {
        std::cout << "Alerta, energia baixa!" << "\n";
    }

    return;
}

double Drone::calcular_distancia(const Drone* drone) const {
    return this->get_posicao_atual().calcular_distancia(drone->get_posicao_atual());
}

void Drone::broadcast_mensagem(Drone** drones, const unsigned int qtd_drones) {
    std::string mensagem = criar_mensagem(*this);

    for(unsigned int i = 0; i < qtd_drones; i++) {
        if(esta_no_alcance(drones[i]) && drones[i]->get_id() != get_id()) {
            drones[i]->salvar_mensagem(mensagem);
        }
    }

    return;
}

std::string criar_mensagem(const Drone& drone) {
    std::stringstream mensagem;
    mensagem.clear();

    mensagem << "Drone: " << drone.get_id() 
             << ", Posição: " << drone.get_posicao_atual().get_dados();
    
    return mensagem.str();
}

bool Drone::esta_no_alcance(const Drone* drone) const {
    double distancia = calcular_distancia(drone);
    return distancia <= raio_comunicacao;
}

void Drone::salvar_mensagem(const std::string mensagem) {
    if(index_salvar_mensagem >= TAMANHO_MAXIMO_BUFFER_MENSAGENS) {
        index_salvar_mensagem = 0;
    }

    this->mensagens[index_salvar_mensagem] = mensagem;
    index_salvar_mensagem++;

    return;
}

void Drone::deletar_mensagen(const std::string& mensagem) {
    for(unsigned int i = 0; i < TAMANHO_MAXIMO_BUFFER_MENSAGENS; i++) {
        if(mensagens[i] == mensagem) {
            mensagens[i] = "";
        }
    }

    return;
}

void Drone::limpar_mensagens() {
    for(unsigned int i = 0; i < TAMANHO_MAXIMO_BUFFER_MENSAGENS; i++) {
        mensagens[i] = "";
    }

    return;
}

void Drone::imprimir_mensagens_recebidas() const {
    std::cout << "Mensagens de " << this->get_id() << "\n";

    for(unsigned int i = 0; i < TAMANHO_MAXIMO_BUFFER_MENSAGENS; i++) {
        if(get_mensagens()[i] != "") {
            std::cout << mensagens[i] << "\n";
        }
    }

    return;
}

void Drone::imprimir_status() const {
    std::cout << get_id() << "\t" << get_posicao_atual().get_x() 
              << "\t" << get_posicao_atual().get_y() << "\t" << get_energia() << "\n";
    return;
}

void Drone::set_id(const int id) {
    this->id = id;
    return;
}

int Drone::get_id() const {
    return id;
}

void Drone::set_energia(const double energia) {
    this->energia = energia;
    return;
}

double Drone::get_energia() const {
    return energia;
}

void Drone::set_raio_comunicacao(const double raio_comunicacao) {
    this->raio_comunicacao = raio_comunicacao;
    return;
}

double Drone::get_raio_comunicacao() const {
    return raio_comunicacao;
}

void Drone::set_posicao_atual(const Ponto2D posicao_atual) {
    this->posicao_atual = posicao_atual;
    return;
}

Ponto2D Drone::get_posicao_atual() const {
    return posicao_atual;
}

std::string* Drone::get_mensagens() const {
    return this->mensagens;
}
