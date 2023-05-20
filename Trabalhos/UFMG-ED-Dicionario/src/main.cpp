#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stdexcept>

#include "Verbete.h"
#include "TiposVerbete.h"

#include "DicionarioHash.h"
#include "DicionarioArvoreAVL.h"

#include "ExcecoesMain.h"

#include "Utils.h"

const std::string FLAG_ARQUIVO_ENTRADA = "-i";
const std::string FLAG_ARQUIVO_SAIDA = "-o";
const std::string FLAG_TIPO_DICIONARIO = "-t";

const std::string INDENTIFICACAO_DICIONARIO_AVL = "arv";
const std::string INDENTIFICACAO_DICIONARIO_HASH = "hash";

const std::string MENSAGEM_ERRO_ARQUIVO_ENTRADA_NAO_INFORMADO = "[ERRO] Arquivo de entrada nao foi informado. Encerrando execucao.";
const std::string MENSAGEM_ERRO_ARQUIVO_ENTRADA_NAO_ABERTO = "[ERRO] Nao foi possivel abrir o arquivo de entrada informado. Encerrando execucao.";
const std::string MENSAGEM_ERRO_ARQUIVO_SAIDA_NAO_INFORMADO = "[ERRO] Nome do arquivo de saida nao foi informado. Encerrando execucao.";
const std::string MENSAGEM_ERRO_ARQUIVO_SAIDA_NAO_ABERTO = "[ERRO] Nao foi possivel abrir o arquivo de saida informado. Encerrando execucao.";
const std::string MENSAGEM_ERRO_TIPO_DICIONARIO_NAO_INFORMADO = "[ERRO] O tipo de dicionario nao foi informado. Por favor, informe o valor \"arv\" para utilizar a Arvore AVL ou \"hash\" para utilizar o Hash por meio da flag \"-t\". Encerrando execucao.";
const std::string MENSAGEM_ERRO_TIPO_DICIONARIO_INFORMADO_INVALIDO = "[ERRO] O tipo de dicionario informado nao e valido. Por favor, informe o valor \"arv\" para utilizar a Arvore AVL ou \"hash\" para utilizar o Hash. Encerrando execucao.";

/**
 * @brief Busca o caminho do arquivo de entrada
 * 
 * @param argc Quantidade de argumentos passados por linha de comando
 * @param argv Vetor com os argumentos passados por linha de comando
 * @return std::string É o caminho do arquivo de entrada
 */
std::string getCaminhoArquivoEntrada(const int argc, char* argv[]);

/**
 * @brief Busca o caminho do arquivo de saida
 * 
 * @param argc Quantidade de argumentos passados por linha de comando
 * @param argv Vetor com os argumentos passados por linha de comando
 * @return std::string É o caminho do arquivo de saida
 */
std::string getCaminhoArquivoSaida(const int argc, char* argv[]);

/**
 * @brief Busca o tipo do dicionario nos parametros informados por terminal
 * 
 * @param argc Quantidade de argumentos passados por linha de comando
 * @param argv Vetor com os argumentos passados por linha de comando
 * @return std::string É o tipo de dicionario informado
 */
std::string getTipoDicionario(const int argc, char* argv[]);

/**
 * @brief Busca o valor de uma determinada flag
 * 
 * @param argc Quantidade de argumentos passados por linha de comando
 * @param argv Vetor com os argumentos passados por linha de comando
 * @param flag Flag que deseja ser buscada
 * @return std::string É o valor contido na flag
 */
std::string getValorFlag(const int argc, char* argv[], const std::string flag);

int main(int argc, char* argv[]) {
    const std::string caminhoArquivoEntrada = getCaminhoArquivoEntrada(argc, argv);
    const std::string caminhoArquivoSaida = getCaminhoArquivoSaida(argc, argv);
    const std::string tipoDicionario = Utils::toLower(getTipoDicionario(argc, argv));

    /*std::string caminhoArquivoEntrada;
    std::cout << "\nDigite o caminho de entrada: ";
    std::cin >> caminhoArquivoEntrada;

    std::string caminhoArquivoSaida;
    std::cout << "\nDigite o caminho de saida: ";
    std::cin >> caminhoArquivoSaida;

    std::string tipoDicionario;
    std::cout << "\nEscolha tipo de dicionario (arv, hash): ";
    std::cin >> tipoDicionario;*/

    Dicionario* dicionario;
    if(tipoDicionario == INDENTIFICACAO_DICIONARIO_AVL) {
        dicionario = new DicionarioArvoreAVL();
    }
    else if(tipoDicionario == INDENTIFICACAO_DICIONARIO_HASH) {
        dicionario = new DicionarioHash();
    }

    std::ifstream arquivoEntrada;
    arquivoEntrada.open(caminhoArquivoEntrada, std::ios::in);

    if(!arquivoEntrada.is_open()) {
        throw ExcecoesMain::ArquivoEntradaNaoAbertoException(MENSAGEM_ERRO_ARQUIVO_ENTRADA_NAO_ABERTO);
    }

    std::string linha = "";
    while(std::getline(arquivoEntrada, linha)) {
        std::istringstream streamLinha(linha);
        char tipoVerbete;
        streamLinha >> tipoVerbete;

        std::string palavra = "";
        streamLinha >> palavra;
        
        while(palavra[palavra.size()-1] != ']') {
            std::string proximaPalavra = "";
            streamLinha >> proximaPalavra;
            palavra.append(" ");
            palavra.append(proximaPalavra);
        }
        palavra = Utils::extrairColchetes(palavra);

        std::string significado = "";
        std::string palavrasSignificado = "";
        while(streamLinha >> palavrasSignificado) {
            significado.append(palavrasSignificado);
            significado.append(" ");
        }
        Utils::trimEnd(significado);
        
        Verbete* novoVerbete = new Verbete(palavra, tipoVerbete, significado);
        dicionario->inserir(*novoVerbete);
    }

    arquivoEntrada.close();

    std::ofstream arquivoSaida;
    arquivoSaida.open(caminhoArquivoSaida, std::ios::app);

    if(!arquivoSaida.is_open()) {
        delete dicionario;
        throw ExcecoesMain::ArquivoSaidaNaoAbertoException(MENSAGEM_ERRO_ARQUIVO_SAIDA_NAO_ABERTO);
    }

    dicionario->imprimirEmArquivo(&arquivoSaida);

    dicionario->removerVerbetesComMaisDeUmSignificado();

    dicionario->imprimirEmArquivo(&arquivoSaida);

    arquivoSaida.close();

    delete dicionario;
    return 0;
}

std::string getCaminhoArquivoEntrada(const int argc, char* argv[]) {
    std::string caminho = getValorFlag(argc, argv, FLAG_ARQUIVO_ENTRADA);

    if(caminho == "" || caminho[0] == '-') {
        throw ExcecoesMain::ArquivoEntradaNaoFornecidoException(MENSAGEM_ERRO_ARQUIVO_ENTRADA_NAO_INFORMADO);
    }

    return caminho;
}

std::string getCaminhoArquivoSaida(const int argc, char* argv[]) {
    std::string caminho = getValorFlag(argc, argv, FLAG_ARQUIVO_SAIDA);
    
    if(caminho == "" || caminho[0] == '-') {
        throw ExcecoesMain::ArquivoSaidaNaoFornecidoException(MENSAGEM_ERRO_ARQUIVO_SAIDA_NAO_INFORMADO);
    }

    return caminho;
}

std::string getTipoDicionario(const int argc, char* argv[]) {
    std::string tipoDicionario = getValorFlag(argc, argv, FLAG_TIPO_DICIONARIO);

    if(tipoDicionario == "" || tipoDicionario[0] == '-') {
        throw ExcecoesMain::TipoDicionarioNaoInformadoException(MENSAGEM_ERRO_TIPO_DICIONARIO_NAO_INFORMADO);
    }

    if(tipoDicionario != INDENTIFICACAO_DICIONARIO_HASH && tipoDicionario != INDENTIFICACAO_DICIONARIO_AVL) {
        throw ExcecoesMain::ArgumentoInvalidoException(MENSAGEM_ERRO_TIPO_DICIONARIO_INFORMADO_INVALIDO);
    }

    return tipoDicionario;
}

std::string getValorFlag(const int argc, char* argv[], const std::string flag) {
    for(int i = 1; i < argc; i++) {
        if(argv[i] == flag) {
            return argv[i+1];
        }
    }

    return "";
}
