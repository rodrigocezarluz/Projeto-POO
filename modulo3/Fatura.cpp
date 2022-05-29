//
// Created by Thales Nunes on 5/11/22.
//

#include "Fatura.h"

const double TAXA_JUROS = 1.02;
const double PRECO_ENERGIA = 0.96574002;  // preço da energia em R$/kW ; valor referencia CEMIG maio de 2022]
int Fatura::nextIdFatura = 0;


Fatura::Fatura() : idFatura(nextIdFatura++), dtPagamento(0) {}

Fatura::Fatura(const double valorInicial, const double consumoEnergia, const time_t dtVencimento, const time_t dtPagamento,
               const time_t dtEmissao) : idFatura(nextIdFatura++), valorInicial(valorInicial), consumoEnergia(consumoEnergia),
                                   dtVencimento(dtVencimento), dtPagamento(dtPagamento), dtEmissao(dtEmissao) {}

Fatura::Fatura(const Fatura& f) : idFatura(f.idFatura), valorInicial(f.valorInicial), consumoEnergia(f.consumoEnergia),
                                   dtVencimento(f.dtVencimento), dtPagamento(f.dtPagamento), dtEmissao(f.dtEmissao)  {}

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

Fatura& Fatura::operator=(const Fatura& other) {
    this->idFatura = other.getIdFatura();
    this->valorInicial = other.getValorInicial();
    this->consumoEnergia = other.getConsumoEnergia();
    this->dtVencimento = other.getDtVencimento();
    this->dtPagamento = other.getDtPagamento();
    this->dtEmissao = other.getDtEmissao();

    return *this;
}