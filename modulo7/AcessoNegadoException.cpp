//
// Created by Thales Nunes on 02/07/2022.
//

#include "AcessoNegadoException.h"

#include <utility>

AcessoNegadoException::AcessoNegadoException(std::string funcionalidade, Usuario usuario)
        : funcionalidade(std::move(funcionalidade)), usuario(std::move(usuario)) {}

char* AcessoNegadoException::what() {
    const std::basic_string<char, std::char_traits<char>, std::allocator<char>> &string =
            "Acesso negado para o usuário: " + this->usuario.getNome() + " a funcionalidade: " + this->funcionalidade;
    return const_cast<char *>(string.c_str());
}

const std::string &AcessoNegadoException::getFuncionalidade() const {
    return funcionalidade;
}

const Usuario &AcessoNegadoException::getUsuario() const {
    return usuario;
}
