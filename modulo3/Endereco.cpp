#include "Endereco.h"
#include "LocalizacaoGeografica.h"
#include <iostream>

Endereco::Endereco() {}

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
