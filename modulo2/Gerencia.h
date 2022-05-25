//
// Created by Thales Nunes on 5/11/22.
//

#ifndef MODULO1_FINANCEIRO_H
#define MODULO1_FINANCEIRO_H
#include <map>
#include <vector>
#include "Cliente.h"
#include "Funcionario.h"
#include "UC.h"
#include "Fatura.h"
#include "Servico.h"

class Gerencia {
private:
    std::map<int, std::vector<Fatura>> relatorioInandimplentes = {};
    std::vector<Cliente> clientes;
    std::vector<Funcionario> funcionarios;

public:
    Gerencia();

    Gerencia(const std::map<int, std::vector<Fatura>> &relatorioInandimplentes, const std::vector<Cliente> &clientes);

    const std::map<int, std::vector<Fatura>> &getRelatorioInandimplentes() const;

    void setRelatorioInandimplentes(const std::map<int, std::vector<Fatura>> &relatorioInandimplentes);

    const std::vector<Cliente> &getClientes() const;

    void setClientes(const std::vector<Cliente> &clientes);

    const std::vector<Funcionario> &getFuncionarios() const;

    void setFuncionarios(const std::vector<Funcionario> &funcionarios);

    void cadastrarCliente(Cliente &cliente);

    void cadastrarFuncionario(Funcionario &funcionario);

    void cadastrarUC(const int &clienteToInsert, UC &uc);

    void cadastrarFaturas(const int &idCliente, int idUC, Fatura &fatura);

    void cadastrarServico(const int &idFuncionario, Servico &servico, const std::string &data, int prioridade_servico);

    void executarServicos(const int &idFuncionario, const std::string &data);

    double receberPagamento(const int &idCliente, const int &idFaturaAPagar, const time_t &dtPagamento);

    void verificarInadimplentes(const time_t &now);
};
#endif //MODULO1_FINANCEIRO_H
