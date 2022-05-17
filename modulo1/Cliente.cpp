#include "Cliente.h"

//
// Created by Thales Nunes on 5/11/22.
//

int Cliente::nextIdCliente = 0;

Cliente::Cliente() : idCliente(nextIdCliente++) {}

Cliente::Cliente(const std::string &nome, const std::vector<UC> &uCs) : idCliente(nextIdCliente++), nome(nome), UCs(uCs) {}

Cliente::Cliente(const Cliente& c) : idCliente(c.idCliente), nome(c.nome), UCs(c.UCs) {}

int Cliente::getIdCliente() const {
    return idCliente;
}

void Cliente::setIdCliente(const int &idCliente) {
    this->idCliente = idCliente;
}

std::string Cliente::getNome() const {
    return nome;
}

void Cliente::setNome(const std::string &nome) {
    this->nome = nome;
}

std::vector<UC> const &Cliente::getUCs() const {
    return UCs;
}

void Cliente::setUCs(std::vector<UC> &uCs) {
    this->UCs = std::move(uCs);
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

void Cliente::pagar(Fatura& faturaAPagar, const time_t &dtPagamento) {
    for (UC uc : this->UCs) {
        for (Fatura fatura: uc.getFaturas()) {
            if(fatura == faturaAPagar) {
                fatura.setDtPagamento(dtPagamento);
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

std::vector<Fatura> Cliente::verificarVencimento(const time_t &now) {
    std::vector<Fatura> faturas;

    for (UC uc : this->UCs) {
        std::vector<Fatura> faturasVencidas = uc.verificarVencimento(now);
        faturas.insert(faturas.end(), faturasVencidas.begin(), faturasVencidas.end());
    }

    return faturas;
}


void Cliente::addFatura(int idUC, Fatura &fatura) {
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

Cliente& Cliente::operator=(const Cliente& other) {
    this->idCliente = other.getIdCliente();
    this->nome = other.getNome();
    this->UCs = other.getUCs();

    return *this;
}