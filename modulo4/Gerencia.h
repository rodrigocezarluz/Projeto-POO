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
#include "Data.h"

class Gerencia {
private:
    std::map<int, std::vector<Fatura>> relatorioInandimplentes = {};
    std::vector<Cliente> clientes;
    std::vector<std::reference_wrapper<Funcionario>> funcionarios;

public:
    Gerencia();

    Gerencia(const std::map<int, std::vector<Fatura>> &relatorioInandimplentes, const std::vector<Cliente> &clientes);

    const std::map<int, std::vector<Fatura>> &getRelatorioInandimplentes() const;

    void setRelatorioInandimplentes(const std::map<int, std::vector<Fatura>> &relatorioInandimplentes);

    const std::vector<Cliente> &getClientes() const;

    void setClientes(const std::vector<Cliente> &clientes);

    const vector<std::reference_wrapper<Funcionario>> &getFuncionarios() const;

    void setFuncionarios(const vector<std::reference_wrapper<Funcionario>> &funcionarios);

    void cadastrarCliente(Cliente &cliente);

    void cadastrarFuncionario(Funcionario &funcionario);

    void cadastrarUC(const int &clienteToInsert, UC &uc);

    void cadastrarFaturas(const int &idCliente, int idUC, Fatura &fatura);

    void cadastrarServico(const int &idFuncionario, Servico &servico, const Data &data, int prioridade_servico);

    void executarServicos(const int &idFuncionario, const Data &data);

    double receberPagamento(const int &idCliente, const int &idFaturaAPagar, const Data &dtPagamento);

    void verificarInadimplentes(Data &now);
};
#endif //MODULO1_FINANCEIRO_H
