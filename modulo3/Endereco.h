#ifndef ENDERECO_H
#define ENDERECO_H

#include <string>

class Endereco {
private:
    std::string logradouro, bairro, complemento, cep, cidade, estado;
    int numero;

public:
    Endereco();

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
