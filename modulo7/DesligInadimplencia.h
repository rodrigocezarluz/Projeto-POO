#ifndef DESLIGINADIMPLENCIA_H
#define DESLIGINADIMPLENCIA_H

#include "Servico.h"

class DesligInadimplencia : public Servico {
public:
    DesligInadimplencia();

    DesligInadimplencia(const Data &inicio, const UC &uc);

    using Servico::Servico;
};

#endif