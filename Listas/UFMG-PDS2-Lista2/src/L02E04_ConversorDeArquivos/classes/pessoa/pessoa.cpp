#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "./pessoa.hpp"

#define NAMEOF(name) #name

const std::string ATRIBUTO_NOME = NAMEOF(nome);
const std::string ATRIBUTO_IDADE = NAMEOF(idade);
const std::string ATRIBUTO_CPF = NAMEOF(cpf);

Pessoa::Pessoa() {
    setIdade(0);
    setCpf(0);
    setNome("");
}

Pessoa::~Pessoa() {}

void Pessoa::GetCampos(std::vector<std::string>& out) const {
    out.push_back(ATRIBUTO_NOME);
    out.push_back(ATRIBUTO_IDADE);
    out.push_back(ATRIBUTO_CPF);

    return;
}

void Pessoa::setAtributo(const std::string key, const std::string valor) {
    if(key == ATRIBUTO_NOME) {
        setNome(valor);
    }
    else if(key == ATRIBUTO_IDADE) {
        setIdade(std::stoi(valor));
    }
    else if(key == ATRIBUTO_CPF) {
        setCpf(std::stoul(valor));
    }

    return;
}

std::string Pessoa::GetAtributo(const std::string key) const {
    if(key == ATRIBUTO_NOME) {
        return getNome();
    }
    else if(key == ATRIBUTO_IDADE) {
        return std::to_string(getIdade());
    }
    else if(key == ATRIBUTO_CPF) {
        return std::to_string(getCpf());
    }

    return "";
}

void Pessoa::setNome(const std::string nome) {
    this->nome = nome;
    return;
}

std::string Pessoa::getNome() const {
    return nome;
}

void Pessoa::setIdade(const unsigned int idade) {
    this->idade = idade;
    return;
}

unsigned int Pessoa::getIdade() const {
    return idade;
}

void Pessoa::setCpf(const unsigned long cpf) {
    this->cpf = cpf;
    return;
}

unsigned long Pessoa::getCpf() const {
    return cpf;
}

bool Pessoa::operator ==(const Pessoa& outraPessoa) const {
    return (this->getCpf() == outraPessoa.getCpf());
}

void Pessoa::print(std::ostream& out) const {
    out << getFormattedData();
    return;
}

std::string Pessoa::getFormattedData() const {
    std::stringstream data;
    data.clear();

    data << "(" << ATRIBUTO_NOME << " = " << getNome()
         << " " << ATRIBUTO_IDADE << " = " << getIdade()
         << " " << ATRIBUTO_CPF << " = " << getCpf() << ")";

    return data.str();
}
