//
// Created by Thales Nunes on 02/07/2022.
//

#ifndef MODULO7_ACESSONEGADOEXCEPTION_H
#define MODULO7_ACESSONEGADOEXCEPTION_H


#include <exception>
#include <string>
#include "Usuario.h"

class AcessoNegadoException : public std::exception {
    std::string funcionalidade;
    Usuario usuario;
public:
    AcessoNegadoException(std::string funcionalidade, Usuario usuario);

    char * what ();

    const std::string &getFuncionalidade() const;

    const Usuario &getUsuario() const;
};


#endif //MODULO7_ACESSONEGADOEXCEPTION_H
