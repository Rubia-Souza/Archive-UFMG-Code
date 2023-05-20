#include <string>
#include <stdexcept>

#include "Usuario.h"

#include "Mensagem.h"
#include "FilaPrioridade.h"
#include "ExcecoesCaixaEntrada.h"
#include "Utils.h"

Usuario::Usuario() {}

Usuario::Usuario(const unsigned int id) {
    setId(id);
    return;
}

Usuario::~Usuario() {}

void Usuario::receberMensagem(const Mensagem mensagem) {
    caixaMensagens.guardarMensagem(mensagem);
    return;
}

Mensagem Usuario::consultarMensagem() {
    Mensagem mensagem;

    try {
        mensagem = caixaMensagens.consultarMensagem();
    }
    catch(const ExcecoesCaixaEntrada::AcessoCaixaEntradaVaziaException* exception) {
        std::string mensagemFormatada = "";
        mensagemFormatada = Utils::replace(exception->what(), "{ID}", std::to_string(getId()));

        throw new ExcecoesCaixaEntrada::AcessoCaixaEntradaVaziaException(mensagemFormatada);
    }

    return mensagem;
}

FilaPrioridade<Mensagem> Usuario::getMensagens() {
    return *caixaMensagens.getMensagens();
}

void Usuario::setId(const unsigned int id) {
    this->id = id;
    return;
}

unsigned int Usuario::getId() const {
    return id;
}

bool Usuario::operator==(const Usuario& outroUsuario) {
    return (getId() == outroUsuario.getId());
}

bool Usuario::operator!=(const Usuario& outroUsuario) {
    return (getId() != outroUsuario.getId());
}
