//
// Created by Thales Nunes on 02/07/2022.
//

#ifndef MODULO7_LOGTENTATIVAACESSO_H
#define MODULO7_LOGTENTATIVAACESSO_H


#include <string>
#include "Log.h"

class LogTentativaAcesso: Log {
    std::string funcAcessada;
public:
    LogTentativaAcesso(string &entidade, Usuario &usuario, string funcAcessada);

    const string &getFuncAcessada() const;

    void setFuncAcessada(const string &funcAcessada);

private:
    string toString() override;
};


#endif //MODULO7_LOGTENTATIVAACESSO_H
