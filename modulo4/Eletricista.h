//
// Created by Thales Nunes on 02/06/2022.
//

#ifndef MODULO1_ELETRICISTA_H
#define MODULO1_ELETRICISTA_H


#include "Funcionario.h"

class Eletricista: public Funcionario {
    using Funcionario::Funcionario;
public:
    void verificarServico(Servico &servico) override;
};


#endif //MODULO1_ELETRICISTA_H
