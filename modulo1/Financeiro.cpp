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

// TODO: Add UC
void Financeiro::cadastrarUC(Cliente &clienteToInsert, UC &uc) {
    for (Cliente cliente : this->clientes) {
        if (cliente.getIdCliente() == clienteToInsert.getIdCliente()) {
            cliente.addUC(uc);
            return;
        }
    }
    throw std::invalid_argument("O cliente da UC nao existe.");
}


void Financeiro::cadastrarFaturas(int idCliente, int idUC, Fatura& fatura) {

    for (Cliente cliente : this->clientes) {
        if (cliente.getIdCliente() != idCliente) {
            continue;
        }
        cliente.addFatura(idUC, fatura);

    }
    throw std::invalid_argument( "O cliente da UC nao existe." );
}

void Financeiro::verificarInadimplentes() {
 // TODO: implementar
}
