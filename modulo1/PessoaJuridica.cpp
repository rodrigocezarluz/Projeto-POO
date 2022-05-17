//
// Created by Thales Nunes on 5/11/22.
//

#include "PessoaJuridica.h"
#include <string>
#include <vector>

PessoaJuridica::PessoaJuridica() = default;

PessoaJuridica::PessoaJuridica(std::string &cnpj) : CNPJ(cnpj) {}

const std::string &PessoaJuridica::getCnpj() const {
    return CNPJ;
}

void PessoaJuridica::setCnpj(const std::string &cnpj) {
    CNPJ = cnpj;
}

bool PessoaJuridica::validarCNPJ(std::string cnpj_) {
    if (cnpj_.size() != 14) {
        return false;
    }

    int dig1, dig2, temp;
    int cnpj[14];

    for(char i = 0; i < 14; i++) {
        cnpj[i] = int(cnpj_[i] - '0');
    }

    temp=0;
    for(char i = 0; i < 4; i++) {
        temp += cnpj[i] * (5 - i);
    }
    for(char i = 4; i < 12; i++) {
        temp += cnpj[i] * (13 - i);
    }

    if((temp % 11) < 2) {
        dig1 = 0;
    }
    else {
        dig1 = 11 - (temp % 11);
    }

    temp=0;
    for(char i = 0; i < 5; i++) {
        temp += cnpj[i] * (6 - i);
    }
    for(char i = 5; i < 13; i++) {
        temp += cnpj[i] * (14 - i);
    }

    if((temp % 11) < 2) {
        dig2 = 0;
    }
    else {
        dig2 = 11 - (temp % 11);
    }

    if (dig1 == cnpj[12] && dig2 == cnpj[13]) {
        return true;
    }
    return false;
}