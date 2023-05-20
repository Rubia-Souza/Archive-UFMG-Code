#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sys/resource.h>

#include "Utils.h"
#include "Registro.h"
#include "QuickSort.h"
#include "QuickSortMediana.h"
#include "QuickSortSelecao.h"
#include "QuickSortIterativo.h"
#include "QuickSortIterativoInteligente.h"
#include "MergeSort.h"
#include "HeapSort.h"

#include "DadosDesempenho.h"
#include "ExcecoesMain.h"

#include "memlog.h"

#define VERSAO_MAIN_PARTE_1 1
#define VERSAO_MAIN_PARTE_2 2

const std::string FLAG_VERSAO_QUICK_SORT = "-v";
const std::string FLAG_NUMERO_MEDIANA = "-k";
const std::string FLAG_MINIMO_PARA_SELECAO = "-m";
const std::string FLAG_ARQUIVO_ENTRADA = "-i";
const std::string FLAG_ARQUIVO_SAIDA = "-o";
const std::string FLAG_SEMENTE = "-s";
const std::string FLAG_REGISTRO_DESEMPENHO = "-p";
const std::string FLAG_VERSAO_EXECUCAO_MAIN = "-r";

const std::string NOME_PADRAO_ARQUIVO_LOCALIDADE = "log.out";

const std::string MENSAGEM_ERRO_ARQUIVO_ENTRADA_NAO_INFORMADO = "[ERRO] Arquivo de entrada nao foi informado. Encerrando execucao.";
const std::string MENSAGEM_ERRO_ARQUIVO_ENTRADA_NAO_ABERTO = "[ERRO] Nao foi possivel abrir o arquivo de entrada informado. Encerrando execucao.";
const std::string MENSAGEM_ERRO_ARQUIVO_SAIDA_NAO_INFORMADO = "[ERRO] Nome do arquivo de saida nao foi informado. Encerrando execucao.";
const std::string MENSAGEM_ERRO_ARQUIVO_SAIDA_NAO_ABERTO = "[ERRO] Nao foi possivel abrir o arquivo de saida informado. Encerrando execucao.";
const std::string MENSAGEM_ERRO_VERSAO_NAO_INFORMADA = "[ERRO] A versao do quick sort nao foi informada. Encerrando execucao.";
const std::string MENSAGEM_ERRO_VERSAO_INVALIDA_PARTE_1 = "[ERRO] A versao do quick sort e invalida. Informe um valor entre 1 e 5. Encerrando execucao.";
const std::string MENSAGEM_ERRO_VERSAO_INVALIDA_PARTE_2 = "[ERRO] A versao do quick sort e invalida. Informe um valor entre 1 e 3. Encerrando execucao.";
const std::string MENSAGEM_ERRO_MEDIANA_NAO_INFORMADA = "[ERRO] A versao do quick sort com mediana (2) necessita de um valor de quantos elementos selecionar para a mediana. Informe um valor por meio da flag: \"-k\". Encerrando execucao.";
const std::string MENSAGEM_ERRO_MEDIANA_INVALIDA = "[ERRO] O valor informado para mediana \"-k\" e invalido. Informe uma valor maior que zero. Encerrando execucao.";
const std::string MENSAGEM_ERRO_MINIMO_PARA_SELECAO_NAO_INFORMADO = "[ERRO] A versao do quick sort com selecao (3) necessita de uma valor para identificar quando iniciar a ordenacao por selecao. Informe um valor por meio da flag: \"-m\". Encerrando execucao.";
const std::string MENSAGEM_ERRO_MINIMO_PARA_SELECAO_INVALIDO = "[ERRO] O valor informado para iniciar a selecao \"-m\" e invalido. Informe um valor maior que zero. Encerrando execucao.";
const std::string MENSAGEM_ERRO_SEMENTE_NAO_INFORMADA = "[ERRO] A semente para geracao aleatoria de numeros nao foi informada. Informe um valor por meio da flag: \"-s\". Encerrando execucao.";
const std::string MENSAGEM_ERRO_FINALIZAR_MEMLOG = "[ERRO] Nao foi possivel encerrar memlog corretamente.";

/**
 * @brief Representa os algoritmos que podem ser executados na parte 1 do trabalho
 * 
 */
enum Opcoes {
    QuickSortPadrao = 1,
    QuickSortMediana = 2,
    QuickSortSelecao = 3,
    QuickSortPilha = 4,
    QuickSortPilhaInteligente = 5,
};

/**
 * @brief Representa os algoritmos que podem ser executados na parte 2 do trabalho
 * 
 */
enum OpcoesParte2 {
    QuickSort = 1,
    MergeSort = 2,
    HeapSort = 3,
};

/**
 * @brief Busca um flag com valor numérico
 * 
 * @param argc Quantidade de argumentos passados por linha de comando
 * @param argv Vetor com os argumentos passados por linha de comando
 * @param flag Flag que deseja ser buscada
 * @param mensagemErro Mensagem de erro que será informada se a flag não for encontrada
 * @return unsigned int Valor numérico da flag buscada
 */
unsigned int getArgumentoNumerico(const int argc, char* argv[], const std::string flag, const std::string mensagemErro);

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
 * @brief Busca o valor de uma determinada flag
 * 
 * @param argc Quantidade de argumentos passados por linha de comando
 * @param argv Vetor com os argumentos passados por linha de comando
 * @param flag Flag que deseja ser buscada
 * @return std::string É o valor contido na flag
 */
std::string getValorFlag(const int argc, char* argv[], const std::string flag);

/**
 * @brief Configura um semente para geração de números aleatórios
 * 
 * @param semente É a semente que será usada como referência para gerar os números aleatórios
 */
void configurarSementeAleatoria(const unsigned int semente);

/**
 * @brief Executa os testes da parte 1 do trabalho
 * 
 * @param versaoQuickSort É a versão de qual quick sort será utilizado
 * @param registros É o vetor que irá armazenar os registros
 * @param quantidadeRegistros É a quantidade de registros que serão gerados e ordenados
 * @param dadosDesempenho É o objeto que irá armazenar os dados de desemepnho do programa
 * @param argc Quantidade de argumentos passados por linha de comando
 * @param argv Vetor com os argumentos passados por linha de comando 
 */
void executarTeste(const unsigned int versaoQuickSort, Registro registros[], const unsigned int quantidadeRegistros, DadosDesempenho& dadosDesempenho, int argc, char* argv[]);

/**
 * @brief Executa os testes da parte 1 do trabalho
 * 
 * @param versaoQuickSort É a identificação de qual metodo de ordenação será utilizado
 * @param registros É o vetor que irá armazenar os registros
 * @param quantidadeRegistros É a quantidade de registros que serão gerados e ordenados
 * @param dadosDesempenho É o objeto que irá armazenar os dados de desemepnho do programa
 * @param argc Quantidade de argumentos passados por linha de comando
 * @param argv Vetor com os argumentos passados por linha de comando 
 */
void executarTesteParte2(const unsigned int versaoSort, Registro registros[], const unsigned int quantidadeRegistros, DadosDesempenho& dadosDesempenho, int argc, char* argv[]);

/**
 * @brief Registra o cabeçalho do algoritmo de execução atual no arquivo de saida
 * 
 * @param arquivo É o arquivo de saída que terá o cabeçalho escrito
 * @param versaoQuickSort É a versão do Quick Sort que será utilizado
 */
void printCabecalho(std::ofstream* arquivo, const unsigned int versaoQuickSort);

/**
 * @brief Registra o cabeçalho do algoritmo de execução atual no arquivo de saida
 * 
 * @param arquivo É o arquivo de saída que terá o cabeçalho escrito
 * @param versaoQuickSort É a identificação do algoritmo de ordenação que será utilizado
 */
void printCabecalhoParte2(std::ofstream* arquivo, const unsigned int versaoQuickSort);

/**
 * @brief Registra os dados de desempenho do programa no arquivo de saida
 * 
 * @param arquivo É o arquivo de saída que terá os dados escritos
 * @param casoTeste Identifica o tamanho do caso de teste que foi executado
 * @param dadosDesempenho Objeto com os dados de desempenho do algoritmo
 * @param tempoExecucao O tempo de execução levado pelo algoritmo
 */
void registrarDadosDesempenho(std::ofstream* arquivo, const unsigned int casoTeste, const DadosDesempenho& dadosDesempenho, const double tempoExecucao);

/**
 * @brief Obtem o nome do arquivo de saida do Memlog
 * 
 * @param argc Quantidade de argumentos passados por linha de comando
 * @param argv Vetor com os argumentos passados por linha de comando 
 * @return std::string É o caminho e o nome do arquivo de saida do memlog
 */
std::string getNomeMemLog(const int argc, char* argv[]);

/**
 * @brief Verifica se determinada flag foi informada por parâmetro
 * 
 * @param argc Quantidade de argumentos passados por linha de comando
 * @param argv Vetor com os argumentos passados por linha de comando 
 * @param flag Identifica qual flag deve ser buscada
 * @return true Se a flag foi passada nos argumentos de entrada
 * @return false Se a flag não foi passada nos argumentos de entrada
 */
bool contemFlag(const int argc, char* argv[], const std::string flag);

int main(int argc, char* argv[]) {
    struct rusage resources;
    int statusGetResources;

    double tempoTotalAnterior = 0.0;
    double tempoTotalAtual = 0.0;
    double userTime = 0.0;
    double sistemTime = 0.0;
    double intervaloExecucao = 0.0;

    unsigned int versaoMain = VERSAO_MAIN_PARTE_1;
    if(contemFlag(argc, argv, FLAG_VERSAO_EXECUCAO_MAIN)) {
        versaoMain = std::stoul(getValorFlag(argc, argv, FLAG_VERSAO_EXECUCAO_MAIN));
    }

    unsigned int versaoQuickSort = getArgumentoNumerico(argc, argv, FLAG_VERSAO_QUICK_SORT, MENSAGEM_ERRO_VERSAO_NAO_INFORMADA);
    if(versaoMain == VERSAO_MAIN_PARTE_1 && versaoQuickSort > Opcoes::QuickSortPilhaInteligente) {
        throw ExcecoesMain::ArgumentoInvalidoExcecao(MENSAGEM_ERRO_VERSAO_INVALIDA_PARTE_1);
    }
    else if(versaoMain >= VERSAO_MAIN_PARTE_2 && versaoQuickSort > OpcoesParte2::HeapSort) {
        throw ExcecoesMain::ArgumentoInvalidoExcecao(MENSAGEM_ERRO_VERSAO_INVALIDA_PARTE_2);
    }
    
    unsigned int semente = getArgumentoNumerico(argc, argv, FLAG_SEMENTE, MENSAGEM_ERRO_SEMENTE_NAO_INFORMADA);
    
    std::string caminhoArquivoEntrada = getCaminhoArquivoEntrada(argc, argv);
    std::string caminhoArquivoSaida = getCaminhoArquivoSaida(argc, argv);

    configurarSementeAleatoria(semente);

    std::ifstream arquivoEntrada;
    arquivoEntrada.open(caminhoArquivoEntrada, std::ios::in);

    if(!arquivoEntrada.is_open()) {
        throw ExcecoesMain::ArquivoEntradaNaoAbertoException(MENSAGEM_ERRO_ARQUIVO_ENTRADA_NAO_ABERTO);
    }

    std::ofstream arquivoSaida;
    arquivoSaida.open(caminhoArquivoSaida, std::ios::app);

    if(!arquivoSaida.is_open()) {
        throw ExcecoesMain::ArquivoSaidaNaoAbertoException(MENSAGEM_ERRO_ARQUIVO_SAIDA_NAO_ABERTO);
    }

    unsigned int quantidadeTestes = 0;
    arquivoEntrada >> quantidadeTestes;

    if(versaoMain == VERSAO_MAIN_PARTE_1) {
        printCabecalho(&arquivoSaida, versaoQuickSort);
    }
    else {
        printCabecalhoParte2(&arquivoSaida, versaoQuickSort);
    }

    std::string nomeMemLog = getNomeMemLog(argc, argv);
    iniciaMemLog((char*) nomeMemLog.c_str());

    for(unsigned int i = 0; i < quantidadeTestes; i++) {
        unsigned int quantidadeRegistros = 0;
        DadosDesempenho dadosDesempenho;
        arquivoEntrada >> quantidadeRegistros;

        Registro* registros = new Registro[quantidadeRegistros];
        for(unsigned int j = 0; j < quantidadeRegistros; j++) {
            registros[j].chave = Utils::gerarNumeroInteiroAleatorio();
        }

        if((statusGetResources = getrusage(RUSAGE_SELF, &resources)) != 0) {
            std::cout << "[ERRO] Nao foi possivel iniciar getrusage().\n";
        }

        userTime = (double) resources.ru_utime.tv_sec + 1.e-6 * (double) resources.ru_utime.tv_usec;
        sistemTime = (double) resources.ru_stime.tv_sec + 1.e-6 * (double) resources.ru_stime.tv_usec;

        tempoTotalAnterior = userTime + sistemTime;

        if(versaoMain == VERSAO_MAIN_PARTE_1) {
            executarTeste(versaoQuickSort, registros, quantidadeRegistros, dadosDesempenho, argc, argv);
        }
        else {
            executarTesteParte2(versaoQuickSort, registros, quantidadeRegistros, dadosDesempenho, argc, argv);
        }

        if((statusGetResources = getrusage(RUSAGE_SELF, &resources)) != 0) {
            std::cout << "[ERRO] Nao foi possivel iniciar getrusage().\n";
        }

        userTime = (double) resources.ru_utime.tv_sec + 1.e-6 * (double) resources.ru_utime.tv_usec;
        sistemTime = (double) resources.ru_stime.tv_sec + 1.e-6 * (double) resources.ru_stime.tv_usec;

        tempoTotalAtual = userTime + sistemTime;
        intervaloExecucao = tempoTotalAtual - tempoTotalAnterior;
        tempoTotalAnterior = tempoTotalAtual;
        
        registrarDadosDesempenho(&arquivoSaida, quantidadeRegistros, dadosDesempenho, intervaloExecucao);
        delete[] registros;
    }

    bool memlogEncerrouCorretamente = finalizaMemLog() != 0;
    if(memlogEncerrouCorretamente) {
        throw ExcecoesMain::ErroAoEncerrarMemLogException(MENSAGEM_ERRO_FINALIZAR_MEMLOG);
    }

    arquivoEntrada.close();
    arquivoSaida.close();

    return 0;
}

unsigned int getArgumentoNumerico(const int argc, char* argv[], const std::string flag, const std::string mensagemErro) {
    std::string valor = getValorFlag(argc, argv, flag);

    if(valor == "" || valor[0] == '-') {
        throw ExcecoesMain::ArgumentoInvalidoExcecao(mensagemErro);
    }

    return std::stoul(valor);
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

std::string getValorFlag(const int argc, char* argv[], const std::string flag) {
    for(int i = 1; i < argc; i++) {
        if(argv[i] == flag) {
            return argv[i+1];
        }
    }

    return "";
}

void configurarSementeAleatoria(const unsigned int semente) {
    srand(semente);
    return;
}

void executarTeste(const unsigned int versaoQuickSort, Registro registros[], const unsigned int quantidadeRegistros, DadosDesempenho& dadosDesempenho, int argc, char* argv[]) {
    switch(versaoQuickSort) {
        case(Opcoes::QuickSortPadrao): {
            QuickSort::ordenarCrescente(registros, quantidadeRegistros, dadosDesempenho);
            break;
        }
        case(Opcoes::QuickSortMediana): {
            unsigned int mediana = getArgumentoNumerico(argc, argv, FLAG_NUMERO_MEDIANA, MENSAGEM_ERRO_MEDIANA_NAO_INFORMADA);
            if(mediana <= 0) {
                throw ExcecoesMain::ArgumentoInvalidoExcecao(MENSAGEM_ERRO_MEDIANA_INVALIDA);
            }

            QuickSortMediana::ordenarCrescente(registros, quantidadeRegistros, mediana, dadosDesempenho);
            break;
        }
        case(Opcoes::QuickSortSelecao): {
            unsigned int selecao = getArgumentoNumerico(argc, argv, FLAG_MINIMO_PARA_SELECAO, MENSAGEM_ERRO_MINIMO_PARA_SELECAO_NAO_INFORMADO);
            if(selecao <= 0) {
                throw ExcecoesMain::ArgumentoInvalidoExcecao(MENSAGEM_ERRO_MINIMO_PARA_SELECAO_INVALIDO);
            }

            QuickSortSelecao::ordenarCrescente(registros, quantidadeRegistros, selecao, dadosDesempenho);
            break;
        }
        case(Opcoes::QuickSortPilha): {
            QuickSortIterativo::ordenarCrescente(registros, quantidadeRegistros, dadosDesempenho);
            break;
        }
        case(Opcoes::QuickSortPilhaInteligente): {
            QuickSortIterativoInteligente::ordenarCrescente(registros, quantidadeRegistros, dadosDesempenho);
            break;
        }
    }

    return;
}

void executarTesteParte2(const unsigned int versaoSort, Registro registros[], const unsigned int quantidadeRegistros, DadosDesempenho& dadosDesempenho, int argc, char* argv[]) {
    switch(versaoSort) {
        case(OpcoesParte2::QuickSort): {
            QuickSortMediana::ordenarCrescente(registros, quantidadeRegistros, 3, dadosDesempenho);
            break;
        }
        case(OpcoesParte2::MergeSort): {
            MergeSort::ordenarCrescente(registros, quantidadeRegistros, dadosDesempenho);
            break;
        }
        case(OpcoesParte2::HeapSort): {
            HeapSort::ordenarCrescente(registros, quantidadeRegistros, dadosDesempenho);
            break;
        }
    }

    return;
}


void printCabecalho(std::ofstream* arquivo, const unsigned int versaoQuickSort) {
    switch(versaoQuickSort) {
        case(Opcoes::QuickSortPadrao): {
            *arquivo << std::endl << "---- Quick Sort:" << std::endl;
            break;
        }
        case(Opcoes::QuickSortMediana): {
            *arquivo << std::endl << "---- Quick Sort com Mediana:" << std::endl;
            break;
        }
        case(Opcoes::QuickSortSelecao): {
            *arquivo << std::endl << "---- Quick Sort com Selecao:" << std::endl;
            break;
        }
        case(Opcoes::QuickSortPilha): {
            *arquivo << std::endl << "---- Quick Sort Iterativo:" << std::endl;
            break;
        }
        case(Opcoes::QuickSortPilhaInteligente): {
            *arquivo << std::endl << "---- Quick Sort Iterativo Inteligente:" << std::endl;
            break;
        }
    }
    
    *arquivo << "Tamanho | Comparações | Atribuições | Tempo Execução" << std::endl;
    return;
}

void printCabecalhoParte2(std::ofstream* arquivo, const unsigned int versaoQuickSort) {
    switch(versaoQuickSort) {
        case(OpcoesParte2::QuickSort): {
            *arquivo << std::endl << "---- Quick Sort:" << std::endl;
            break;
        }
        case(OpcoesParte2::MergeSort): {
            *arquivo << std::endl << "---- Merge Sort:" << std::endl;
            break;
        }
        case(OpcoesParte2::HeapSort): {
            *arquivo << std::endl << "---- Heap Sort:" << std::endl;
            break;
        }
    }
    
    *arquivo << "Tamanho | Comparações | Atribuições | Tempo Execução" << std::endl;
    return;
}

void registrarDadosDesempenho(std::ofstream* arquivo, const unsigned int casoTeste, const DadosDesempenho& dadosDesempenho, const double tempoExecucao) {   
    *arquivo << casoTeste << " | ";
    *arquivo << dadosDesempenho.quantidadeComparacoes << " | " << dadosDesempenho.quantidadeAtribuicoes << " | " << tempoExecucao << std::endl;
    return;
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

bool contemFlag(const int argc, char* argv[], const std::string flag) {
    for(int i = 1; i < argc; i++) {
        if(argv[i] == flag) {
            return true;
        }
    }

    return false;
}
