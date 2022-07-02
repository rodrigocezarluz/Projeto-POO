//
// Created by Thales Nunes on 02/07/2022.
//

#include "LogTentativaAcesso.h"

#include <utility>

LogTentativaAcesso::LogTentativaAcesso(string &entidade, Usuario &usuario, string funcAcessada)
        : Log(entidade, usuario, "TentativaAcesso"), funcAcessada(std::move(funcAcessada)) {}

const string &LogTentativaAcesso::getFuncAcessada() const {
    return funcAcessada;
}

void LogTentativaAcesso::setFuncAcessada(const string &funcAcessada) {
    LogTentativaAcesso::funcAcessada = funcAcessada;
}

string LogTentativaAcesso::toString() {
    return "Time: " + Log::getData().toString() + " usuario: " + Log::getUsuario().getNome() +
    + " entidade lida: " + Log::getEntidade() + " funcionalidade Acessada: " + this->funcAcessada;
}
