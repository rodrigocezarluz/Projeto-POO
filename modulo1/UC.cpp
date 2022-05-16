//
// Created by Thales Nunes on 5/11/22.
//

#include "UC.h"
#include "Fatura.h"

UC::UC() {}

UC::UC(int idUc, const std::vector<Fatura> &faturas) : idUC(idUc), faturas(faturas) {}

int UC::getIdUc() const {
    return idUC;
}

void UC::setIdUc(int idUc) {
    idUC = idUc;
}

std::vector<Fatura> &UC::getFaturas() {
    return faturas;
}

void UC::setFaturas(std::vector<Fatura> &faturas) {
    UC::faturas = std::move(faturas);
}

std::vector<Fatura> UC::verificarPagamento() {
    std::vector<Fatura> faturasApagar;

    for (Fatura fat : this->faturas) {
        if (!fat.verificarPagamento()) {
            faturasApagar.push_back(fat);
        }
    }
    return faturasApagar;
}

std::vector<Fatura> UC::verificarVencimento(time_t now) {
    std::vector<Fatura> faturasVencidas;

    for (Fatura fat : this->faturas) {
        if (!fat.verificarPagamento() && now > fat.getDtVencimento()) {
            faturasVencidas.push_back(fat);
        }
    }
    return faturasVencidas;
}

void UC::addFatura(Fatura &new_fatura) {
    for (Fatura fat : this->faturas) {
        if (fat == new_fatura) {
            throw std::runtime_error("Repeated Fatura id");
        }
    }
    faturas.push_back(new_fatura);
}

bool UC::operator==(const UC& other) {
  return this->idUC == other.getIdUc();
}

