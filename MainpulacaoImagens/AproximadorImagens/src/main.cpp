#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string caminhoArquivoEntrada = "../teste.pgm";

    std::ifstream arquivoEntrada(caminhoArquivoEntrada);
    if(arquivoEntrada.fail()) {
        std::cout << "\nNao foi possivel abrir o arquivo de entrada.";
        return -1;
    }

    std::ofstream arquivoSaida("./imagem.pgm");
    if(arquivoSaida.fail()) {
        std::cout << "\nNao foi possivel criar o arquivo de saida.";
        return -1;
    }

    std::string tipo;
    std::getline(arquivoEntrada, tipo);
    
    unsigned int altura, largura;
    arquivoEntrada >> largura >> altura;

    unsigned int maiorTom;
    arquivoEntrada >> maiorTom;

    const unsigned int quantidadeMaximaCaracteresPorLinha = 64;

    arquivoSaida << tipo << "\n";
    arquivoSaida << largura << " " << altura << "\n";
    arquivoSaida << maiorTom << "\n";

    unsigned int valorAtual = 0;
    unsigned int contadorCaracteresLinha = 0;
    while(arquivoEntrada >> valorAtual) {
        if(valorAtual < 200) {
            arquivoSaida << "  0";
        }
        else {
            arquivoSaida << " 255";
        }

        contadorCaracteresLinha += 4;
        if(contadorCaracteresLinha >= quantidadeMaximaCaracteresPorLinha) {
            arquivoSaida << "\n";
            contadorCaracteresLinha = 0;
        }
    }

    arquivoEntrada.close();
    arquivoSaida.close();

    return 0;
}