//
// Created by Thales Nunes on 02/06/2022.
//

#ifndef MODULO1_USUARIO_H
#define MODULO1_USUARIO_H


#include <string>
#include <vector>
#include "Permissao.h"

class Usuario {
    static int next_id_servico;
    int idUsuario;
    std::string nome;
    std::vector<Permissao> permissoes;
};


#endif //MODULO1_USUARIO_H
