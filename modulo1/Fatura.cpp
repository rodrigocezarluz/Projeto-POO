//
// Created by Thales Nunes on 5/11/22.
//

#include "Fatura.h"

const double TAXA_JUROS = 1.02;
Fatura::Fatura() {}

Fatura::Fatura(int idFatura, double valorInicial, double consumoEnergia, time_t dtVencimento, time_t dtPagamento,
               time_t dtEmissao) : idFatura(idFatura), valorInicial(valorInicial), consumoEnergia(consumoEnergia),
                                   dtVencimento(dtVencimento), dtPagamento(dtPagamento), dtEmissao(dtEmissao) {};

int Fatura::getIdFatura() const {
    return idFatura;
}

void Fatura::setIdFatura(int idFatura) {
    this->idFatura = idFatura;
}

double Fatura::getValorInicial() const {
    return valorInicial;
}

void Fatura::setValorInicial(double valorInicial) {
    this->valorInicial = valorInicial;
}

double Fatura::getConsumoEnergia() const {
    return consumoEnergia;
}

void Fatura::setConsumoEnergia(double consumoEnergia) {
    this->consumoEnergia = consumoEnergia;
}

time_t Fatura::getDtVencimento() const {
    return dtVencimento;
}

void Fatura::setDtVencimento(time_t dtVencimento) {
    this->dtVencimento = dtVencimento;
}

time_t Fatura::getDtPagamento() const {
    return dtPagamento;
}

void Fatura::setDtPagamento(time_t dtPagamento) {
    this->dtPagamento = dtPagamento;
}

time_t Fatura::getDtEmissao() const {
    return dtEmissao;
}

void Fatura::setDtEmissao(time_t dtEmissao) {
    this->dtEmissao = dtEmissao;
}

double Fatura::calcularValor(time_t now) {
    int diasVencidos = diffDays(now, this->dtVencimento);

    if (diasVencidos > 0) {
        return valorInicial * std::pow(TAXA_JUROS,  diasVencidos);
    }

    return valorInicial;
}

bool Fatura::verificarPagamento() {
    return dtPagamento != 0.0;
}

bool Fatura::operator==(const Fatura& other) {
  return this->idFatura == other.getIdFatura();
}

