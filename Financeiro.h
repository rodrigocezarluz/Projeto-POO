//
// Created by Thales Nunes on 5/11/22.
//

#ifndef MODULO1_FINANCEIRO_H
#define MODULO1_FINANCEIRO_H
#include <map>
#include <vector>
#include "Cliente.h"

class Financeiro {
    std::map<int, std::vector<int>> relatorioInandimplentes = {};
    std::vector<Cliente> clientes;
public:
    Financeiro();

    Financeiro(const std::map<int, std::vector<int>> &relatorioInandimplentes, const std::vector<Cliente> &clientes);

    const std::map<int, std::vector<int>> &getRelatorioInandimplentes() const;

    void setRelatorioInandimplentes(const std::map<int, std::vector<int>> &relatorioInandimplentes);

    const std::vector<Cliente> &getClientes() const;

    void setClientes(const std::vector<Cliente> &clientes);

    void cadastrarCliente(Cliente &cliente);

    void cadastrarUC(Cliente &clienteToInsert, UC &uc);

    void cadastrarFaturas(Cliente &clienteToInsert, UC &ucToInsert, Fatura &fatura);


};
#endif //MODULO1_FINANCEIRO_H
