//
// Created by Thales Nunes on 5/11/22.
//

#ifndef MODULO1_FINANCEIRO_H
#define MODULO1_FINANCEIRO_H
#include <map>
#include <vector>
#include "Cliente.h"

class Gerencia {
private:
    std::map<int, std::vector<Fatura>> relatorioInandimplentes = {};
    std::vector<Cliente> clientes;

public:
    Gerencia();

    Gerencia(const std::map<int, std::vector<Fatura>> &relatorioInandimplentes, const std::vector<Cliente> &clientes);

    const std::map<int, std::vector<Fatura>> &getRelatorioInandimplentes() const;

    void setRelatorioInandimplentes(const std::map<int, std::vector<Fatura>> &relatorioInandimplentes);

    const std::vector<Cliente> &getClientes() const;

    void setClientes(const std::vector<Cliente> &clientes);

    void cadastrarCliente(Cliente &cliente);

    void cadastrarUC(const int &clienteToInsert, UC &uc);

    void cadastrarFaturas(const int &idCliente, int idUC, Fatura &fatura);

    double receberPagamento(const int &idCliente, const int &idFaturaAPagar, const time_t &dtPagamento);

    void verificarInadimplentes(const time_t &now);
};
#endif //MODULO1_FINANCEIRO_H
