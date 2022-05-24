#include "Servico.h"

int Servico::next_id_servico = 0;

Servico::Servico() : id_servico(next_id_servico++), inicio((time_t)(0)), fim((time_t)(0)){

}

Servico::Servico(time_t inicio, const UC &uc) : inicio(inicio), uc(uc), id_servico(next_id_servico++) , fim((time_t)(0)){

}

Servico::Servico(time_t inicio, time_t fim, const UC &uc) : inicio(inicio), fim(fim), uc(uc), id_servico(next_id_servico++) {

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

int Servico::getIDServico(){
    return this->id_servico;
}