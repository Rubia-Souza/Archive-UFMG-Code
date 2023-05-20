#include <iostream>
#include <fstream>

int main() {
    std::cout << "\nDigite a quantidade de usuarios que serao cadastrados: ";
    unsigned int quantidadeUsuarios = 0;
    std::cin >> quantidadeUsuarios;

    std::cout << "\nDigite a quantidade de mensagens que um usuario ira receber: ";
    unsigned int quantidadeMensagensPorUsuario = 0;
    std::cin >> quantidadeMensagensPorUsuario;

    std::cout << "\nDigite a mesagem padrao que sera enviada para o usuario: ";
    std::string mensagemPadrao = "";
    std::getchar();
    std::getline(std::cin, mensagemPadrao);

    std::cout << "\nDeve enviar a mensagem para todos os usuarios: ";
    bool deveEnviarParaTodosUsuarios = false;
    std::cin >> deveEnviarParaTodosUsuarios;

    std::fstream arquivoSaida;
    std::string caminhoSaida = "";

    do {
        std::cout << "\nDigite o caminho do arquivo de saida: ";
        std::cin >> caminhoSaida;

        arquivoSaida.open(caminhoSaida, std::ios::out);

        if(!arquivoSaida.is_open()) {
            std::cout << "\nNao foi possivel criar o arquivo. Informe novamente o caminho.";
        }
    } while(!arquivoSaida.is_open());

    for(unsigned int i = 0; i < quantidadeUsuarios; i++) {
        arquivoSaida << "CADASTRA " << i << "\n";
    }

    if(deveEnviarParaTodosUsuarios) {
        for(unsigned int i = 0; i < quantidadeUsuarios; i++) {
            for(unsigned int j = 0; j < quantidadeMensagensPorUsuario; j++) {
                arquivoSaida << "ENTREGA " << i << " 9 " << mensagemPadrao << " FIM\n";
            }
        }
    }
    else {
        for(unsigned int i = 0; i < quantidadeMensagensPorUsuario; i++) {
            arquivoSaida << "ENTREGA " << (quantidadeUsuarios - 1) << " 9 " << mensagemPadrao << " FIM\n";
        }
    }

    if(deveEnviarParaTodosUsuarios) {
        for(unsigned int i = 0; i < quantidadeUsuarios; i++) {
            for(unsigned int j = 0; j < quantidadeMensagensPorUsuario; j++) {
                arquivoSaida << "CONSULTA " << i << "\n";
            }
        }
    }
    else {
        for(unsigned int i = 0; i < quantidadeMensagensPorUsuario; i++) {
            arquivoSaida << "CONSULTA " << (quantidadeUsuarios - 1) << "\n";
        }
    }

    for(unsigned int i = 0; i < quantidadeUsuarios; i++) {
        arquivoSaida << "REMOVE " << i << "\n";
    }

    arquivoSaida.close();
    return 0;
}
