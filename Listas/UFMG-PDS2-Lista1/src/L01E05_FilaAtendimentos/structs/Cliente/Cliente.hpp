#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

struct Cliente {
    unsigned int idade;
    int senha;
    std::string nome;

    Cliente();
    Cliente(const std::string nome, const unsigned int idade, const int senha);

    bool eh_prioritario() const;
    unsigned int tempo_estimado_atendimento() const;
    void imprimir_dados() const;

    void set_nome(const std::string nome);
    std::string get_nome() const;

    void set_idade(const unsigned int idade);
    unsigned int get_idade() const;

    void set_senha(const int senha);
    int get_senha() const;
};


#endif
