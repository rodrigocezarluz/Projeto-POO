//
// Created by Thales Nunes on 5/11/22.
//

#ifndef MODULO1_UC_H
#define MODULO1_UC_H

#include "Fatura.h"
#include <vector>
#include <stdexcept>

class UC {
private:
    static int nextIdUC;
    int idUC;
    std::vector<Fatura> faturas;

public:
    UC();

    UC(const std::vector<Fatura> &faturas);

    UC(const UC& uc);

    int getIdUc() const;

    void setIdUc(int idUc);

    std::vector<Fatura> const & getFaturas() const;

    void setFaturas(std::vector<Fatura> &faturas);

    double pagar(const int &idFaturaAPagar, const time_t &dtPagamento);

    std::vector<Fatura> verificarPagamento();

    std::vector<Fatura> verificarVencimento(const time_t &now);

    void addFatura(Fatura &fatura);

    bool operator==(const UC& other);

    UC& operator=(const UC& other);
};
#endif //MODULO1_UC_H
