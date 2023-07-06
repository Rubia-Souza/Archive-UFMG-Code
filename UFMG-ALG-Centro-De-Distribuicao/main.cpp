#include <iostream>
#include <string>

#include "SeparadorLigasBottomUp.hpp"
#include "SeparadorLigasTopDown.hpp"

#define MINIMO_LIGAS_METALICAS 1
#define MAXIMO_LIGAS_METALICAS 1000

#define MINIMO_DEMANDA_CLIENTE 1
#define MAXIMO_DEMANDA_CLIENTE 1000000

#define TAMANHO_MINIMO_LIGA_METALICA 1
#define TAMANHO_MAXIMO_LIGA_METALICA 1000

const std::string MENSAGEM_ERRO_QUANTIDADE_INVALIDA_LIGAS_METALICAS = "[ERROR] Quantidade invalida de ligas metalicas informada.";
const std::string MENSAGEM_ERRO_QUANTIDADE_INVALIDA_DEMANDA_CLIENTE = "[ERROR] Quantidade invalida da demanda do cliente informada.";
const std::string MENSAGEM_ERRO_TAMANHO_INVALIDO_LIGA_METALICA = "[ERROR] Tamanho da liga metalica informado eh invalido.";

int main(int argc, char const *argv[]) {
    unsigned int quantidadeCasosTeste = 0;
    std::cin >> quantidadeCasosTeste;

    for(unsigned int casoTesteAtual = 0; casoTesteAtual < quantidadeCasosTeste; casoTesteAtual++) {
        unsigned int numeroLigasMetalicas = 0;
        unsigned int demandaCliente = 0;

        std::cin >> numeroLigasMetalicas >> demandaCliente;
        if(numeroLigasMetalicas < MINIMO_LIGAS_METALICAS || numeroLigasMetalicas > MAXIMO_LIGAS_METALICAS) {
            std::cout << MENSAGEM_ERRO_QUANTIDADE_INVALIDA_LIGAS_METALICAS << std::endl;
            throw MENSAGEM_ERRO_QUANTIDADE_INVALIDA_LIGAS_METALICAS;
        }

        if(demandaCliente < MINIMO_DEMANDA_CLIENTE || demandaCliente > MAXIMO_DEMANDA_CLIENTE) {
            std::cout << MENSAGEM_ERRO_QUANTIDADE_INVALIDA_DEMANDA_CLIENTE << std::endl;
            throw MENSAGEM_ERRO_QUANTIDADE_INVALIDA_DEMANDA_CLIENTE;
        }

        std::vector<unsigned int> ligasMetalicas(numeroLigasMetalicas);
        for(unsigned int i = 0; i < numeroLigasMetalicas; i++) {
            std::cin >> ligasMetalicas[i];
            if(ligasMetalicas[i] < TAMANHO_MINIMO_LIGA_METALICA || ligasMetalicas[i] > TAMANHO_MAXIMO_LIGA_METALICA) {
                std::cout << MENSAGEM_ERRO_TAMANHO_INVALIDO_LIGA_METALICA << std::endl;
                throw MENSAGEM_ERRO_TAMANHO_INVALIDO_LIGA_METALICA;
            }
        }

        SeparadorLigasBottomUp separador;
        //SeparadorLigasTopDown separador; // INFO: Solução TopDown falha para certos casos de teste devido ao limite máximo de chamadas recursivas que podem ser feitas definido pelo sistema operacional

        std::cout << separador.Separar(demandaCliente, ligasMetalicas) << std::endl;
    }

    return 0;
}