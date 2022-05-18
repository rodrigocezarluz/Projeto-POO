//
// Created by Thales Nunes on 5/11/22.
//

#include "Financeiro.h"
#include <stdexcept>

Financeiro::Financeiro() {}

Financeiro::Financeiro(const std::map<int, std::vector<Fatura>> &relatorioInandimplentes,
                       const std::vector<Cliente> &clientes) : relatorioInandimplentes(relatorioInandimplentes),
                                                               clientes(clientes) {};

const std::map<int, std::vector<Fatura>> &Financeiro::getRelatorioInandimplentes() const {
    return relatorioInandimplentes;
}

void Financeiro::setRelatorioInandimplentes(const std::map<int, std::vector<Fatura>> &relatorioInandimplentes) {
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

void Financeiro::cadastrarUC(const int &clienteToInsert, UC &uc) {
    for (Cliente cliente : this->clientes) {
        if (cliente.getIdCliente() == clienteToInsert) {
            cliente.addUC(uc);
            return;
        }
    }
    throw std::invalid_argument("O cliente da UC nao existe.");
}


void Financeiro::cadastrarFaturas(const int &idCliente, int idUC, Fatura& fatura) {

    for (Cliente cliente : this->clientes) {
        if (cliente.getIdCliente() != idCliente) {
            continue;
        }
        cliente.addFatura(idUC, fatura);
        return;

    }
    throw std::invalid_argument( "O cliente da UC nao existe." );
}

double Financeiro::receberPagamento(const int &idCliente, const int &idFaturaAPagar, const time_t &dtPagamento) {
    for (Cliente cliente : this->clientes) {
        if (cliente.getIdCliente() == idCliente) {
            return cliente.pagar(idFaturaAPagar, dtPagamento);
        }
    }
}

void Financeiro::verificarInadimplentes(const time_t &now) {
    relatorioInandimplentes.clear();
    for (Cliente cliente : this->clientes) {
        std::vector<Fatura> faturasVencidas = cliente.verificarVencimento(now);
        if (faturasVencidas.size() > 0) {
                relatorioInandimplentes[cliente.getIdCliente()] = faturasVencidas;
        }
    }
}
