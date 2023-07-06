#include <iostream>
#include <fstream>
#include <string>

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

    std::ofstream arquivoSaida("./imagem.pgm");
    if(arquivoSaida.fail()) {
        std::cout << "\nNao foi possivel criar o arquivo de saida.";
        return -1;
    }

    const std::string tipo = "P2";
    const unsigned int altura = 198;
    const unsigned int largura = 198;
    const unsigned int maiorTom = 255;
    const unsigned int quantidadeMaximaCaracteresPorLinha = 64;

    arquivoSaida << tipo << "\n";
    arquivoSaida << largura << " " << altura << "\n";
    arquivoSaida << maiorTom << "\n";

    std::string linhaAtual = "";
    unsigned int contadorCaracteresLinha = 0;
    while(std::getline(arquivoEntrada, linhaAtual)) {
        for(char caracter : linhaAtual) {
            if(caracter == '0') {
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
    }

    arquivoEntrada.close();
    arquivoSaida.close();

    return 0;
}