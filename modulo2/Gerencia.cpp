//
// Created by Thales Nunes on 5/11/22.
//

#include "Gerencia.h"
#include <stdexcept>

Gerencia::Gerencia() {}

Gerencia::Gerencia(const std::map<int, std::vector<Fatura>> &relatorioInandimplentes,
                       const std::vector<Cliente> &clientes) : relatorioInandimplentes(relatorioInandimplentes),
                                                               clientes(clientes) {};

const std::map<int, std::vector<Fatura>> &Gerencia::getRelatorioInandimplentes() const {
    return relatorioInandimplentes;
}

void Gerencia::setRelatorioInandimplentes(const std::map<int, std::vector<Fatura>> &relatorioInandimplentes) {
    Gerencia::relatorioInandimplentes = relatorioInandimplentes;
}

const std::vector<Cliente> &Gerencia::getClientes() const {
    return clientes;
}

void Gerencia::setClientes(const std::vector<Cliente> &clientes) {
    Gerencia::clientes = clientes;
}

void Gerencia::cadastrarCliente(Cliente &cliente) {
    this->clientes.push_back(cliente);
}

void Gerencia::cadastrarUC(const int &clienteToInsert, UC &uc) {
    for (auto &cliente : this->clientes) {
        if (cliente.getIdCliente() == clienteToInsert){
            cliente.addUC(uc);
            return;
        }
    }

    throw std::invalid_argument("O cliente da UC nao existe.");
}


void Gerencia::cadastrarFaturas(const int &idCliente, int idUC, Fatura& fatura) {

    for (auto &cliente : this->clientes) {
        if (cliente.getIdCliente() != idCliente) {
            continue;
        }
        cliente.addFatura(idUC, fatura);
        return;
    }
    throw std::invalid_argument( "O cliente da UC nao existe." );
}

double Gerencia::receberPagamento(const int &idCliente, const int &idFaturaAPagar, const time_t &dtPagamento) {
    for (auto &cliente : this->clientes) {
        if (cliente.getIdCliente() == idCliente) {
            return cliente.pagar(idFaturaAPagar, dtPagamento);
        }
    }
}

void Gerencia::verificarInadimplentes(const time_t &now) {
    relatorioInandimplentes.clear();
    for (auto &cliente : this->clientes) {
        std::vector<Fatura> faturasVencidas = cliente.verificarVencimento(now);
        if (faturasVencidas.size() > 0) {
                relatorioInandimplentes[cliente.getIdCliente()] = faturasVencidas;
        }
    }
}
