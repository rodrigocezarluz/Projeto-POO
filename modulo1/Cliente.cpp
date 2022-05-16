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

void Cliente::addUC(UC &new_uc) {
    for (UC uc : this->UCs) {
        if (uc == new_uc) {
            throw std::runtime_error("Repeated UC id");
        }
    }
    UCs.push_back(new_uc);
}

void Cliente::removeUC(UC &remove_uc) {

    const auto orig_size = UCs.size();

    UCs.erase(std::remove(UCs.begin(), UCs.end(), remove_uc), UCs.end());

    if (UCs.size() == orig_size) {
        throw std::runtime_error( "UC not found." );
    }
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
        std::vector<Fatura> faturasApagar = uc.verificarPagamento();
        faturas.insert(faturas.end(), faturasApagar.begin(), faturasApagar.end());
    }

    return faturas;
}

std::vector<Fatura> Cliente::verificarVencimento(time_t now) {
    std::vector<Fatura> faturas;

    for (UC uc : this->UCs) {
        std::vector<Fatura> faturasVencidas = uc.verificarVencimento(now);
        faturas.insert(faturas.end(), faturasVencidas.begin(), faturasVencidas.end());
    }

    return faturas;
}


void Cliente::addFatura(int idUC, Fatura &fatura) {
    // implementar
    for (UC uc : this->UCs) {
        if (uc.getIdUc() != idUC) {
            continue;
        }
        uc.addFatura(fatura);

    }
}

bool Cliente::operator==(const Cliente& other) {
  return this->idCliente == other.getIdCliente();
}

