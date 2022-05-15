//
// Created by Thales Nunes on 5/11/22.
//

#ifndef MODULO1_PESSOAJURIDICA_H
#define MODULO1_PESSOAJURIDICA_H
#include <string>
#include <vector>
#include "Cliente.h"

class PessoaJuridica : public Cliente {
    std::string CNPJ;

public:
    PessoaJuridica(const std::string &cnpj);

    const std::string &getCnpj() const;

    void setCnpj(const std::string &cnpj);

    // TODO: Escrever metodo de validacao de CNPJ
};
#endif //MODULO1_PESSOAJURIDICA_H

