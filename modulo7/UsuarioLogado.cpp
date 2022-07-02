//
// Created by Thales Nunes on 02/07/2022.
//

#include "UsuarioLogado.h"
UsuarioLogado::UsuarioLogado() {
     this->isUserLoggedIn = false;
}

UsuarioLogado* UsuarioLogado::singleton_ = nullptr;;

UsuarioLogado *UsuarioLogado::GetInstance()
{
    if(singleton_ == nullptr){
        singleton_ = new UsuarioLogado();
    }
    return singleton_;
}

Usuario UsuarioLogado::getUsuario() {
    if (!this->isUserLoggedIn) {
        throw std::exception();
    }

    return usuario;
}

void UsuarioLogado::login(const Usuario &usuario) {
    UsuarioLogado::usuario = usuario;
    this->isUserLoggedIn = true;
}

void UsuarioLogado::logout() {
    this->isUserLoggedIn = false;
}
