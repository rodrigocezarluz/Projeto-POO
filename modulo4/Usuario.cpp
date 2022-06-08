//
// Created by Thales Nunes on 02/06/2022.
//

#include "Usuario.h"
int Usuario::next_id_usuario = 0;

Usuario::Usuario(): idUsuario(next_id_usuario++) {}

Usuario::Usuario(const std::string &nome, const std::vector<std::reference_wrapper<Permissao>> &permissoes) : idUsuario(next_id_usuario++), nome(
        nome), permissoes(permissoes) {}

int Usuario::getIdUsuario() const {
    return idUsuario;
}

void Usuario::setIdUsuario(int idUsuario) {
    this->idUsuario = idUsuario;
}

const std::string &Usuario::getNome() const {
    return nome;
}

void Usuario::setNome(const std::string &nome) {
    this->nome = nome;
}

const std::vector<std::reference_wrapper<Permissao>> &Usuario::getPermissoes() const {
    return permissoes;
}

void Usuario::setPermissoes(const std::vector<std::reference_wrapper<Permissao>> &permissoes) {
    this->permissoes = permissoes;
}
