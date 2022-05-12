//
// Created by Thales Nunes on 5/11/22.
//

#ifndef MODULO1_PESSOAFISICA_H
#define MODULO1_PESSOAFISICA_H
#include "Cliente.h"
#include <string>
#include <vector>

class PessoaFisica : public Cliente{
public:
    PessoaFisica(std::string &cpf);

    PessoaFisica();
    // The class
public:             // Access specifier
    std::string CPF;  // Attribute (string variable)

    static bool validarCPF(std::string CPF);
};

#endif //MODULO1_PESSOAFISICA_H
