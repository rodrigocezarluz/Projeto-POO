//
// Created by Thales Nunes on 5/11/22.
//


#include <string>
#include "Pessoajuridica.h"

PessoaJuridica::PessoaJuridica(
        const std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>> &cnpj) : CNPJ(
        cnpj) {}

const std::string &PessoaJuridica::getCnpj() const {
    return CNPJ;
}

void PessoaJuridica::setCnpj(const std::string &cnpj) {
    CNPJ = cnpj;
}
