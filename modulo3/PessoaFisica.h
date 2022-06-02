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
    using Cliente::Cliente;

    PessoaFisica(const string &nome, const string &telefoneContato, const vector<UC> &uCs,
                 const Endereco &endereco, const string &cpf);

    bool validarCPF(std::string cpf_);

    const string &getCpf() const;

    void setCpf(const std::string &cpf);
};

#endif //MODULO1_PESSOAFISICA_H
