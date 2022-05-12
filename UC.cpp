//
// Created by Thales Nunes on 5/11/22.
//

#include "UC.h"
#include "Fatura.h"

UC::UC() {}

UC::UC(int idUc, TipoUC tipo, std::vector<Fatura> &faturas) : idUC(idUc), tipo(tipo), faturas(faturas) {}

int UC::getIdUc() const {
    return idUC;
}

void UC::setIdUc(int idUc) {
    idUC = idUc;
}

TipoUC UC::getTipo() const {
    return tipo;
}

void UC::setTipo(TipoUC tipo) {
    UC::tipo = tipo;
}

std::vector<Fatura> &UC::getFaturas() {
    return faturas;
}

void UC::setFaturas(std::vector<Fatura> &faturas) {
    UC::faturas = std::move(faturas);
}

std::vector<Fatura> UC::verificarPagamento() {
    std::vector<Fatura> faturasVencidas;

    std::copy_if (this->faturas.begin(), this->faturas.end(), std::back_inserter(faturasVencidas), [](Fatura fatura){
        return !fatura.verificarPagamento();
    });

    return faturasVencidas;
}



