//
// Created by Thales Nunes on 5/11/22.
//

#include "UC.h"
#include "Fatura.h"

int UC::nextIdUC = 0;

UC::UC() : idUC(nextIdUC++) {}

UC::UC(const std::vector<Fatura> &faturas) : idUC(nextIdUC++), faturas(faturas) {}

UC::UC(const UC& uc) : idUC(uc.idUC), faturas(uc.faturas) {}

int UC::getIdUc() const {
    return idUC;
}

void UC::setIdUc(int idUc) {
    this->idUC = idUc;
}

std::vector<Fatura> const & UC::getFaturas() const{
    return faturas;
}

void UC::setFaturas(std::vector<Fatura> &faturas) {
    this->faturas = std::move(faturas);
}

double UC::pagar(const int &idFaturaAPagar, const time_t &dtPagamento) {
    for (auto &fatura: this->faturas) {
        if(fatura.getIdFatura() == idFaturaAPagar) {
            fatura.setDtPagamento(dtPagamento);
            return fatura.calcularValor(dtPagamento);
        }
    }
    throw std::invalid_argument( "Fatura a Pagar nao existe." );
}

std::vector<Fatura> UC::verificarPagamento() {
    std::vector<Fatura> faturasApagar;

    for (auto &fat : this->faturas) {
        if (!fat.verificarPagamento()) {
            faturasApagar.push_back(fat);
        }
    }
    return faturasApagar;
}

std::vector<Fatura> UC::verificarVencimento(const time_t &now) {
    std::vector<Fatura> faturasVencidas;

    for (auto &fat : this->faturas) {
        if (!fat.verificarPagamento() && now > fat.getDtVencimento()) {
            faturasVencidas.push_back(fat);
        }
    }
    return faturasVencidas;
}

void UC::addFatura(Fatura &new_fatura) {
    for (auto &fat : this->faturas) {
        if (fat == new_fatura) {
            throw std::runtime_error("Repeated Fatura id");
        }
    }
    faturas.push_back(new_fatura);
}

bool UC::operator==(const UC& other) {
  return this->idUC == other.getIdUc();
}

UC& UC::operator=(const UC& other) {
    this->idUC = other.getIdUc();
    this->faturas = other.getFaturas();

    return *this;
}