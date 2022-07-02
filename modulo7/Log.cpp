#include "Data.h"
#include "Log.h"

#include <utility>

 Data Log::getData() const {
    return data;
}

void Log::setData(const Data &data) {
    Log::data = data;
}

const std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>> &Log::getEntidade() const {
    return entidade;
}

void
Log::setEntidade(const std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>> &entidade) {
    Log::entidade = entidade;
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

