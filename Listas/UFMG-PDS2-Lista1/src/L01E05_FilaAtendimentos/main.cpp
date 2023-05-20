#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "./structs/Cliente/Cliente.hpp"
#include "./structs/FilaAtendimento/FilaAtendimento.hpp"
#include "./avaliacao_basica_atendimento.hpp"

#define ADICIONAR 'a'
#define CHAMAR 'c'
#define ESTIMATIVA_TEMPO 'e'
#define IMPRIMIR_FILA 'p'
#define AVALIACAO_BASICA 'b'

std::string get_line();
std::vector<std::string> get_entradas(const string& input);
std::vector<std::string> juntar_comandos_paramentros(const std::vector<char> comandos, const std::vector<std::string> parametros);
bool contem_valor(const char* array, const unsigned int tamanho, const char valor);
std::vector<string> split_string(const string& referencia, const char character_quebra);

int main() {
    FilaAtendimento* fila = new FilaAtendimento();
    std::string input = "";
    getline(std::cin, input);
    std::vector<std::string> entradas = get_entradas(input);

    for(unsigned int i = 0; i < entradas.size(); i++) {
        std::vector<string> parametros = split_string(entradas[i], ' ');
        char comando = parametros[0][0];

        switch(comando) {
            case(ADICIONAR):{
                std::string nome = parametros[1];
                std::string idade = parametros[2];

                fila->adicionar_cliente(nome, std::stoi(idade));
                break;
            }

            case(CHAMAR): {
                fila->chamar_cliente();
                break;
            }

            case(ESTIMATIVA_TEMPO): {
                std::string senha = parametros[1];
                fila->estimativa_tempo_espera(std::stoi(senha));
                break;
            }

            case(IMPRIMIR_FILA): {
                fila->imprimir_fila();
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

std::string get_line() {
    std::stringstream input;
    input.clear();

    std::string temp = "";
    while(std::cin >> temp) {
        input << temp << " ";
    }

    return input.str();
}

std::vector<std::string> get_entradas(const string& input) {
    const char LISTA_COMANDOS[] = { ADICIONAR, CHAMAR, ESTIMATIVA_TEMPO, IMPRIMIR_FILA, AVALIACAO_BASICA };
    const unsigned int TAMANHO_LISTA_COMANDOS = sizeof(LISTA_COMANDOS) / sizeof(LISTA_COMANDOS[0]);

    std::vector<std::string> input_separado = split_string(input, ' ');

    std::vector<char> comandos;
    std::vector<std::string> parametros;

    for(unsigned int i = 0; i < input_separado.size(); i++) {
        std::string palavra_atual = input_separado[i];
        if(palavra_atual.size() == 1 && contem_valor(LISTA_COMANDOS, TAMANHO_LISTA_COMANDOS, palavra_atual[0])) {
            comandos.push_back(palavra_atual[0]);
        }
        else {
            parametros.push_back(palavra_atual);
        }
    }


    return juntar_comandos_paramentros(comandos, parametros);
}

bool contem_valor(const char* array, const unsigned int tamanho, const char valor) {
    for(unsigned int i = 0; i < tamanho; i++) {
        if(array[i] == valor) {
            return true;
        }
    }

    return false;
}

std::vector<std::string> juntar_comandos_paramentros(const std::vector<char> comandos, const std::vector<std::string> parametros) {
    std::vector<std::string> comandos_e_parametros;

    for(unsigned int index_comandos = 0, index_paramentros = 0; index_comandos < comandos.size(); index_comandos++) {
        std::stringstream uniao;
        uniao.clear();
        
        char comando_atual = comandos[index_comandos];

        if(comando_atual == ADICIONAR) {
            uniao << comandos[index_comandos] << " " 
                  << parametros[index_paramentros] << " " 
                  << parametros[index_paramentros + 1];

            index_paramentros += 2;
            comandos_e_parametros.push_back(uniao.str());
        }
        else if(comando_atual == ESTIMATIVA_TEMPO) {
            uniao << comandos[index_comandos] << " " 
                  << parametros[index_paramentros];

            index_paramentros += 1;
            comandos_e_parametros.push_back(uniao.str());

        }
        else {
            comandos_e_parametros.push_back(std::string(1, comandos[index_comandos]));
        }
    }

    return comandos_e_parametros;
}

std::vector<string> split_string(const string& referencia, const char character_quebra) {
    std::string palavra_atual = "";
    std::vector<string> string_separada;

    for(unsigned int i = 0; i < referencia.size(); i++) {
        char caracter_atual = referencia[i];
        if(caracter_atual != character_quebra) {
            palavra_atual.push_back(caracter_atual);
        }
        else {
            string_separada.push_back(palavra_atual);
            palavra_atual.clear();
        }
    }

    string_separada.push_back(palavra_atual);
    return string_separada;
}
