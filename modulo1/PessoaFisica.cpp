//
// Created by Thales Nunes on 5/11/22.
//

#include "PessoaFisica.h"
#include <string>
#include <vector>

PessoaFisica::PessoaFisica() = default;

PessoaFisica::PessoaFisica(std::string &cpf) : CPF(cpf) {}

bool PessoaFisica::validarCPF(std::string CPF) {
    return false;
}

inline bool validaCPF(const std::string& cpf)
{
    unsigned int lenght = cpf.size();
    int ver1 = 0, ver2 = 0;
    char aux;

    if (lenght != 11)
        return false;

    /* Calculando o primeiro dígito verificador. Cada dígito tem um peso co-
     * meçando de 1 até 9. Para calculá-lo deve-se somar cada dígito, multi-
     * plicando-se por seu peso e ao final realizar a operação de módulo por
     * 11
     */
    for (int j=0; j<9; j++){
        aux = cpf[j];
        ver1 += std::atoi(&aux)*(j+1);
    }

    ver1 %= 11;

    /* Para o segundo dígito verificador calcula-se a partir do segundo dí-
     * gito até o 10º ( dígito verificador 1 ) atribuindo-se o peso de 1  a
     * 9, e no final realizar a operação Módulo por 11
     */
    for (int j=0; j<9; j++){
        aux = cpf[j];
        ver2 += std::atoi(&aux)*j;
    }

    ver2 += ver1*9;
    ver2 %= 11;

    /* compara-se agora ver1 e ver2 com os dígitos do cpf */
    aux = cpf[lenght-2];
    if (std::atoi(&aux) != ver1) {
        return false;
    }
    aux = cpf[lenght-1];
    return std::atoi(&aux) == ver2;
}
