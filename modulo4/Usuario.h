//
// Created by Thales Nunes on 02/06/2022.
//

#ifndef MODULO1_USUARIO_H
#define MODULO1_USUARIO_H


#include <string>
#include <vector>
#include "Permissao.h"

class Usuario {
    static int next_id_usuario;
    int idUsuario;
    std::string nome;
    std::vector<std::reference_wrapper<Permissao>> permissoes;
public:
    Usuario(const std::string &nome, const std::vector<std::reference_wrapper<Permissao>> &permissoes);

    Usuario();

    int getIdUsuario() const;

    void setIdUsuario(int idUsuario);

    const std::string &getNome() const;

    void setNome(const std::string &nome);

    const std::vector<std::reference_wrapper<Permissao>> &getPermissoes() const;

    void setPermissoes(const std::vector<std::reference_wrapper<Permissao>> &permissoes);
};


#endif //MODULO1_USUARIO_H
