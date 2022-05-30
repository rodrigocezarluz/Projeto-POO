//
// Created by Thales Nunes on 5/11/22.
//

#include "UC.h"
#include <cstdlib>


int UC::nextIdUC = 0;

UC::UC() : idUC(nextIdUC++), consumoEnergiaTotal(0), consumoEnergiaMedido(0) {}

UC::UC(const std::vector<Fatura> &faturas) : idUC(nextIdUC++), faturas(faturas), consumoEnergiaTotal(0), consumoEnergiaMedido(0) {}

UC::UC(const UC& uc) : idUC(uc.idUC), faturas(uc.faturas), consumoEnergiaTotal(uc.consumoEnergiaTotal), consumoEnergiaMedido(uc.consumoEnergiaMedido) {}

int UC::getIdUc() const {
    return idUC;
}

void UC::setIdUc(int idUc) {
    this->idUC = idUc;
}

double UC::getConsumoEnergiaTotal() const {
    return this->consumoEnergiaTotal;
}

void UC::setConsumoEnergiaTotal(double consumoMedido) {
    this->consumoEnergiaTotal += consumoMedido;
    return;
}

double UC::getConsumoEnergiaMedido() const {
    return this->consumoEnergiaMedido;
}

void UC::setConsumoEnergiaMedido(double consumoMedido) {
    this->consumoEnergiaMedido = consumoMedido;
    return;
}

std::vector<Fatura> const & UC::getFaturas() const{
    return faturas;
}

void UC::setFaturas(std::vector<Fatura> &faturas) {
    this->faturas = std::move(faturas);
}

double UC::pagar(const int &idFaturaAPagar, const Data &dtPagamento) {
    for (auto &fatura: this->faturas) {
        if(fatura.getIdFatura() == idFaturaAPagar) {
            fatura.setDtPagamento(dtPagamento);
            return fatura.calcularValor(dtPagamento);
        }
    }
    throw std::invalid_argument( "Fatura a Pagar nao existe." );
}

double UC::medirEnergia(){
    
    // obtendo um valor de consumo de energia aleatório
    std::srand(time(0));  // Initialize random number generator.    
    double valor_maximo = 10000;
    double valor_minino = 0;
    double valor_medido = static_cast <double> (std::rand()) / ( static_cast <double> (RAND_MAX/(valor_maximo-valor_minino)));
        
    // obtendo a quantidade de energia consumida desde a última medição.
    this->setConsumoEnergiaMedido(valor_medido);

    // incrementando o consumo de energia total da UC
    this->setConsumoEnergiaTotal(this->getConsumoEnergiaMedido());
    return this->getConsumoEnergiaTotal();
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

std::vector<Fatura> UC::verificarVencimento(Data &now) {
    std::vector<Fatura> faturasVencidas;

    for (auto &fat : this->faturas) {
        if (!fat.verificarPagamento() && now.diffData(fat.getDtVencimento()) > 0) {
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
    this->consumoEnergiaMedido = other.getConsumoEnergiaMedido();
    this->consumoEnergiaTotal = other.getConsumoEnergiaTotal();

    return *this;
}