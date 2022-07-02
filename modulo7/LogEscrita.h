//
// Created by Thales Nunes on 02/07/2022.
//

#ifndef MODULO7_LOGESCRITA_H
#define MODULO7_LOGESCRITA_H


#include "Log.h"

class LogEscrita : public Log {

    std::string atributosAntes;
    std::string atributosDepois;
public:
    LogEscrita(string &entidade, Usuario &usuario, string atributosAntes, string atributosDepois);

    const string &getAtributosAntes() const;

    void setAtributosAntes(const string &atributosAntes);

    const string &getAtributosDepois() const;

    void setAtributosDepois(const string &atributosDepois);

    string toString() override;
};


#endif //MODULO7_LOGESCRITA_H
