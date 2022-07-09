//
// Created by Thales Nunes on 5/11/22.
//

#include "PessoaFisica.h"
#include "Erro.h"
#include <string>
#include <vector>

PessoaFisica::PessoaFisica(const string &nome, const string &telefoneContato, const vector<UC> &uCs,
                           const Endereco &endereco, const string &cpf) : Cliente(nome, telefoneContato, uCs,
                                                                                  endereco), CPF(cpf) {}

void PessoaFisica::setCpf(const std::string &cpf) {
    if (this->validarCPF(cpf)) {
        CPF = cpf;
    } else {
        throw Erro("CPF invalido.");
    }
}

const string &PessoaFisica::getCpf() const {
    return CPF;
}

bool PessoaFisica::validarCPF(std::string cpf_) {
    if (cpf_.size() != 11) {
        return false;
    }

    int dig1, dig2, temp;
    int cpf[11];

    for(char i = 0; i < 11; i++) {
        cpf[i] = int(cpf_[i] - '0');
    }

    temp=0;
    for(char i = 0; i < 9; i++) {
        temp += cpf[i] * (10 - i);
    }

    if((temp % 11) < 2) {
        dig1 = 0;
    }
    else {
        dig1 = 11 - (temp % 11);
    }

    temp=0;
    for(char i = 0; i < 10; i++) {
        temp += cpf[i] * (11 - i);
    }

    if((temp % 11) < 2) {
        dig2 = 0;
    }
    else {
        dig2 = 11 - (temp % 11);
    }

    if (dig1 == cpf[9] && dig2 == cpf[10]) {
        return true;
    }
    return false;
}
// inline bool validaCPF(const std::string& cpf)
// {
//     unsigned int lenght = cpf.size();
//     int ver1 = 0, ver2 = 0;
//     char aux;

//     if (lenght != 11)
//         return false;

//     /* Calculando o primeiro dígito verificador. Cada dígito tem um peso co-
//      * meçando de 1 até 9. Para calculá-lo deve-se somar cada dígito, multi-
//      * plicando-se por seu peso e ao final realizar a operação de módulo por
//      * 11
//      */
//     for (int j=0; j<9; j++){
//         aux = cpf[j];
//         ver1 += std::atoi(&aux)*(j+1);
//     }

//     ver1 %= 11;

//     /* Para o segundo dígito verificador calcula-se a partir do segundo dí-
//      * gito até o 10º ( dígito verificador 1 ) atribuindo-se o peso de 1  a
//      * 9, e no final realizar a operação Módulo por 11
//      */
//     for (int j=0; j<9; j++){
//         aux = cpf[j];
//         ver2 += std::atoi(&aux)*j;
//     }

//     ver2 += ver1*9;
//     ver2 %= 11;

//     /* compara-se agora ver1 e ver2 com os dígitos do cpf */
//     aux = cpf[lenght-2];
//     if (std::atoi(&aux) != ver1) {
//         return false;
//     }
//     aux = cpf[lenght-1];
//     return std::atoi(&aux) == ver2;
// }
