//
// Created by Thales Nunes on 5/11/22.
//

#ifndef MODULO1_PESSOAJURIDICA_H
#define MODULO1_PESSOAJURIDICA_H
#include "Cliente.h"
#include <string>
#include <vector>

class PessoaJuridica : public Cliente {
    std::string CNPJ;

public:
    PessoaJuridica(std::string &cnpj);

    PessoaJuridica();

    bool validarCNPJ(std::string cnpj_);

    const std::string &getCnpj() const;

    void setCnpj(const std::string &cnpj);
};

#endif //MODULO1_PESSOAJURIDICA_H

