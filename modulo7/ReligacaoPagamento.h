#ifndef RELIGACAOPAGAMENTO_H
#define RELIGACAOPAGAMENTO_H

#include "Servico.h"

class ReligacaoPagamento : public Servico {
public:
    ReligacaoPagamento();

    ReligacaoPagamento(const Data &inicio, const Data &fim, const UC &uc);

    ReligacaoPagamento(const Data &inicio, const UC &uc);

    using Servico::Servico;
};

#endif