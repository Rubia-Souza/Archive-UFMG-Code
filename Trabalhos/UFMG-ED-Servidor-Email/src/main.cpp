#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stdexcept>

#include "Servidor.h"
#include "ExcecoesServidor.h"
#include "ExcecoesCaixaEntrada.h"
#include "ExcecoesMain.h"

#include "Utils.h"

const std::string COMANDO_CADASTRAR_USUARIO = "CADASTRA";
const std::string COMANDO_REMOVER_USUARIO = "REMOVE";
const std::string COMANDO_ENTREGAR_MENSAGEM_USUARIO = "ENTREGA";
const std::string COMANDO_CONSULTAR_MENSAGEM_USUARIO = "CONSULTA";

const std::string MENSAGEM_SUCESSO_CADASTRO_USUARIO = "OK: CONTA {ID} CADASTRADA\n";
const std::string MENSAGEM_SUCESSO_REMOVER_USUARIO = "OK: CONTA {ID} REMOVIDA\n";
const std::string MENSAGEM_SUCESSO_ENTREGAR_MENSAGEM = "OK: MENSAGEM PARA {ID} ENTREGUE\n";
const std::string FORMATACAO_EXIBIR_MENSAGEM = "CONSULTA {ID}: {MSG}\n";

const std::string MENSAGEM_ERRO_ARQUIVO_ENTRADA_NAO_INFORMADO = "[ERRO] Arquivo de leitura nao foi informado. Encerrando execucao.";
const std::string MENSAGEM_ERRO_AO_ABRIR_ARQUIVO_ENTRADA = "[ERRO] Nao foi possivel abrir arquivo de leitura. Encerrando execucao.";

std::string getCaminhoArquivoEntrada();

void executarComando(std::istringstream& comando, Servidor& servidor);
void realizarCadastroUsuario(Servidor& servidor, const std::string id);
void realizarRemocaoUsuario(Servidor& servidor, const std::string id);
void realizarEnvioMensagemUsuario(Servidor& servidor, const std::string id, const std::string prioridade, const std::string mensagem);
void realizarConsultaMensagem(Servidor& servidor, const std::string id);

void printMensagem(const std::string id, const Mensagem& mensagem);

int main(int argc, char* argv[]) {
    if(argc <= 1) {
        throw new ExcecoesMain::AquivoEntradaNaoInformadoException(MENSAGEM_ERRO_ARQUIVO_ENTRADA_NAO_INFORMADO);
    }

    Servidor servidor;
    std::fstream arquivoEntrada;
    std::string caminhoArquivoEntrada = argv[1];

    arquivoEntrada.open(caminhoArquivoEntrada, std::ios::in);
    if(!arquivoEntrada.is_open()) {
        throw new ExcecoesMain::ErroAoAbrirAquivoEntradaException(MENSAGEM_ERRO_AO_ABRIR_ARQUIVO_ENTRADA);
    }

    std::string linha = "";
    while(std::getline(arquivoEntrada, linha)) {
        std::istringstream streamLinha(linha);
        executarComando(streamLinha, servidor);
    }
    
    arquivoEntrada.close();
    return 0;
}

std::string getCaminhoArquivoEntrada() {
    std::string caminhoArquivoEntrada = "";

    std::cout << "\nDigite o caminho e o nome do arquivo de entrada: ";
    std::cin >> caminhoArquivoEntrada;

    return caminhoArquivoEntrada;
}

void executarComando(std::istringstream& comando, Servidor& servidor) {
    std::string acao = "";
    comando >> acao;
    
    std::string id = "";
    comando >> id;

    acao = Utils::toUpper(acao);
    if(acao == COMANDO_CADASTRAR_USUARIO) {
        realizarCadastroUsuario(servidor, id);
    }
    else if(acao == COMANDO_REMOVER_USUARIO) {
        realizarRemocaoUsuario(servidor, id);
    }
    else if(acao == COMANDO_ENTREGAR_MENSAGEM_USUARIO) {
        std::string prioridade = "";
        comando >> prioridade;

        std::string mensagemCompleta = "";
        std::string palavra = "";
        while(comando >> palavra) {
            if(palavra != "FIM") {
                mensagemCompleta.append(palavra);
                mensagemCompleta.append(" ");
            }
        }
        Utils::trimEnd(mensagemCompleta);

        realizarEnvioMensagemUsuario(servidor, id, prioridade, mensagemCompleta);
    }
    else if(acao == COMANDO_CONSULTAR_MENSAGEM_USUARIO) {
        realizarConsultaMensagem(servidor, id);
    }
    
    return;
}

void realizarCadastroUsuario(Servidor& servidor, const std::string id) {
    try {
        servidor.cadastrarNovoUsuario(std::stoul(id));
        std::cout << Utils::replace(MENSAGEM_SUCESSO_CADASTRO_USUARIO, "{ID}", id);
    }
    catch(const ExcecoesServidor::UsuarioJaCadastradoException* exception) {
        std::cout << exception->what();
    }

    return;
}

void realizarRemocaoUsuario(Servidor& servidor, const std::string id) {
    try {
        servidor.removerUsuario(std::stoul(id));
        std::cout << Utils::replace(MENSAGEM_SUCESSO_REMOVER_USUARIO, "{ID}", id);
    }
    catch(const ExcecoesServidor::UsuarioNaoEncontradoException* exception) {
        std::cout << exception->what();
    }

    return;
}

void realizarEnvioMensagemUsuario(Servidor& servidor, const std::string id, const std::string prioridade, const std::string mensagem) {
    try {
        servidor.entregarMensagem(std::stoul(id), Mensagem(mensagem, std::stoul(prioridade.c_str())));
        std::cout << Utils::replace(MENSAGEM_SUCESSO_ENTREGAR_MENSAGEM, "{ID}", id);
    }
    catch(const ExcecoesServidor::UsuarioNaoEncontradoException* exception) {
        std::cout << exception->what();
    }

    return;
}

void realizarConsultaMensagem(Servidor& servidor, const std::string id) {
    try {
        Mensagem mensagem = servidor.consultarEmail(std::stoul(id));
        printMensagem(id, mensagem);
    }
    catch(const ExcecoesServidor::UsuarioNaoEncontradoException* exception) {
        std::cout << exception->what();
    }
    catch(const ExcecoesCaixaEntrada::AcessoCaixaEntradaVaziaException* exception) {
        std::cout << exception->what();
    }

    return;
}

void printMensagem(const std::string id, const Mensagem& mensagem) {
    std::string stringFormatada = "";

    stringFormatada = Utils::replace(FORMATACAO_EXIBIR_MENSAGEM, "{ID}", id);
    stringFormatada = Utils::replace(stringFormatada, "{MSG}", mensagem.getTexto());

    std::cout << stringFormatada;
    return;
}
