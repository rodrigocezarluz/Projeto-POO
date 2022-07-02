//
// Created by Thales Nunes on 02/07/2022.
//

#ifndef MODULO7_LOG_H
#define MODULO7_LOG_H


#include "Data.h"
#include "Usuario.h"

class Log {
    Data data;
    std::string entidade;
    Usuario usuario;
    std::string LogType;
protected:
public:
    Log(string entidade, Usuario usuario, string logType);

public:
    Data getData() const;

    void setData(const Data &data);

    const string &getEntidade() const;

    void setEntidade(const string &entidade);

    const Usuario &getUsuario() const;

    void setUsuario(const Usuario &usuario);

    virtual std::string toString() = 0;
};


#endif //MODULO7_LOG_H
