#ifndef DESLIGENCERRAMENTO_H
#define DESLIGENCERRAMENTO_H

#include "Servico.h"

class DesligEncerramento : public Servico {
public:
    DesligEncerramento();

    DesligEncerramento(const Data &inicio, const UC &uc);

    DesligEncerramento(const Data &inicio, const Data &fim, const UC &uc);

    using Servico::Servico;
};

#endif