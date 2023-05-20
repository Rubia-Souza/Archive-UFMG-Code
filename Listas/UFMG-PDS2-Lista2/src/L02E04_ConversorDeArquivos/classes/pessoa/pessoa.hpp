#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <string>

#include "../ireadable/ireadable.hpp"

class Pessoa : public IReadable {
    private:
        std::string nome = "";
        unsigned int idade = 0;
        unsigned long cpf = 0;

    public:
        Pessoa();
        ~Pessoa();

        virtual void GetCampos(std::vector<std::string>& out) const override;

        virtual void setAtributo(const std::string key, const std::string valor) override;
        virtual std::string GetAtributo(const std::string key) const override;

        void setNome(const std::string nome);
        std::string getNome() const;

        void setIdade(const unsigned int idade);
        unsigned int getIdade() const;

        void setCpf(const unsigned long cpf);
        unsigned long getCpf() const;

        bool operator ==(const Pessoa& outraPessoa) const;
    
    protected:
        virtual void print(std::ostream& out) const override;
    
    private:
        std::string getFormattedData() const;
};

#endif
