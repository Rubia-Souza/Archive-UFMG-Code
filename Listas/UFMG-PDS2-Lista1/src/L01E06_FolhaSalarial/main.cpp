#include <iostream>
#include <string>

#include "./avaliacao_basica_nba.hpp"
#include "./structs/RegistroNBA/RegistroNBA.hpp"
#include "./structs/Jogador/Jogador.hpp"

#define ADICIONAR_TIME 't'
#define ADICIONAR_JOGADOR 'j'
#define LISTAR_JOGADORES_DO_TIME 'l'
#define IMPRIMIR_FOLHA_SALARIAL_DO_TIME 'f'
#define IMPRIMIR_FOLHA_SALARIAL_GERAL 'g'
#define AVALIACAO_BASICA 'b'

std::string get_nome_time();
Jogador get_dados_jogador();

int main() {
    char input;
    RegistroNBA* registro = new RegistroNBA();

    while(std::cin >> input) {    
        switch(input) {
            case(ADICIONAR_TIME): {
                std::string nome_time = get_nome_time();
                registro->adicionar_time(nome_time);

                break;
            }
            case(ADICIONAR_JOGADOR): {
                std::string nome_time = get_nome_time();
                Jogador jogador = get_dados_jogador();

                registro->adicionar_jogador(nome_time, jogador.get_nome(), jogador.get_posicao(), jogador.get_salario());

                break;
            }
            case(LISTAR_JOGADORES_DO_TIME): {
                std::string nome_time = get_nome_time();
                registro->imprimir_lista_jogadores_time(nome_time);

                break;
            }
            case(IMPRIMIR_FOLHA_SALARIAL_DO_TIME): {
                std::string nome_time = get_nome_time();
                registro->imprimir_folha_consolidada_time(nome_time);

                break;
            }
            case(IMPRIMIR_FOLHA_SALARIAL_GERAL): {
                registro->imprimir_folha_salarial_geral();
                break;
            }
            case(AVALIACAO_BASICA): {
                avaliacao_basica();
                break;
            }
        }
    }

    return 0;
}

std::string get_nome_time() {
    std::string nome_time = "";
    std::cin >> nome_time;

    return nome_time;
}

Jogador get_dados_jogador() {
    std::string nome_jogador = "";
    std::string posicao = "";
    unsigned int salario = 0;

    std::cin >> nome_jogador >> posicao >> salario;

    return *(new Jogador(nome_jogador, posicao, salario));
}
