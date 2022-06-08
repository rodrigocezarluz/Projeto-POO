#include "Cliente.h"
#include <iostream>
//
// Created by Thales Nunes on 5/11/22.
//

int Cliente::nextIdCliente = 0;

Cliente::Cliente() : Usuario(), idCliente(nextIdCliente++) {
    Endereco endereco1;
    this->endereco = endereco1;
}

Cliente::Cliente(const std::string &nome, const std::vector<UC> &uCs) : Usuario(), idCliente(nextIdCliente++), UCs(uCs) {
    Endereco endereco1;
    this->endereco = endereco1;
    this->setNome(nome);
}

Cliente::Cliente(const Cliente& c) : Usuario(), idCliente(c.idCliente), UCs(c.UCs) {
    Endereco endereco1;
    this->endereco = endereco1;
    this->setNome(c.getNome());
}

Cliente::Cliente(const string &nome, const string &telefoneContato, const vector<UC> &uCs, const Endereco &endereco) : Usuario(), 
                                            idCliente(nextIdCliente++), telefoneContato(telefoneContato), UCs(uCs), endereco(endereco) {
    this->setNome(nome);
}

int Cliente::getIdCliente() const {
    return idCliente;
}

void Cliente::setIdCliente(const int &idCliente) {
    this->idCliente = idCliente;
}

std::string Cliente::getTelefoneContato() const {
    return telefoneContato;
}

void Cliente::setTelefoneContato(const std::string &telefoneContato) {
    this->telefoneContato = telefoneContato;
}

const Endereco &Cliente::getEndereco() const {
    return endereco;
}

void Cliente::setEndereco(const Endereco &endereco) {
    Cliente::endereco = endereco;
}

std::vector<UC> const &Cliente::getUCs() const {
    return UCs;
}

void Cliente::setUCs(std::vector<UC> &uCs) {
    this->UCs = std::move(uCs);
}

void Cliente::addUC(UC &new_uc) {
    for (auto &uc : this->UCs) {
        if (uc == new_uc) {
            throw std::invalid_argument("Repeated UC id");
        }
    }
    this->UCs.push_back(new_uc);
}

void Cliente::removeUC(UC &remove_uc) {

    const auto orig_size = this->UCs.size();

    this->UCs.erase(std::remove(UCs.begin(), UCs.end(), remove_uc), UCs.end());

    if (this->UCs.size() == orig_size) {
        throw std::invalid_argument( "UC not found." );
    }
}

double Cliente::pagar(const int &idFaturaAPagar, const Data &dtPagamento) {
    for (auto &uc : this->UCs) {
        for (auto &fatura: uc.getFaturas()) {
            if(fatura.getIdFatura() == idFaturaAPagar) {
                return uc.pagar(idFaturaAPagar, dtPagamento);
            }
        }
    }
    throw std::invalid_argument( "Fatura a Pagar nao existe." );
}
 
std::vector<Fatura> Cliente::verificarPagamento() {
    std::vector<Fatura> faturas;

    for (auto &uc : this->UCs) {
        std::vector<Fatura> faturasApagar = uc.verificarPagamento();
        faturas.insert(faturas.end(), faturasApagar.begin(), faturasApagar.end());
    }

    return faturas;
}

std::vector<Fatura> Cliente::verificarVencimento(Data &now) {
    std::vector<Fatura> faturas;

    for (auto &uc : this->UCs) {
        std::vector<Fatura> faturasVencidas = uc.verificarVencimento(now);
        faturas.insert(faturas.end(), faturasVencidas.begin(), faturasVencidas.end());
    }

    return faturas;
}


void Cliente::addFatura(int idUC, Fatura &fatura) {
    for (auto &uc : this->UCs) {
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
    this->setNome(other.getNome());
    this->UCs = other.getUCs();

    return *this;
}
