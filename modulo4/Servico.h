#ifndef SERVICO_H
#define SERVICO_H

#include <ctime>
#include "UC.h"
#include "Data.h"

class Servico {
    static int next_id_servico;
    int id_servico; 
    Data inicio;
    Data fim;
    UC uc;

public:
    Servico();

    Servico(Data inicio, const UC &uc);

    Servico(Data inicio, Data fim, const UC &uc);

    Data getInicio() const;

    void setInicio(Data inicio);

    Data getFim() const;

    void setFim(Data fim);

    virtual void executar();

    int getIDServico();

    UC& getUC();

};

#endif