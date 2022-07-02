//
// Created by Thales Nunes on 02/07/2022.
//

#include "LogEscrita.h"

#include <utility>

LogEscrita::LogEscrita(string &entidade, Usuario &usuario, string atributosAntes, string atributosDepois) :
        Log(entidade, usuario, "Escrita"),
        atributosAntes(std::move(atributosAntes)),
        atributosDepois(std::move(
                atributosDepois)) {}

const string &LogEscrita::getAtributosAntes() const {
    return atributosAntes;
}

void LogEscrita::setAtributosAntes(const string &atributosAntes) {
    LogEscrita::atributosAntes = atributosAntes;
}

const string &LogEscrita::getAtributosDepois() const {
    return atributosDepois;
}

void LogEscrita::setAtributosDepois(const string &atributosDepois) {
    LogEscrita::atributosDepois = atributosDepois;
}

string LogEscrita::toString() {
return "Time: " + Log::getData().toString() + " usuario: " + Log::getUsuario().getNome() + " entidade lida: " + Log::getEntidade()
    + " attr Antes: " + this->getAtributosAntes() + " attr depois: " + this->getAtributosDepois();
}
