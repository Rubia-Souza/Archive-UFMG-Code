#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include <stdexcept>

const unsigned int TOM_MAXIMO = 255;
const std::string TIPO_FORMATO_GERADO = "P3";
const std::string EXTENSAO_ARQUIVO_SAIDA = ".ppm";

unsigned int getDimensao();
std::string getCaminhoComNome();
void criarHeader(std::ofstream* arquivo, const unsigned int dimensao);
void preencherArquivoComPixelsAleatorios(std::ofstream* arquivo, const unsigned int dimensao);
short gerarPixelAleatorio();

int main() {
    unsigned int dimensao = getDimensao();
    std::string caminhoComNome = getCaminhoComNome();

    std::ofstream arquivoSaida((caminhoComNome + EXTENSAO_ARQUIVO_SAIDA));
    if(arquivoSaida.fail()) {
        throw std::runtime_error("[ERRO] Nao foi possivel abrir o caminho informado. Encerrando execucao\n");
    }

    criarHeader(&arquivoSaida, dimensao);
    preencherArquivoComPixelsAleatorios(&arquivoSaida, dimensao);

    arquivoSaida.close();
    return 0;
}

unsigned int getDimensao() {
    unsigned int dimensao = 0;

    std::cout << "Informe o tamanho da imagem: ";
    std::cin >> dimensao;

    return dimensao;
}

std::string getCaminhoComNome() {
    std::string caminhoComNome = "";

    std::cout << "\nInforme o caminho com o nome da imagem: ";
    std::cin >> caminhoComNome;

    return caminhoComNome;
}

void criarHeader(std::ofstream* arquivo, const unsigned int dimensao) {
    *arquivo << TIPO_FORMATO_GERADO << "\n";
    *arquivo << dimensao << " " << dimensao << "\n";
    *arquivo << TOM_MAXIMO << "\n";

    return;
}

void preencherArquivoComPixelsAleatorios(std::ofstream* arquivo, const unsigned int dimensao) {
    unsigned int quantidadeCaracteresPorLinha = 0;
    for(unsigned int i = 0; i < dimensao; i++) {
        for(unsigned int j = 0; j < dimensao; j++) {
            *arquivo << gerarPixelAleatorio() << " ";
            *arquivo << gerarPixelAleatorio() << " ";
            *arquivo << gerarPixelAleatorio() << " ";

            quantidadeCaracteresPorLinha += 12;
            if(quantidadeCaracteresPorLinha >= 65) {
                *arquivo << "\n";
                quantidadeCaracteresPorLinha = 0;
            }
        }
    }

    return;
}

short gerarPixelAleatorio() {
    return (rand() % (TOM_MAXIMO + 1));
}
