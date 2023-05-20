#include <string>

#include "../Drone/Drone.hpp"
#include "./Mensagem.hpp"

Mensagem::Mensagem() {
    setDestinatario(*(new Drone()));
    setRemetente(*(new Drone()));
    setMensagem("");
}

Mensagem::Mensagem(const std::string id, const Drone remetente, const Drone destinatario, const std::string mensagem) {
    setId(id);
    setDestinatario(destinatario);
    setRemetente(remetente);
    setMensagem(mensagem);
}

void Mensagem::setId(const std::string id) {
    this->id = id;
    return;
}

void Mensagem::setRemetente(const Drone remetente) {
    this->remetente = remetente;
    return;
}

void Mensagem::setDestinatario(const Drone destinatario) {
    this->destinatario = destinatario;
    return;
}

void Mensagem::setMensagem(const std::string mensagem) {
    this->mensagem = mensagem;
    return;
}

std::string Mensagem::getId() const {
    return this->id;
}

Drone Mensagem::getRemetente() const {
    return this->remetente;
}

Drone Mensagem::getDestinatario() const {
    return this->destinatario;
}

std::string Mensagem::getMensagem() const {
    return this->mensagem;
}
