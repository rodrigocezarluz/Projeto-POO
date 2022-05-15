//
// Created by Thales Nunes on 5/11/22.
//

#ifndef MODULO1_UC_H
#define MODULO1_UC_H

#include "TipoUC.h"
#include "Fatura.h"
#include <vector>

class UC {
private:
    int idUC;
    TipoUC tipo;
    std::vector<Fatura> faturas;

public:
    UC();

    UC(int idUc, TipoUC tipo, std::vector<Fatura> &faturas);

    int getIdUc() const;

    void setIdUc(int idUc);

    TipoUC getTipo() const;

    void setTipo(TipoUC tipo);

    std::vector<Fatura> & getFaturas();

    void setFaturas(std::vector<Fatura> &faturas);

    std::vector<Fatura> verificarPagamento();

};
#endif //MODULO1_UC_H
