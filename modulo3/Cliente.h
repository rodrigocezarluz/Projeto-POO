//
// Created by Thales Nunes on 5/11/22.
//

#ifndef MODULO1_CLIENTE_H
#define MODULO1_CLIENTE_H
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include "UC.h"

class Cliente {
private:
    static int nextIdCliente;
    int idCliente;
    std::string nome, telefoneContato;
    std::vector<UC> UCs;

public:
    Cliente();

    Cliente(const std::string &nome, const std::vector<UC> &uCs);

    Cliente(const Cliente& c);

    int getIdCliente() const;

    void setIdCliente(const int &idCliente);

    std::string getNome() const;

    void setNome(const std::string &nome);

    std::string getTelefoneContato() const;

    void setTelefoneContato(const std::string &telefoneContato);

    double pagar(const int &idFaturaAPagar, const time_t &dtPagamento);

    std::vector<Fatura> verificarPagamento();

    std::vector<Fatura> verificarVencimento(const time_t &now);

    std::vector<UC> const &getUCs() const;

    void setUCs(std::vector<UC> &uCs);

    void addUC(UC &new_uc);

    void removeUC(UC &remove_uc);

    void addFatura(int idUC, Fatura &fatura);

    bool operator==(const Cliente& other);

    Cliente& operator=(const Cliente& other);
};
#endif //MODULO1_CLIENTE_H
