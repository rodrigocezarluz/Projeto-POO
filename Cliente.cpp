#include "Cliente.h"
#include <vector>
#include <stdexcept>
//
// Created by Thales Nunes on 5/11/22.
//

Cliente::Cliente() {}

Cliente::Cliente(int idCliente, const std::string &nome, const std::vector<UC> &uCs) : idCliente(idCliente), nome(nome),
                                                                                       UCs(uCs) {}

int Cliente::getIdCliente() const {
    return idCliente;
}

void Cliente::setIdCliente(int idCliente) {
    Cliente::idCliente = idCliente;
}

const std::string &Cliente::getNome() const {
    return nome;
}

void Cliente::setNome(const std::string &nome) {
    Cliente::nome = nome;
}

std::vector<UC> &Cliente::getUCs() {
    return UCs;
}

void Cliente::setUCs(const std::vector<UC> &uCs) {
    UCs = uCs;
}

void Cliente::pagar(Fatura& faturaAPagar) {
    for (UC uc : this->UCs) {
        for (Fatura fatura: uc.getFaturas()) {
            if(fatura.getIdFatura() == faturaAPagar.getIdFatura()) {
                fatura.setDtPagamento(time(nullptr));
                return;
            }
        }
    }
    throw std::invalid_argument( "Fatura a Pagar nao existe." );
}

std::vector<Fatura> Cliente::verificarPagamento() {
    std::vector<Fatura> faturas;

    for (UC uc : this->UCs) {
        std::vector<Fatura> faturasVencidas = uc.verificarPagamento();
        faturas.insert(faturas.end(), faturasVencidas.begin(), faturasVencidas.end());
    }

    return faturas;
}



