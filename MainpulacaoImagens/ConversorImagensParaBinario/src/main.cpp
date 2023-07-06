#include <iostream>
#include <fstream>
#include <string>

void converterBinarioParaImagem(std::ifstream* arquivoEntrada, std::ofstream* arquivoSaida);
void converterImagemParaBinario(std::ifstream* arquivoEntrada, std::ofstream* arquivoSaida);

int main() {
    std::string caminhoArquivoEntrada = "";
    std::cout << "\nDigite o caminho do arquivo de entrada: ";
    std::cin >> caminhoArquivoEntrada;
    std::cin.ignore();

    std::ifstream arquivoEntrada(caminhoArquivoEntrada);
    if(arquivoEntrada.fail()) {
        std::cout << "\nNao foi possivel abrir o arquivo de entrada.";
        return -1;
    }

    std::string caminhoArquivoSaida = "";
    std::cout << "\nDigite o caminho do arquivo de saida: ";
    std::cin >> caminhoArquivoSaida;
    std::cin.ignore();

    std::ofstream arquivoSaida(caminhoArquivoSaida);
    if(arquivoSaida.fail()) {
        std::cout << "\nNao foi possivel criar o arquivo de saida.";
        return -1;
    }

    std::cout << "\nDigite 1 para converter de binario para imagem ou 2 para converter de imagem para binario: ";
    unsigned int opcao = 0;
    std::cin >> opcao;
    std::cin.ignore();

    if(opcao == 1) {
        converterBinarioParaImagem(&arquivoEntrada, &arquivoSaida);
    }
    else {
        converterImagemParaBinario(&arquivoEntrada, &arquivoSaida);
    }

    arquivoEntrada.close();
    arquivoSaida.close();

    return 0;
}

void converterBinarioParaImagem(std::ifstream* arquivoEntrada, std::ofstream* arquivoSaida) {
    std::string tipo = "P2";
    unsigned int altura = 881;
    unsigned int largura = 673;
    unsigned int maiorTom = 255;

    *arquivoSaida << tipo << "\n";
    *arquivoSaida << altura << " " << largura << "\n";
    *arquivoSaida << maiorTom << "\n";

    unsigned int bit = 0;
    unsigned int contadorCaracteresLinha = 0;
    const unsigned int quantidadeMaximaCaracteresPorLinha = 64;
    while(*arquivoEntrada >> bit) {
        if(bit == 0) {
            *arquivoSaida << " 0";
        }
        else {
            *arquivoSaida << " 255";
        }

        contadorCaracteresLinha += 4;
        if(contadorCaracteresLinha >= quantidadeMaximaCaracteresPorLinha) {
            *arquivoSaida << "\n";
            contadorCaracteresLinha = 0;
        }
    }
    
    return;
}

void converterImagemParaBinario(std::ifstream* arquivoEntrada, std::ofstream* arquivoSaida) {
    std::string tipo = "";
    unsigned int altura = 0;
    unsigned int largura = 0;
    unsigned int maiorTom = 0;

    *arquivoEntrada >> tipo;
    *arquivoEntrada >> largura >> altura;
    *arquivoEntrada >> maiorTom;

    unsigned int pixelAtual = 0;
    while(*arquivoEntrada >> pixelAtual) {
        if(pixelAtual == 0) {
            *arquivoSaida << " 0";
        }
        else {
            *arquivoSaida << " 1";
        }
    }

    return;
}