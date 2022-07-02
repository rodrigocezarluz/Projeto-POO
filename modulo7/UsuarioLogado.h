//
// Created by Thales Nunes on 02/07/2022.
//

#ifndef MODULO7_USUARIOLOGADO_H
#define MODULO7_USUARIOLOGADO_H


#include <string>
#include "Usuario.h"

class UsuarioLogado {
protected:
    UsuarioLogado();

    static UsuarioLogado* singleton_;

    Usuario usuario;
    bool isUserLoggedIn;

public:
    UsuarioLogado(UsuarioLogado &other) = delete;

    void operator=(const UsuarioLogado &) = delete;

    static UsuarioLogado *GetInstance();

    Usuario getUsuario();

    void login(const Usuario &usuario);

    void logout();
};



#endif //MODULO7_USUARIOLOGADO_H
