#include "Servico.h"

int Servico::next_id_servico = 0;

Servico::Servico() : id_servico(next_id_servico++), inicio(Data(0)), fim(Data(0)){

}

Servico::Servico(Data inicio, const UC &uc) : inicio(inicio), uc(uc), id_servico(next_id_servico++) , fim(Data(0)){

}

Servico::Servico(Data inicio, Data fim, const UC &uc) : inicio(inicio), fim(fim), uc(uc), id_servico(next_id_servico++) {

}


Data Servico::getInicio() const {
    return inicio;
}

void Servico::setInicio(Data inicio) {
    Servico::inicio = inicio;
}

Data Servico::getFim() const {
    return fim;
}

void Servico::setFim(Data fim) {
    Servico::fim = fim;
}

UC & Servico::getUC()  {
    return this->uc;
}


void Servico::executar() {
    this->setFim(time(0));
}

int Servico::getIDServico(){
    return this->id_servico;
}