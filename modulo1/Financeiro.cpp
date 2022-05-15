//
// Created by Thales Nunes on 5/11/22.
//

#include "Financeiro.h"
#include <stdexcept>

Financeiro::Financeiro() {}

Financeiro::Financeiro(const std::map<int, std::vector<int>> &relatorioInandimplentes,
                       const std::vector<Cliente> &clientes) : relatorioInandimplentes(relatorioInandimplentes),
                                                               clientes(clientes) {};

const std::map<int, std::vector<int>> &Financeiro::getRelatorioInandimplentes() const {
    return relatorioInandimplentes;
}

void Financeiro::setRelatorioInandimplentes(const std::map<int, std::vector<int>> &relatorioInandimplentes) {
    Financeiro::relatorioInandimplentes = relatorioInandimplentes;
}

const std::vector<Cliente> &Financeiro::getClientes() const {
    return clientes;
}

void Financeiro::setClientes(const std::vector<Cliente> &clientes) {
    Financeiro::clientes = clientes;
}

void Financeiro::cadastrarCliente(Cliente &cliente) {
    this->clientes.push_back(cliente);
}

void Financeiro::cadastrarUC(Cliente &clienteToInsert, UC &uc) {
    for (Cliente cliente : this->clientes) {
        if (cliente.getIdCliente() == clienteToInsert.getIdCliente()) {
            cliente.getUCs().push_back(uc);
            return;
        }
    }
    throw std::invalid_argument( "O cliente da UC nao existe." );
}


void Financeiro::cadastrarFaturas(Cliente &clienteToInsert, UC &ucToInsert, Fatura& fatura) {
    for (Cliente cliente : this->clientes) {
        if (cliente.getIdCliente() != clienteToInsert.getIdCliente()) {
            continue;
        }
        for (UC uc : cliente.getUCs()) {
            if (uc.getIdUc() != ucToInsert.getIdUc()) {
                continue;
            }
            uc.getFaturas().push_back(fatura);
        }

        throw std::invalid_argument( "A UC informada nao existe para o cliente informado." );
    }
    throw std::invalid_argument( "O cliente da UC nao existe." );
}
