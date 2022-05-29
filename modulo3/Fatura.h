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

private:
    static int nextIdFatura;
    int idFatura;
    double valorInicial;
    double consumoEnergia;
    time_t dtVencimento;
    time_t dtPagamento;
    time_t dtEmissao;
   

public:
    
    static const double PRECO_ENERGIA;  // preço da energia em R$/kW ; valor referencia CEMIG maio de 2022

    Fatura();

    Fatura(const double valorInicial, const double consumoEnergia, const time_t dtVencimento, const time_t dtPagamento, const time_t dtEmissao);

    Fatura(const Fatura& f);

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

    Fatura& operator=(const Fatura& other);

    

};

#endif //MODULO1_FATURA_H
