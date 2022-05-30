//
// Created by Thales Nunes on 5/11/22.
//

#ifndef MODULO1_FATURA_H
#define MODULO1_FATURA_H
#include <ctime>
#include <stdexcept>
#include <algorithm>
#include <cmath>
#include "Data.h"

class Fatura {

private:
    static int nextIdFatura;
    int idFatura;
    double valorInicial;
    double consumoEnergia;
    Data dtVencimento;
    Data dtPagamento;
    Data dtEmissao;
   

public:
    
    static const double PRECO_ENERGIA;  // preço da energia em R$/kW ; valor referencia CEMIG maio de 2022

    Fatura();

    Fatura(const double valorInicial, const double consumoEnergia, const Data dtVencimento, const Data dtPagamento, const Data dtEmissao);

    Fatura(const Fatura& f);

    int getIdFatura() const;

    void setIdFatura(int idFatura);

    double getValorInicial() const;

    void setValorInicial(double valorInicial);

    double getConsumoEnergia() const;

    void setConsumoEnergia(double consumoEnergia);

    Data getDtVencimento() const;

    void setDtVencimento(Data dtVencimento);

    Data getDtPagamento() const;

    void setDtPagamento(Data dtPagamento);

    Data getDtEmissao() const;

    void setDtEmissao(Data dtEmissao);

    double calcularValor(Data now);

    bool verificarPagamento();

    bool operator==(const Fatura& other);

    Fatura& operator=(const Fatura& other);

    

};

#endif //MODULO1_FATURA_H
