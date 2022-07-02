//
// Created by Thales Nunes on 02/07/2022.
//

#ifndef MODULO7_LOGLEITURA_H
#define MODULO7_LOGLEITURA_H


#include "Log.h"

class LogLeitura : public Log {

    std::string infoAcessada;
public:
    LogLeitura(string &entidade, Usuario &usuario, string infoAcessada);

    const string &getInfoAcessada() const;

    void setInfoAcessada(const string &infoAcessada);

    string toString() override;
};


#endif //MODULO7_LOGLEITURA_H
