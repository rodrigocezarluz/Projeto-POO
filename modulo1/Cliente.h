//
// Created by Thales Nunes on 5/11/22.
//

#ifndef MODULO1_CLIENTE_H
#define MODULO1_CLIENTE_H
#include <string>
#include <vector>
#include "UC.h"

class Cliente {
    int idCliente;
    std::string nome;
    std::vector<UC> UCs;
public:
    Cliente();

    Cliente(int idCliente, const std::string &nome, const std::vector<UC> &uCs);


    int getIdCliente() const;

    void setIdCliente(int idCliente);

    const std::string &getNome() const;

    void setNome(const std::string &nome);

    void pagar(Fatura &fatura);

    std::vector<Fatura> verificarPagamento();

    std::vector<UC> &getUCs();

    void setUCs(const std::vector<UC> &uCs);

    //TODO: Adicionar metodos para adicao/remocao de UCs
    void addUC(UC &uc);

    void addFatura(int idUC, Fatura &fatura);
};
#endif //MODULO1_CLIENTE_H
