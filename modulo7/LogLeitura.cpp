//
// Created by Thales Nunes on 02/07/2022.
//

#include "LogLeitura.h"

#include <utility>

const string &LogLeitura::getInfoAcessada() const {
    return infoAcessada;
}

void LogLeitura::setInfoAcessada(const string &infoAcessada) {
    LogLeitura::infoAcessada = infoAcessada;
}

string LogLeitura::toString() {
    return "Time: " + Log::getData().toString() + " usuario: " + Log::getUsuario().getNome()
    + + " entidade lida: " + Log::getEntidade() + " info Acessada: " + this->infoAcessada;
}

LogLeitura::LogLeitura(string &entidade, Usuario &usuario, string infoAcessada)
: Log(entidade, usuario, "Leitura"), infoAcessada(std::move(infoAcessada)) {}
