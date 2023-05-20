#ifndef MENSAGEM_H
#define MENSAGEM_H

#include <string>

#include "../Drone/Drone.hpp"

struct Mensagem {
    std::string id;
    Drone remetente;
    Drone destinatario;
    std::string mensagem;

    Mensagem();
    Mensagem(const std::string id, const Drone remetente, const Drone destinatario, const std::string mensagem);

    void setId(const std::string id);
    std::string getId() const;

    void setRemetente(const Drone remetente);
    Drone getRemetente() const;

    void setDestinatario(const Drone destinatario);
    Drone getDestinatario() const;

    void setMensagem(const std::string mensagem);
    std::string getMensagem() const;
};

#endif
