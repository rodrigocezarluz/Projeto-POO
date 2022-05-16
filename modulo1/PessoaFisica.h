//
// Created by Thales Nunes on 5/11/22.
//

#ifndef MODULO1_PESSOAFISICA_H
#define MODULO1_PESSOAFISICA_H
#include "Cliente.h"
#include <string>
#include <vector>

class PessoaFisica : public Cliente {
    std::string CPF;

public:
    PessoaFisica(std::string &cpf);

    PessoaFisica();

    bool validarCPF(std::string cpf_);

    const std::string &getCpf() const;

    void setCpf(const std::string &cpf);
};

#endif //MODULO1_PESSOAFISICA_H
