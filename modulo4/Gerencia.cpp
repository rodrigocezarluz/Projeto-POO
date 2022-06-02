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
    this->relatorioInandimplentes = relatorioInandimplentes;
}

const std::vector<Cliente> &Gerencia::getClientes() const {
    return clientes;
}

void Gerencia::setClientes(const std::vector<Cliente> &clientes) {
    this->clientes = clientes;
}

const std::vector<Funcionario> &Gerencia::getFuncionarios() const {
    return funcionarios;
}

void Gerencia::setFuncionarios(const std::vector<Funcionario> &funcionarios) {
    this->funcionarios = funcionarios;
}

void Gerencia::cadastrarCliente(Cliente &cliente) {
    this->clientes.push_back(cliente);
}

void Gerencia::cadastrarFuncionario(Funcionario &funcionario) {
    this->funcionarios.push_back(funcionario);
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

void Gerencia::cadastrarServico(const int &idFuncionario, Servico &servico, const Data &data, int prioridade_servico) {
    for (auto &funcionario : this->funcionarios) {
        if (funcionario.getIDFuncionario() == idFuncionario){
            funcionario.adicionarServico(servico, data, prioridade_servico);
            return;
        }
    }

    throw std::invalid_argument("O funcionario nao existe.");
}

void Gerencia::executarServicos(const int &idFuncionario, const Data &data) {
    for (auto &funcionario : this->funcionarios) {
        if (funcionario.getIDFuncionario() == idFuncionario) {
            funcionario.executarServicos(data);
            return;
        }
    }
    throw std::invalid_argument("O funcionario nao existe.");
}

double Gerencia::receberPagamento(const int &idCliente, const int &idFaturaAPagar, const Data &dtPagamento) {
    for (auto &cliente : this->clientes) {
        if (cliente.getIdCliente() == idCliente) {
            return cliente.pagar(idFaturaAPagar, dtPagamento);
        }
    }
    throw std::invalid_argument("O cliente nao existe.");
}

void Gerencia::verificarInadimplentes(Data &now) {
    relatorioInandimplentes.clear();
    for (auto &cliente : this->clientes) {
        std::vector<Fatura> faturasVencidas = cliente.verificarVencimento(now);
        if (faturasVencidas.size() > 0) {
                relatorioInandimplentes[cliente.getIdCliente()] = faturasVencidas;
        }
    }
}
