#include "Endereco.h"
#include "LocalizacaoGeografica.h"

Endereco::Endereco() : LocalizacaoGeografica(0.,0.) {}

Endereco::Endereco(const std::string &logradouro, const std::string &bairro, const std::string &complemento,
                   const std::string &cep, const std::string &cidade, const std::string &estado, int numero)
        : LocalizacaoGeografica(0.,0.), logradouro(logradouro), bairro(bairro), complemento(complemento), cep(cep), cidade(cidade), estado(estado),
          numero(numero) {}

Endereco::Endereco(double latitude, double longitude, const std::string &logradouro, const std::string &bairro,
                   const std::string &complemento, const std::string &cep, const std::string &cidade,
                   const std::string &estado, int numero) : LocalizacaoGeografica(latitude, longitude),
                                                            logradouro(logradouro), bairro(bairro),
                                                            complemento(complemento), cep(cep), cidade(cidade),
                                                            estado(estado), numero(numero) {}

int Endereco::getNumero() const {
    return numero;
}

void Endereco::setNumero(const int &numero) {
    this->numero = numero;
}

std::string Endereco::getLogradouro() const {
    return logradouro;
}

void Endereco::setLogradouro(const std::string &logradouro) {
    this->logradouro = logradouro;
}

std::string Endereco::getBairro() const {
    return bairro;
}

void Endereco::setBairro(const std::string &bairro) {
    this->bairro = bairro;
}

std::string Endereco::getComplemento() const {
    return complemento;
}

void Endereco::setComplemento(const std::string &complemento) {
    this->complemento = complemento;
}

std::string Endereco::getCep() const {
    return cep;
}

void Endereco::setCep(const std::string &cep) {
    this->cep = cep;
}

std::string Endereco::getCidade() const {
    return cidade;
}

void Endereco::setCidade(const std::string &cidade) {
    this->cidade = cidade;
}

std::string Endereco::getEstado() const {
    return estado;
}

void Endereco::setEstado(const std::string &estado) {
    this->estado = estado;
}
