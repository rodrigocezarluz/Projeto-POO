#ifndef ENDERECO_H
#define ENDERECO_H

#include <string>
#include "LocalizacaoGeografica.h"

class Endereco: public LocalizacaoGeografica {
    std::string logradouro;
    std::string bairro;
    std::string complemento;
    std::string cep;
    std::string cidade;
    std::string estado;
    int numero;

public:
    Endereco();

    Endereco(const std::string &logradouro, const std::string &bairro, const std::string &complemento, const std::string &cep,
             const std::string &cidade, const std::string &estado, int numero);

    Endereco(double latitude, double longitude, const std::string &logradouro, const std::string &bairro,
             const std::string &complemento, const std::string &cep, const std::string &cidade, const std::string &estado, int numero);

    int getNumero() const;

    void setNumero(const int &numero);

    std::string getLogradouro() const;

    void setLogradouro(const std::string &logradouro);

    std::string getBairro() const;

    void setBairro(const std::string &bairro);

    std::string getComplemento() const;

    void setComplemento(const std::string &complemento);

    std::string getCep() const;

    void setCep(const std::string &cep);

    std::string getCidade() const;

    void setCidade(const std::string &cidade);

    std::string getEstado() const;

    void setEstado(const std::string &estado);

};
#endif
