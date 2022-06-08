//
// Created by Thales Nunes on 02/06/2022.
//

#ifndef MODULO1_LEITURISTA_H
#define MODULO1_LEITURISTA_H


#include "Funcionario.h"

class Leiturista: public Funcionario {
    using Funcionario::Funcionario;
public:
    void verificarServico(Servico& servico) override;
};


#endif //MODULO1_LEITURISTA_H
