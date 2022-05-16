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
    int idUC;
    std::vector<Fatura> faturas;

public:
    UC();

    UC(int idUc, const std::vector<Fatura> &faturas);

    int getIdUc() const;

    void setIdUc(int idUc);

    std::vector<Fatura> & getFaturas();

    void setFaturas(std::vector<Fatura> &faturas);

    std::vector<Fatura> verificarPagamento();

    std::vector<Fatura> verificarVencimento(time_t now);

    void addFatura(Fatura &fatura);

    bool operator==(const UC& other);
};
#endif //MODULO1_UC_H
