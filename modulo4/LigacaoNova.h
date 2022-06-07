#ifndef LIGACAONOVA_H
#define LIGACAONOVA_H

#include "Servico.h"

class LigacaoNova : public Servico {
public:
    LigacaoNova();

    LigacaoNova(const Data &inicio, const Data &fim, const UC &uc);

    LigacaoNova(const Data &inicio, const UC &uc);

    using Servico::Servico;
};

#endif