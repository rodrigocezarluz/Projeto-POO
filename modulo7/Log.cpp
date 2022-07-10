#include "Data.h"
#include "Log.h"

#include <utility>

Data Log::getData() const {
    return data;
}

void Log::setData(const Data &data) {
    Log::data = data;
}

const Usuario &Log::getUsuario() const {
    return usuario;
}

void Log::setUsuario(const Usuario &usuario) {
    Log::usuario = usuario;
}

Log::Log(string entidade, Usuario usuario, string logType) : entidade(std::move(entidade)),
                                                                                  usuario(std::move(usuario)),
                                                                                  LogType(std::move(logType)) {
    this->data = Data::dateNow();
}

const string &Log::getEntidade() const {
    return entidade;
}

void Log::setEntidade(const string &entidade) {
    Log::entidade = entidade;
}

