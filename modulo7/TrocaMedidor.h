#ifndef TROCAMEDIDOR_H
#define TROCAMEDIDOR_H

#include "Servico.h"

class TrocaMedidor : public Servico {
public:
    TrocaMedidor();

    TrocaMedidor(const Data &inicio, const Data &fim, const UC &uc);

    TrocaMedidor(const Data &inicio, const UC &uc);

    using Servico::Servico;
};

#endif