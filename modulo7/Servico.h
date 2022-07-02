#ifndef SERVICO_H
#define SERVICO_H

#include <ctime>
#include "UC.h"
#include "Data.h"
#include "TipoServico.h"

class Servico {
    static int next_id_servico;
    int id_servico; 
    Data inicio;
    Data fim;
    UC uc;
    TipoServico tipoServico;

public:
    Servico();

    Servico(TipoServico tipoServico);

    Servico(TipoServico tipoServico, Data inicio, Data fim, const UC &uc);

    Servico(TipoServico tipoServico, Data inicio, const UC &uc);

    Data getInicio() const;

    void setInicio(Data inicio);

    Data getFim() const;

    void setFim(Data fim);

    virtual void executar();

    int getIDServico();

    UC& getUC();

    TipoServico getTipoServico() const;

};

#endif