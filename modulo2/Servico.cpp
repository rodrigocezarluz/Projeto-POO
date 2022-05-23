#include "Servico.h"

Servico::Servico() {

}

Servico::Servico(time_t inicio, const UC &uc) : inicio(inicio), uc(uc) {

}

Servico::Servico(time_t inicio, time_t fim, const UC &uc) : inicio(inicio), fim(fim), uc(uc) {

}


time_t Servico::getInicio() const {
    return inicio;
}

void Servico::setInicio(time_t inicio) {
    Servico::inicio = inicio;
}

time_t Servico::getFim() const {
    return fim;
}

void Servico::setFim(time_t fim) {
    Servico::fim = fim;
}

void Servico::executar() {
    Servico::setFim(time(0));
}
