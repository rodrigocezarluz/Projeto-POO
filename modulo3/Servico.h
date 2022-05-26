#ifndef SERVICO_H
#define SERVICO_H

#include <ctime>
#include "UC.h"

class Servico {
    static int next_id_servico;
    int id_servico; 
    std::time_t inicio;
    std::time_t fim;
    UC uc;
public:
    Servico();

    Servico(time_t inicio, const UC &uc);

    Servico(time_t inicio, time_t fim, const UC &uc);


    time_t getInicio() const;

    void setInicio(time_t inicio);

    time_t getFim() const;

    void setFim(time_t fim);

    void executar();

    int getIDServico();
};

#endif