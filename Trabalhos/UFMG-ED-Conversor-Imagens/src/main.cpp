#include <string>
#include <iostream>
#include <stdexcept>

#include "PPMReader.h"
#include "Imagem.h"
#include "ConversorImagem.h"
#include "PGMWriter.h"
#include "ExcecoesMain.h"

#include "memlog.h"
#include "msgassert.h"

const std::string FLAG_NOME_ARQUIVO_ENTRADA = "-i";
const std::string FLAG_NOME_ARQUIVO_SAIDA = "-o";
const std::string FLAG_REGISTRO_DESEMPENHO = "-p";
const std::string FLAG_PADRAO_ACESSO_LOCALIDADE = "-l";
const std::string NOME_PADRAO_ARQUIVO_LOCALIDADE = "log.out";

const std::string MENSAGEM_ERRO_ARQUIVO_ENTRADA_NAO_INFORMADO = "[ERRO] Arquivo de entradao nao foi informado. Encerrando execucao.";
const std::string MENSAGEM_ERRO_ARQUIVO_SAIDA_NAO_INFORMADO = "[ERRO] Nome do arquivo de saida nao foi informado. Encerrando execucao.";
const std::string MENSAGEM_ERRO_FINALIZAR_MEMLOG = "[ERRO] Nao foi possivel encerrar memlog corretamente.";

std::string getCaminhoLeitura(const int argc, char* argv[]);
std::string getCaminhoSaida(const int argc, char* argv[]);
std::string getNomeMemLog(const int argc, char* argv[]);
std::string getValorFlag(const int argc, char* argv[], const std::string flag);
bool contemFlag(const int argc, char* argv[], const std::string flag);

int main(int argc, char* argv[]) {
    std::string caminhoEntrada = getCaminhoLeitura(argc, argv);
    std::string caminhoSaida = getCaminhoSaida(argc, argv);

    char* nomeMemLog = (char*) getNomeMemLog(argc, argv).c_str();
    iniciaMemLog(nomeMemLog);

    if(contemFlag(argc, argv, FLAG_PADRAO_ACESSO_LOCALIDADE)) {
        ativaMemLog();
    }
    else {
        desativaMemLog();
    }
    
    defineFaseMemLog(0);
    PPMReader reader(caminhoEntrada);
    Imagem* imagemComCores = reader.lerImagem();

    defineFaseMemLog(1);
    Imagem* imagemEmTonsCinzas = ConversorImagem::converterPPMparaPGM(*imagemComCores);

    defineFaseMemLog(2);    
    PGMWriter writer(caminhoSaida);
    writer.criarImagem(*imagemEmTonsCinzas);

    delete imagemEmTonsCinzas;
    delete imagemComCores;

    bool memlogEncerrouCorretamente = finalizaMemLog() != 0;
    if(memlogEncerrouCorretamente) {
        erroAssert(memlogEncerrouCorretamente, MENSAGEM_ERRO_FINALIZAR_MEMLOG.c_str());
        throw ExcecoesMain::ErroAoEncerrarMemLogException(MENSAGEM_ERRO_FINALIZAR_MEMLOG);
    }

    return 0;
}

std::string getCaminhoLeitura(const int argc, char* argv[]) {
    std::string caminho = getValorFlag(argc, argv, FLAG_NOME_ARQUIVO_ENTRADA);

    if(caminho == "" || caminho[0] == '-') {
        erroAssert(caminho == "", MENSAGEM_ERRO_ARQUIVO_ENTRADA_NAO_INFORMADO.c_str());
        throw ExcecoesMain::ArquivoEntradaNaoFornecidoException(MENSAGEM_ERRO_ARQUIVO_ENTRADA_NAO_INFORMADO);
    }

    return caminho;
}

std::string getCaminhoSaida(const int argc, char* argv[]) {
    std::string caminho = getValorFlag(argc, argv, FLAG_NOME_ARQUIVO_SAIDA);
    
    if(caminho == "" || caminho[0] == '-') {
        erroAssert(caminho == "", MENSAGEM_ERRO_ARQUIVO_SAIDA_NAO_INFORMADO.c_str());
        throw ExcecoesMain::ArquivoSaidaNaoFornecidoException(MENSAGEM_ERRO_ARQUIVO_SAIDA_NAO_INFORMADO);
    }

    return caminho;
}

std::string getNomeMemLog(const int argc, char* argv[]) {
    std::string nome = "";

    try {
        nome = getValorFlag(argc, argv, FLAG_REGISTRO_DESEMPENHO);
    }
    catch(std::logic_error& exp) {
        nome = NOME_PADRAO_ARQUIVO_LOCALIDADE;
    }

    if(nome.empty() || nome == " " || nome[0] == '-') {
        nome = NOME_PADRAO_ARQUIVO_LOCALIDADE;
    }

    return nome;
}

std::string getValorFlag(const int argc, char* argv[], const std::string flag) {
    for(int i = 1; i < argc; i++) {
        if(argv[i] == flag) {
            return argv[i + 1];
        }
    }

    return "";
}

bool contemFlag(const int argc, char* argv[], const std::string flag) {
    for(int i = 1; i < argc; i++) {
        if(argv[i] == flag) {
            return true;
        }
    }

    return false;
}
