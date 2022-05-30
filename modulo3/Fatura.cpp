//
// Created by Thales Nunes on 5/11/22.
//

#include "Fatura.h"

const double TAXA_JUROS = 1.02;
const double Fatura::PRECO_ENERGIA = 0.96574002;  // preço da energia em R$/kW ; valor referencia CEMIG maio de 2022]
int Fatura::nextIdFatura = 0;


Fatura::Fatura() : idFatura(nextIdFatura++), dtPagamento(0) {}

Fatura::Fatura(const double valorInicial, const double consumoEnergia, const Data dtVencimento, const Data dtPagamento,
               const Data dtEmissao) : idFatura(nextIdFatura++), valorInicial(valorInicial), consumoEnergia(consumoEnergia),
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

Data Fatura::getDtVencimento() const {
    return dtVencimento;
}

void Fatura::setDtVencimento(Data dtVencimento) {
    this->dtVencimento = dtVencimento;
}

Data Fatura::getDtPagamento() const {
    return dtPagamento;
}

void Fatura::setDtPagamento(Data dtPagamento) {
    this->dtPagamento = dtPagamento;
}

Data Fatura::getDtEmissao() const {
    return dtEmissao;
}

void Fatura::setDtEmissao(Data dtEmissao) {
    this->dtEmissao = dtEmissao;
}

double Fatura::calcularValor(Data now) {
    int diasVencidos = now.diffData(this->dtVencimento);

    if (diasVencidos > 0) {
        return valorInicial * std::pow(TAXA_JUROS,  diasVencidos);
    }

    return valorInicial;
}

bool Fatura::verificarPagamento() {
    return dtPagamento.getTicks() != 0;
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