//
// Created by Thales Nunes on 5/11/22.
//

#ifndef MODULO1_FATURA_H
#define MODULO1_FATURA_H
#include <ctime>
#include <stdexcept>
#include <algorithm>
#include <cmath>
#include "utils.h"

class Fatura {
    int idFatura;
    double valorInicial;
    double consumoEnergia;
    time_t dtVencimento;
    time_t dtPagamento;
    time_t dtEmissao;
public:
    Fatura();

    Fatura(int idFatura, double valorInicial, double consumoEnergia, time_t dtVencimento, time_t dtPagamento,
           time_t dtEmissao);

    int getIdFatura() const;

    void setIdFatura(int idFatura);

    double getValorInicial() const;

    void setValorInicial(double valorInicial);

    double getConsumoEnergia() const;

    void setConsumoEnergia(double consumoEnergia);

    time_t getDtVencimento() const;

    void setDtVencimento(time_t dtVencimento);

    time_t getDtPagamento() const;

    void setDtPagamento(time_t dtPagamento);

    time_t getDtEmissao() const;

    void setDtEmissao(time_t dtEmissao);

    double calcularValor(time_t now);

    bool verificarPagamento();

    bool operator==(const Fatura& other);

};

#endif //MODULO1_FATURA_H
