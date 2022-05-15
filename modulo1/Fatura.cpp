//
// Created by Thales Nunes on 5/11/22.
//

#include "Fatura.h"
#include <cmath>

const double TAXA_JUROS = 2.94;
Fatura::Fatura() {}

Fatura::Fatura(int idFatura, double valorInicial, double consumoEnergia, time_t dtVencimento, time_t dtPagamento,
               time_t dtEmissão) : idFatura(idFatura), valorInicial(valorInicial), consumoEnergia(consumoEnergia),
                                   dtVencimento(dtVencimento), dtPagamento(dtPagamento), dtEmissao(dtEmissão) {};

int Fatura::getIdFatura() const {
    return idFatura;
}

void Fatura::setIdFatura(int idFatura) {
    Fatura::idFatura = idFatura;
}

double Fatura::getValorInicial() const {
    return valorInicial;
}

void Fatura::setValorInicial(double valorInicial) {
    Fatura::valorInicial = valorInicial;
}

double Fatura::getConsumoEnergia() const {
    return consumoEnergia;
}

void Fatura::setConsumoEnergia(double consumoEnergia) {
    Fatura::consumoEnergia = consumoEnergia;
}

time_t Fatura::getDtVencimento() const {
    return dtVencimento;
}

void Fatura::setDtVencimento(time_t dtVencimento) {
    Fatura::dtVencimento = dtVencimento;
}

time_t Fatura::getDtPagamento() const {
    return dtPagamento;
}

void Fatura::setDtPagamento(time_t dtPagamento) {
    Fatura::dtPagamento = dtPagamento;
}

time_t Fatura::getDtEmissao() const {
    return dtEmissao;
}

void Fatura::setDtEmissao(time_t dtEmissao) {
    Fatura::dtEmissao = dtEmissao;
}

//TODO: ver taxa de juros.
double Fatura::calcularValor() {
    time_t now = time(0);
    double diasVencidos = std::floor(difftime(this->dtVencimento, now) / ((1000.0 / 3600.0) / 24.0));

    if (diasVencidos > 0) {
        return valorInicial * pow(TAXA_JUROS,  diasVencidos);
    }

    return valorInicial;
}

bool Fatura::verificarPagamento() {
    return dtPagamento == 0.0;
}



